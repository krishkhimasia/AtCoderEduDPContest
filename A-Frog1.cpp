#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;
    int h[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>h[i];
    }
    int dp[n+1]={0};
    dp[n]=0;
    dp[n-1]=abs(h[n]-h[n-1]);
    for(int i=n-2;i>0;i--)
    {
        dp[i]=min(abs(h[i]-h[i+1])+dp[i+1],abs(h[i]-h[i+2])+dp[i+2]);
    }
    cout<<dp[1]<<endl;
    return 0;
}