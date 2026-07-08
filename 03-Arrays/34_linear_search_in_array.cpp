/*
    Problem: Linear Search
    Platform: self practice
    Link: N/A
    Difficulty: Easy
    Approach: Single Pass — compare each element with target, return index if found
    Time: O(n)
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int key;
    cout<<"Enter the key to search: ";
    cin>>key;
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            cout<<"Key found at index "<<i<<endl;
            return 0;
        }
    }
    cout<<"Key not found"<<endl;
    return 0;
}