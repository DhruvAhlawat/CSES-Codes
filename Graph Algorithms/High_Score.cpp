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
vector<bool> currentlyUnder;
bool DFS(vector<vector<pint>> &Adj,int cur,int parent, vector<bool> &flagged)
{
    currentlyUnder[cur] = true;
    if(flagged[cur] == true)
    {
        return true;
    }

    for (int i = 0; i < Adj[cur].size(); i++)
    {
        if(Adj[cur][i].first == parent)
            continue;
        if(currentlyUnder[Adj[cur][i].first])
            continue;
        bool isFlagged = DFS(Adj, Adj[cur][i].first, cur, flagged);
        if(isFlagged)
        {
            return true;
        }
    }
    currentlyUnder[cur] = false;
    return false;
}
int bellmanFord(vector<pair<pint,int>> edges, int totVertices, vector<vector<pint>> Adj)
{
    vector<int> dist(totVertices,MOD*MOD);
    dist[0] = 0;
    for (int i = 0; i < totVertices-1; i++)
    {
        for (int j = 0; j < edges.size(); j++)
        {
            if(dist[edges[j].first.second] > edges[j].second + dist[edges[j].first.first])
            {
                if(dist[edges[j].first.first] != MOD*MOD)
                    dist[edges[j].first.second] = edges[j].second + dist[edges[j].first.first]; 
            }
        }
    }
    vector<bool> flagged(totVertices,false);
    bool found = false;
    for (int j = 0; j < edges.size(); j++)
    {
        if(dist[edges[j].first.second] > edges[j].second + dist[edges[j].first.first] && dist[edges[j].first.second] != MOD*MOD)
        {
            flagged[edges[j].first.second] = true;
            found = true;
        }
    }
    if(!found)
    {
        return (-dist[totVertices-1]);
    }
    //now DFS from n, or perhaps BFS works just as well too

    currentlyUnder = vector<bool>(totVertices,false);
    bool cantDo = DFS(Adj, totVertices-1,totVertices,flagged);
    if(!cantDo)
    {
        return (-dist[totVertices-1]);
    }
    else
    {
        return -1;
    }
}




signed main()
{
    FASTINOUT;
    //Plan is to first do BFS from the starting node and mark all the nodes that can be visited from this node
    //next we BFS from the ending node and traverse the edges in reverse and check all the nodes from which we can arrive at the ending node
    //and we take the intersection of these to get the final nodes that need to be considered

    //then we can check if a positive cycle exists in this reduced graph and IF it does, the answer is -1
    //otherwise we can do DFS from the start node to the end node
    int n,m; cin >> n >> m;
    vector<vector<pint>> Adj(n);
    vector<pair<pint,int>> edges;
    for (int i = 0; i < m; i++)
    {
        int a,b,x; cin >> a >> b >>x;
        a--; b--; x = -x;
        Adj[b].push_back({a,x}); 
        edges.push_back({{a,b},x});
    }
    
    cout << bellmanFord(edges,n,Adj) << endl;



 
}