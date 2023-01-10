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
vector<bool> under;
vector<bool> visited;
vector<int> previous;
int DFS(const vector<vector<int>> &Adj, int cur)
{
    under[cur] = true;
    visited[cur] = true;
    int ans = -1;
    for (int i = 0; i < Adj[cur].size(); i++)
    {
        if(under[Adj[cur][i]] == true)
        {
            previous[Adj[cur][i]] = cur;
            under[cur] = false;
            return cur;
        }
        //else what we do is
        if(visited[Adj[cur][i]] == false)
        {
            previous[Adj[cur][i]] = cur;
            ans = max(ans, DFS(Adj, Adj[cur][i]));
            if(ans > 0) 
            {
                under[cur] = false;
                return ans;
            }
            
        }
            
    }   
    under[cur] = false;
    return ans;
}

signed main()
{
    FASTINOUT;
    int n,m; cin >> n >> m;
    vector<pint> edgeList; 
    under = vector<bool>(n,false);
    visited = under;
    previous = vector<int>(n,-1);
    vector<vector<int>> AdjOut(n);
    for (int i = 0; i < m; i++)
    {
        int a,b; cin >> a >> b; a--; b--;
        edgeList.push_back({a,b}); AdjOut[a].push_back(b);
    }
    //now we will DFS to check if there are any backedges

    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        if(visited[i] == false)
        {
            ans = max(ans,DFS(AdjOut,i));
            if(ans >= 0)
            {
                break;
            }
        }
    }
    if(ans == -1)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    set<int> taken; int backupAns = ans;
    vector<int> finalAns;
    while(ans != -1 && taken.count(ans) == 0)
    {
        finalAns.push_back(ans+1);
        taken.insert(ans);
        ans = previous[ans];
    }   
    finalAns.push_back(ans+1);
    reverse(all(finalAns));
    cout << finalAns.size() << endl;
    printVectorArray(finalAns);
}