/*
    Problem: Linked List Cycle II
    Platform: LeetCode
    Link: https://leetcode.com/problems/linked-list-cycle-ii/
    Difficulty: Medium
    Approach: Floyd's Tortoise and Hare — detect collision point with fast and slow pointers, then reset slow to head and move both 1 step at a time until they meet at the cycle entry node
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
node* iscycle(node *head){
   node* slow=head;
   node* fast=head;
   while(fast!=nullptr && fast->next!=nullptr){
    slow=slow->next;
    fast=fast->next->next;
    if(slow==fast){
        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
       return slow;
    }
   }
   return nullptr;
}
int main(){
     node *head=nullptr;
     insert(head,10);
     insert(head,20);
     insert(head,30);
     insert(head,40);
     insert(head,50);
     insert(head,60);
     node* ans=iscycle(head);
     if(ans) cout << ans->data;
     else{
        cout << "NULL";
    }
}