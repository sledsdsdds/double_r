#include <iostream>
#include <string>
#include <cstdlib>
#include "Queue.h"

/**
 * @brief Выводит подробную информацию о состоянии очереди
 *
 * Функция отображает:
 * - Строковое представление очереди
 * - Текущий размер очереди
 * - Статус пустоты очереди
 * - Значение первого элемента (если очередь не пуста)
 *
 * @param q Ссылка на константную очередь для вывода информации
 * @param name Имя очереди для идентификации в выводе
 *
 * @note Функция использует методы toString(), size(), isEmpty() и peek()
 * @warning Если очередь пуста, peek() не вызывается
 */
void printQueueInfo(const Queue& q, const std::string& name)
{
    std::cout << name << ": " << q.toString() << std::endl;
    std::cout << "Размер: " << q.size() << ", Пуста: " << (q.isEmpty() ? "да" : "нет") << std::endl;
    if (!q.isEmpty())
    {
        std::cout << "Первый элемент: " << q.peek() << std::endl;
    }
    std::cout << std::endl;
}

/**
 * @brief Главная функция программы
 *
 * Последовательно демонстрирует:
 * 1. Создание пустой очереди
 * 2. Создание очереди со списком инициализации
 * 3. Добавление элементов методом enqueue()
 * 4. Извлечение элементов методом dequeue()
 * 5. Использование операторов сдвига (<< и >>)
 * 6. Поиск элементов методом contains()
 * 7. Работу конструктора копирования
 * 8. Работу оператора присваивания
 * 9. Работу конструктора перемещения
 * 10. Очистку очереди методом clear()
 *
 * @return int Возвращает 0 при успешном выполнении
 */
int main()
{
    std::cout << "========== Демонстрация работы очереди (Queue) ==========\n\n";

    Queue q1;
    std::cout << "1. Создана пустая очередь:" << std::endl;
    printQueueInfo(q1, "q1");

    Queue q2 = { 10, 20, 30, 40, 50 };
    std::cout << "2. Очередь со списком инициализации:" << std::endl;
    printQueueInfo(q2, "q2");

    std::cout << "3. Добавление элементов (enqueue):" << std::endl;
    q2.enqueue(60);
    q2.enqueue(70);
    std::cout << "Добавлены 60 и 70:" << std::endl;
    printQueueInfo(q2, "q2");

    std::cout << "4. Извлечение элементов (dequeue):" << std::endl;
    int value = q2.dequeue();
    std::cout << "Извлечено: " << value << std::endl;
    value = q2.dequeue();
    std::cout << "Извлечено: " << value << std::endl;
    printQueueInfo(q2, "q2");

    std::cout << "5. Операторы сдвига:" << std::endl;
    Queue q3;
    q3 << 100 << 200 << 300;
    std::cout << "После q3 << 100 << 200 << 300:" << std::endl;
    printQueueInfo(q3, "q3");

    int extracted;
    q3 >> extracted;
    std::cout << "Извлечено через оператор >>: " << extracted << std::endl;
    printQueueInfo(q3, "q3");

    std::cout << "6. Поиск элемента:" << std::endl;
    int searchValue = 30;
    std::cout << "Содержит ли q2 значение " << searchValue << "? "
        << (q2.contains(searchValue) ? "Да" : "Нет") << std::endl;
    searchValue = 10;
    std::cout << "Содержит ли q2 значение " << searchValue << "? "
        << (q2.contains(searchValue) ? "Да" : "Нет") << std::endl;
    std::cout << std::endl;

    std::cout << "7. Конструктор копирования:" << std::endl;
    Queue q4(q2);
    std::cout << "Оригинал q2: " << q2.toString() << std::endl;
    std::cout << "Копия q4:    " << q4.toString() << std::endl;
    std::cout << std::endl;

    std::cout << "8. Оператор присваивания:" << std::endl;
    Queue q5;
    q5 = q2;
    std::cout << "q5 = q2:" << std::endl;
    printQueueInfo(q5, "q5");

    std::cout << "9. Конструктор перемещения:" << std::endl;
    Queue q6(std::move(q5));
    std::cout << "q6 (перемещён из q5): " << q6.toString() << std::endl;
    std::cout << "q5 после перемещения: " << q5.toString() << std::endl;
    std::cout << std::endl;

    std::cout << "10. Очистка очереди:" << std::endl;
    std::cout << "До очистки: ";
    printQueueInfo(q6, "q6");
    q6.clear();
    std::cout << "После очистки: ";
    printQueueInfo(q6, "q6");

    std::cout << "========== Демонстрация завершена ==========\n";
    return 0;
}
