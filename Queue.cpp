#include "Queue.h"
#include <sstream>
#include <stdexcept>

const size_t INITIAL_CAPACITY = 4;

Queue::Queue() : m_elements(nullptr), m_count(0), m_capacity(0), m_front(0), m_rear(0) {}

Queue::Queue(const std::initializer_list<int> items)
    : m_elements(nullptr), m_count(items.size()), m_capacity(items.size()), m_front(0), m_rear(items.size())
{
    if (m_count > 0)
    {
        m_elements = new int[m_capacity];
        size_t idx = 0;
        for (const int& val : items)
        {
            m_elements[idx++] = val;
        }
    }
}

Queue::~Queue()
{
    delete[] m_elements;
}

Queue::Queue(const Queue& other)
    : m_elements(nullptr), m_count(other.m_count), m_capacity(other.m_capacity),
    m_front(other.m_front), m_rear(other.m_rear)
{
    if (m_capacity > 0)
    {
        m_elements = new int[m_capacity];
        for (size_t i = 0; i < m_capacity; ++i)
        {
            m_elements[i] = other.m_elements[i];
        }
    }
}

Queue::Queue(Queue&& other)
    : m_elements(other.m_elements), m_count(other.m_count), m_capacity(other.m_capacity),
    m_front(other.m_front), m_rear(other.m_rear)
{
    other.m_elements = nullptr;
    other.m_count = 0;
    other.m_capacity = 0;
    other.m_front = 0;
    other.m_rear = 0;
}

void Queue::resize()
{
    size_t new_capacity = (m_capacity == 0) ? INITIAL_CAPACITY : m_capacity * 2;
    int* new_elements = new int[new_capacity];

    // Копируем элементы в новое место (выравниваем с начала)
    for (size_t i = 0; i < m_count; ++i)
    {
        new_elements[i] = m_elements[(m_front + i) % m_capacity];
    }

    delete[] m_elements;
    m_elements = new_elements;
    m_front = 0;
    m_rear = m_count;
    m_capacity = new_capacity;
}

void Queue::enqueue(const int value)
{
    if (m_count == m_capacity)
    {
        resize();
    }

    if (m_count == 0)
    {
        if (m_capacity == 0)
        {
            resize();
        }
        m_front = 0;
        m_rear = 0;
    }

    m_elements[m_rear] = value;
    m_rear = (m_rear + 1) % m_capacity;
    m_count++;
}

int Queue::dequeue()
{
    if (is_empty())
    {
        throw std::out_of_range("Error: The queue is empty, and you cannot delete an item.");
    }

    int value = m_elements[m_front];
    m_front = (m_front + 1) % m_capacity;
    m_count--;

    return value;
}

int Queue::peek() const
{
    if (is_empty())
    {
        throw std::out_of_range("Error: The queue is empty, and there are no items to view.");
    }
    return m_elements[m_front];
}

std::string Queue::to_string() const
{
    if (is_empty())
        return "Empty";

    std::stringstream ss;
    for (size_t i = 0; i < m_count; ++i)
    {
        ss << m_elements[(m_front + i) % m_capacity];
        if (i < m_count - 1)
            ss << " ";
    }
    return ss.str();
}

size_t Queue::get_size() const
{
    return m_count;
}

bool Queue::is_empty() const
{
    return m_count == 0;
}

void Queue::clear()
{
    delete[] m_elements;
    m_elements = nullptr;
    m_count = 0;
    m_capacity = 0;
    m_front = 0;
    m_rear = 0;
}

Queue& Queue::operator=(const Queue& other)
{
    if (this != &other)
    {
        delete[] m_elements;

        m_count = other.m_count;
        m_capacity = other.m_capacity;
        m_front = other.m_front;
        m_rear = other.m_rear;

        if (m_capacity > 0)
        {
            m_elements = new int[m_capacity];
            for (size_t i = 0; i < m_capacity; ++i)
            {
                m_elements[i] = other.m_elements[i];
            }
        }
        else
        {
            m_elements = nullptr;
        }
    }
    return *this;
}

Queue& Queue::operator=(Queue&& other)
{
    if (this != &other)
    {
        delete[] m_elements;

        m_elements = other.m_elements;
        m_count = other.m_count;
        m_capacity = other.m_capacity;
        m_front = other.m_front;
        m_rear = other.m_rear;

        other.m_elements = nullptr;
        other.m_count = 0;
        other.m_capacity = 0;
        other.m_front = 0;
        other.m_rear = 0;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Queue& q)
{
    os << q.to_string();
    return os;
}

std::istream& operator>>(std::istream& is, Queue& q)
{
    int value = 0;
    if (is >> value)
    {
        q.enqueue(value);
    }
    return is;
}
