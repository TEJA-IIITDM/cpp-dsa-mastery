/*
    Problem: Delete Node in a Linked List
    Platform: LeetCode
    Link: https://leetcode.com/problems/delete-node-in-a-linked-list/
    Difficulty: Medium
    Approach: Copy and Bypass — copy the data from the next node into the given node, then bypass and delete the next node
    Time: O(1)
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
void deletenode(node *&Node){
    node *temp=Node->next;
    Node->data=temp->data;
    Node->next=temp->next;
    delete temp;
}
int main(){
     node *head=new node(10);
      node *second=new node(20);
     node *third=new node(30);
     node *fourth=new node(40);

     head->next=second;
     second->next=third;
     third->next=fourth;
     deletenode(third);
     printlist(head);
}