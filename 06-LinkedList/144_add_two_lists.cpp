/*
    Problem: Add Two Numbers
    Platform: LeetCode
    Link: https://leetcode.com/problems/add-two-numbers/
    Difficulty: Medium
    Approach: Elementary Addition with Dummy Node — traverse both lists simultaneously, track sum and carry, append new nodes using a tail pointer for O(1) additions
    Time: O(max(m, n))
    Space: O(max(m, n)) for the result list
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

node *addtwolist(node *head,node *head1){
node *curr=head;
node *curr1=head1;
node *dummy=new node(0);
node *temp=dummy;
int sum=0;
while(curr!=nullptr || curr1!=nullptr || sum){
    if(curr){
        sum+=curr->data;
        curr=curr->next;
    }
    if(curr1){
        sum+=curr1->data;
        curr1=curr1->next;
    }
    temp->next=new node(sum%10);
    temp=temp->next;
    sum=sum/10;
}
return dummy->next;
}
int main(){
     node *head=nullptr;
     insert(head,9);
     insert(head,9);
     insert(head,9);
     insert(head,9);
     insert(head,9);
     insert(head,9);
     insert(head,9);
     node *head1=nullptr;
     insert(head1,9);
     insert(head1,9);
     insert(head1,9);
     insert(head1,9);
    node *newhead=addtwolist(head,head1);
     printlist(newhead);
}