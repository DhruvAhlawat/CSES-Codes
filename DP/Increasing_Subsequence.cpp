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
void printVectorGrid(vector<vector<ll>> a)
{
    for(int j = 0;j < a.size();j++) {
        for(int i = 0;i < a[i].size();i++)
        {
            cout << a[j][i] << " "; 
        }
        cout << "\n";
    }
}
signed main()
{
    //classic problem apparently
    FASTINOUT;
    int n;
    cin >> n;
    vector<int> x;
    for(int i = 0;i < n;i++)
    {
        int temp;
        cin>>temp;
        x.push_back(temp);
    }
    vector<int> dp(n,MOD); //fill em all with max elements
    //fill dp[i] with the minimum ending element of subsequence of size of i+1;
    //finding the longest increasing subsequence
    for (int i = 0; i < n; i++)
    {
        //find the position where we can place x[i] by considering the longest subsequence upto it ending in a value less than x[i]
        auto k = lower_bound(dp.begin(),dp.end(),x[i]);
        // k--;
        // if(k <= -1)
        // {
        //     k = 0;
        // }
        //now that we have its index, we can just set it at that position
        *k = x[i];
        //cout << distance(k,dp.begin()) << " goes to " << x[i]  << " at " << i << endl;
    }
    int i = 0;
    for(;i < n;i++)
    {
        if(dp[i] >= MOD)
        {
            break;
        }
    }
    cout << i << endl;
}
