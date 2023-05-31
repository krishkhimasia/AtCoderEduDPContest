#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

using ll = long long;
#define endl "\n"
#define pb push_back
#define mp make_pair
#define fi first
#define se second

long long n,k;

const ll matmod=mod;
using matrix=vector<vector<ll>>;

matrix I(int n)
{
    matrix temp(n,vector<ll>(n,0));
    for(int i=0;i<n;i++)
    {
        temp[i][i]=1;
    }
    return temp;
}

matrix add(const matrix &a, const matrix &b)
{
    matrix c(a.size(),vector<ll>(a.size()));
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<a.size();j++)
        {
            c[i][j]=a[i][j]+b[i][j];
        }
    }
    return c;
}

matrix sub(const matrix &a, const matrix &b)
{
    matrix c(a.size(),vector<ll>(a.size()));
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<a.size();j++)
        {
            c[i][j]=a[i][j]-b[i][j];
        }
    }
    return c;
}

matrix mul(matrix a, matrix b)
{
    matrix c(a.size(),vector<ll>(b[0].size(),0));
    for(int i=0;i<a.size();i++)
    {
        for(int k=0;k<a[0].size();k++)
        {
            if(a[i][k])
            {
                for(int j=0;j<b[0].size();j++)
                {
                    c[i][j]+=a[i][k]*b[k][j];
                    c[i][j]%=mod;
                }
            }
        }
    }
    return c;
}

matrix mod_mul(matrix a)
{
    matrix c(a.size(),vector<ll>(a.size(),0));
    for(int i=0;i<a.size();i++)
    {
        for(int k=0;k<a.size();k++)
        {
            if(a[i][k])
            {
                for(int j=0;j<a.size();j++)
                {
                    c[i][j]+=a[i][k]*a[k][j];
                    c[i][j]%=mod;
                }
            }
        }
    }
    return c;
}

matrix binary_pow(matrix a, ll p)
{
    matrix ans=I(a.size());
    while(p>0)
    {
        if(p&1) ans=mul(ans,a);
        a=mul(a,a);
        p/=2;
    }
    return ans;
}

int main()
{
    cin>>n>>k;
    matrix g;
    g.resize(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int x;
            cin>>x;
            g[i].push_back(x);
        }
    }
    g=binary_pow(g,k);
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ans=(ans+g[i][j])%mod;
        }
    }
    cout<<ans<<endl;
    return 0;
}