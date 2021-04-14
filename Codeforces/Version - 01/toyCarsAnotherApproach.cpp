#include<bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    long int arr[100][100];
 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    vector<int> vc;
    int a(0), c(0);
 
    for(int i = 0; i < n; i++) {
        c = 0;
        for(int j = 0; j < n; j++) {
            if(i == j)
                continue;
            if(arr[i][j] == 0 || arr[i][j] == 2) {
                c++;
            }
        }
        if(c == n - 1) {
            a++;
            vc.push_back(i + 1);
        }
    }
 
    cout << a << endl;
    for(int i = 0; i < vc.size(); i++) {
        cout << vc[i] << " ";
    }
    puts("");
}