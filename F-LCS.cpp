#include<bits/stdc++.h>
using namespace std;

int dp[3001][3001];

int main()
{
    string s,t;
    cin>>s>>t;
    int n1=s.length();
    int n2=t.length();
    for(int i=1;i<=n1;i++)
    {
        for(int j=1;j<=n2;j++)
        {
            if(s[i-1]==t[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                if(dp[i-1][j]>=dp[i][j-1])
                {
                    dp[i][j]=dp[i-1][j];
                }
                else
                {
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
    }
    int len=dp[n1][n2];
    // cout<<len<<endl;
    char final[len+1];
    final[len]='\0';
    int cnt=len-1;
    int i=n1,j=n2;
    while(i>0 && j>0 && cnt>=0)
    {
        if(s[i-1]==t[j-1])
        {
            final[cnt]=s[i-1];
            i--;
            j--;
            cnt--;
        }
        else
        {
            if(dp[i][j]==dp[i][j-1])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }
    cout<<final<<endl;
    return 0;
}