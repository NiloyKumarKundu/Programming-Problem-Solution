//to get rid of the recursion using dynamic programming
//which is done by loops

#include<bits/stdc++.h>
using namespace std;

long long F[10000];

long long fib(int n)
{
    F[0]=0;
    F[1]=1;
    for(int i=2; i<=n; i++)
    {
        F[i]=F[i-1]+F[i-2];
    }
    return F[n];
}


int main()
{
    cout<<fib(100);
    return 0;

}

