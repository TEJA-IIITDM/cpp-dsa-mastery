
/*
    Problem: Longest Subarray with Sum K (Positive Elements Only)
    Platform: self practice
    Link: N/A
    Difficulty: Medium
    Approach: Sliding Window (Two Pointer) — expand right, shrink left when sum exceeds k, track max window size on exact match
    Time: O(n)
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr={2,3,5,1,9};
    int l=0,maxlen=0,k=10,s=0;
    for(int r=0;r<arr.size();r++){
        s+=arr[r];
        while(s>k){
            s-=arr[l];
            l++;
        }
        if(s==k) maxlen=max(maxlen,r-l+1);
    }
    cout << maxlen;
}