/*
    Problem: factorial of n
    Platform: self pratice
    Link: N/A
    Difficulty: easy
    Approach: Recursion — f(n) = n * f(n-1), base case n=0 return 1
    Time: O(n)
    Space: O(n)
*/

// Time Complexity: O(n)
// Space Complexity: O(n) due to recursive stack space

#include<bits/stdc++.h>
using namespace std;

int factorial(int n) {
    if(n==0) {
        return 1;
    }
    return n * factorial(n-1);
}
int main() {
    
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Factorial of " << n << " is: " << factorial(n) << endl;
}

