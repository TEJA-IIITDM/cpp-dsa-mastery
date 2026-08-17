/*
    Problem: Insert Node at End of Doubly Linked List (with Tail Pointer)
    Platform: Self Practice
    Difficulty: Easy
    Approach: O(1) Tail Pointer Link Update — if list is empty, set head and tail to new node; otherwise attach new node to tail->next, update new node's prev to tail, and shift tail pointer
    Time: O(1)
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
void insertatend(node *&head,node *&tail,int val){
node *newnode=new node(val);
if(head==nullptr){
    head=newnode;
    tail=newnode;
}
tail->next=newnode;
newnode->prev=tail;
tail=newnode;
}
int main(){
     node *head=nullptr;
     node *tail=nullptr;
     insertatend(head,tail,10);
     insertatend(head,tail,20);
     insertatend(head,tail,30);
     insertatend(head,tail,40);
   printlist(head);
}