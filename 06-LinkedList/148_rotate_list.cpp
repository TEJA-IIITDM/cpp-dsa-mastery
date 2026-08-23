/*
    Problem: Rotate List
    Platform: LeetCode
    Link: https://leetcode.com/problems/rotate-list/
    Difficulty: Medium
    Approach: Ring Buffer / Cyclic Link — connect tail to head to form a circle, calculate k % length, advance (length - k) steps to find new tail, break circle and return new head
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
void printlist(node* head){
    node *temp=head;
    while(temp!=nullptr){
        cout << temp->data << "->";
        temp=temp->next;
    }
    cout << "NULL";
}
node *rotatelist(node *head,int k){
    if(head==nullptr || head->next==nullptr || k==0) return head;
node *temp=head;
int length=1;
while(temp->next!=nullptr){
    temp=temp->next;
   length++;
}
k=k%length;
if(k==0) return head;
temp->next=head;
int steps=length-k;
while(steps!=0){
    temp=temp->next;
    steps--;
}
head=temp->next;
temp->next=nullptr;
return head;
}
int main(){
     node *head=nullptr;
     insert(head,1);
     insert(head,2);
     insert(head,3);
     insert(head,4);
     insert(head,5);
     int k=2;
    head=rotatelist(head,k);
    printlist(head);
}