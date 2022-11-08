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
    int t;
    cin >> t;
    for(int testCase = 0;testCase < t;testCase++)
    {
        int n,k;
        cin >> n >> k;
        vector<int> a;
        for(int i = 0;i < n;i++)
        {
            int temp;
            cin>>temp;
            a.push_back(temp);
        }

        if(n > 2*k)
        {
            cout << "Case #" << testCase+1 << ": NO" << endl;
            continue;
        }
        sort(a.begin(),a.end());
        bool canDo = true;
        for (int i = 1; i < n-1; i++)
        {
            if(a[i] == a[i-1] && a[i] == a[i+1])
            {
                canDo = false;
                break;
            }
        }

        if(canDo)
        {
            cout << "Case #" << testCase+1 << ": YES" << endl;
        }
        else
        {
            cout << "Case #" << testCase+1 << ": NO" << endl;
        }
    }
 
}