/*
    Problem: Intersection of Two Linked Lists
    Platform: LeetCode
    Link: https://leetcode.com/problems/intersection-of-two-linked-lists/
    Difficulty: Easy
    Approach: Two Pointers (Difference in Length / Synchronized Traversal) — redirect each pointer to the opposite list's head upon reaching NULL so both cover equal total distances and meet at the intersection
    Time: O(m + n)
    Space: O(1)
*/
#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
    node(int x) : data(x), next(nullptr) {}
};

node* getIntersectionNode(node *headA, node *headB) {
    if (headA == nullptr || headB == nullptr) return nullptr;

    node *p1 = headA;
    node *p2 = headB;

    while (p1 != p2) {
        p1 = (p1 == nullptr) ? headB : p1->next;
        
        p2 = (p2 == nullptr) ? headA : p2->next;
    }

    return p1; 
}

int main() {
    // Shared intersection part: 8 -> 10
    node *common = new node(8);
    common->next = new node(10);

    // List A: 4 -> 1 -> 8 -> 10
    node *headA = new node(4);
    headA->next = new node(1);
    headA->next->next = common;

    // List B: 5 -> 6 -> 1 -> 8 -> 10
    node *headB = new node(5);
    headB->next = new node(6);
    headB->next->next = new node(1);
    headB->next->next->next = common;

    node *intersection = getIntersectionNode(headA, headB);

    if (intersection != nullptr) {
        cout << "Intersection at node with data: " << intersection->data << endl; // Output: 8
    } else {
        cout << "No intersection" << endl;
    }

    return 0;
}