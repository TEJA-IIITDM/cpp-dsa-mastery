/*
    Problem: Subset Sum Exists (Boolean Check)
    Platform: Self Practice
    Difficulty: Medium
    Approach: Backtracking / Pick-and-Don't-Pick with Short-Circuiting — return true immediately when a branch hits sum == k, avoiding redundant evaluation of exclude branch
    Time: O(2^N) worst case, significantly faster on average
    Space: O(N) call stack space
*/
#include<bits/stdc++.h>
using namespace std;
bool subsequences(vector<int>& arr,int index,int sum,int k){
    if(index==arr.size()){
        if(sum==k){
            return true;
        }
        return false;
    }
    if(subsequences(arr,index+1,sum+arr[index],k)){
        return true;
    }
    return subsequences(arr,index+1,sum,k);
}
bool countsubsequences(vector<int>& arr,int k){
return subsequences(arr,0,0,k);
}
int main(){
    vector<int> arr={4,9,2,5,1};
    int k=10;
    bool ans=countsubsequences(arr,k);
    if(ans){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}