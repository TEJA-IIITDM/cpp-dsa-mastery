/*
    Problem: recursive bubble sort
    Platform: self pratice
    Link: N/A
    Difficulty: easy
    Approach: Recursion — each call = one pass, push largest to end
    Time: O(n^2)
    Space: O(n)
*/

//time complexity: O(n^2)
//space complexity: O(n)
#include<bits/stdc++.h>
using namespace std;
void recursivebubblesort(vector<int>& arr,int n){
    if(n==1) return;
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    recursivebubblesort(arr,n-1);
}
int main(){
    vector<int> arr={64, 34, 25, 12, 22, 11, 90};
    int n=arr.size();
    recursivebubblesort(arr,n);
    cout<<"Sorted array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

