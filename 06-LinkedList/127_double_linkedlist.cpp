/*
    Problem: Doubly Linked List Node Definition
    Platform: Self Practice
    Difficulty: Easy
    Approach: Structure Definition — define node structure with data, next, and prev pointers using C++ constructors
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
int main(){
     node *head=new node(10);
     node *second=new node(20);
     node *third=new node(30);
     node *fourth=new node(40);

     head->next=second;
     second->prev=head;
     second->next=third;
     third->prev=second;
     third->next=fourth;
     fourth->prev=third;
   printlist(head);
}