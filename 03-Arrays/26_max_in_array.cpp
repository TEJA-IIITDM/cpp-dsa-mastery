/*
    Problem: Find Max in Array
    Platform: self practice
    Link: N/A
    Difficulty: Easy
    Approach: Linear Scan — track max variable, compare each element
    Time: O(n)
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int findmaxinarray(vector<int>& arr){
    int max=arr[0];
    for(int i=1;i<arr.size();i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}
int main(){
    vector<int> arr={64, 34, 25, 12, 22, 11, 90};
    cout<<"Maximum element in the array is: "<<findmaxinarray(arr)<<endl;
    return 0;
}