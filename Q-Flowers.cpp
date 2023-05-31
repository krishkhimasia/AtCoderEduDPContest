#include<bits/stdc++.h>
using namespace std;
//O(nlogn) soln

//dp[i] answer if we choose flower with height i and end there
long long dp[200020];
vector <long long> tree;
int n;
vector <long long> h,a;

int main()
{
    cin>>n;
    h.resize(n);
    a.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>h[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    memset(dp,0,sizeof(dp));
    int base=1;
    while(base<=n)
    {
        base*=2;
    }
    tree.resize(2*base+1);
    for(int flower=0;flower<n;flower++)
    {
        int x=base+h[flower];
        long long best=0;
        while(x>1)
        {
            if(x%2==1)
            {
                best=max(best,tree[x-1]);
            }
            x/=2;
        }
        dp[h[flower]]=best+a[flower];
        for(int i=base+h[flower];i>=1;i/=2)
        {
            tree[i]=max(tree[i],dp[h[flower]]);
        }
    }
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,dp[i]);
    }
    cout<<ans;
    return 0;
}