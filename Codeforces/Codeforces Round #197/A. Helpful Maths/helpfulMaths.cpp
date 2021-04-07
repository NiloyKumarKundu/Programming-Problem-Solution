#include <bits/stdc++.h>
#include <iostream>
#include <string>
 
using namespace std;
 
 
int main() {
    string j;
    int count = 0;
 
    cin >> j;
 
    int length = j.size();
 
    int p = (length/2) + 1;
 
    sort(j.begin(), j.end());
 
    j.erase(0, p-1);
 
    for(int i=0; i<p; i++) {
        count++;
 
        cout << j[i];
 
        if(count != p)
            cout << "+";
    }
}