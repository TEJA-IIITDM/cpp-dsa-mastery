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
    int max_freq=0;
    int max_freq_element=0;
    int min_freq_element=0;
    int min_freq=n;
    for(auto [key, value]:mp){
        cout<<key<<" : "<<value<<endl;
        if(value>max_freq){
            max_freq=value;
            max_freq_element=key;
        }
        if(value<min_freq){
            min_freq=value;
            min_freq_element=key;
        }

       
    }
    cout<<"The element with the maximum frequency is: "<<max_freq_element<<" with frequency: "<<max_freq<<endl;
    cout<<"The element with the minimum frequency is: "<<min_freq_element<<" with frequency: "<<min_freq<<endl;
}
