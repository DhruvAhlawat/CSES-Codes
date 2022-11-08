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
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> a(n,0);
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    
    vector<int> b(n,0);
    for(int i = 0;i < m;i++)
    {
        cin >> b[i];
    }
    
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    //printVectorArray(a);
    //printVectorArray(b);
    //now that a and b are sorted, we can assign them with the lowest they can do.
    int cnt = 0;
    int i = 0;
    int j = 0;
    while(i < n && j < m)
    {
        if(b[j] >= a[i]-k)
        {
            //might be a valid specimen, iff
            if(b[j] <= a[i]+k)
            {
                //valid specimen indeed, so we increase count
                cnt++; i++; j++;
            }
            else
            {
                //invalid specimen is i, not j 
                i++;
            }
        }
        else
        {
            //not a valid specimen, j
            j++;
        }
    }
    cout << cnt << endl;
    

 
}