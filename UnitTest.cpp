#include "CppUnitTest.h"
#include "Queue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace QueueTests
{
    TEST_CLASS(QueueConstructorTests)
    {
    public:
        TEST_METHOD(DefaultConstructor_CreatesEmptyQueue)
        {
            Queue q;
            Assert::IsTrue(q.isEmpty());
            Assert::AreEqual(size_t(0), q.size());
        }

        TEST_METHOD(InitializerListConstructor_CreatesQueueWithElements)
        {
            Queue q = { 1, 2, 3, 4, 5 };
            Assert::IsFalse(q.isEmpty());
            Assert::AreEqual(size_t(5), q.size());
            Assert::AreEqual(1, q.peek());
        }

        TEST_METHOD(CopyConstructor_CreatesDeepCopy)
        {
            Queue original = { 10, 20, 30 };
            Queue copy(original);

            Assert::AreEqual(original.size(), copy.size());
            Assert::AreEqual(original.peek(), copy.peek());

            // Изменение копии не влияет на оригинал
            copy.dequeue();
            Assert::AreEqual(size_t(3), original.size());
            Assert::AreEqual(size_t(2), copy.size());
        }

        TEST_METHOD(MoveConstructor_TransfersOwnership)
        {
            Queue original = { 5, 10, 15 };
            size_t originalSize = original.size();
            int originalFront = original.peek();

            Queue moved(std::move(original));

            Assert::AreEqual(originalSize, moved.size());
            Assert::AreEqual(originalFront, moved.peek());
            Assert::IsTrue(original.isEmpty());
        }
    };

    TEST_CLASS(QueueOperationTests)
    {
    public:
        TEST_METHOD(Enqueue_AddsElementToBack)
        {
            Queue q;
            q.enqueue(42);
            Assert::IsFalse(q.isEmpty());
            Assert::AreEqual(size_t(1), q.size());
            Assert::AreEqual(42, q.peek());

            q.enqueue(100);
            Assert::AreEqual(size_t(2), q.size());
            Assert::AreEqual(42, q.peek());
        }

        TEST_METHOD(Dequeue_RemovesAndReturnsFrontElement)
        {
            Queue q = { 10, 20, 30 };
            int value = q.dequeue();
            Assert::AreEqual(10, value);
            Assert::AreEqual(size_t(2), q.size());
            Assert::AreEqual(20, q.peek());
        }

        TEST_METHOD(Dequeue_OnEmptyQueue_ThrowsException)
        {
            Queue q;
            auto func = [&q]() { q.dequeue(); };
            Assert::ExpectException<std::runtime_error>(func);
        }

        TEST_METHOD(Peek_ReturnsFrontElementWithoutRemoving)
        {
            Queue q = { 5, 15, 25 };
            int front = q.peek();
            Assert::AreEqual(5, front);
            Assert::AreEqual(size_t(3), q.size());
        }

        TEST_METHOD(Peek_OnEmptyQueue_ThrowsException)
        {
            Queue q;
            auto func = [&q]() { q.peek(); };
            Assert::ExpectException<std::runtime_error>(func);
        }

        TEST_METHOD(Clear_RemovesAllElements)
        {
            Queue q = { 1, 2, 3, 4, 5 };
            q.clear();
            Assert::IsTrue(q.isEmpty());
            Assert::AreEqual(size_t(0), q.size());
        }

        TEST_METHOD(Contains_FindsExistingElement)
        {
            Queue q = { 10, 20, 30, 40 };
            Assert::IsTrue(q.contains(20));
            Assert::IsTrue(q.contains(10));
            Assert::IsTrue(q.contains(40));
            Assert::IsFalse(q.contains(100));
            Assert::IsFalse(q.contains(0));
        }
    };

    TEST_CLASS(QueueOperatorTests)
    {
    public:
        TEST_METHOD(ShiftLeftOperator_AddsElement)
        {
            Queue q;
            q << 5 << 10 << 15;
            Assert::AreEqual(size_t(3), q.size());
            Assert::AreEqual(5, q.peek());

            q << 20;
            Assert::AreEqual(size_t(4), q.size());
        }

        TEST_METHOD(ShiftRightOperator_ExtractsElement)
        {
            Queue q = { 100, 200, 300 };
            int value;
            q >> value;
            Assert::AreEqual(100, value);
            Assert::AreEqual(size_t(2), q.size());
        }

        TEST_METHOD(CopyAssignmentOperator_CreatesDeepCopy)
        {
            Queue q1 = { 7, 14, 21 };
            Queue q2;
            q2 = q1;

            Assert::AreEqual(q1.size(), q2.size());
            Assert::AreEqual(q1.peek(), q2.peek());

            q2.dequeue();
            Assert::AreEqual(size_t(3), q1.size());
            Assert::AreEqual(size_t(2), q2.size());
        }

        TEST_METHOD(MoveAssignmentOperator_TransfersOwnership)
        {
            Queue q1 = { 1, 2, 3, 4 };
            Queue q2;
            q2 = std::move(q1);

            Assert::AreEqual(size_t(4), q2.size());
            Assert::IsTrue(q1.isEmpty());
        }
    };

    TEST_CLASS(QueueFIFOTests)
    {
    public:
        TEST_METHOD(Queue_FollowsFIFOOrder)
        {
            Queue q;
            q.enqueue(1);
            q.enqueue(2);
            q.enqueue(3);

            Assert::AreEqual(1, q.dequeue());
            Assert::AreEqual(2, q.dequeue());
            Assert::AreEqual(3, q.dequeue());
            Assert::IsTrue(q.isEmpty());
        }

        TEST_METHOD(ToString_ReturnsCorrectStringRepresentation)
        {
            Queue q = { 1, 2, 3, 4 };
            std::string str = q.toString();
            Assert::AreEqual(std::string("[1, 2, 3, 4]"), str);

            Queue empty;
            Assert::AreEqual(std::string("[]"), empty.toString());
        }

        TEST_METHOD(Queue_WithSingleElement_BehavesCorrectly)
        {
            Queue q;
            q.enqueue(42);
            Assert::AreEqual(42, q.peek());
            Assert::AreEqual(42, q.dequeue());
            Assert::IsTrue(q.isEmpty());
        }
    };
}
