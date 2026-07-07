/*
    Problem: reverse a number
    Platform: self pratice
    Link: N/A
    Difficulty: easy
    Approach: Modulo & Division Loop (n%10, n/10, build reverse)
    Time: O(log n)
    Space: O(1)
*/

// Time Complexity: O(log n)
// Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;
int main() {
    int num,reversed=0;
    cout << "Enter a number: ";
    cin >> num;
    while(num!=0){
        int digit=num%10;
        reversed=reversed*10+digit;
        num/=10;
    }
    cout << "Reversed number: " << reversed;
    return 0;
    
}

