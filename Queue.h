#pragma once
#include <iostream>
#include <string>
#include "Queue.cpp"

/**
 * @brief Шаблонный класс Очередь (Queue)
 * Реализует структуру данных FIFO (первым пришёл - первым ушёл)
 * 
 * @tparam Type тип хранимых элементов
 */
template <class Type>
class Queue
{
private:
    /**
     * @brief Максимальный размер очереди
     */
    enum { MAX = 10 };
    
    /**
     * @brief Массив для хранения элементов
     */
    Type items[MAX];
    
    /**
     * @brief Индекс начала очереди (откуда удаляем)
     */
    size_t front;
    
    /**
     * @brief Индекс конца очереди (куда добавляем)
     */
    size_t rear;
    
    /**
     * @brief Количество элементов в очереди
     */
    size_t count;

public:
    /**
     * @brief Конструктор по умолчанию
     */
    Queue();
    
    /**
     * @brief Проверка, пуста ли очередь
     * @return true если пуста, false если не пуста
     */
    bool isEmpty() const;
    
    /**
     * @brief Проверка, заполнена ли очередь
     * @return true если заполнена, false если есть место
     */
    bool isFull() const;
    
    /**
     * @brief Добавление элемента в конец очереди (enqueue)
     * @param item добавляемый элемент
     * @return true если добавление успешно, false если очередь заполнена
     */
    bool enqueue(Type& item);
    
    /**
     * @brief Удаление элемента из начала очереди (dequeue)
     * @param item переменная для сохранения удалённого элемента
     * @return true если удаление успешно, false если очередь пуста
     */
    bool dequeue(Type& item);
    
    /**
     * @brief Просмотр головного элемента без удаления (peek)
     * @param item переменная для сохранения элемента
     * @return true если очередь не пуста, false если пуста
     */
    bool peek(Type& item) const;
    
    /**
     * @brief Возвращает количество элементов в очереди
     * @return размер очереди
     */
    size_t getSize() const;
    
    /**
     * @brief Очистка очереди
     */
    void clear();
    
    /**
     * @brief Вывод очереди в поток
     */
    void print() const;
    
    /**
     * @brief Преобразование очереди в строку
     * @return строковое представление очереди
     */
    std::string toString() const;
};
