/*
    Problem: Length of Linked List (Count Nodes)
    Platform: Self Practice
    Difficulty: Easy
    Approach: Iterative Traversal — initialize a counter to 0, traverse the list from head to nullptr, incrementing the counter at each node
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
int lengthoflist(node *&head){
    node *temp=head;
    int count=0;
    while(temp!=nullptr){
    count++;
    temp=temp->next;
    }
    return count;
}
int main(){
     node *head=new node(10);
      node *second=new node(20);
     node *third=new node(30);
     node *fourth=new node(40);

     head->next=second;
     second->next=third;
     third->next=fourth;
    int length= lengthoflist(head);
    cout << length;
}