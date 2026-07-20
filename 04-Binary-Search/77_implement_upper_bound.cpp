/*
    Problem: Implement Upper Bound
    Platform: self practice (GeeksforGeeks)
    Link: N/A
    Difficulty: Easy
    Approach: Binary Search — find leftmost index where arr[i] > k by narrowing search space, keeping track of best candidate while searching left half
    Time: O(log n)
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int binarysearch(vector<int>& arr,int k){
int low=0,high=arr.size()-1;
int ans=arr.size();
while(low<=high){
   int mid=low+(high-low)/2;
   if(arr[mid]>k){
    ans=mid;
    high=mid-1;
   }
   else low=mid+1;
   
}
return ans;
}
int main(){
    vector<int> arr={1,2,3,4,5,6};
    int target=7;
    int result=binarysearch(arr,target);
    cout << result;
}