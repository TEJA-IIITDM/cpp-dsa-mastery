/*
    Problem: Reverse Linked List
    Platform: LeetCode
    Link: https://leetcode.com/problems/reverse-linked-list/
    Difficulty: Easy
    Approach: Iterative 3-Pointer — maintain prev, curr, and next pointers to flip node connections in a single pass
    Time: O(n)
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
void insert(node *&head,int val){
node *newnode=new node(val);
node *temp=head;
if(head==nullptr){
    head=newnode;
    return;
}
while(temp->next!=nullptr){
temp=temp->next;
}
temp->next=newnode;
temp=newnode;
}
void printlist(node* head){
    node *temp=head;
    while(temp!=nullptr){
        cout << temp->data << "->";
        temp=temp->next;
    }
    cout << "NULL";
}
void reverse(node *&head){
    node* temp=head;
    node *prev=nullptr;
    node *nextnode=nullptr;
    while(temp!=nullptr){
      nextnode=temp->next;
      temp->next=prev;
      prev=temp;
      temp=nextnode;
    }
    head=prev;
}
int main(){
     node *head=nullptr;
     insert(head,10);
     insert(head,20);
     insert(head,30);
     insert(head,40);
     insert(head,50);
     insert(head,60);
     reverse(head);
     printlist(head);
}