// circularQueue.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//


//
//lass Queue
//{
//public:
//
//	Queue();
//	~Queue();
//
//	// Modifiers
//	void enqueue(int value);
//	int dequeue();
//
//	// Getters
//	int size();
//	bool empty();
//
//private:
//	int _front;   // Index to the front (-1 if empty)
//	int _back;	// Index to the back (-1 if empty)
//int* _array;  // Dynamically allocated array
//int _capacity;
//void resize() {} //needed when the array reaches its limit
//};



#include <iostream>
#include <stdexcept>

using namespace std;

class Queue
{
public:
    // Constructor
    Queue(int capacity = 10)
        : front(0), back(0), capacity(capacity), size(0)
    {
        array = new int[capacity];
    }

    // Destructor
    ~Queue()
    {
        delete[] array;
    }

    // Modifiers
    void enqueue(int value)
    {
        // Check if the queue is full and resize if necessary
        if (size == capacity)
        {
            resize();
        }

        // Insert value at the back of the queue
        array[back] = value;
        back = (back + 1) % capacity;  // Wrap around if needed
        ++size;
    }

    int dequeue()
    {
        if (empty())
        {
            throw out_of_range("Queue is empty!");
        }

        // Get the front value
        int value = array[front];
        front = (front + 1) % capacity;  // Move the front pointer
        --size;
        return value;
    }

    // Getters
    int size() const
    {
        return size;
    }

    bool empty() const
    {
        return size == 0;
    }

private:
    // Private helper methods
    void resize()
    {
        // Double the capacity
        int new_capacity = capacity * 2;
        int* new_array = new int[new_capacity];

        // Copy the elements to the new array
        for (int i = 0; i < size; ++i)
        {
            new_array[i] = array[(front + i) % capacity];
        }

        // Delete the old array and update the capacity and pointers
        delete[] array;
        array = new_array;
        front = 0;
        back = size;
        capacity = new_capacity;
    }

private:
    int front;        // Index to the front (-1 if empty)
    int back;         // Index to the back (-1 if empty)
    int* array;       // Dynamically allocated array
    int capacity;     // Current capacity of the queue
    int size;         // Current size of the queue
};

int main()
{
    Queue q;

    // Test enqueue
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    // Test size
    cout << "Queue size: " << q.size() << endl;

    // Test dequeue
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Queue size after dequeue: " << q.size() << endl;

    // Test if the queue is empty
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl;

    // Dequeue all elements to see the behavior
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl;

    return 0;
}

