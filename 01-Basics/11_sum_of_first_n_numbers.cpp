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