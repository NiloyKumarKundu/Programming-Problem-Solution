#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 
int main() {
    int num=0;
    char s[101];
    cin >> s;
    int length = strlen(s);
    sort(s, s+length);
 
    for(int i=0; i<length; i++) {
      if(s[i] != s[i+1]) {
          num++;
      }
    }
 
    if(num % 2 == 0) {
        cout << "CHAT WITH HER!" << endl;
    } else {
        cout << "IGNORE HIM!" << endl;
    }
 
    return 0;
}