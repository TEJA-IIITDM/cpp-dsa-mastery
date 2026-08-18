/*
    Problem: Middle of the Linked List
    Platform: LeetCode
    Link: https://leetcode.com/problems/middle-of-the-linked-list/
    Difficulty: Easy
    Approach: Fast and Slow Pointers (Floyd's Tortoise & Hare) — advance slow pointer by 1 step and fast pointer by 2 steps; when fast reaches end, slow rests at the middle node
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
node* middleinlist(node *head){
    node *slow=head;
    node *fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
int main(){
     node *head=nullptr;
     insert(head,10);
     insert(head,20);
     insert(head,30);
     insert(head,40);
     insert(head,50);
     insert(head,60);
     node* middle=middleinlist(head);
     cout << middle->data;
}