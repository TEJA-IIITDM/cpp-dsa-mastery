/*
    Problem: Letter Combinations of a Phone Number (LeetCode 17)
    Platform: LeetCode
    Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
    Difficulty: Medium
    Approach: Recursive Backtracking — map digits to corresponding letter strings and systematically combine options level by level
    Time: O(4^N * N) worst case
    Space: O(N) call stack space
*/
#include<bits/stdc++.h>
using namespace std;
void helper(string mp[],int index,vector<string>& answer,string digits,string &temp){
if(index==digits.size()){
    answer.push_back(temp);
    return;
}
int digit=digits[index]-'0';
 for(char ch: mp[digit]){
    temp.push_back(ch);
    helper(mp,index+1,answer,digits,temp);
    temp.pop_back();
 }
}
vector<string> subsequences(string mp[],string digits){
    vector<string> answer;
    if (digits.empty()) return answer;
    string temp="";
    helper(mp,0,answer,digits,temp);
    return answer;
}
int main(){
    string digits="23";
    string mp[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string>result=subsequences(mp,digits);
    for(auto x:result){
        cout << x << " ";
    }
}