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
void printVectorGrid(vector<vector<int>> a)
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
    cin>>n;
    if((n*(n+1))%4 != 0)
    {
        cout << 0 << endl;
        return 0;
    }
    //else what we do is, check by 0-1 knapsack if we can make the total sum n*(n-1)/4 or not.
    int numsum = n*(n+1)/4;
    //now we run 0-1knapsack.
    vector<int> temp(numsum+1, false);
    vector<vector<int>> knapsack(n+1,temp);
    //we initialise it by making knapsack[0][0] = 1;
    knapsack[0][0] = 1;
    // for (int i = 0; i < n; i++)
    // {
    //     knapsack[i][0] = true; //for each, we can always make a sum of 0;
    // }
    
    //knapsack[1][1] = true;
    for (int i = 1; i <= n; i++)
    {
        //for each coin.
        for (int j = 0; j < numsum+1; j++)
        {
            knapsack[i][j] = knapsack[i-1][j]; //considering we didn't take the ith element.
            if(j - i >= 0)
            {
                knapsack[i][j] = knapsack[i-1][j-i] +  knapsack[i-1][j]; //considering we took the ith element
                knapsack[i][j] = knapsack[i][j]%MOD;
            }
        }
    }
    cout << knapsack[n-1][numsum] << endl;
    //printVectorGrid(knapsack);
    


 
}