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
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=w;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j>=wt[i])
            {
                dp[i][j]=max(dp[i][j],v[i]+dp[i-1][j-wt[i]]);
            }
        }
    }
    cout<<dp[n][w]<<endl;
    return 0;
}