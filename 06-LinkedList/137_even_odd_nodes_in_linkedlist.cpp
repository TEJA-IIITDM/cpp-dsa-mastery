/*
    Problem: Segregate Even and Odd Nodes in Linked List
    Platform: LeetCode
    Link: https://leetcode.com/problems/odd-even-linked-list/
    Difficulty: Medium
    Approach: Multi-Pointer Linking — maintain odd and even pointers to rearrange odd-indexed nodes together followed by even-indexed nodes in a single pass
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
node* evenodd(node *head){
node *odd=head;
node *even=head->next;
node *evenhead=even;
while(even!=nullptr && even->next!=nullptr){
    odd->next=even->next;
    odd=odd->next;
    even->next=odd->next;
    even=even->next;
}
odd->next=evenhead;
return head;
}
int main(){
     node *head=nullptr;
     insert(head,2);
     insert(head,1);
     insert(head,3);
     insert(head,5);
     insert(head,6);
     insert(head,4);
     insert(head,7);
     head= evenodd(head);
     printlist(head);
}