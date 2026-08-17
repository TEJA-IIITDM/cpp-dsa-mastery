/*
    Problem: Search in a Linked List
    Platform: Self Practice
    Difficulty: Easy
    Approach: Linear Traversal — traverse nodes sequentially starting from head to check if any node's value equals target key
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
string searchinlist(node *&head,int number){
    node *temp=head;
    while(temp!=nullptr){
        if(temp->data==number){
            return "true";
        }
        temp=temp=temp->next;
    }
    return "false";
}
int main(){
     node *head=new node(10);
     node *second=new node(20);
     node *third=new node(30);
     node *fourth=new node(40);

     head->next=second;
     second->next=third;
     third->next=fourth;
    int number;
    cout << "enter the number to search";
    cin >> number;
    string result=searchinlist(head,number);
    cout << result;
}