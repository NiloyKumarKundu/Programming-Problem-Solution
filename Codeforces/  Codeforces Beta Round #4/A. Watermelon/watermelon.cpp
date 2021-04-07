#include <stdio.h>
 
int main() {
 
    int n;
    scanf("%d", &n);
 
    if(n<=0 || n>=101)
        return 0;
 
    else if(n%2 == 0)
        if(n<=2)
            printf("NO\n");
        else
            printf("YES\n");
    else
        printf("NO\n");
}