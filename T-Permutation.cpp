#include<bits/stdc++.h>
using namespace std;
//O(n^2)

int mod=1e9+7;
using ll = long long;
#define endl "\n"
#define pb push_back
#define mp make_pair
#define fi first
#define se second

int n;
string s;
//dp[i][j] - answer for prefix of length i, ending with j
long long dp[3001][3001];

int main()
{
    cin>>n>>s;
    memset(dp,0,sizeof(dp));
    dp[1][1]=1;
    for(int len=2;len<=n;len++)
    {
        long long prefsum[n+1]={0};
        prefsum[0]=0;
        for(int i=1;i<=n;i++)
        {
            prefsum[i]=(prefsum[i-1]+dp[len-1][i])%mod;
        }
        for(int b=1;b<=len;b++)
        {
            int l,r;
            if(s[len-2]=='<')
            {
                l=1;
                r=b-1;
            }
            else
            {
                l=b;
                r=len-1;
            }
            dp[len][b]=(dp[len][b]+(prefsum[r]-prefsum[l-1]+mod))%mod;
        }
    }
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=(ans+dp[n][i])%mod;
    }
    cout<<ans<<endl;
    return 0;
}