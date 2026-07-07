/*
    Problem: insertion sort
    Platform: self pratice
    Link: N/A
    Difficulty: easy
    Approach: Find minimum in unsorted part — swap to correct position
    Time: O(n^2)
    Space: O(1)
*/

// Time Complexity: O(n^2)
// Space Complexity: O(1) 
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<n;i++){
        int key=arr[i]; 
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }    
    cout<<"The sorted array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

