/*
    Problem: Find Missing and Repeated Values
    Platform: LeetCode
    Link: https://leetcode.com/problems/find-missing-and-repeated-values/
    Difficulty: Easy
    Approach: Sum and Sum-of-Squares — same as 1D array version, but treat the n x n grid as n*n total numbers ranging from 1 to n*n
    Time: O(n^2)
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int main (){
 vector<vector<int>> arr={{1,2},{2,3}};
 int N=arr.size();
 long long n=(long long)N*N;
 long long sum=(long long)(n)*(n+1)/2;
 long long squaresum=(long long)(n)*(n+1)*(2*n+1)/6;
 long long sumarray=0,squaresumarray=0;
 for(auto& x : arr){
    for(int y : x){
        sumarray+=y;
     squaresumarray+=(long long)y*y;
    }
 }
 long long d=sumarray-sum;
 long long d2=squaresumarray-squaresum;
 long long repeated=(d+(d2/d))/2;
 long long missing=repeated-d;
 cout << "the missing number is" << " " << missing << endl;
 cout << "the repeated number is" << " " << repeated;
}