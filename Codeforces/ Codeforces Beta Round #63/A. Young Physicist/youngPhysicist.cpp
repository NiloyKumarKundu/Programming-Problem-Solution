#include <iostream>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    int arr[n][3];
 
    int firstq = 0, secondq = 0, thirdq = 0;
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 1; j++) {
            firstq += arr[i][j];
        }
        for(int j = 1; j < 2; j++) {
            secondq += arr[i][j];
        }
        for(int j = 2; j < 3; j++) {
            thirdq += arr[i][j];
        }
    }
 
    if(firstq == 0 && secondq == 0 && thirdq == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
