// Time Complexity: O(log n)
// Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int num) {
    if(num < 0) return false; // Negative numbers are not palindromes
     if (num != 0 && num % 10 == 0) return false; // trailing zero (e.g. 10) can't be palindrome unless x==0

    long original = num;
    long reversed = 0;
    while(num != 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    return original == reversed;
}   

int main() {
    
    int num;
    cout << "Enter a number: ";
    cin >> num;
    if(isPalindrome(num)) {
        cout << " TRUE " << endl;
    } else {
        cout  << " FALSE " << endl;
    }
}
   