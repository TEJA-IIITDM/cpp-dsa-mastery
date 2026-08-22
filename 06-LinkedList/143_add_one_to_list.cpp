/*
    Problem: Add 1 to a Number Represented as Linked List
    Platform: Self Practice
    Difficulty: Medium
    Approach: Reverse, Add & Reverse Back — reverse list to bring ones-digit to head, traverse and add 1 propagating carry, then reverse back to restore original order
    Time: O(n)
    Space: O(1) auxiliary space
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
node* reverse(node *&head){
    node* temp=head;
    node *prev=nullptr;
    node *nextnode=nullptr;
    while(temp!=nullptr){
      nextnode=temp->next;
      temp->next=prev;
      prev=temp;
      temp=nextnode;
    }
    return prev;
}
node *addonetolist(node *head){
head=reverse(head);
node *curr=head;
int add=1;
while(curr!=nullptr){
int sum=curr->data+add;
curr->data=sum%10;
add=sum/10;
if(curr->next==nullptr && add){
curr->next=new node(add);
add=0;
}
curr=curr->next;
}
head=reverse(head);
return head;
}
int main(){
     node *head=nullptr;
     insert(head,1);
     insert(head,2);
     insert(head,3);
    head=addonetolist(head);
     printlist(head);
}