#pragma once
#include <memory_resource>
#include <vector>
#include <new>
#include <iostream>

class FixedMemoryResource : public std::pmr::memory_resource
{
private:
    size_t block_size;
    size_t total_size;
    std::vector<void *> free_blocks;

public:
    FixedMemoryResource(size_t block_size, size_t total_size)
        : block_size(block_size), total_size(total_size)
    {
        size_t num_blocks = total_size / block_size;
        for (size_t i = 0; i < num_blocks; ++i)
        {
            void *block = ::operator new(block_size);
            free_blocks.push_back(block);
        }
        std::cout << "Memory pool initialized with " << num_blocks << " blocks of size "
                  << block_size << " bytes.\n";
    }

    ~FixedMemoryResource()
    {
        for (auto ptr : free_blocks)
        {
            ::operator delete(ptr);
        }
        std::cout << "Memory pool destroyed.\n";
    }

protected:
    void *do_allocate(std::size_t bytes, std::size_t alignment) override
    {
        if (bytes > block_size || free_blocks.empty())
        {
            throw std::bad_alloc();
        }

        void *ptr = free_blocks.back();
        free_blocks.pop_back();
        return ptr;
    }

    void do_deallocate(void *pointer, std::size_t bytes, std::size_t alignment) override
    {
        if (bytes > block_size)
        {
            std::cerr << "Attempting to deallocate a block with size greater than pool block size.\n";
            return;
        }

        free_blocks.push_back(pointer);
    }

    bool do_is_equal(const std::pmr::memory_resource &other) const noexcept override
    {
        return this == &other;
    }
};