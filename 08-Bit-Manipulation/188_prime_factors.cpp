/*
    Problem: Find Prime Factors of a Number
    Platform: Self Practice / GeeksforGeeks
    Link: https://www.geeksforgeeks.org/problems/prime-facotrs5621/1
    Difficulty: Easy
    Approach: Trial Division — divide out 2s, then loop odd divisors up to sqrt(N); append any remaining N > 2
    Time: O(sqrt(N))
    Space: O(log N) auxiliary space for factor vector
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> primefactors(int n){
    vector<int> factors;
    while(n%2==0){
        factors.push_back(2);
        n/=2;
    }
    for(int i=3;i*i<=n;i+=2){
        while(n%i==0){
            factors.push_back(i);
            n/=i;
        }
    }
    if(n>2){
        factors.push_back(n);
    }
    return factors;
}
int main(){
    int n=315;
    vector<int> factors=primefactors(n);
    for(int i=0;i<factors.size();i++){
        cout<<factors[i]<<" ";
    }
}