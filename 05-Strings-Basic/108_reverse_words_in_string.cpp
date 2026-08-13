/*
    Problem: Reverse Words in a String
    Platform: LeetCode
    Link: https://leetcode.com/problems/reverse-words-in-a-string/
    Difficulty: Medium
    Approach: Use stringstream to extract words (automatically skips extra whitespace), then join them in reverse order
    Time: O(n)
    Space: O(n)
*/
#include<bits/stdc++.h>
using namespace std;    
int main(){
    string s="the sky is blue";
    stringstream ss(s);
    string word;
    vector<string> words;
    while(ss >> word) {
        words.push_back(word);
    }
    for(int i=words.size()-1; i>=0; i--) {
        cout << words[i];
        if(i > 0) cout << " ";
    }
    cout << endl;
}