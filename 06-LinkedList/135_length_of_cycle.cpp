/*
    Problem: Find Length of Loop in Linked List
    Platform: Self Practice
    Difficulty: Easy
    Approach: Fast and Slow Pointers — detect cycle collision using Floyd's algorithm, freeze one pointer, and traverse the cycle to count its length
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
node *link;
if(head==nullptr){
    head=newnode;
    return;
}
while(temp->next!=nullptr){
temp=temp->next;
}
temp->next=newnode;
temp=newnode;
if(newnode->data==30){
    link=newnode;
}
if(newnode->data==60){
    newnode->next=link;
}
}
int iscycle(node *head){
   node* slow=head;
   node* fast=head;
   int count;
   while(fast!=nullptr && fast->next!=nullptr){
    slow=slow->next;
    fast=fast->next->next;
    if(slow==fast){
        count=1;
      node *temp=slow->next;
      while(temp!=slow){
        count++;
        temp=temp->next;
      }
      return count;
    }
   }
   return 0;
}
int main(){
     node *head=nullptr;
     insert(head,10);
     insert(head,20);
     insert(head,30);
     insert(head,40);
     insert(head,50);
     insert(head,60);
     int ans=iscycle(head);
     cout << ans;
}