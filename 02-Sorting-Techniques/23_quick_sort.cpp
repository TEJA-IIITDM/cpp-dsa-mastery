/*
    Problem: quick sort
    Platform: self pratice
    Link: N/A
    Difficulty: medium
    Approach: Partition around pivot — place smaller left, larger right, recurse
    Time: O(n log n) average
    Space: O(log n) average
*/

//time complexity: O(nlogn) in average case and O(n^2) in worst case
//space complexity: O(logn) in average case and O(n) in worst case
#include<bits/stdc++.h>
using namespace std;
int partition(vector<int>& arr,int l,int r){
   int pivot=arr[r];
   int i=l-1;
    for(int j=l;j<r;j++){
        if(arr[j]<=pivot){
          i++;
          swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}
void quicksort(vector<int>& arr,int l,int r){
    if(l<r){
        int p=partition(arr,l,r);
        quicksort(arr,l,p-1);
        quicksort(arr,p+1,r);
    }
}
int main(){
    vector<int> arr={10,7,8,9,1,5};
    int n=arr.size();
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

