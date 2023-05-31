#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;
vector <vector<int>>g;
vector<int> color;
int n;
long long dp[100010][2];

//0 white, 1 black

long long solve(int v, int p, int col)
{
    if(g[v].size()==1 && g[v][0]==p)
    {
        return 1;
    }
    if(g[v].size()==0)
    {
        return 1;
    }
    if(dp[v][col]==-1)
    {
        long long ans=1;
        for(auto c: g[v])
        {
            if(c!=p)
            {
                long long newans=0;
                newans=(newans+solve(c,v,0))%mod;
                if(col!=1)
                {
                    newans=(newans+solve(c,v,1))%mod;
                }
                ans=(ans*newans)%mod;
            }
        }
        dp[v][col]=ans;
    }
    return dp[v][col];
}

int main()
{
    cin>>n;
    g.resize(n+1);
    color.resize(n+1);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    long long op1=solve(1,0,0);
    long long op2=solve(1,0,1);
    long long ans=(op1+op2)%mod;
    cout<<ans<<endl;
    return 0;
}