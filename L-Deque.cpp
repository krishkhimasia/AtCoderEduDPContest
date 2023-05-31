#include<bits/stdc++.h>
using namespace std;

int n;
vector <long long> a;

long long dp[3000][3000];

long long solve(int l,int r)
{
    if(l==r)
    {
        return a[l];
    }
    if(dp[l][r]==-1)
    {
        long long op1=a[l]-solve(l+1,r);
        long long op2=a[r]-solve(l,r-1);
        long long ans=max(op1,op2);
        dp[l][r]=ans;
    }
    return dp[l][r];
}

int main()
{
    memset(dp,-1,sizeof(dp));
    cin>>n;
    a.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<solve(0,n-1)<<endl;
    return 0;
}