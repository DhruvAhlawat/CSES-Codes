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
const int mod = 1000000007;
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
    int n,x;
    cin >> n >> x;
    vector<int> c;
    for(int i = 0;i < n;i++)
    {
        int temp;
        cin>>temp;
        c.push_back(temp);
    }
    vector<int> ways(x+1,0);
    ways[0] = 1;
    for (int i = 1; i < x+1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i-c[j] >= 0)
            {
                ways[i] += ways[i-c[j]]%mod; //number of ways the sum has c[j] at the end
            }
        }
        ways[i] = ways[i]%mod;
    }
    
    cout << ways[x] << endl;

}