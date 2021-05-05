#include <stdio.h>

int C(int n, int r) {
    if(r == 0)
        return 1;
    if(n == r)
        return 1;
    return C(n-1, r-1) + C(n-1, r);
}

int main() {

    printf("%d", C(60,42));
    return 0;
}
