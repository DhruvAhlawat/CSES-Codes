#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#define ll long long
using namespace std;

#define MOD 1000000007
#define FASTINOUT cin.tie(0); ios::sync_with_stdio(false);

vector<vector<int>> dp;
vector<int> pages;
vector<int> prices;
int maxval(int n,int w)
{
    if(n == 0)
    {
        return 0;
    }
    else if(dp[n][w] != -1)
    {
        return dp[n][w];
    }
    int k2 = 0;
    int k1 = maxval(n-1,w);
    if(w-prices[n-1] >= 0)
        k2 = maxval(n-1,w-prices[n-1]) + pages[n-1];

    //dp[n][w] = max(k2,k1);
    return dp[n][w] = max(k2,k1);
}

signed main()
{
    FASTINOUT;
    int n,x;
    cin >> n >> x;
    //vector<int> price;
    for(int i = 0;i < n;i++)
    {
        int temp;
        cin>>temp;
        prices.push_back(temp);
    }
    for(int i = 0;i < n;i++)
    {
        int temp;
        cin>>temp;
        pages.push_back(temp);
    }
    //we either have an item, or we don't
    //vector<int> dp(n,0);
    vector<int> temp(x+1,0);
    //vector<vector<int>> dpcopy(n+1,temp);
    for (int i = 0; i < n+1; i++)
    {
        dp.push_back(temp);
    }
    //prices = price;
    for (int i = 0; i < x+1; i++)
    {
        dp[0][i] = 0;
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
                int k2 = 0;
                int k1 = dp[i-1][j];
                if(j-prices[i-1] >= 0)
                    k2 = dp[i-1][j-prices[i-1]] + pages[i-1];
                dp[i][j] = max(k1,k2);
        }
    }
    



    cout << dp[n][x];
    
}