#include<bits/stdc++.h>
using namespace std;

long long dp[101][100010];

int main()
{
    int n,w;
    cin>>n>>w;
    long long wt[n+1],v[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>wt[i]>>v[i];
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=1000*n;j++)
        {
            dp[i][j]=1e12;
        }
    }
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=0;
    }
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=1000*n;j++)
        {
            long long op1=dp[i-1][j];
            dp[i][j]=dp[i-1][j];
            if(j>=v[i])
            {
                long long op2=dp[i-1][j-v[i]]+wt[i];
                dp[i][j]=min(dp[i][j],dp[i-1][j-v[i]]+wt[i]);
            }
        }
    }
    long long mx=0,ans=0;
    for(int i=1000*n;i>0;i--)
    {
        if(dp[n][i]<=w)
        {
            ans=i;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}