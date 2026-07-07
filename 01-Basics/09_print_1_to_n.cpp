/*
    Problem: print 1 to n
    Platform: self pratice
    Link: N/A
    Difficulty: easy
    Approach: Recursion — Forward (increment counter, base case i>n)
    Time: O(n)
    Space: O(n)
*/

// Time Complexity: O(n)
// Space Complexity: O(n) due to recursive stack space

#include<bits/stdc++.h>
using namespace std;

void print(int n) {
    if(n==0) {
        return;
    }
    print(n-1);
   cout << n << endl;
}
int main() {
    
    int n;
    cout << "Enter a number: ";
    cin >> n;
    print(n);
}

