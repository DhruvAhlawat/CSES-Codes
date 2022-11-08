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

int ways(vector<int> coins,int n,int sum)
{
    int toreturn = 0;
    //toreturn = max(ways(coins,n-1,sum),ways(coins,n-1,sum-coins[n-1]));

    return toreturn;
}


signed main()
{
    FASTINOUT;
    int n,x;
    cin >> n >> x;

    vector<int> c;
    for(int i = 0;i < n;i++)
    {
        int temp;
        cin>>temp;
        c.push_back(temp);
    }
    vector<int> dp(x+1,0);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= x ;j++)
        {
            if(j - c[i] >= 0)
            {
                dp[j] += dp[j-c[i]]%1000000007;
                dp[j]%= 1000000007;
            }
        }
    }
    
    cout << dp[x] << endl;
 
}