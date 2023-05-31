#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;

vector <string> g;
int h,w;

int dx[]={0,1};
int dy[]={1,0};
long long dp[1000][1000];

int check(int x, int y)
{
    if(x>=0&&x<h&&y>=0&&y<w&&g[x][y]=='.')
    {
        return 1;
    }
    return 0;
}

long long solve(int x, int y)
{
    if(x==h-1 && y==w-1)
    {
        return 1;
    }
    if(dp[x][y]==-1)
    {
        long long ans=0;
        if(check(x+1,y))
        {
            ans=(ans+solve(x+1,y))%mod;
        }
        if(check(x,y+1))
        {
            ans=(ans+solve(x,y+1))%mod;
        }
        dp[x][y]=ans;
    }
    return dp[x][y];
}

int main()
{
    cin>>h>>w;
    g.resize(h);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<h;i++)
    {
        cin>>g[i];
    }
    cout<<solve(0,0)<<endl;
    return 0;
}