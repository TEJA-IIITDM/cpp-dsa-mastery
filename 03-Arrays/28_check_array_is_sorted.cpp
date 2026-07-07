/*
    Problem: Check if Array is Sorted
    Platform: self practice
    Link: N/A
    Difficulty: Easy
    Approach: Single Pass — compare each element with the next, return false on first violation
    Time: O(n)
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
bool issorted(vector<int> &arr){
    for(int i=1;i<arr.size();i++){
        if(arr[i]<arr[i-1]){
            return false;
        }
    }
    return true;
}
int main(){
    vector<int> arr={1,2,3,4,5};
    if(issorted(arr)){
        cout<<"Array is sorted"<<endl;
    }
    else{
        cout<<"Array is not sorted"<<endl;
    }
    return 0;
}