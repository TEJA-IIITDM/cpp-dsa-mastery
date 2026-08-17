/*
    Problem: Delete Last Node of Linked List
    Platform: Self Practice
    Difficulty: Easy
    Approach: Traversal to Second-Last Node — handle edge cases (0 or 1 node), traverse until temp->next->next is nullptr, free last node, and update second-last next pointer to nullptr
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
void printlist(node *head){
    node *temp=head;
    while(temp!=nullptr){
        cout << temp->data << "->";
        temp=temp->next;
    }
    cout << "NULL";
}
void deletenodeatend(node *&head){
    node *temp=head;
    if(head==nullptr || head->next==nullptr ){
        delete head;
        head=nullptr;
        return;
    }
    while(temp->next->next!=nullptr){
      temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
}
int main(){
     node *head=new node(10);
      node *second=new node(20);
     node *third=new node(30);
     head->next=second;
     second->next=third;
     deletenodeatend(head);
     printlist(head);
}