/*
    Problem: Palindrome Linked List
    Platform: LeetCode
    Link: https://leetcode.com/problems/palindrome-linked-list/
    Difficulty: Easy
    Approach: Fast and Slow Pointers + In-Place Reversal — locate middle using slow/fast pointers, reverse the second half, and compare values sequentially with the first half
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
node* reverselist(node *head){
node *nextnode=nullptr;
node *prev=nullptr;
node *temp=head;
while(temp!=nullptr){
nextnode=temp->next;
temp->next=prev;
prev=temp;
temp=nextnode;
}
return prev;
}
string palindromelist(node *head){
    node *slow=head;
    node *fast=head;
    while(fast->next!=nullptr && fast->next->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    node *secondhead=reverselist(slow->next);
    node *firsthead=head;
    while(secondhead!=nullptr){
        if(firsthead->data!=secondhead->data){
            return "false";
            break;
        }
        firsthead=firsthead->next;
        secondhead=secondhead->next;
    }
    return "true";
}
int main(){
     node *head=nullptr;
     insert(head,10);
     insert(head,20);
     insert(head,20);
     insert(head,10);
     string result=palindromelist(head);
     cout << result;
}