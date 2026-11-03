/*
    Problem: Implement Stack using Array
    Platform: Striver's A2Z DSA Sheet / Self Practice
    Link: https://takeuforward.org/data-structure/implement-stack-using-array/
    Difficulty: Easy
    Approach: Fixed-size array with topIndex pointer for constant-time operations
    Time: O(1) for all stack operations
    Space: O(N) where N is the stack capacity
*/
#include<bits/stdc++.h>
using namespace std;
class arraystack{
    private:
      int *arr;
       int top;
       int capacity;
    public:
    
      arraystack(int size=1000){
          arr=new int[size];
          capacity=size;
          top=-1;
      }
      ~arraystack(){
          delete[] arr;
      }
      void push(int x){
          if(top==capacity-1){
              cout<<"Stack Overflow"<<endl;
          }
          arr[++top]=x;
      }
      int pop(){
          if(top==-1){
              cout<<"Stack Underflow"<<endl;
          }
          return arr[top--];
      }
      int peek(){
          if(top==-1){
              cout<<"Stack is empty"<<endl;
          }
          return arr[top];
      }
      bool isEmpty(){
          return top==-1;
      }
};
int main(){
    arraystack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.pop()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.isEmpty()<<endl;
    return 0;
}