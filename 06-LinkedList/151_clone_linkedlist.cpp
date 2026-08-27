/*
    Problem: Copy List with Random Pointer
    Platform: LeetCode
    Link: https://leetcode.com/problems/copy-list-with-random-pointer/
    Difficulty: Medium
    Approach: Interleaving Method — create clone nodes inline next to original nodes, map random pointers via original->random->next, then decouple the lists
    Time: O(n)
    Space: O(1) auxiliary space
*/
#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
    node *random;
    node(int x) : data(x), next(nullptr), random(nullptr) {}
};

node *clonelist(node *head){
    node *curr=head;
    while(curr!=nullptr){
    node *nextterm=new node(curr->data);
    nextterm->next=curr->next;
    curr->next=nextterm;
    curr=nextterm->next;
    }
    curr=head;
    while(curr!=nullptr){
        if(curr->random!=nullptr){
        curr->next->random=curr->random->next;
        }
        else{
            curr->next->random=nullptr;
        }
        curr=curr->next->next;
    }
node *dummy=new node(-1);
node *clonedtail=dummy;
curr=head;
while(curr!=nullptr){
    node *clonednode=curr->next;
    node *nextoriginal=clonednode->next;
    curr->next=nextoriginal;
    clonedtail->next=clonednode;
    clonedtail=clonednode;
    curr=nextoriginal;
}
node *clonedhead=dummy->next;
delete dummy;
return clonedhead;
}
void printlist(node *head){
    node *temp=head;
    while(temp!=nullptr){
        if(temp->random){
cout << "[" << temp->data << " " << temp->random->data << "]" << "->" << " ";
        temp=temp->next;
        }
        else{
            cout << "[" << temp->data << " " << nullptr << "]" << "->" << " ";
        temp=temp->next;
        }
    }
    cout << "NULL";
}
int main() {
    node *head=new node(7);
    node *second=new node(13);
    head->next=second;
    node *third=new node(11);
    second->next=third;
    node *fourth=new node(10);
    third->next=fourth;
    node *fifth=new node(2);
    fourth->next=fifth;
    head->random=nullptr;
    second->random=head;
    third->random=fifth;
    fourth->random=third;
    fifth->random=head;
    node *clonedhead=clonelist(head);
    printlist(clonedhead);
}