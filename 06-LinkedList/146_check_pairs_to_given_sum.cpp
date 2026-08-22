/*
    Problem: Find Pairs with Given Sum in Sorted Doubly Linked List
    Platform: Self Practice
    Difficulty: Easy
    Approach: Two Pointers — maintain left pointer at head and right pointer at tail, move inward based on sum comparison until pointers cross
    Time: O(n)
    Space: O(1) auxiliary space (excluding output vector)
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
    node *temp = head;
    cout << "NULL";
    while (temp != nullptr) {
        cout << "<-" << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void insert(node *&head, node *&tail, int val){
    node *newnode = new node(val);
    if (head == nullptr) {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}
vector<pair<int,int>> deleteoccurences(node *head,node *tail,int target){
    vector<pair<int,int>> ans;
node *left=head;
node *right=tail;
int sum=0;
while(left!=right && right->next!=left){
    sum=left->data+right->data;
    if(sum==target) {
        ans.push_back({left->data,right->data});
        left=left->next;
        right=right->prev;
    }
    else if(sum<target) left=left->next;
    else right=right->prev;
}
return ans;
}
int main(){
     node *head=nullptr;
     node *tail=nullptr;
     insert(head,tail,2);
     insert(head,tail,3);
     insert(head,tail,5);
     insert(head,tail,9);
     int target=12;
     vector<pair<int,int>> result=deleteoccurences(head,tail,target);
     for( auto &s : result){
        cout << s.first << " " << s.second;
     }
}