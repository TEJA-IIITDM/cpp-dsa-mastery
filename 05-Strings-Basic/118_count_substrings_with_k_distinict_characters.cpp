/*
    Problem: Count Number of Substrings with Exactly K Distinct Characters
    Platform: self practice (GeeksforGeeks)
    Link: N/A
    Difficulty: Hard
    Approach: Sliding Window — exactly K = (at most K) - (at most K-1); count "at most K distinct" using expanding/shrinking window, subtract "at most K-1"
    Time: O(n)
    Space: O(k)
*/
#include<bits/stdc++.h>
using namespace std;
int countatmostksubstrings(string s,int k){
int right=0,left=0;
int res=0;
unordered_map<char,int>mp;
for(right;right<s.size();right++){
    mp[s[right]]++;
    while(mp.size()>k){
        mp[s[left]]--;
        if(mp[s[left]]==0) mp.erase(s[left]);
        left++;
    }
    res+=right-left+1;
}
return res;
}
int  countsubstrings(string s,int k){
return (countatmostksubstrings(s,k)-countatmostksubstrings(s,k-1));
}
int main(){
 string s="pqpqs";
 int k=2;
 int result=countsubstrings(s,k);
 cout << result;
}