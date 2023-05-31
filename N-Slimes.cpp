#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long dp[401][401];
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int l=n;l>0;l--)
    {
        for(int r=l;r<=n;r++)
        {
            if(l==r)
            {
                dp[l][r]=0;
                continue;
            }
            dp[l][r]=1e18;
            long long s=0;
            for(int i=l;i<=r;i++)
            {
                s+=a[i];
            }
            for(int i=l;i<r;i++)
            {
                dp[l][r]=min(dp[l][r],dp[l][i]+dp[i+1][r]+s);
            }
        }
    }
    cout<<dp[1][n]<<endl;
    return 0;
}