#pragma once
#include <iostream>
#include <initializer_list>
#include <string>

/**
 * @brief Класс Очередь (Queue)
 * Реализует структуру данных FIFO (первым пришёл - первым ушёл)
 */
class Queue
{
private:
    /**
     * @brief Указатель на массив элементов
     */
    int* m_elements;

    /**
     * @brief Количество элементов в очереди
     */
    size_t m_count;

    /**
     * @brief Ёмкость очереди (максимальное количество элементов)
     */
    size_t m_capacity;

    /**
     * @brief Индекс начала очереди (для удаления)
     */
    size_t m_front;

    /**
     * @brief Индекс конца очереди (для добавления)
     */
    size_t m_rear;

    /**
     * @brief Увеличение ёмкости очереди при необходимости
     */
    void resize();

public:
    /**
     * @brief Конструктор по умолчанию
     */
    Queue();

    /**
     * @brief Конструктор со списком инициализации
     */
    Queue(const std::initializer_list<int> items);

    /**
     * @brief Конструктор копирования
     */
    Queue(const Queue& other);

    /**
     * @brief Конструктор перемещения
     */
    Queue(Queue&& other);

    /**
     * @brief Деструктор
     */
    ~Queue();

    /**
     * @brief Добавление элемента в конец очереди (enqueue)
     * @param value добавляемое значение
     */
    void enqueue(const int value);

    /**
     * @brief Удаление элемента из начала очереди (dequeue)
     * @return удалённое значение
     */
    int dequeue();

    /**
     * @brief Чтение головного элемента без удаления (peek)
     * @return значение головного элемента
     */
    int peek() const;

    /**
     * @brief Возвращает строку с содержимым очереди
     */
    std::string to_string() const;

    /**
     * @brief Возвращает текущий размер очереди
     */
    size_t get_size() const;

    /**
     * @brief Проверка очереди на пустоту
     */
    bool is_empty() const;

    /**
     * @brief Очистка очереди
     */
    void clear();

    /**
     * @brief Оператор присваивания (копирование)
     */
    Queue& operator=(const Queue& other);

    /**
     * @brief Оператор присваивания (перемещение)
     */
    Queue& operator=(Queue&& other);

    /**
     * @brief Перегрузка оператора сдвига влево
     */
    friend std::ostream& operator<<(std::ostream& os, const Queue& q);

    /**
     * @brief Перегрузка оператора сдвига вправо (enqueue)
     */
    friend std::istream& operator>>(std::istream& is, Queue& q);
};
