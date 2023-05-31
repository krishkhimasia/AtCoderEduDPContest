#include<bits/stdc++.h>
using namespace std;

int dp[100010];

int main()
{
    int n,k;
    cin>>n>>k;
    int a[n+1];
    memset(dp,0,sizeof(dp));

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        dp[a[i]]=1;
    }
    for(int i=1;i<=k;i++)
    {
        if(dp[i]==0)
        {
            for(int j=1;j<=n;j++)
            {
                if(i+a[j]<=k)
                    dp[i+a[j]]=1;
            }
        }
    }
    if(dp[k])
    {
        cout<<"First"<<endl;
    }
    else
    {
        cout<<"Second"<<endl;
    }
    return 0;
}