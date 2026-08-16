/*
    Problem: Reverse Words in a String III
    Platform: LeetCode
    Link: https://leetcode.com/problems/reverse-words-in-a-string-iii/
    Difficulty: Easy
    Approach: Reverse the whole string first (this automatically reverses letters within each word), then read words back in reverse order via stringstream to restore original word order
    Time: O(n)
    Space: O(n)
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
 string s="Let's take LeetCode contest";
 reverse(s.begin(),s.end());
 stringstream ss(s);
 string word,result="";
 vector<string>words;
 while(ss >> word){
  words.push_back(word);
 }
 for(int i=words.size()-1;i>=0;i--){
  result+=words[i];
  if(i!=0) result+=" ";
 }
 cout << result;
}