/*
    Problem: Intersection of Two Sorted Arrays
    Platform: self practice
    Link: N/A
    Difficulty: Easy
    Approach: Two Pointer — move pointer with smaller value, on match push once and move both
    Time: O(n + m)
    Space: O(min(n,m)) for result array
*/

#include<bits/stdc++.h>
using namespace std;
vector<int> findintersection(vector<int>& arr1,vector<int>& arr2,int m,int n){
    int i=0,j=0;
    vector<int> in;
    while(i<m && j<n){
        if(arr1[i]<arr2[j]) i++;
        else if(arr2[j]<arr1[i]) j++;
        else{
            if(in.empty() || in.back()!=arr1[i]){
                in.push_back(arr1[i]);
            }
            i++;
            j++;
        }
    }
    return in;
}
int main(){
    vector<int> arr1={1,2,3};
    vector<int> arr2={3,4,5,6,7};
    int m=arr1.size();
    int n=arr2.size();
  vector<int> result=findintersection(arr1,arr2,m,n);
  for(int x : result){
    cout << x << " ";
  }
    
}