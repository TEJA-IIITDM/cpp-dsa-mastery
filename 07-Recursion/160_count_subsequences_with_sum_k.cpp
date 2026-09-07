/*
    Problem: Count Subsets / Subsequences with Sum K
    Platform: Self Practice / GeeksforGeeks
    Link: https://www.geeksforGeeks.org/count-of-subsets-with-sum-equal-to-x/
    Difficulty: Medium
    Approach: Backtracking / Decision Tree — branch into include (sum + arr[index]) and exclude (sum) paths, returning 1 when base case reaches target K
    Time: O(2^N)
    Space: O(N) call stack space
*/
#include<bits/stdc++.h>
using namespace std;
int subsequences(vector<int>& arr,int index,int sum,int k){
    if(index==arr.size()){
        if(sum==k){
            return 1;
        }
        return 0;
    }
    int include=subsequences(arr,index+1,sum+arr[index],k);
    int exclude=subsequences(arr,index+1,sum,k);
    return include+exclude;
}
int countsubsequences(vector<int>& arr,int k){
return subsequences(arr,0,0,k);
}
int main(){
    vector<int> arr={4,9,2,5,1};
    int k=10;
    cout << "Subsequences of the array are: " << countsubsequences(arr, k) << endl;
}