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

class DSU
{
    public:
    vector<int> parents, rank;

    DSU(int n) //constructor that creates the DSU object
    {
        parents = vector<int>(n,0);
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
        if(rank[a] == rank[b])
            rank[a]++;
        
        if(rank[a] > rank[b])
        {
            parents[b] = a;
        }
        else
        {
            parents[a] = b;
        }
    }

};
signed main()
{
    FASTINOUT;
    int n,m; cin >> n >> m;
    vector<pair<int,pint>> roads;
    for (int i = 0; i < m; i++)
    {
        int a,b,c; cin >> a >> b >> c;
        a--; b--; 
        roads.push_back({c,{a,b}});
    }
    DSU city(n+1);
    int cnt = 0;
    sort(all(roads));
    int cost = 0;
    for (int i = 0; i < m; i++ && cnt < n-1)
    {
        if(city.get(roads[i].second.first) != city.get((roads[i].second.second)))
        {
            cost += roads[i].first;
            city.Combine(roads[i].second.first,roads[i].second.second);
            cnt++;
        }
    }
    if(cnt < n-1)
    {
        cout << "IMPOSSIBLE" <<endl;
        return 0;
    }
    cout << cost << endl;
}