#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;

    DNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class SortedDoublyLinkedList {
public:
    DNode* head;

    SortedDoublyLinkedList() : head(nullptr) {}

    void insert(int val) {
        DNode* newNode = new DNode(val);
        if (!head || head->data >= val) {
            newNode->next = head;
            if (head) head->prev = newNode;
            head = newNode;
            return;
        }

        DNode* current = head;
        while (current->next && current->next->data < val) {
            current = current->next;
        }

        newNode->next = current->next;
        newNode->prev = current;
        if (current->next) current->next->prev = newNode;
        current->next = newNode;
    }

    void display() {
        DNode* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    SortedDoublyLinkedList list;
    list.insert(10);
    list.insert(5);
    list.insert(20);
    list.insert(15);
    list.insert(1);

    list.display();
    return 0;
}