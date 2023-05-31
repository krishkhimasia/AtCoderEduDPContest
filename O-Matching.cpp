#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;
int n;
int a[22][22];
long long dp[1<<21];
int main()
{
    cin>>n;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    dp[0]=1;
    // for(int i=0;i<n;i++)
    // {
        for(int mask=0;mask<(1<<n);mask++)
        {
            for(int b=0;b<n;b++)
            {
                if(a[__builtin_popcount(mask)][b] && !(mask&(1<<b)))
                {
                    int mask2=(mask|(1<<b));
                    dp[mask2]=(dp[mask2]+dp[mask])%mod;
                }
            }
        }
    // }
    cout<<dp[(1<<n)-1]<<endl;
    return 0;
}