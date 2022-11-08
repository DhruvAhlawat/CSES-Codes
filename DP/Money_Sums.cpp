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
//#define int long long // for huge inputs,outputs, can be removed for space
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
    int n;
    cin >> n;
    vector<int> c; int sum = 0;
    for(int i = 0;i < n;i++)
    {
        int temp;
        cin>>temp;
        c.push_back(temp);
        sum += temp;
    }
    vector<bool> temp(sum+100,false);
    vector<vector<bool>> dp(n+1,temp); //dp[i][j] stores if its possible to make j using the first i coins
    //for each coin, we only check once.
    //dp[0][0] = true;
    for (int i = 0; i < n; i++)
    {
        dp[i][c[i]] = true;
    }
    
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if(j - c[i] >= 0)
                dp[i][j] = dp[i-1][j] || dp[i-1][j-c[i]]||dp[i][j];
            else
                dp[i][j] = dp[i-1][j]||dp[i][j];
        } 
    }

    vector<int> ans;
    for (int i = 0; i <= sum; i++)
    {
        if(dp[n-1][i] == true)
        {
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    printVectorArray(ans);
}   