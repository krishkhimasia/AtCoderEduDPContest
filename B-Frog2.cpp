#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n,k;
    cin>>n>>k;
    int h[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>h[i];
    }
    int dp[n+1]={0};
    dp[n]=0;
    dp[n-1]=abs(h[n]-h[n-1]);
    for(int i=n-2;i>n-k;i--)
    {
        dp[i]=1e9;
        for(int j=i+1;j<=n;j++)
        {
            dp[i]=min(dp[i],abs(h[i]-h[j])+dp[j]);
        }
    }
    for(int i=n-k;i>0;i--)
    {
        dp[i]=1e9;
        for(int j=i+1;j<=i+k;j++)
        {
            dp[i]=min(abs(h[i]-h[j])+dp[j],dp[i]);
        }
    }
    cout<<dp[1]<<endl;
    return 0;
}