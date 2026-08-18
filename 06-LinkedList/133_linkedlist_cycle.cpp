/*
    Problem: Linked List Cycle
    Platform: LeetCode
    Link: https://leetcode.com/problems/linked-list-cycle/
    Difficulty: Easy
    Approach: Fast and Slow Pointers (Floyd's Cycle Finding Algorithm) — move slow pointer by 1 step and fast pointer by 2 steps; if a cycle exists, fast and slow will eventually meet
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
void insert(node* &head,int val){
node *newnode=new node(val);
node *temp=head;
node *link;
if(head==nullptr){
    head=newnode;
    return;
}
while(temp->next!=nullptr){
temp=temp->next;
}
temp->next=newnode;
temp=newnode;
if(newnode->data==30){
    link=newnode;
}
if(newnode->data==60){
    newnode->next=link;
}
}
void printlist(node* head){
    node *temp=head;
    node *already;
    while(temp!=nullptr){
        cout << temp->data << "->";
        if(already==temp) break;
        if(temp->data==30){
          already=temp;
        }
        temp=temp->next;
    }
}
string iscycle(node *head){
   node* slow=head;
   node* fast=head;
   while(fast!=nullptr && fast->next!=nullptr){
    slow=slow->next;
    fast=fast->next->next;
    if(slow==fast) return "true";
   }
   return "false";
}
int main(){
     node *head=nullptr;
     insert(head,10);
     insert(head,20);
     insert(head,30);
     insert(head,40);
     insert(head,50);
     insert(head,60);
     string answer=iscycle(head);
     cout << answer;
}