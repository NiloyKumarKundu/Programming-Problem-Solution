#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n;
double c,t,lo,hi,mid,d[1005],s[1005];
int main()
{
    ll i,j,k=0;
    cin>>n;
    lo=-1000000.0;
    for(i=1;i<=n;i++)
    {
        cin>>d[i]>>s[i];
        lo=max(lo,-1.0*s[i]);
    }
    cin>>t;
    hi=10000000.0;
    k=0;
    while(k<=5000&&lo<=hi)
    {
        mid=(lo+hi)/2.0;
        k++;
        double cur=0.0;
        for(i=1;i<=n;i++)
        {
            cur+=(d[i]/(s[i]+mid+0.0));
        }
        if(cur>=t)
        lo=mid;
        else
        hi=mid;
    }
    cout<<fixed<<setprecision(8)<<mid;
    return 0;
}