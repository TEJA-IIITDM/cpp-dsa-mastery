/*
    Problem: Reverse a Doubly Linked List
    Platform: Self Practice
    Difficulty: Easy
    Approach: Iterative Pointer Swapping — swap next and prev pointers for every node while traversing, update head to the last non-null node, and reassign tail
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
 node *temp=head;
 cout << "NULL";
 while(temp!=nullptr){
    cout << "<-" << temp->data << "->";
    temp=temp->next;
 }
 cout << "NULL";
}
void insert(node *&head,node *&tail,int val){
node *newnode=new node(val);
if(head==nullptr){
    head=newnode;
    tail=newnode;
    return;
}
tail->next=newnode;
newnode->prev=tail;
tail=newnode;
}
void reverse(node *&head,node *&tail){
    node *temp=head;
    node *nextnode=nullptr;
    tail=head;
    while(temp!=nullptr){
     nextnode=temp->next;
     temp->next=temp->prev;
     temp->prev=nextnode;
     if(nextnode==nullptr) head=temp;
     temp=nextnode;
    }
}
int main(){
     node *head=nullptr;
     node *tail=nullptr;
     insert(head,tail,10);
     insert(head,tail,20);
     insert(head,tail,30);
     reverse(head,tail);
     printlist(head);
}