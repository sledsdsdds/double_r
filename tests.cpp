#include <gtest/gtest.h>
#include "Queue.h"

TEST(QueueTest, DefaultConstructor)
{
    Queue q;
    EXPECT_EQ(q.get_size(), 0);
    EXPECT_TRUE(q.is_empty());
    EXPECT_EQ(q.to_string(), "Empty");
}

TEST(QueueTest, InitializerList)
{
    Queue q = { 10, 20, 30 };
    EXPECT_EQ(q.get_size(), 3);
    EXPECT_EQ(q.to_string(), "10 20 30");
}

TEST(QueueTest, CopyConstructor)
{
    Queue q1 = { 1, 2, 3 };
    Queue q2 = q1;
    EXPECT_EQ(q2.to_string(), q1.to_string());
}

TEST(QueueTest, AssignmentOperator)
{
    Queue q1 = { 7, 8, 9 };
    Queue q2;
    q2 = q1;
    EXPECT_EQ(q2.to_string(), "7 8 9");
}

TEST(QueueTest, Enqueue)
{
    Queue q;
    q.enqueue(100);
    q.enqueue(200);
    q.enqueue(300);
    EXPECT_EQ(q.to_string(), "100 200 300");
    EXPECT_EQ(q.get_size(), 3);
}

TEST(QueueTest, Dequeue)
{
    Queue q = { 10, 20, 30 };
    int val = q.dequeue();
    EXPECT_EQ(val, 10);
    EXPECT_EQ(q.to_string(), "20 30");
    EXPECT_EQ(q.get_size(), 2);
}

TEST(QueueTest, Peek)
{
    Queue q = { 5, 15, 25 };
    int val = q.peek();
    EXPECT_EQ(val, 5);
    EXPECT_EQ(q.to_string(), "5 15 25");
    EXPECT_EQ(q.get_size(), 3);
}

TEST(QueueTest, Clear)
{
    Queue q = { 1, 2, 3, 4, 5 };
    q.clear();
    EXPECT_EQ(q.get_size(), 0);
    EXPECT_TRUE(q.is_empty());
    EXPECT_EQ(q.to_string(), "Empty");
}

TEST(QueueTest, EmptyQueueDequeueThrows)
{
    Queue q;
    EXPECT_THROW(q.dequeue(), std::out_of_range);
}

TEST(QueueTest, EmptyQueuePeekThrows)
{
    Queue q;
    EXPECT_THROW(q.peek(), std::out_of_range);
}

TEST(QueueTest, LargeNumberOfElements)
{
    Queue q;
    for (int i = 1; i <= 100; ++i)
    {
        q.enqueue(i);
    }
    EXPECT_EQ(q.get_size(), 100);
    EXPECT_EQ(q.peek(), 1);

    for (int i = 1; i <= 50; ++i)
    {
        EXPECT_EQ(q.dequeue(), i);
    }
    EXPECT_EQ(q.get_size(), 50);
    EXPECT_EQ(q.peek(), 51);
}

TEST(QueueTest, MultipleEnqueueDequeue)
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    EXPECT_EQ(q.dequeue(), 1);
    q.enqueue(3);
    EXPECT_EQ(q.dequeue(), 2);
    EXPECT_EQ(q.dequeue(), 3);
    EXPECT_TRUE(q.is_empty());
}
