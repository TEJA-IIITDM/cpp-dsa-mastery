/*
    Problem: Generate Binary Strings Without Consecutive 1s
    Platform: Self Practice
    Difficulty: Medium
    Approach: Backtracking with Pruning — at each step, append '0' unconditionally, but append '1' only if the trailing character is not '1'
    Time: O(1.618^N) ~ O(Fibonacci(N+2))
    Space: O(N) call stack space
*/
#include<bits/stdc++.h>
using namespace std;
void generate(vector<string> &result,int n,string current){
    if(current.length()==n){
        result.push_back(current);
        return;
    }
    generate(result,n,current+'0');
    if(current.empty() || current.back()!='1'){
      generate(result,n,current+'1');
    }
}
int main(){
    vector<string> result;
    int n=3;
    generate(result,n,"");
    for(auto s : result){
        cout<<s<<endl;
    }
}