#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<int> good(n, 1);
 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int x; cin >> x;
            if(x == 1 || x == 3) {
                good[i] = 0;
            }
        }
    }
 
    int temp(0);
    for(int i = 0; i < n; i++) {
        if(good[i]) {
            temp++;
        }
    }
 
    cout << temp << "\n";
    for(int i = 0; i < n; i++) {
        if(good[i]) {
            cout << i + 1 << " ";
        }
    }
    puts("");
}