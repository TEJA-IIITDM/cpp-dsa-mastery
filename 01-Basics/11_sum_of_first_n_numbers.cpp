/*
    Problem: sum of first n numbers
    Platform: self pratice
    Link: N/A
    Difficulty: easy
    Approach: Recursion — f(n) = n + f(n-1), base case n=0 return 0
    Time: O(n)
    Space: O(n)
*/

// Time Complexity: O(n)
// Space Complexity: O(n) due to recursive stack space

#include<bits/stdc++.h>
using namespace std;

int sumN(int n) {
    if(n==0) {
        return 0;
    }
    return n + sumN(n-1);
}
int main() {
    
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Sum of first " << n << " natural numbers is: " << sumN(n) << endl;
}

