/*
    Problem: Delete Node at End of Doubly Linked List (with Tail Pointer)
    Platform: Self Practice
    Difficulty: Easy
    Approach: O(1) Tail Pointer Deletion — if single node, delete and set head/tail to nullptr; otherwise update tail to tail->prev, unlink tail->next, and free old tail memory
    Time: O(1)
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *next;
    node *prev;
    node():data(0),next(nullptr),prev(nullptr){}
    node(int x):data(x),next(nullptr),prev(nullptr){}
    node(int x,node *nextnode,node *prevnode):data(x),next(nextnode),prev(prevnode){}
};
void printlist(node *head){
 node *temp=head;
 cout << "NULL";
 while(temp!=nullptr){
    cout << "<-" << temp->data << "->";
    temp=temp->next;
 }
 cout << "NULL";
}
void insert(node *&head,node *&tail,int val){
node *newnode=new node(val);
if(head==nullptr){
    head=newnode;
    tail=newnode;
    return;
}
tail->next=newnode;
newnode->prev=tail;
tail=newnode;
}
void deleteatend(node *&head,node *&tail){
    if(tail==nullptr) return;
    if(tail==head){
        delete tail;
        head=nullptr;
        tail=nullptr;
        return;
    }
   node *temp=tail;
   tail=temp->prev;
   tail->next=nullptr;
   delete temp;
}
int main(){
     node *head=nullptr;
     node *tail=nullptr;
     insert(head,tail,10);
     insert(head,tail,20);
     insert(head,tail,30);
     insert(head,tail,40);
     deleteatend(head,tail);
   printlist(head);
}