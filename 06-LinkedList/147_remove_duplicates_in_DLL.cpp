/*
    Problem: Remove Duplicates from a Sorted Doubly Linked List
    Platform: Self Practice
    Difficulty: Easy
    Approach: Single Pass In-Place Pointer Rewiring — compare adjacent node values, adjust next/prev pointers when duplicates are detected, and deallocate memory safely
    Time: O(n)
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *next;
    node *prev;
    node():data(0),next(nullptr),prev(nullptr){}
    node(int x):data(x),next(nullptr),prev(nullptr){}
    node(int x,node *nextnode,node *prevnode):data(x),next(nextnode),prev(prevnode){}
};
void printlist(node *head){
    node *temp = head;
    cout << "NULL";
    while (temp != nullptr) {
        cout << "<-" << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void insert(node *&head, node *&tail, int val){
    node *newnode = new node(val);
    if (head == nullptr) {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}
node *removeduplicates(node *head){
node *temp=head;
while(temp->next!=nullptr){
    if(temp->data==temp->next->data){
        node *dup=temp->next;
        temp->next=dup->next;
        if(dup->next!=nullptr){
        dup->next->prev=temp;
        }
        delete dup;
    }
   else temp=temp->next;
}
return head;
}
int main(){
     node *head=nullptr;
     node *tail=nullptr;
     insert(head,tail,1);
     insert(head,tail,1);
     insert(head,tail,3);
     insert(head,tail,3);
     insert(head,tail,4);
     insert(head,tail,5);
     head=removeduplicates(head);
     printlist(head);
}