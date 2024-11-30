#pragma once
#include <memory>
#include <iterator>
#include <iostream>
#include "custom_memory_resources.h"

template <typename T>
class DoublyLinkedList
{
private:
    struct Node
    {
        T data;
        std::shared_ptr<Node> prev;
        std::shared_ptr<Node> next;

        explicit Node(const T &data) : data(data), prev(nullptr), next(nullptr) {}
    };

    std::shared_ptr<Node> head;
    std::shared_ptr<Node> tail;
    size_t list_size;

public:
    explicit DoublyLinkedList() : head(nullptr), tail(nullptr), list_size(0) {}

    ~DoublyLinkedList()
    {
        clear();
    }

    void push_back(const T &value)
    {
        auto new_node = std::make_shared<Node>(value);
        if (!tail)
        {
            head = tail = new_node;
        }
        else
        {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
        list_size++;
    }

    void remove(const T &value)
    {
        auto current = head;
        while (current)
        {
            if (current->data == value)
            {
                if (current->prev)
                {
                    current->prev->next = current->next;
                }
                else
                {
                    head = current->next;
                }
                if (current->next)
                {
                    current->next->prev = current->prev;
                }
                else
                {
                    tail = current->prev;
                }
                list_size--;
                return;
            }
            current = current->next;
        }
    }

    size_t size() const { return list_size; }

    class Iterator
    {
    private:
        std::shared_ptr<Node> current;

    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T *;
        using reference = T &;

        explicit Iterator(std::shared_ptr<Node> node) : current(node) {}

        T &operator*() { return current->data; }
        T *operator->() { return &current->data; }

        Iterator &operator++()
        {
            current = current->next;
            return *this;
        }

        bool operator!=(const Iterator &other) const
        {
            return current != other.current;
        }

        bool operator==(const Iterator &other) const
        {
            return current == other.current;
        }
    };

    Iterator begin() const { return Iterator(head); }
    Iterator end() const { return Iterator(nullptr); }

private:
    void clear()
    {
        head = tail = nullptr;
        list_size = 0;
    }
};
