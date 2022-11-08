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
    FASTINOUT;
    int n;
    cin >> n;
    vector<int> a;
    int sum = 0;
    for(int i = 0;i < n;i++)
    {
        int temp;
        cin>>temp;
        a.push_back(temp);
        sum += temp;
    }

    vector<int> d(n,0);
    vector<vector<int>> diff(n+1,d);
    //stores score1 - score2;
    for (int i = 0; i < n; i++)
    {
        diff[i][i] = a[i];
    }
    for (int l = n - 1; l >= 0; l--)
    {
        for (int r = l+1; r < n; r++)
        {
            
            diff[l][r] = max(a[l] - diff[l+1][r],a[r] - diff[l][r-1]); //first is incase P1 chooses the left element, second is when they choose the right element
        }
    }
    //printVectorGrid(diff);
    //cout << diff[0][n-1];
    cout << (sum + diff[0][n-1])/2 << endl;
    return 0;
}