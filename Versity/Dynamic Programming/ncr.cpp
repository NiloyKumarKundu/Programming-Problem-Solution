//combination problem using memoization

#include<bits/stdc++.h>
using namespace std;

long long table[100][100];
void init_table()
{
    for(int i=0; i<100; i++)
    {
        for(int j=0; j<100; j++)
        {
            table[i][j] = -1;
        }
    }
    for(int i=0; i<100; i++)
    {
        table[i][0]=1;
    }
    for(int i=0; i<100; i++)
    {
        table[i][i]=1;
    }
}

long long C(int n,int r)
{
    if(n==r || r==0)
    {
        return table[n][r];
    }
    if(table[n-1][r-1]==-1)
            table[n-1][r-1]=C(n-1,r-1);

    if(table[n-1][r]==-1)
              table[n-1][r]=C(n-1,r);

    return table[n-1][r-1]+table[n-1][r];
}


int main()
{
    init_table();
    cout<<C(60,42);
    return 0;
}
