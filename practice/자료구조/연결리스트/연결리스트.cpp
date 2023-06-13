#include <iostream>

using namespace std;

// 연결리스트
struct Node {
    int val;
    Node* prev;
    Node* next;
    Node(int val) {
        this->val = val;
        this->prev = nullptr;
        this->next = nullptr;
    }
    Node(int val, Node* prev, Node* next) {
        this->val = val;
        this->prev = prev;
        this->next = next;
    }
};

// insert front of dummy
void insertNode(Node* head, Node* newNode) {
    if (head->next == nullptr) {
        head->next = newNode;
        newNode->prev = head;
    } else {
        // 1
        head->next->prev = newNode;
        newNode->next = head->next;

        // 2
        newNode->prev = head;
        head->next = newNode;
    }
}

// delete matched elements
void deleteNode(Node* head, int x) {
    Node* cur = head->next;
    Node* pre = nullptr;
    for (; cur != nullptr; cur = cur->next) {
        if (cur->val == x) {
            break;
        }
        pre = cur;
    }

    if (cur == nullptr) {
        cout << "not matched elements" << endl;
        return;
    }

    if (cur->next == nullptr) {
        pre->next = cur->next;
    } else {
        pre->next = cur->next;
        cur->next->prev = pre;
    }
}

void printAllNode(Node* head) {
    for (Node* ptr = head->next; ptr != nullptr; ptr = ptr->next) {
        cout << ptr->val << ' ';
    }
    cout << endl;
}

int main() {
    Node* head = new Node(-1);

    Node* n1 = new Node(4);
    Node* n2 = new Node(3);
    Node* n3 = new Node(2);
    Node* n4 = new Node(1);

    insertNode(head, n1);
    insertNode(head, n2);
    insertNode(head, n3);
    insertNode(head, n4);

    printAllNode(head);

    deleteNode(head, 3);
    printAllNode(head);

    deleteNode(head, 4);
    printAllNode(head);

    return 0;
}
