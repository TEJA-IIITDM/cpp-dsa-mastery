/*
    Problem: Find Nth Root of M
    Platform: Self Practice
    Link: NA
    Difficulty: Medium
    Approach: Binary Search on Answer — search in range [1, m], using a custom multiplication loop with early termination to compute mid^n without integer overflow
    Time: O(n * log m)
    Space: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
long long power(int mid,int n,int m){
long long  ans=1;
for(int i=0;i<n;i++){
    ans*=mid;
    if(ans>m) break;
}
return ans;
}
int nthroot(int n,int m){
    int low=1,high=m;
    while(low<=high){
        int mid=low+(high-low)/2;
        long long val=power(mid,n,m);
        if(val==m) return mid;
        if(val<m) low=mid+1;
        else high=mid-1;
    }
   return -1;
}
int main() {
    int n=3,m=27;
    int result=nthroot(n,m);
    cout << result;
}