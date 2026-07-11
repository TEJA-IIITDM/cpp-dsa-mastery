/*
    Problem: Majority Element
    Platform: LeetCode
    Link: https://leetcode.com/problems/majority-element/
    Difficulty: Easy
    Approach: Moore's Voting Algorithm — maintain a candidate and count, count++ on match, count-- otherwise, switch candidate when count hits 0
    Time: O(n)
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int check(vector<int>& arr){
int count=0,person=0;
for(int x : arr){
    if(count==0) person=x;
    count+=(person==x)? 1 : -1;
}
return person;
}
int main(){
    vector<int> arr={2,2,1,1,1,2,2};
    int result=check(arr);
    cout << result;
}