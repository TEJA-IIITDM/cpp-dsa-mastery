/*
    Problem: Rearrange Array Elements by Sign (Variant: Unequal Positives & Negatives)
    Platform: self pratice
    Link: NA
    Difficulty: Medium
    Approach: Separate & Alternate Loop — isolate elements into positive/negative lists, alternate them up to the smaller list's size, then append the remaining items
    Time: O(n)
    Space: O(n)
*/
#include<bits/stdc++.h>
using namespace std;
int main (){
    vector<int> arr={-1,-2,-4,-5,3,4};
    int n=arr.size();
  vector<int> ans1;
  vector<int> ans2;
    for(int i=0;i<n;i++){
        if(arr[i]>0){
        ans1.push_back(arr[i]);
        }
        else{
           ans2.push_back(arr[i]);

        }
    }
if(ans1.size()>ans2.size()){
    for(int i=0;i<ans2.size();i++){
    arr[2*i]=ans1[i];
    arr[2*i+1]=ans2[i];
    }
   int index=ans2.size()*2;
   for(int i=ans2.size();i<ans1.size();i++){
    arr[index]=ans1[i];
    index++;
   }
}
else{
    for(int i=0;i<ans1.size();i++){
    arr[2*i]=ans1[i];
    arr[2*i+1]=ans2[i];
    }
   int index=ans1.size()*2;
   for(int i=ans1.size();i<ans2.size();i++){
    arr[index]=ans2[i];
    index++;
   }
}
for(int x : arr){
    cout << x << " ";
}
}