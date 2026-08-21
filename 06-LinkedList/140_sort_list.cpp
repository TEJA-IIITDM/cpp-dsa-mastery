/*
    Problem: Sort List
    Platform: LeetCode
    Link: https://leetcode.com/problems/sort-list/
    Difficulty: Medium
    Approach: Merge Sort (Divide & Conquer) — split list into two halves using slow/fast pointers, recursively sort both halves, and merge them using two pointers
    Time: O(n log n)
    Space: O(log n) recursive stack depth (O(1) auxiliary)
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
node *findmiddle(node *head){
    node *slow=head;
    node *fast=head->next;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
node *merge(node *l,node *r){
node dummy(0);
node *tail=&dummy;
while(l!=nullptr && r!=nullptr){
    if(l->data<=r->data){
        tail->next=l;
        l=l->next;
    }
    else{
        tail->next=r;
        r=r->next;
    }
    tail=tail->next;
}
if(l!=nullptr) tail->next=l;
else tail->next=r;
return dummy.next;
}
node* sortlist(node *head){
if(head==nullptr || head->next==nullptr) return head;
node *mid=findmiddle(head);
node *righthead=mid->next;
mid->next=nullptr;
node *left=sortlist(head);
node *right=sortlist(righthead);

return merge(left,right);
}
int main(){
     node *head=nullptr;
     insert(head,-1);
     insert(head,5);
     insert(head,3);
     insert(head,4);
     insert(head,0);
     head=sortlist(head);
     printlist(head);
}