#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;
long long n,k;



int main()
{
    vector <long long> a;
    long long dp[100010];
    memset(dp,0,sizeof(dp));
    cin>>n>>k;
    a.resize(n);
    dp[0]=1;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        vector <long long> pref(k+1);
        for(int used=k;used>=0;used--)
        {
            int L=used+1;
            int R=used+min(a[i],k-used);
            if(L<=R)
            {
                pref[L]=(pref[L]+dp[used])%mod;
                if(R+1<=k)
                {
                    pref[R+1]=(pref[R+1]+mod-dp[used])%mod;
                }
            }
        }
        long long prefsum=0;
        for(int j=0;j<=k;j++)
        {
            prefsum=(prefsum+pref[j])%mod;
            dp[j]=(dp[j]+prefsum)%mod;;
        }
    }
    cout<<dp[k]<<endl;
    return 0;
}