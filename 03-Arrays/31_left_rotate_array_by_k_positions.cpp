/*
    Problem: Left Rotate Array by K Positions
    Platform: self practice
    Link: N/A
    Difficulty: Easy
    Approach: Reversal Algorithm — reverse first k, reverse remaining n-k, reverse whole array (k = k % n to handle k > n)
    Time: O(n)
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
  int arr[]={1,2,3,4,5};
  int n=sizeof(arr)/sizeof(arr[0]);
  int k;
  cout<<"Enter the value of k: ";
  cin>>k;
  if(n==0) return 0;
  if(k>n) return 0;
  reverse(arr,(arr+n-k-1));
  reverse((arr+n-k-1),arr+n);
  reverse(arr,arr+n);
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}