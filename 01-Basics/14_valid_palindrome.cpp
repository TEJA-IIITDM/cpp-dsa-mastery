/*
    Problem: valid palindrome
    Platform: LeetCode
    Link: https://leetcode.com/problems/valid-palindrome/
    Difficulty: easy
    Approach: Two Pointer — compare characters from both ends, skip non-alphanumeric
    Time: O(n)
    Space: O(1)
*/

// Time Complexity: O(n)
// Space Complexity: O(1) 
#include<bits/stdc++.h>
using namespace std;

bool isstringpalindrome(string str) {
    int left = 0;
    int right = str.length() - 1;
    while(left<right){
        while(left<right && !isalnum(str[left])){
            left++;
        }
        while(left<right && !isalnum(str[right])){
            right--;
        }
        if(tolower(str[left]) != tolower(str[right])){
            cout << "The string is not a palindrome." << endl;
            return false;
        }
        left++;
        right--;

    }
    cout << "The string is a palindrome." << endl;
    return true;
}
int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;
    isstringpalindrome(str);
    return 0;
}

