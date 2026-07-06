// Time Complexity: O(n)
// Space Complexity: O(n) 
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    } 
    cout<<"The frequency of each element in the array is: "<<endl;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    for(auto [key, value]:mp){
        cout<<key<<"->"<<value<<endl;
    }
}