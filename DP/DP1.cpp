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

const int MOD = 1000000007;
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
    vector<int> values = {1,2,4,8,16,32,63};
    if(n <= 7)
    {
        cout << values[n-1] << endl;
        return 0;
    }
    for (int i = 8; i <= n; i++)
    {
        int ans = 0;
        for (int j = 1; j <= 6; j++)
        {
            ans += values[i-j-1]; 
            //cout << "added " << values[i-j-1] << endl;
        }
        //ans += values[i-2]*2 - values[i-7];
        ans%= MOD;
        values.push_back(ans);
        cout << i << "th - " << ans << endl;
    }
    cout << values[(n-1)];
}