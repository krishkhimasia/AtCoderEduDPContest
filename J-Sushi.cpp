#include<bits/stdc++.h>
using namespace std;

double dp[301][301][301];

int n;

double solve(int x,int y,int z)
{
    if(x==y && y==z && z==0)
    {
        return 0;
    }
    if(dp[x][y][z]==-1)
    {
        double ans=1;
        if(x>0)
            ans+=(double(x)/n)*(solve(x-1,y,z));
        if(y>0)
            ans+=(double(y)/n)*(solve(x+1,y-1,z));
        if(z>0)
            ans+=(double(z)/n)*(solve(x,y+1,z-1));
        ans*=n/double(x+y+z);
        dp[x][y][z]=ans;
    }
    return dp[x][y][z];
}

int main()
{
    for(int i=0;i<=300;i++)
    {
        for(int j=0;j<=300;j++)
        {
            for(int k=0;k<=300;k++)
            {
                dp[i][j][k]=-1;
            }
        }
    }
    cin>>n;
    int x=0,y=0,z=0;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        if(a==1)
        {
            x++;
        }
        else if(a==2)
        {
            y++;
        }
        else
        {
            z++;
        }
    }
    cout<<setprecision(10);
    cout<<solve(x,y,z)<<endl;
    return 0;
}