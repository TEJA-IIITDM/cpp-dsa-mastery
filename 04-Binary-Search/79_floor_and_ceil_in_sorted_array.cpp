/*
    Problem: Floor and Ceil in Sorted Array
    Platform: self practice (GeeksforGeeks)
    Link: N/A
    Difficulty: Easy
    Approach: Binary Search — floor finds largest element <= k (search right on match), ceil finds smallest element >= k (search left on match)
    Time: O(log n)
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int findfloor(vector<int>& arr,int k){
int low=0,high=arr.size()-1;
int ans=-1;
while(low<=high){
   int mid=low+(high-low)/2;
   if(arr[mid]<=k){
    ans=arr[mid];
    low=mid+1;
   }
   else high=mid-1;
   
}
return ans;
}
int findceil(vector<int>& arr,int k){
int low=0,high=arr.size()-1;
int ans=-1;
while(low<=high){
   int mid=low+(high-low)/2;
   if(arr[mid]>=k){
    ans=arr[mid];
    high=mid-1;
   }
   else low=mid+1;
   
}
return ans;
}
int main(){
    vector<int> arr={3,4,4,7,8,10};
    int target=5;
    int f=findfloor(arr,target);
    int c=findceil(arr,target);
    cout << "the floor is" << f << endl;
    cout << "the ceil is" << c;

}