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
#define Grid(x) vector<vector<x>>
const long long MOD = 1e9 + 7;
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
#define ff first 
#define ss second
signed main()
{
    FASTINOUT;
    int n,m; cin >> n >> m;
    vector<string> grid(n);
    vector<pint> monsters;
    pint player = {0,0};
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
        for (int j = 0; j < m; j++)
        {
            if(grid[i][j] == 'M')
            {
                monsters.push_back({i,j});
            }
            if(grid[i][j] == 'A')
                player = {i,j};
        }
    }
    //preplace the numbers of shortest distance from the nearest monsters into the cells.
    //and then while BFSing for the shortest path we can just check if current distance is lesser than monster distance
    queue<pint> left;
    for (int i = 0; i < monsters.size(); i++)
    {
        left.push(monsters[i]);
    }
    vector<vector<int>> distMin(n,vector<int>(m,MOD));
    for (int i = 0; i < monsters.size(); i++)
    {
        distMin[monsters[i].ff][monsters[i].ss] = 0;
    }
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    while(left.size() != 0)
    {
        pint cur = left.front(); left.pop();
        if(visited[cur.first][cur.second])
            continue; //already visited before
        visited[cur.first][cur.second] = true;
        //else we need to do BFS and then assign the distance
        vector<pint> dir = {{-1,0},{0,1},{1,0},{0,-1}};
        for (int i = 0; i < dir.size(); i++)
        {
            if(cur.first + dir[i].first >= n || cur.first + dir[i].first < 0 || cur.second+dir[i].second >= m || cur.second+dir[i].second < 0)
                continue;
            if(grid[cur.first + dir[i].first][cur.second+dir[i].second] == '#')
                continue; //skip if wall or other monster or player position
            if(visited[cur.first + dir[i].first][cur.second+dir[i].second])
                continue; //no need to update this
            //else
            if(distMin[cur.first + dir[i].first][cur.second+dir[i].second] == MOD)
            {
                left.push({cur.first + dir[i].first,cur.second + dir[i].second}); //pushing this anyway
            }
            distMin[cur.first + dir[i].first][cur.second+dir[i].second] = 
            min(distMin[cur.first + dir[i].first][cur.second+dir[i].second], 
                1 + distMin[cur.first][cur.second]);
        }
    }

    //now that distmin is prepared lets just do BFS!
    visited = vector<vector<bool>>(n,vector<bool>(m,false));
    Grid(pint) prev(n,vector<pint>(m,{-1,-1}));
    Grid(int) dist(n,vector<int>(m,MOD));
    dist[player.first][player.second] = 0;
    prev[player.ff][player.ss] = {-2,-2};
    queue<pint> pp;
    pp.push(player);
    bool canDo = false;
    pint lastOne = {0,0};
    while(pp.size() != 0)
    {
        pint cur = pp.front(); pp.pop();
        if(visited[cur.first][cur.second])
            continue;
        visited[cur.first][cur.second] = true;
        if(cur.first == n-1 || cur.first == 0 || cur.second == m-1 || cur.second == 0)
        {
            canDo = true;
            lastOne = cur;
            break;
        }
        vector<pint> dir = {{-1,0},{0,1},{1,0},{0,-1}};
        for (int i = 0; i < 4; i++)
        {
            if(cur.first+dir[i].first >= n || cur.first+dir[i].first < 0 || cur.second + dir[i].second >= m || cur.second + dir[i].second < 0)
                continue;
            if(grid[cur.first+dir[i].first][cur.second + dir[i].second] != '.')
                continue; //nothing there
            if(visited[cur.first+dir[i].first][cur.second + dir[i].second]) continue;
            if(distMin[cur.first+dir[i].first][cur.second + dir[i].second] <= dist[cur.first][cur.second] + 1)
            {
                continue;
            }
            //else we can add this
            prev[cur.first+dir[i].first][cur.second + dir[i].second] = cur;
            pp.push({cur.first+dir[i].first,cur.second + dir[i].second});
            dist[cur.first+dir[i].first][cur.second + dir[i].second] = dist[cur.first][cur.second] + 1;
        }
    }
    if(canDo)
    {
        Yes();
        //then we first find the valid path that we found
        string path = "";
        while(lastOne != player)
        {
            pint nextOne =  prev[lastOne.first][lastOne.second];
            if(nextOne.first-lastOne.first == 1)    
                path.push_back('U');
            else if(nextOne.first-lastOne.first == -1)
                path.push_back('D');
            else if(nextOne.second - lastOne.second == 1)
                path.push_back('L');
            else if(nextOne.second - lastOne.second == -1)
                path.push_back('R');
            lastOne = nextOne;
        }
        reverse(all(path));
        cout << path.size() << endl;
        cout << path << endl;
    }
    else
    {
        No();
    }
}