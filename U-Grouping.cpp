#include<bits/stdc++.h>
using namespace std;

//O(3^n);

using ll = long long;
#define endl "\n"
#define pb push_back
#define mp make_pair
#define fi first
#define se second

long long n;
long long grp_comp[(1<<16)];
long long dp[(1<<16)];
long long a[17][17];

void computecomp()
{
    for(int mask=0;mask<(1<<n);mask++)
    {
        if(mask==0)
        {
            grp_comp[0]=0;
            continue;
        }
        int temp=0;
        for(int i=16;i>=0;i--)
        {
            if((mask)&(1<<i))
            {
                temp=i;
                break;
            }
        }
        for(int i=0;i<temp;i++)
        {
            if(mask&(1<<i))
                grp_comp[mask]+=a[temp][i];
        }
        grp_comp[mask]+=grp_comp[mask^(1<<temp)];
    }
}

long long solve(int mask)
{
    if(mask==0)
    {
        return 0;
    }
    if(dp[mask]==-1)
    {
        long long ans=-1e18;
        for(int submask=mask;submask;submask=(submask-1)&mask)
        {
            ans=max(ans,grp_comp[submask]+solve(mask^submask));
        }
        dp[mask]=ans;
    }
    return dp[mask];
}

int main()
{
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    computecomp();
    // for(int i=0;i<(1<<n);i++)
    // {
    //     cout<<i<<" "<<grp_comp[i]<<endl;
    // }
    cout<<solve((1<<n)-1)<<endl;
    return 0;
}