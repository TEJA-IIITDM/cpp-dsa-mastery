//time complexity: worst O(n^2) and best O(n)
//space complexity: O(n)
#include<bits/stdc++.h>
using namespace std;
void recursiveinsertionsort(vector<int>& arr,int n){
    if(n<=1) return;
    recursiveinsertionsort(arr,n-1);
    int last=arr[n-1];
    int j=n-2;
    while(j>=0 && arr[j]>last){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=last;
}
int main(){
    vector<int> arr={64, 34, 25, 12, 22, 11, 90};
    int n=arr.size();
    recursiveinsertionsort(arr,n);
    cout<<"Sorted array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
   