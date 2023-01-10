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

const long long MOD = 1000000007;
#define all(x) (x).begin(), (x).end()
#define FASTINOUT cin.tie(0); ios::sync_with_stdio(false);
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
ll BINARY_SEARCH(vector<ll> dp , ll n , ll key) {
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
int LCM(int a,int b)
{
    return (a/GCD(a,b))*b;
}


set<int> PRIMES;
vector<int> PRIMES_vec;
void SetPrimesEratosthenes(int n)
{
    set<int> p;
    vector<int> p_vec;
    PRIMES_vec.clear();
    //doing the sieve of eratosthenes prime reporting algorithm
    //primes.insert(2);
    vector<bool> done(n+1,false);
    for (int i = 2; i <= n; i++)
    {
        //finding primes
        if(done[i] == false)
        {
            //then we insert it
            p.insert(i);
            p_vec.push_back(i);
            done[i] = true;
            //and remove all of its multiples
            for (int j = 0; j <= n; j+=i)
            {
                done[j] = true;
            }
        }
    }
    PRIMES = p;
    PRIMES_vec = p_vec;
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
        int k = binExpMod(n,(r/2),modulus);
        return ((k)*(k))%modulus;
    }
    else
    {
        return ((binExpMod(n,r-1,modulus)*n)%modulus);
    }
}

int nCr(int a,int b,int modulus)
{
    int ans = 1;
    b = min(b,a-b);
    for (int i = 0; i < b; i++)
    {
        ans = (ans*(a-i))%modulus;
        ans = ans*binExpMod(i+1,modulus-2,modulus);
        ans %= modulus;
    }
    return ans;
}
int ExtendedEuclidean(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = ExtendedEuclidean(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
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

vector<bool> visited;
vector<int> ans;
void topSort(int cur, vector<vector<int>> &Adj)
{
    visited[cur] = true;
    for (int i = 0; i < Adj[cur].size(); i++)
    {
        if(visited[Adj[cur][i]] == false)
        {
            topSort(Adj[cur][i], Adj);
        }
    }
    ans.push_back(cur+1);
}
vector<int> DFS(vector<vector<int>> &Adj)
{
    for (int i = 0; i < Adj.size(); i++)
    {
        if(visited[i] == false)
        {
            topSort(i,Adj); 
        }
    }
    reverse(all(ans));
    return ans; //returns the finally topological sorted array
}

signed main()
{
    FASTINOUT;
    int n,m; cin >> n >> m;
    vector<vector<int>> Adj(n);
    vector<pint> edgeList;
    for(int i = 0; i < m; i++)
    {
        int a,b; cin >> a >> b;
        a--; b--; 
        Adj[a].push_back(b);
        edgeList.push_back({a,b});
    }
        //now to setup topological sorting in a DAG
    visited = vector<bool>(n,false);
    DFS(Adj); reverse(all(ans));
    bool canDo = true;
    //change this if no path exists, duh
    //now time for some dp
    vector<int> dist(n, -1); dist[0] = 0;
    vector<int> prev(n,-1);
    for (int i = 0; i < n; i++)
    {
        int cur = ans[i]-1;
        if(dist[cur] < 0) continue;
        for (int j = 0; j < Adj[cur].size(); j++)
        {
            if(dist[Adj[cur][j]] < dist[cur] + 1)
            {
                dist[Adj[cur][j]] = dist[cur]+1;
                prev[Adj[cur][j]] = cur;
            }
        }
    }
    if(dist[n-1] == -1)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    vector<int> cities;
    int cur = n-1;
    while(cur != -1)
    {
        cities.push_back(cur+1);
        cur = prev[cur];
    }
    cout << cities.size() << endl;
    reverse(all(cities));
    printVectorArray(cities);
}