/*
    Problem: merge sort
    Platform: self pratice
    Link: N/A
    Difficulty: medium
    Approach: Divide & Conquer — split until single elements, merge with two pointer technique
    Time: O(n log n)
    Space: O(n)
*/

//time complexity of merge sort is O(nlogn) and space complexity is O(n)
#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>& arr,int l,int m,int r){
  vector<int> leftarr(arr.begin()+l,arr.begin()+m+1);
  vector<int> rightarr(arr.begin()+m+1,arr.begin()+r+1);
  int i=0,j=0,k=l;
  while(i<leftarr.size() && j<rightarr.size()){
    if(leftarr[i]<=rightarr[j]){
      arr[k++]=leftarr[i++];
    }
    else{
      arr[k++]=rightarr[j++];
    }
  }
  while(i<leftarr.size()) arr[k++]=leftarr[i++];
  while(j<rightarr.size()) arr[k++]=rightarr[j++];
}
void mergesort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergesort(arr, l, m);
    mergesort(arr, m + 1, r);
    merge(arr,l,m,r);
}
int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    int n = arr.size();
    mergesort(arr, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

