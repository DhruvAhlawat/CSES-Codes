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

const int infi = 214748000;
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
    vector<int> coins;
    for(int i = 0;i < n;i++)
    {
        int temp;
        cin>>temp;
        coins.push_back(temp);
    }
    //coins are made. now we dp on them.
    sort(coins.begin(),coins.end());
    queue<int> toDo;
    vector<bool> checked(max(x+1,*max_element(coins.begin(),coins.end())),false);
    vector<int> ways(max(x+1,*max_element(coins.begin(),coins.end())),-1);
    for (int i = 0; i < n; i++)
    {
        ways[coins[i]] = 1;
        checked[coins[i]] = true;
        toDo.push(coins[i]);
    }
    int k = 10;
    while(toDo.size() > 0 && (checked[x] == false && toDo.front() <= x))
    {
        int top = toDo.front();
        toDo.pop();
        for (int i = 0; i < n; i++)
        {
            if(top + coins[i] <= x)
            {
                ways[top+coins[i]] = min(ways[top+coins[i]], ways[top] + 1);
                if(!checked[top+coins[i]])
                {
                    ways[top + coins[i]] = ways[top] + 1;
                    toDo.push(top+coins[i]);
                    checked[top+coins[i]] = true;
                }
            }
        }
    }
    if(ways[x] >= infi)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << ways[x];
}