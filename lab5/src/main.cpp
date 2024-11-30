#include <iostream>
#include <memory>
#include <string>
#include "linked_list.h"

class FixedMemoryResource : public std::pmr::memory_resource
{
private:
    std::byte *pool;
    size_t size;
    size_t offset;

public:
    FixedMemoryResource(size_t total_size)
        : size(total_size), offset(0)
    {
        pool = new std::byte[total_size];
    }

    ~FixedMemoryResource()
    {
        delete[] pool;
    }

protected:
    void *do_allocate(std::size_t bytes, std::size_t alignment) override
    {
        std::size_t current_address = reinterpret_cast<std::size_t>(pool + offset);
        std::size_t misalignment = current_address % alignment;
        std::size_t adjustment = misalignment == 0 ? 0 : (alignment - misalignment);
        std::size_t aligned_offset = offset + adjustment;

        if (aligned_offset + bytes <= size)
        {
            void *ptr = pool + aligned_offset;
            offset = aligned_offset + bytes;
            return ptr;
        }
        else
        {
            throw std::bad_alloc();
        }
    }

    void do_deallocate(void *p, std::size_t bytes, std::size_t alignment) override
    {
        // В фиксированном пуле память не освобождается
    }

    bool do_is_equal(const std::pmr::memory_resource &other) const noexcept override
    {
        return this == &other;
    }
};

int main()
{
    FixedMemoryResource memory_resource(1024);
    DoublyLinkedList<int> int_list(&memory_resource);

    int_list.push_back(10);
    int_list.push_back(20);
    int_list.push_back(30);

    std::cout << "int list: ";
    for (const auto &elem : int_list)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    struct ComplexType
    {
        int id;
        std::string name;
    };

    DoublyLinkedList<ComplexType> complex_list(&memory_resource);
    complex_list.push_back(ComplexType{1, "Item 1"});
    complex_list.push_back(ComplexType{2, "Item 2"});

    std::cout << "ComplexType list: \n";
    for (const auto &elem : complex_list)
    {
        std::cout << "ID: " << elem.id << ", Name: " << elem.name << std::endl;
    }

    return 0;
}
