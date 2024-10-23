/*Aaron is learning data structures, and his teacher gave him a task related to the queue data structure. The queue should be implemented as a linked list, where each node holds a customer's ID.



He is required to implement a simple program that supports the following operations:

Enqueue: Add a customer's ID to the end of the queue.
Dequeue: Remove and return the customer's ID from the front of the queue.
Display: Display the current customer IDs in the queue.


Your task is to help Aaron implement the operations mentioned above.*/
#include <iostream>
using namespace std;

class Node {
public:
    int customer_id;
    Node* next;
    
    Node(int id) {
        customer_id = id;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    bool is_empty() {
        return front == nullptr;
    }

    void enqueue(int customer_id) {
        Node* new_node = new Node(customer_id);
        if (rear == nullptr) {
            front = rear = new_node;
        } else {
            rear->next = new_node;
            rear = new_node;
        }
        cout << "Customer ID " << customer_id << " is enqueued" << endl;
    }

    void dequeue() {
        if (is_empty()) {
            cout << "Queue is empty" << endl;
        } else {
            int dequeued_id = front->customer_id;
            Node* temp = front;
            front = front->next;
            if (front == nullptr) {
                rear = nullptr;
            }
            delete temp;
            cout << "Dequeued customer ID: " << dequeued_id << endl;
        }
    }

    void display() {
        if (is_empty()) {
            cout << "Queue is empty" << endl;
        } else {
            Node* current = front;
            cout << "Customer IDs in the queue are: ";
            while (current != nullptr) {
                cout << current->customer_id << " ";
                current = current->next;
            }
            cout << endl;
        }
    }
};

int main() {
    Queue queue;
    int choice, id;

    while (true) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> id;
                queue.enqueue(id);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                queue.display();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid option" << endl;
        }
    }

    return 0;
}
