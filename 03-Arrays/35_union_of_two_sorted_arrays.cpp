/*
    Problem: Union of Two Sorted Arrays
    Platform: self practice
    Link: N/A
    Difficulty: Easy
    Approach: Two Pointer — merge while skipping duplicates, both within and across arrays
    Time: O(n + m)
    Space: O(n + m) for result array
*/
// IF TWO ARRAYS ARE SORTED USE TWO POINTER MERGE
#include<bits/stdc++.h>
using namespace std;
vector<int> findunion(vector<int>& arr1,vector <int>& arr2,int m,int n){
    int j=0,i=0;
    vector<int> u;
  while(i<m && j<n){
    if(arr1[i]<arr2[j]){
      if(u.empty() || u.back()!=arr1[i]){
          u.push_back(arr1[i]);
      }
       i++;
     }
     else{
         if(u.empty() || u.back()!=arr2[j]){
        u.push_back(arr2[j]);
     }
     j++;
     }
  }
  while(i<m){
      if(u.empty() || u.back()!=arr1[i]){
          u.push_back(arr1[i]);
      }
       i++;
     }
   while(j<n){
    if(u.empty() || u.back()!=arr2[j]){
        u.push_back(arr2[j]);
       }
     j++;
    }
return u;

}
int main(){
    vector<int> arr1={1,2,3,4,5,6,7,8,9};
    vector<int> arr2={6,7,8,9,10};
    int m=arr1.size();
    int n=arr2.size();
    vector<int>result=findunion(arr1,arr2,m,n);
    for(int x : result){
        cout << x <<" ";
    }

}
