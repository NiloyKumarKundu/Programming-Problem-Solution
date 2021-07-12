#include<stdio.h>

int main()
{
    int m, n, c, start, end;


    printf("Enter a: ");
    scanf("%d", &start);
    printf("Enter b: ");
    scanf("%d", &end);


    m = 0;
    n = 1;
    c = 0;

    printf("Series: \n");

    while(c <= end)
    {


        if(c >= start)
        {
            printf("%d ", c);
        }

        m = n;
        n = c;
        c = m + n;
    }

    return 0;
}