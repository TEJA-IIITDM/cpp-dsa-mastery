/*
    Problem: Longest Common Prefix
    Platform: LeetCode
    Link: https://leetcode.com/problems/longest-common-prefix/
    Difficulty: Easy
    Approach: Vertical Scan — compare characters column by column across all strings simultaneously, stop at the first mismatch or shortest-string boundary
    Time: O(n*m)
    Space: O(1) extra (excluding output)
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
vector<string> strs = {"flower","flow","flight"};
if(strs.empty()){
    cout<<""<<endl;
    return 0;
}
for(int i=0;i<strs[0].size();i++){
     char c = strs[0][i];
     for(int j=1;j<strs.size();j++){
         if(i>=strs[j].size() || strs[j][i]!=c){
             cout<<strs[0].substr(0,i)<<endl;
             return 0;
         }
     }
 }
 cout<<strs[0]<<endl;
}