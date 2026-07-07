//time complexity: O(n)
//space complexity: O(1)
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