#include "Queue.h"
#include <string>
#include <stdexcept>

Queue::Queue() : head(nullptr), tail(nullptr), count(0) {}

Queue::Queue(const std::initializer_list<int> init) : head(nullptr), tail(nullptr), count(0)
{
    for (int value : init)
    {
        enqueue(value);
    }
}

Queue::Queue(const Queue& other) : head(nullptr), tail(nullptr), count(0)
{
    Node* current = other.head;
    while (current != nullptr)
    {
        enqueue(current->data);
        current = current->next;
    }
}

Queue::Queue(Queue&& other) noexcept : head(other.head), tail(other.tail), count(other.count)
{
    other.head = nullptr;
    other.tail = nullptr;
    other.count = 0;
}

Queue::~Queue()
{
    clear();
}

Queue& Queue::operator=(const Queue& other)
{
    if (this != &other)
    {
        clear();
        Node* current = other.head;
        while (current != nullptr)
        {
            enqueue(current->data);
            current = current->next;
        }
    }
    return *this;
}

Queue& Queue::operator=(Queue&& other) noexcept
{
    if (this != &other)
    {
        clear();
        head = other.head;
        tail = other.tail;
        count = other.count;
        other.head = nullptr;
        other.tail = nullptr;
        other.count = 0;
    }
    return *this;
}

void Queue::enqueue(const int value)
{
    Node* newNode = new Node(value);
    if (isEmpty())
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    ++count;
}

int Queue::dequeue()
{
    if (isEmpty())
    {
        throw std::runtime_error("Ошибка: очередь пуста");
    }
    int value = head->data;
    Node* temp = head;
    head = head->next;
    delete temp;
    --count;
    if (isEmpty())
    {
        tail = nullptr;
    }
    return value;
}

int Queue::peek() const
{
    if (isEmpty())
    {
        throw std::runtime_error("Ошибка: очередь пуста");
    }
    return head->data;
}

bool Queue::isEmpty() const
{
    return head == nullptr;
}

size_t Queue::size() const
{
    return count;
}

void Queue::clear()
{
    while (!isEmpty())
    {
        dequeue();
    }
}

std::string Queue::toString() const
{
    std::string result = "[";
    Node* current = head;
    while (current != nullptr)
    {
        result += std::to_string(current->data);
        if (current->next != nullptr)
        {
            result += ", ";
        }
        current = current->next;
    }
    result += "]";
    return result;
}

Queue& Queue::operator<<(const int value)
{
    enqueue(value);
    return *this;
}

Queue& Queue::operator>>(int& value)
{
    value = dequeue();
    return *this;
}

bool Queue::contains(const int value) const
{
    Node* current = head;
    while (current != nullptr)
    {
        if (current->data == value)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}
