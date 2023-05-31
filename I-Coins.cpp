#include<bits/stdc++.h>
using namespace std;

int n;
double dp[3000][3000];
double p[3000];

double solve(int idx,int h)
{
    if(idx==n+1)
    {
        if(2*h>n)
            return 1;
        else
            return 0;
    }
    if(dp[idx][h]<0)
    {
        double ans=0;
        ans=p[idx]*solve(idx+1,h+1)+(1-p[idx])*solve(idx+1,h);
        dp[idx][h]=ans;
    }
    return dp[idx][h];
}

int main()
{
    for(int i=0;i<3000;i++)
    {
        for(int j=0;j<3000;j++)
        {
            dp[i][j]=-1;
        }
    }
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
    }
    cout<<setprecision(10);
    cout<<solve(1,0)<<endl;
    return 0;
}