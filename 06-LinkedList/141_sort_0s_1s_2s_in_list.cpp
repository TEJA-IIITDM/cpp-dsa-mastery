/*
    Problem: Sort a Linked List of 0s, 1s and 2s
    Platform: Self Practice
    Difficulty: medium
    Approach: 3-Dummy Node Partitioning — partition nodes into three independent sublists (0s, 1s, 2s) using dummy nodes, then reconnect their pointers in a single pass
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
node* sortlist(node *head){
    if(head==nullptr || head->next==nullptr) return head;
node *dummy0 =new node(-1);
node *dummy1=new node(-1);
node *dummy2=new node(-1);
node *zero=dummy0;
node *one=dummy1;
node *two=dummy2;
node *temp=head;
while(temp!=nullptr){
    if(temp->data==0) {
        zero->next=temp;
        zero=zero->next;
    }
    if(temp->data==1) {
        one->next=temp;
        one=one->next;
    }
    if(temp->data==2) {
        two->next=temp;
        two=two->next;
    }
    temp=temp->next;
}
zero->next=(dummy1->next)?dummy1->next:dummy2->next;
one->next=dummy2->next;
two->next=nullptr;
head=dummy0->next;
delete dummy0;
delete dummy1;
delete dummy2;
return head;
}
int main(){
     node *head=nullptr;
     insert(head,1);
     insert(head,2);
     insert(head,0);
     insert(head,1);
     insert(head,0);
     insert(head,2);
     head=sortlist(head);
     printlist(head);
}