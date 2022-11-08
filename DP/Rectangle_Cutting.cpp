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
    int a,b;
    cin >> a >> b;
    if(a==b)
    {
        cout << 0;
        return 0;
    }
    int dp[a+1][b+1];
    for (int i = 0; i < a+1; i++)
    {
        for (int j = 0; j < b+1; j++)
        {
            dp[i][j] = 1000000007;
        }
        
    }
    
    for (int i = 0; i <= min(a,b); i++)
    {
        dp[i][i] = 0;
    }
    int m = min(a,b);
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if(i == j)
            {
                continue;
            }
            if(dp[i][j] != 1000000007)
            {
                continue;
            }
            // else if(i < m && j < m && dp[j][i] != 1000000007)
            // {

            // }
            for (int k = 1; k < j; k++)
            {
                dp[i][j] = min(dp[i][j-k]+dp[i][k]+1,dp[i][j]);
                if(i < m && j < m)
                    dp[j][i] = dp[i][j];
            }
            for (int k = 1; k < i; k++)
            {
                dp[i][j] = min(dp[i-k][j]+dp[k][j]+1,dp[i][j]);
            }
        }
    }
    // for (int i = 1; i <= a; i++)
    // {
    //     for (int j = 1; j <= b; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[a][b];
    
}