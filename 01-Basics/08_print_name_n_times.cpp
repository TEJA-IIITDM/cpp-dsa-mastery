// Time Complexity: O(n)
// Space Complexity: O(n) due to recursive stack space

#include<bits/stdc++.h>
using namespace std;

void printhello(int n) {
    if(n==0) {
        return;
    }
    cout << "Hello" << endl;
    printhello(n-1);
   
}
int main() {
    
    int n;
    cout << "Enter a number: ";
    cin >> n;
    printhello(n);
    
}