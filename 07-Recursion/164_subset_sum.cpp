/*
    Problem: Subset Sums (Subset Sums I)
    Platform: Self Practice
    Difficulty: Medium
    Approach: Backtracking / Pick-and-Don't-Pick — branch into adding arr[index] to running sum or excluding it, pushing final sum at base case and sorting results
    Time: O(2^N log(2^N)) due to output vector sort
    Space: O(N) auxiliary call stack space
*/
#include<bits/stdc++.h>
using namespace std;
void subsetssum(vector<int>& arr,int index,int sum,vector<int>& result){
    if(index==arr.size()){
        result.push_back(sum);
        return;
    }
    subsetssum(arr,index+1,sum+arr[index],result);
    subsetssum(arr,index+1,sum,result);
}
vector<int> subsets(vector<int>& arr){
    vector<int> result;
    subsetssum(arr,0,0,result);
    return result;
}
int main(){
    vector<int> arr={2,3};
    vector<int>result=subsets(arr);
    sort(result.begin(),result.end());
    for(int num : result){
        cout<<num<<" ";
    }
}