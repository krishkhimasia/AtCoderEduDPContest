#include<bits/stdc++.h>
using namespace std;

using lli = long long;
string k;
lli d,len;

lli mod = 1e9+7;

lli dp[10010][2][101];

lli rec(lli idx, lli hi, lli rem)
{
    lli ans=0;
    if(idx==len)
    {
        return (rem==0);
    }
    if(dp[idx][hi][rem]==-1)
    {
        int l=0,h=9;
        if(hi==1) h=k[idx]-'0';
        for(int i=l;i<=h;i++)
        {
            lli nhi=hi;
            if(i!=k[idx]-'0')
            {
                nhi=0;
            }
            lli nrem=(rem+i)%d;
            ans=(ans+rec(idx+1,nhi,nrem))%mod;
        }
        dp[idx][hi][rem]=ans;
    }
    return dp[idx][hi][rem];
}

int main()
{
    cin>>k>>d;
    len=k.length();
    memset(dp,-1,sizeof(dp));
    cout<<(rec(0,1,0)-1+mod)%mod<<endl;
    return 0;
}