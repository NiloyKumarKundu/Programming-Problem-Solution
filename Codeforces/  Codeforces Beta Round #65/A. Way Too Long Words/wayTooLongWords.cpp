#include <stdio.h>
#include <string.h>
 
int main() {
    int n, length, count, i, j;
    char ch[100];
 
    scanf("%d", &n);
 
    for(i=0; i<n; i++) {
        scanf("%s", ch);
        length = strlen(ch);
 
        if(length > 10) {
            count = 0;
            for(j=1; ch[j]!='\0'; j++) {
                count++;
            }
 
            printf("%c%d%c\n", ch[0], --count, ch[length-1]);
        }
 
        else {
            printf("%s\n", ch);
        }
 
    }
}