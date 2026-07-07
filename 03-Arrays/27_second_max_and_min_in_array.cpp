/*
    Problem: Second Smallest and Second Largest in Array
    Platform: self practice
    Link: N/A
    Difficulty: Easy
    Approach: Single Pass — track largest/second largest and smallest/second smallest simultaneously
    Time: O(n)
    Space: O(1)
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    long long max = LLONG_MIN, second_max = LLONG_MIN, min = LLONG_MAX, second_min = LLONG_MAX;
    if(arr.size() < 2){
        cout << "Array must have at least two elements." << endl;
        return 0;
    }
    for(int i=0; i<arr.size(); i++){
        if(arr[i] > max){
            second_max = max;
            max = arr[i];
        }
        else if(arr[i] > second_max && arr[i] != max){
            second_max = arr[i];
        }
        if(arr[i] < min){
            second_min = min;
            min = arr[i];
        }
        else if(arr[i] < second_min && arr[i] != min){
            second_min = arr[i];
        }
    }
    cout << "The second largest element is: " << second_max << endl;
    cout << "The second smallest element is: " << second_min << endl;
}