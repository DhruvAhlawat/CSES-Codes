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
#define pint pair<int,int>
#define tint tuple<int,int,int>
//#define int long long // for huge inputs,outputs, can be removed for space
using namespace std;

#define MOD 1000000007
#define FASTINOUT cin.tie(0); ios::sync_with_stdio(false);
ll BINARY_SEARCH(vector<ll> dp , ll n , ll key) {
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
    FASTINOUT;
    int n;
    cin >> n;
    int maxDays = 0;
    vector<tuple<int,int,int>> abr;
    for (int i = 0; i < n; i++)
    {
        int a,b,r;
        cin >> a >> b >> r;
        abr.push_back(make_tuple(a,b,r));
        if(b > maxDays)
            maxDays = b;
    }
    sort(abr.begin(),abr.end());
    //make a dp[i] that stores the maximum reward stored after i days
    vector<ll> RewardMax(maxDays+1,0);
    for (int i = 0; i < n; i++)
    {
        //taking 2 cases of considering the ith day, and not considering the ith challenge
        int a,b,r;
        tie(a,b,r) = abr[i];
        ll cur = max(RewardMax[a-1] + r,RewardMax[b]);
        //cout << cur << endl;
        //RewardMax[b] = cur;
        for (int j = b; j <= maxDays; j++)
        {
            RewardMax[j] = cur;
            //cout << "changed RewardMax[" << j << "] to " << cur << endl;
        }
        
    }
    cout << RewardMax[maxDays] << endl;
    //printVectorArray(RewardMax);

}