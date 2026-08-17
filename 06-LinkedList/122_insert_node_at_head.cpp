/*
    Problem: Insert Node at Head of Linked List
    Platform: Basic Data Structures Practice / LeetCode Concept
    Difficulty: Easy
    Approach: Pass Pointer by Reference — create new node, point its next to current head, and update head reference to new node
    Time: O(1)
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *next;
    node():data(0),next(nullptr){}
    node(int x):data(x),next(nullptr){}
    node(int x,node *nextnode):data(x),next(nextnode){}
};
void printlist(node *head){
    node *temp=head;
    while(temp!=nullptr){
        cout << temp->data << "->";
        temp=temp->next;
    }
    cout << "NULL";
}
void insertnodeathead(node *&head){
    node *newnode=new node(40);
    newnode->next=head;
    head=newnode;
}
int main(){
     node *head=new node(10);
     node *second=new node(20);
     node *third=new node(30);
     head->next=second;
     second->next=third;
     insertnodeathead(head);
     printlist(head);
}