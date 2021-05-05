#include <stdio.h>

long long table[100][100];

long long C(int n, int r) {
    for(int i=0; i<=n; i++)
        table[i][0] = 1;

    for(int i=0; i<=n; i++)
        table[i][i] = 1;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<i; j++) {
            table[i][j] = table[i-1][j-1] + table[i-1][j];
        }
    }

    return table[n][r];
}

int main() {

    printf("%lld", C(60,42));

    return 0;
}
