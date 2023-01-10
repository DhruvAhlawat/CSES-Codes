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

class DSU
{
    public:
    vector<int> parents, rank;
    vector<int> size;
    int curMaxSize = 1;
    int components;
    DSU(int n) //constructor that creates the DSU object
    {
        parents = vector<int>(n,0);
        size = vector<int>(n,1);
        components = n;
        for (int i = 0; i < n; i++)
        {
            parents[i] = i;
        }
        rank = vector<int>(n,0);
    }

    int get(int a)
    {
        return parents[a] = (parents[a] == a)? a : get(parents[a]);
    }

    void Combine(int a,int b)
    {
        a = get(a); b = get(b);
        if(a == b)
            return; //since same component lol
        components--;
        if(rank[a] == rank[b])
            rank[a]++;
        
        if(rank[a] > rank[b])
        {
            parents[b] = a;
            //also 
            size[a] += size[b];
            if(size[a] > curMaxSize)
            {
                curMaxSize = size[a];
            }
        }
        else
        {
            parents[a] = b;
            size[b] += size[a];
            if(size[b] > curMaxSize)
            {
                curMaxSize = size[b];
            }
        }
       
    }

};

signed main()
{
    FASTINOUT;
    int n,m; cin >> n >> m;
    DSU cities(n);
    for (int i = 0; i < m; i++)
    {
        int a,b; cin >> a >> b;
        a--; b--;
        cities.Combine(a,b);
        cout << cities.components << " " << cities.curMaxSize << endl;
    }
    
 
}