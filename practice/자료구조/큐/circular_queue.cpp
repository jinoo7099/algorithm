#include <iostream>

const int MX = 5;
int arr[MX];
int front, rear;

using namespace std;

bool isFull() {
    return (rear + 1) % MX == front;
}

bool isEmpty() {
    return front == rear;
}

void enqueue(int x) {
    if (isFull()) {
        cout << "queue is full" << endl;
        return;
    }

    rear = (rear + 1) % MX;
    arr[rear] = x;
}

int dequeue() {
    if (isEmpty()) {
        cout << "queue is empty" << endl;
        return -1;
    }

    front = (front + 1) % MX;
    return arr[front];
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);

    cout << dequeue() << endl;
    cout << dequeue() << endl;
    cout << dequeue() << endl;
    cout << dequeue() << endl;
    return 0;
}