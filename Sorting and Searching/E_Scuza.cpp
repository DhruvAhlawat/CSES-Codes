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
        int n,queries;
        cin >> n >> queries;
        vector<int> a(n,0);
        vector<int> q(queries,0);
        vector<int> prefixSums(n,0);
        vector<pint> arr;
        for(int i = 0;i < n;i++)
        {
            cin >> a[i];
            arr.push_back({a[i],i});
        }
        for (int i = 0; i < queries; i++)
        {
            cin >> q[i];
        }
        prefixSums[0] = a[0];
        for (int i = 1; i < n; i++)
        {
            prefixSums[i] = prefixSums[i-1] + a[i];
        }
        sort(all(arr));
        sort(all(a));
        vector<int> mindex(n,0); 
        //to store the minimum index of the number that is greater than or equal to it
        mindex[n-1] = arr[n-1].second;//the index of the largest element
        for (int i = n - 2; i >= 0; i--)
        {
            mindex[i] = min(mindex[i+1],arr[i].second); //the minimum of them
        } //does enough if no duplicates are present, ButttT
        //printVectorArray(mindex);

        //duplicate checker
        int l = 0;
        for (int i = 1; i < n; i++)
        {
            if(arr[i].first > arr[i-1].first)
            {
                l = i;
            }
            else if(arr[i].first == arr[i].second)
            {
                mindex[i] = min(mindex[l],mindex[i]);
            }
        }
        //printVectorArray(mindex);
        for (int i = 0; i < queries; i++)
        {
            auto it = upper_bound(a.begin(),a.end(),q[i]);
            int x = it - a.begin();
            if(it == a.end())
            {
                //cout << prefixSums[arr[mindex[n-1]].second] << " ";
                //continue;
                x--;
                cout << prefixSums[n-1] << " ";
                continue;
            }
            //else
            //now to check what the prefix sum of x would be
            int ansPos = mindex[arr[x].second]-1; //the highest element we can go to
            if(ansPos < 0)
                cout << 0 << " ";
            else
                cout << prefixSums[ansPos] << " ";
        }
        cout << endl;
        //cout << prefixSums[0] << endl;
        //a range tree would be best tbh
        //start from the end
    }
 
}