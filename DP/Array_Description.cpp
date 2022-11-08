#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<deque>
#include<queue>
#define ll long long
#define int long long // for huge inputs,outputs, can be removed for space
using namespace std;

#define MOD 1000000007
#define FASTINOUT cin.tie(0); ios::sync_with_stdio(false);
ll BINARY_SEARCH(ll dp[] , ll n , ll key) {
ll s = 1;
ll e = n;
while(s <= e)
{
    ll mid = (s + e) / 2;
    if(dp[mid] == key) return mid; 
    else if (dp[mid] > key) e = mid - 1;
    else s = mid + 1;
}
return -1;
}

string CONVERT_TO_BINARY(ll s) {
    string res = "";
    while(s != 0) { 
        res += (char)('0' + s % 2);
        s /= 2; 
}
    reverse(res.begin() , res.end());
    return res;
}
void printVectorArray(vector<int> a)
{
    for(int i = 0;i < a.size();i++)
    {
        cout << a[i] << " "; 
    }
    cout << "\n";
}
/* void printVectorArray(vector<ll> a)
{
    for(int i = 0;i < a.size();i++)
    {
        cout << a[i] << " "; 
    }
    cout << "\n";
} */
signed main()
{
    FASTINOUT;
    int n,m;
    cin >> n >> m;
    vector<int> a;
    for(int i = 0;i < n;i++)
    {
        int temp;
        cin>>temp;
        a.push_back(temp);
    }
    vector<vector<int>> dp(n+1,vector<int>(m+2,0)); //a[i][v] is the number of ways to fill the array upto ith place, if a[i] = v
    if(a[0] == 0)
    {
        for (int i = 1; i < m+1; i++)
        {
            dp[0][i] = 1;
        }
    }
    else
    {
        dp[0][a[0]] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m+1; j++)
        {
            if(a[i-1] != 0)
            {
                if(abs(a[i-1] - j) <= 1)
                {
                    dp[i][j] = dp[i-1][a[i-1]];
                }
                
            }
            else if(j+1 <= m && j-1 >= 1)
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
            else if(j-1 >= 1)
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            else if(j+1 <= m)
                dp[i][j] = dp[i-1][j+1] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
            dp[i][j] %= MOD;
        }
    }
    // for (int i = 0; i < m+1; i++)
    // {
    //     ans += dp[n-1][i];
    // }
    // cout << ans;
    if(a[n-1] != 0)
    {
        cout << dp[n-1][a[n-1]] << endl;
    }
    else
    {
        int ans = 0;
        for (int i = 1; i < m+1; i++)
        {
            ans+= dp[n-1][i];
        }
        ans %= MOD;
        cout << ans << endl;
    }
}