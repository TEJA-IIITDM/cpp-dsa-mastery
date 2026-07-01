// Time Complexity: O(n)
// Space Complexity: O(n) due to recursive stack space

#include<bits/stdc++.h>
using namespace std;

void print(int n) {
    if(n==0) {
        return;
    }
   cout << n << endl;
   print(n-1);
}
int main() {
    
    int n;
    cout << "Enter a number: ";
    cin >> n;
    print(n);
}