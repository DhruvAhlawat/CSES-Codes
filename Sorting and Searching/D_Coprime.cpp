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

const long long MOD = 1000000007
#define all(x) (x).begin(), (x).end()
#define FASTINOUT cin.tie(0); ios::sync_with_stdio(false);
;ll BINARY_SEARCH(vector<ll> dp , ll n , ll key) {
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
//sort(all(vec));
//vec.resize(unique(all(vec)) - vec.begin());
//rotate(vec.begin(), vec.begin() + k, vec.end());
void printVectorArray(vector<int> a)
{
    for(int i = 0;i < a.size();i++)
    {
        cout << a[i] << " "; 
    }
    cout << "\n";
}
int GCD(int a, int b)
{
   if (b == 0) return a;
   return GCD(b, a%b);
}

long long binExpMod(long long n,long long r,long long modulus)
{
    n = (n%modulus);
    if(n == 0)
        return 0;
    if(n==1)
        return 1;
    if(r == 0)
        return 1;
    if(r == 1)
        return n;
    
    if(r%2 == 0)
    {
        return (((binExpMod(n,(r/2),modulus))*(binExpMod(n,(r/2),modulus)))%modulus);
    }
    else
    {
        return ((binExpMod(n,r-1,modulus)*n)%modulus);
    }
}

int sqrtFloored(int x)
{
    int k = sqrt(x);
    if(k*k == x)
        return k;
    if(k*k <= x)
    {
        if((k+1)*(k+1) <= x)
        {
            return k+1;
        }
        return k;
    }
    else
    {
        return k-1;
    }
}
/* void printVectorArray(vector<ll> a)
{
    for(int i = 0;i < a.size();i++)
    {
        cout << a[i] << " "; 
    }
    cout << "\n";
} */
void FullSort(vector<int> &a)
{
    sort(a.begin(),a.end());
}
void printVectorGrid(vector<vector<ll>> a)
{
    for(int j = 0;j < a.size();j++) {
        for(int i = 0;i < a[j].size();i++)
        {
            cout << a[j][i] << " "; 
        }
        cout << "\n";
    }
}
signed main()
{
    FASTINOUT;
    int t;
    cin >> t;
    for(int testCase = 0;testCase < t;testCase++)
    {
        int n;
        cin >> n;
        vector<int> a(n,0);
        vector<int> prefixSums(n,0);
        vector<pint> arr;
        for(int i = 0;i < n;i++)
        {
            cin >> a[i];
            arr.push_back({a[i],i});
        }
        prefixSums[0] = a[0];
        for (int i = 1; i < n; i++)
        {
            prefixSums[i] = prefixSums[i-1] + a[i];
        }
        sort(all(arr));

        vector<int> mindex(n,MOD);
        // int l = 0;
        // mindex[0] = 0;
        // for (int i = 1; i < n; i++)
        // {
        //     if(arr[i].first > arr[i-1].first)
        //     {
        //         l = i;
        //         mindex[i] = i;
        //     }
        //     else
        //     {
        //         mindex[i] = l;
        //     }
        // }
        mindex[n-1] = arr[n-1].second;
        for (int i = n - 2; i >= 0; i--)
        {
            mindex[i] = min(arr[i].second,mindex[i+1]);
        }
        


        //a range tree would be best tbh
        //start from the end

    }
 
}