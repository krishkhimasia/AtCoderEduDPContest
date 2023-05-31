#include<bits/stdc++.h>
using namespace std;

vector <vector<int>> g;
int dp[100010];

void dfs(int n)
{
    dp[n]=0;
    for(auto c: g[n])
    {
        if(dp[c]==-1)
        {
            dfs(c);
        }
        dp[n]=max(dp[n],1+dp[c]);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
    }
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        if(dp[i]==-1)
            dfs(i);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}