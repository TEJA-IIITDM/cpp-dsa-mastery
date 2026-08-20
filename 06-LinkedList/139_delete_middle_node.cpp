/*
    Problem: Delete the Middle Node of a Linked List
    Platform: LeetCode
    Link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
    Difficulty: Medium
    Approach: Fast and Slow Pointers — skip fast by 2 steps initially to land slow directly on the node preceding the middle, then unlink and free the middle node
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
node* deletemiddlenode(node *head){
if(head==nullptr || head->next==nullptr){
    delete head;
    return nullptr;
}
node *slow=head;
node* fast=head->next->next;
while(fast!=nullptr && fast->next!=nullptr){
    slow=slow->next;
    fast=fast->next->next;
}
node *delnode=slow->next;
slow->next=delnode->next;
delete delnode;
return head;
}
int main(){
     node *head=nullptr;
     insert(head,1);
     insert(head,2);
     insert(head,3);
     insert(head,4);
     insert(head,5);
     insert(head,6);
     insert(head,7);
     head=deletemiddlenode(head);
     printlist(head);
}