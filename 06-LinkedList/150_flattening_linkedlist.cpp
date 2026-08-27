/*
    Problem: Flattening a Linked List
    Platform: Self Practice
    Difficulty: Medium
    Approach: Post-Order Divide & Conquer — recursively flatten sublists from right to left, merging adjacent sorted columns via child pointers
    Time: O(N * M) where N is number of main nodes and M is average nodes per column
    Space: O(N) auxiliary call stack space
*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *child;
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
};


    
    Node* mergeTwoLists(Node* a, Node* b) {
        if (!a) return b;
        if (!b) return a;

        Node* result;
        if (a->data < b->data) {
            result = a;
            result->child = mergeTwoLists(a->child, b);
        } else {
            result = b;
            result->child = mergeTwoLists(a, b->child);
        }

        
        result->next = nullptr;
        return result;
    }

    Node* flattenLinkedList(Node* head) {
        
        if (!head || !head->next) return head;

        
        head->next = flattenLinkedList(head->next);

        
        head = mergeTwoLists(head, head->next);

        return head;
    }


void printFlattenedList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->child;
    }
    cout << "NULL\n";
}

int main() {
    // Constructing test list
    Node* head = new Node(5);
    head->child = new Node(7);
    head->child->child = new Node(8);
    head->child->child->child = new Node(30);

    head->next = new Node(10);
    head->next->child = new Node(20);

    head->next->next = new Node(19);
    head->next->next->child = new Node(22);
    head->next->next->child->child = new Node(50);

    head->next->next->next = new Node(28);
    head->next->next->next->child = new Node(35);
    head->next->next->next->child->child = new Node(40);
    head->next->next->next->child->child->child = new Node(45);


    head = flattenLinkedList(head);

    cout << "Flattened List:\n";
    printFlattenedList(head);

    return 0;
}