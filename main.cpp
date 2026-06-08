#include <iostream>
#include <string>
#include <cstdlib>
#include "Queue.h"

int getValue(std::string report = "");

enum Actions
{
    ENQUEUE = 1,
    DEQUEUE,
    PEEK,
    CLEAR,
    EXIT
};

int main()
{
    Queue<int> queue;
    int choice = 0;
    
    std::cout << "Queue Demo (max size = 10) \n" << std::endl;
    
    std::cout << "enter initial number of elements (max 10): ";
    int n = getValue();
    
    if (n < 0 || n > 10)
    {
        std::cout << "error. number must be between 0 and 10.\n";
        return 1;
    }
    
    for (int i = 0; i < n; ++i)
    {
        int val = getValue("enter element: ");
        queue.enqueue(val);
    }
    
    queue.print();
    std::cout << "size: " << queue.getSize() << std::endl;
    
    while (choice != EXIT)
    {
        std::cout << "\nchoose action:" << std::endl;
        std::cout << ENQUEUE << " - enqueue (add to end)" << std::endl;
        std::cout << DEQUEUE << " - dequeue (remove from front)" << std::endl;
        std::cout << PEEK << " - peek (view front)" << std::endl;
        std::cout << CLEAR << " - clear queue" << std::endl;
        std::cout << EXIT << " - exit" << std::endl;
        std::cout << "your choice: ";
        choice = getValue();
        
        switch (choice)
        {
        case ENQUEUE:
        {
            int val = getValue("enter value to enqueue: ");
            if (queue.enqueue(val))
            {
                queue.print();
                std::cout << "size: " << queue.getSize() << std::endl;
            }
            break;
        }
        case DEQUEUE:
        {
            int val;
            if (queue.dequeue(val))
            {
                std::cout << "dequeued value: " << val << std::endl;
                queue.print();
                std::cout << "size: " << queue.getSize() << std::endl;
            }
            break;
        }
        case PEEK:
        {
            int val;
            if (queue.peek(val))
            {
                std::cout << "front element: " << val << std::endl;
            }
            break;
        }
        case CLEAR:
        {
            queue.clear();
            std::cout << "queue cleared!" << std::endl;
            queue.print();
            break;
        }
        case EXIT:
        {
            std::cout << "exiting program." << std::endl;
            break;
        }
        default:
        {
            std::cout << "error. invalid choice.\n";
            break;
        }
        }
    }
    
    return 0;
}

int getValue(std::string report)
{
    std::cout << report;
    int value = 0;
    std::cin >> value;
    if (std::cin.fail())
    {
        std::cout << "error, invalid value entered.\n";
        exit(1);
    }
    return value;
}
