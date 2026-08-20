/*
    Problem: Remove Nth Node From End of List
    Platform: LeetCode
    Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
    Difficulty: Medium
    Approach: Two Pointers (Fast & Slow) + Dummy Node — create a dummy head, advance fast pointer by N+1 steps, then advance fast and slow together until fast reaches end to locate the target's predecessor
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
node* deletefromend(node *head,int n){
node *dummy=new node(0);
dummy->next=head;
node *slow=dummy;
node *fast=dummy;
for(int i=0;i<=n;i++){
    if(fast==nullptr) return head;
    fast=fast->next;
}
while(fast!=nullptr){
    slow=slow->next;
    fast=fast->next;
}
node *delnode=slow->next;
slow->next=delnode->next;
delete delnode;
return dummy->next;
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
     head=deletefromend(head,2);
     printlist(head);
}