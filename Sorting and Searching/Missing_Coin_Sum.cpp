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
#define int long long // for huge inputs,outputs, can be removed for space
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
void FullSort(vector<int> &a)
{
    sort(a.begin(),a.end());
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
void Yes()
{
    cout << "YES" << endl;
}
void No()
{
    cout << "NO" << endl;
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
    vector<int> x(n,0);
    for(int i = 0;i < n;i++)
    {
        cin >> x[i];
    }
    //sort(x.begin(),x.end());
    FullSort(x);
    //smallest sum we cannot create huh
    //should we use dp hmMmMM, we can just find all possible sums of the subsets with that, but we probably gotta find it faster
    vector<int> smallestNumberNotRepresentable(n+1,1);
    int ans = 1;
    if(x[0] != 1)
    {
        cout << 1 << endl;
        return 0;
    }
   
    smallestNumberNotRepresentable[0] = 2;
    
    for (int i = 1; i < n; i++)
    {
        if(x[i] > smallestNumberNotRepresentable[i-1])
        {
            ans = smallestNumberNotRepresentable[i-1];
            break;
        }
        else
        {
            smallestNumberNotRepresentable[i] = x[i] + smallestNumberNotRepresentable[i-1];
        }
    }
    
    if(ans != 1)
    {
        cout << ans << endl;
    }
    else
    {
        cout << smallestNumberNotRepresentable[n-1] << endl;
    }
 
}