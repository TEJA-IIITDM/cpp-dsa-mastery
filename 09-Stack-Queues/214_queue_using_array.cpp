/*
    Problem: Implement Queue using Array (Circular Array Approach)
    Platform: Striver's A2Z DSA Sheet / Self Practice
    Link: https://takeuforward.org/data-structure/implement-queue-using-array/
    Difficulty: Easy
    Approach: Circular Array Queue with front, rear, and currSize counters for optimal space reuse
    Time: O(1) for all queue operations
    Space: O(N) where N is queue capacity
*/
#include <bits/stdc++.h>
using namespace std;
class ArrayQueue {
int* arr;
int start,end;
int currSize,maxSize;
public:
ArrayQueue() {
maxSize=10;
arr=new int[maxSize];
start=-1;
end=-1;
currSize=0;
}
void push(int x) {
if(currSize==maxSize) {
cout<<"Queue is full"<<endl;
return;
}
if(end==-1) {
start=0;
end=0;
} else {
end=(end+1)%maxSize;
}
arr[end]=x;
currSize++;
}
int pop() {
if(isEmpty()) {
cout<<"Queue is empty"<<endl;
return -1;
}
int val=arr[start];
if(currSize==1) {
start=-1;
end=-1;
} else {
start=(start+1)%maxSize;
}
currSize--;
return val;
}
int peek() {
if(isEmpty()) {
cout<<"Queue is empty"<<endl;
return -1;
}
return arr[start];
}
bool isEmpty() {
return currSize==0;
}
};
int main() {
ArrayQueue queue;
queue.push(5);
queue.push(10);
cout<<queue.peek()<<" ";
cout<<queue.pop()<<" ";
cout<<(queue.isEmpty()?"true":"false");
return 0;
}
