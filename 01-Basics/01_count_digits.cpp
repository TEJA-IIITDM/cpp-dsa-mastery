/*
    Problem: count number of digits
    Platform: self pratice
    Link: N/A
    Difficulty: easy
    Approach: Modulo & Division Loop
    Time: O(log n)
    Space: O(1)
*/

// Time Complexity: O(log n), number of digits
// Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;
int main(){
    int num,count=0;
    cout << "enter the number";
    cin >> num;
    if(num==0){
     return 1;
    }
    while(num!=0){
     count++;
     num/=10;
    }
    cout << "the number of digits in the given number is " << count;

}

