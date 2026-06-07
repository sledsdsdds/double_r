#include <iostream>
#include <string>
#include <cstdlib>
#include "Queue.h"

using namespace std;

/**
 * @brief Нумерация объектов выбора
 */
enum Actions
{
    ENQUEUE = 1,
    DEQUEUE,
    PEEK,
    CLEAR,
    EXIT
};

/**
 * @brief Выводит ошибку и завершает работу программы
 * @param text - текст, выводимый на экран
 */
void ERROR(const string text)
{
    cerr << text << endl;
    exit(1);
}

/**
 * @brief Считывает значение, введенное с клавиатуры
 * @return считанное значение
 */
int get_choice()
{
    int number = 0;
    cin >> number;
    if (cin.fail())
    {
        ERROR("Input error");
    }
    return number;
}

/**
 * @brief Точка входа в программу
 * @return Если программа выполнена корректно - 0, иначе 1
 */
int main()
{
    Queue collection;

    cout << "Specify the initial number of queue items: ";
    int n = get_choice();

    if (n < 0)
    {
        ERROR("Error: The number of elements cannot be negative");
    }

    if (n > 0)
    {
        cout << "Enter " << n << " queue elements: " << endl;
        for (size_t i = 0; i < static_cast<size_t>(n); ++i)
        {
            int val = get_choice();
            collection.enqueue(val);
        }
    }

    cout << "The initial queue: " << collection << endl;
    cout << "Queue size: " << collection.get_size() << endl;

    int choice = 0;
    while (choice != EXIT)
    {
        cout << "\nSelect an action with a queue: " << endl
            << ENQUEUE << " - Add an element to the end (enqueue)" << endl
            << DEQUEUE << " - Remove an element from the beginning (dequeue)" << endl
            << PEEK << " - View the head element (peek)" << endl
            << CLEAR << " - Clear the queue" << endl
            << EXIT << " - Exit" << endl;
        cout << "Your choice: ";
        choice = get_choice();

        try
        {
            switch (choice)
            {
            case ENQUEUE:
            {
                cout << "Enter a value to add: ";
                int val = get_choice();
                collection.enqueue(val);
                cout << "After adding: " << collection << endl;
                cout << "Queue size: " << collection.get_size() << endl;
                break;
            }
            case DEQUEUE:
            {
                int val = collection.dequeue();
                cout << "Dequeued element: " << val << endl;
                cout << "After dequeuing: " << collection << endl;
                cout << "Queue size: " << collection.get_size() << endl;
                break;
            }
            case PEEK:
            {
                int val = collection.peek();
                cout << "Head element: " << val << endl;
                cout << "Current queue: " << collection << endl;
                break;
            }
            case CLEAR:
            {
                collection.clear();
                cout << "The queue has been cleared!" << endl;
                cout << "The size of the queue is: " << collection.get_size() << endl;
                break;
            }
            case EXIT:
            {
                cout << "Program termination." << endl;
                break;
            }
            default:
                ERROR("Error: Invalid menu item selection.");
            }
        }
        catch (const exception& e)
        {
            cout << "Error! " << e.what() << endl;
        }
    }

    return 0;
}
