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
string a,b;
vector<vector<int>> dp;
int editDistance(int n,int m)
{

    if(n < 0 || m < 0)
    {
        return MOD;
    }
    if(n == 0 && m == 0)
    {
        return 0;
    }
    if(dp[n][m] != -1)
    {
        return dp[n][m];
    }
    //consider only the last element.
    if(a[n-1] == b[m-1])
    {
        return dp[n][m] = editDistance(n-1,m-1);
    }
    //consider we are changing the string b
    
    int k1 = editDistance(n-1,m) + 1; //if we insert an element at the end of b to match it with a., now we have m more elements to matchz
    int k2 = editDistance(n,m-1) + 1; //if we remove the last element of b; have got to match n elements of a with m-1 elements of b
    int k3 = editDistance(n-1,m-1) + 1; //if we replace the last element of b. size of b remains m, only have to consider the next elements

    return dp[n][m] = min(k1,min(k2,k3));
    
}






signed main()
{
    FASTINOUT;
    int n,m;
    //string a,b;
    cin >> a >> b;
    n = a.size();
    m = b.size();
    
    vector<int> temp(m+1,-1);
    vector<vector<int>> dpcopy(n+1,temp);
    dp = dpcopy;
    cout << editDistance(n,m);
}