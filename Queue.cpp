/**
 * @brief Конструктор по умолчанию
 */
template <class Type>
Queue<Type>::Queue() : front(0), rear(0), count(0) {}

/**
 * @brief Проверка, пуста ли очередь
 */
template <class Type>
bool Queue<Type>::isEmpty() const
{
    return count == 0;
}

/**
 * @brief Проверка, заполнена ли очередь
 */
template <class Type>
bool Queue<Type>::isFull() const
{
    return count == MAX;
}

/**
 * @brief Добавление элемента в конец очереди (enqueue)
 */
template <class Type>
bool Queue<Type>::enqueue(Type& item)
{
    if (isFull())
    {
        std::cout << "Error: queue is full!\n";
        return false;
    }
    
    items[rear] = item;
    rear = (rear + 1) % MAX;
    count++;
    return true;
}

/**
 * @brief Удаление элемента из начала очереди (dequeue)
 */
template <class Type>
bool Queue<Type>::dequeue(Type& item)
{
    if (isEmpty())
    {
        std::cout << "Error: queue is empty!\n";
        return false;
    }
    
    item = items[front];
    front = (front + 1) % MAX;
    count--;
    return true;
}

/**
 * @brief Просмотр головного элемента без удаления (peek)
 */
template <class Type>
bool Queue<Type>::peek(Type& item) const
{
    if (isEmpty())
    {
        std::cout << "Error: queue is empty!\n";
        return false;
    }
    
    item = items[front];
    return true;
}

/**
 * @brief Возвращает количество элементов в очереди
 */
template <class Type>
size_t Queue<Type>::getSize() const
{
    return count;
}

/**
 * @brief Очистка очереди
 */
template <class Type>
void Queue<Type>::clear()
{
    front = 0;
    rear = 0;
    count = 0;
}

/**
 * @brief Вывод очереди в поток
 */
template <class Type>
void Queue<Type>::print() const
{
    if (isEmpty())
    {
        std::cout << "Queue: empty\n";
        return;
    }
    
    std::cout << "Queue: ";
    for (size_t i = 0; i < count; ++i)
    {
        std::cout << items[(front + i) % MAX];
        if (i < count - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

/**
 * @brief Преобразование очереди в строку
 */
template <class Type>
std::string Queue<Type>::toString() const
{
    if (isEmpty())
    {
        return "Empty";
    }
    
    std::string result;
    for (size_t i = 0; i < count; ++i)
    {
        result += std::to_string(items[(front + i) % MAX]);
        if (i < count - 1)
            result += " ";
    }
    return result;
}
