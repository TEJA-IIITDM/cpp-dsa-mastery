/*
    Problem: Delete All Occurrences of a Given Key in a Doubly Linked List
    Platform: Self Practice
    Difficulty: Medium
    Approach: Single Pass Pointer Rewiring — traverse DLL, un-link prev/next pointers for matching key nodes, handle head updates and free memory
    Time: O(n)
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
node *deleteoccurences(node *head,int key){
node *temp=head;
while(temp!=nullptr){
    if(temp->data==key){
        node *nextnode=temp->next;
        if(temp==head){
            head=temp->next;
            if(head!=nullptr){
                head->prev=nullptr;
            }
        }
        else{
            temp->prev->next=temp->next;
            if(temp->next!=nullptr) temp->next->prev=temp->prev;
        }
        delete temp;
            temp=nextnode;
    }
    else{
          temp=temp->next;
        }
}
return head;
}
int main(){
     node *head=nullptr;
     node *tail=nullptr;
     insert(head,tail,1);
     insert(head,tail,2);
     insert(head,tail,3);
     insert(head,tail,1);
     insert(head,tail,4);
     int key=1;
     head=deleteoccurences(head,key);
     printlist(head);
}