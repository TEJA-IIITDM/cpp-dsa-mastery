/*
    Problem: Reverse Nodes in k-Group
    Platform: LeetCode / GeeksforGeeks
    Link: https://leetcode.com/problems/reverse-nodes-in-k-group/
    Difficulty: Hard
    Approach: Group Iterative Reversal — find the k-th node in each group, reverse the group recursively or iteratively, and reconnect tail pointers
    Time: O(n)
    Space: O(1) auxiliary (iterative) or O(n/k) call stack (recursive)
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
node * reverselist(node *head){
node *prev = nullptr;
    node *curr = head;
    while (curr != nullptr) {
        node *nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}
node *getkthnode(node *temp,int k){
k=k-1;
while(temp!=nullptr && k>0){
temp=temp->next;
k--;
}
return temp;
}
node *reverselistksize(node *head,int k){
    if(head==nullptr || k==1) return head;
    node *temp=head;
    node *prev=nullptr;
    while(temp!=nullptr){
    node *kthnode=getkthnode(temp,k);
       if(kthnode==nullptr){
        if(prev!=nullptr){
            prev->next=temp;
        }
       break;
       }
    node *nextnode=kthnode->next;
    kthnode->next=nullptr;
    reverselist(temp);
    if(temp==head){
        head=kthnode;
    }
    else{
        prev->next=kthnode;
    }
    prev=temp;
    temp=nextnode;
    }
    return head;
}
int main(){ 
     node *head=nullptr;
     insert(head,1);
     insert(head,2);
     insert(head,3);
     insert(head,4);
     insert(head,5);
     int k=2;
    head=reverselistksize(head,k);
    printlist(head);
}