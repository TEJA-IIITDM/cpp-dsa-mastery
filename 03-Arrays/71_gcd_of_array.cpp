/*
    Problem: Find Greatest Common Divisor of Array
    Platform: LeetCode
    Link: https://leetcode.com/problems/find-greatest-common-divisor-of-array/
    Difficulty: Easy
    Approach: Find min and max of the array in a single pass, then compute their GCD using the Euclidean algorithm
    Time: O(n)
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    while(b!=0){
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
int main (){
 vector<int> arr={2,5,6,9,10};
 int max=INT_MIN,min=INT_MAX;
 for(int i=0;i<arr.size();i++){
    if(arr[i]>max){
        max=arr[i];
    }
    if(arr[i]<min){
        min=arr[i];
    }
 }
 int result = gcd(min,max);
 cout << result;
}