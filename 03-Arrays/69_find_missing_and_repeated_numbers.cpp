/*
    Problem: Find the Repeating and Missing Numbers
    Platform: self practice (GeeksforGeeks)
    Link: N/A
    Difficulty: Medium
    Approach: Sum and Sum-of-Squares — use difference of actual vs expected sum, and actual vs expected sum of squares, solve two equations to find repeating and missing numbers
    Time: O(n)
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int main (){
 vector<int> arr={1,2,3,4,4,5};
 int n=arr.size();
 long long sum=(long long)(n)*(n+1)/2;
 long long squaresum=(long long)(n)*(n+1)*(2*n+1)/6;
 long long sumarray=0,squaresumarray=0;
 for(int x : arr){
 sumarray+=x;
 squaresumarray+=(long long)x*x;
 }
 long long d=sumarray-sum;
 long long d2=squaresumarray-squaresum;
 long long repeated=(d+(d2/d))/2;
 long long missing=repeated-d;
 cout << "the missing number is" << " " << missing << endl;
 cout << "the repeated number is" << " " << repeated;
}