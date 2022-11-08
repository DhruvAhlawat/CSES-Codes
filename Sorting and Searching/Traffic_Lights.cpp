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
    int x,n;
    cin >> x >> n;
    vector<int> a(n,0);
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    
    //now what can we do
    set<int> positions;

    multiset<int> gaps;
    positions.insert(a[0]);
    gaps.insert(a[0]); gaps.insert(x-a[0]); //initial case done
    cout << *(--gaps.end()) << " ";
    for (int i = 1; i < n; i++)
    {
        auto location = positions.lower_bound(a[i]); //the smallest position greater than current number
        if(location == positions.end())
        {
            //inserted at the end;
            //remove previous element from multiset
            auto it = positions.end(); it--;
            positions.insert(a[i]);
            auto rem = gaps.lower_bound(x-*it);
            gaps.erase(rem);
            gaps.insert(x-a[i]); gaps.insert(a[i] - *it);
            
        }
        else if(location == positions.begin())
        {
            //gonna insert at the start
            int removal = *positions.begin();
            gaps.erase(gaps.lower_bound(removal));
            positions.insert(a[i]);
            gaps.insert(a[i]); gaps.insert(removal - a[i]);

        }
        else
        {
            int ahead = *location;
            int behind = *(--location);
            gaps.erase(gaps.lower_bound(ahead-behind));
            positions.insert(a[i]);
            gaps.insert(ahead-a[i]); gaps.insert(a[i]-behind);
        }

        cout << *(--gaps.end()) << " ";
    }
    
 
}