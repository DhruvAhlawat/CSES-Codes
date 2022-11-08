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

vector<int> dig(int n)
{
    vector<int> result;
    vector<bool> done(10,false);
    while(n > 0)
    {
        int k = n%10;
        if(done[k] == false)
        {
            result.push_back(k);
            done[k] = true;
        }
        n = (n-k)/10;
    }
    return result;
}
int maxDig(int n)
{
    int md = 0;
    while(n > 0)
    {
        int k = n%10;
        if(k > md)
        {
            md = k;
        }
        n = (n-k)/10;
    }
    return md;
}
signed main()
{
    FASTINOUT;
    //printVectorArray(dig(45104));
    int n;
    cin >> n;
    int cnt = 0;
    while(n > 0)
    {
        n -= maxDig(n);
        cnt++;
    }

    cout << cnt;
}