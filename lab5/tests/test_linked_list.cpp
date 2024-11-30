#include <gtest/gtest.h>
#include "custom_memory_resources.h"
#include "linked_list.h"

TEST(DoublyLinkedListTest, EmptyList)
{
    FixedMemoryResource memory_resource(64, 1024);
    DoublyLinkedList<int> list(&memory_resource);
    EXPECT_EQ(list.size(), 0);
    EXPECT_EQ(list.begin(), list.end());
}

TEST(DoublyLinkedListTest, AddSingleElement)
{
    FixedMemoryResource memory_resource(64, 1024);
    DoublyLinkedList<int> list(&memory_resource);
    list.push_back(42);
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(*list.begin(), 42);
}

TEST(DoublyLinkedListTest, AddMultipleElements)
{
    FixedMemoryResource memory_resource(64, 1024);
    DoublyLinkedList<int> list(&memory_resource);
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    int expected[] = {1, 2, 3};
    int index = 0;
    for (int value : list)
    {
        EXPECT_EQ(value, expected[index]);
        index++;
    }
}

TEST(DoublyLinkedListTest, RemoveMiddleElement)
{
    FixedMemoryResource memory_resource(64, 1024);
    DoublyLinkedList<int> list(&memory_resource);
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.remove(2);
    int expected[] = {1, 3};
    int index = 0;
    for (int value : list)
    {
        EXPECT_EQ(value, expected[index]);
        index++;
    }
}

TEST(DoublyLinkedListTest, RemoveHeadElement)
{
    FixedMemoryResource memory_resource(64, 1024);
    DoublyLinkedList<int> list(&memory_resource);
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.remove(1);
    int expected[] = {2, 3};
    int index = 0;
    for (int value : list)
    {
        EXPECT_EQ(value, expected[index]);
        index++;
    }
}

TEST(DoublyLinkedListTest, RemoveTailElement)
{
    FixedMemoryResource memory_resource(64, 1024);
    DoublyLinkedList<int> list(&memory_resource);
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.remove(3);
    int expected[] = {1, 2};
    int index = 0;
    for (int value : list)
    {
        EXPECT_EQ(value, expected[index]);
        index++;
    }
}

TEST(DoublyLinkedListTest, MemoryReuse)
{
    FixedMemoryResource memory_resource(64, 1024);
    DoublyLinkedList<int> list(&memory_resource);
    list.push_back(1);
    list.push_back(2);
    list.remove(1);
    list.push_back(3);
    int expected[] = {2, 3};
    int index = 0;
    for (int value : list)
    {
        EXPECT_EQ(value, expected[index]);
        index++;
    }
}

TEST(DoublyLinkedListTest, EmptyIteration)
{
    FixedMemoryResource memory_resource(64, 1024);
    DoublyLinkedList<int> list(&memory_resource);
    for (int value : list)
    {
        FAIL() << "Nope";
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}