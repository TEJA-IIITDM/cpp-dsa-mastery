/*
    Problem: armstrong number
    Platform: self pratice
    Link: N/A
    Difficulty: easy
    Approach: Sum of digits each raised to power of digit count (pow() function)
    Time: O(log10(n))
    Space: O(1)
*/

// Time Complexity: O(log10(n))
// Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

bool isarmstrong(int n) {
    int original = n;
    int sum = 0;
    int digits = log10(n) + 1; 
    while (n > 0) {
        int d= n % 10;
        sum += pow(d, digits);
        n /= 10;
    }
    return sum == original;
}
int main() {
    
    int n;
    cout << "Enter a number: ";
    cin >> n;
    if (isarmstrong(n)) {
        cout << n << " is an Armstrong number." << endl;
    } else {
        cout << n << " is not an Armstrong number." << endl;
    }
    
}
    
