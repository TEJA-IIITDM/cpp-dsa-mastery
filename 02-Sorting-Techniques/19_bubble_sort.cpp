/*
    Problem: bubble sort
    Platform: self pratice
    Link: N/A
    Difficulty: easy
    Approach: Adjacent swaps — push largest to end each pass
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
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }    
    cout<<"The sorted array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}

