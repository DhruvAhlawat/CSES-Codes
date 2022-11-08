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
signed main()
{
    FASTINOUT;
    int n;
    cin >> n;
    vector<string> grid;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        grid.push_back(temp);
    }
    vector<int> temp(n,0);
    vector<vector<int>> numpath(n,temp);
    if(grid[0][0] != '*')
        numpath[0][0] = 1;
    

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(grid[i][j] == '*' ||(i == 0 && j == 0))
            {
                continue; //do nothing, let it stay at 0;
            }
            if(i == 0)
            {
                numpath[i][j] = numpath[i][j-1];
            }
            else if(j == 0)
            {
                numpath[i][j] = numpath[i-1][j];                  
            }
            else
                numpath[i][j] = numpath[i-1][j] + numpath[i][j-1];
                numpath[i][j] %= 1000000007;
        }
    }
    cout << numpath[n-1][n-1];

 
}