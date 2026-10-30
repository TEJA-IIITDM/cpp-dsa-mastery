/*
    Problem: Number of Substrings Containing All Three Characters (LeetCode 1358)
    Platform: Self Practice / LeetCode
    Link: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
    Difficulty: Medium
    Approach: Sliding Window — count remaining valid suffixes (s.size() - right) once all 3 characters are present
    Time: O(N)
    Space: O(1) auxiliary space
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s="abcabc";
    int left=0,right=0;
    int count=0;
    vector<int> freq(3,0);
    while(right<s.size()){
        freq[s[right]-'a']++;
        while(freq[0]>0 && freq[1]>0 && freq[2]>0){
            count+=(s.size()-right);
            freq[s[left]-'a']--;
            left++;
        }
        right++;
    }
    cout << count;
}