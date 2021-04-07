#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
 
    string a, b;
    cin >> a >> b;
    reverse(b.begin(), b.end());
 
    if(a == b)
        cout << "YES" << endl;
 
    else
        cout << "NO" << endl;
 
    return 0;
 }