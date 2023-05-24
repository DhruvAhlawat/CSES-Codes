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


long long binExpMod(long long n,long long r,long long modulus)
{
if(modulus <= 0)
{
    if(r%2 == 0)
    {
        int k = binExpMod(n,(r/2),modulus);
        return ((k)*(k));
    }
    else
    {
        return ((binExpMod(n,r-1,modulus)*n));
    }
}
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
signed main()
{
    FASTINOUT;
    int n,m,q; cin >> n >> m >> q;
    vector<vector<pint>> roads(n);
    for (int i = 0; i < m; i++)
    {
        int a,b,c; cin >> a >> b >> c;
        a--; b--;
        roads[a].push_back({b,c});
        roads[b].push_back({a,c}); //since two way roads
    }
    vector<vector<int>> d(n ,vector<int>(n,1e18));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < roads[i].size(); j++)
        {
            d[i][roads[i][j].first] = min(d[i][roads[i][j].first], roads[i][j].second); //initial distance is set as this.
        }        
    }
    
    //cannot and will not use Djikstra. Instead will use Floyd Warshall algorithm
    for (int i = 0; i < n; i++)
    {
        d[i][i] = 0; //distance to itself is obviously 0.
        //then we should set its distance to its neighbours.

        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                d[j][k] = min(d[j][k],d[j][i] + d[i][k]);
                d[k][j] = d[j][k];
            }
        }

        


    }



    for (int i = 0; i < q; i++)
    {
        int a,b; cin >> a >> b;
        a--; b--;
        if(d[a][b] >= 1e18)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << d[a][b] << endl;
        }
    }
    
 
}