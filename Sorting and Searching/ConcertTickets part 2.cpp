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

#define MOD 1000000007
#define FASTINOUT cin.tie(0); ios::sync_with_stdio(false);

int BinarySearchUpperBound(const vector<int> &a, int key,int l,int r) {
    int n = a.size();
    if(l == r)
    {
        if(a[l] <= key)
            return n;
        else
            return l;
    }
    if(l+1 == r)
    {
        if(a[l] > key)
            return l;
        else if(a[r] > key)
            return r;
        else
            return n;
    }
    int cur = (l+r)/2;
    if(a[cur] > key)
        return BinarySearchUpperBound(a,key,l,cur);
    else
        return BinarySearchUpperBound(a,key,cur,r);
}




signed main()
{
    FASTINOUT;
    int n,m;
    cin >> n >> m;

    vector<int> p(n,0);
    for(int i = 0;i < n;i++)
    {
        cin >> p[i];
    }
    vector<bool> sold(n,false);
    vector<int> t(n,0);
    for(int i = 0;i < m;i++)
    {
        cin >> t[i];
    }
    sort(p.begin(),p.end());

    for (int i = 0; i < m; i++)
    {
        //auto it = upper_bound(p.begin(),p.end(),t[i]);
        int k = BinarySearchUpperBound(p,t[i],0,p.size()-1);
        if(k == 0)
        {
            cout << -1 << endl;
            continue;
        }
        k--;

        while (sold[k] == true)
        {
            k--;
            if(k < 0)
            {
                break;
            }
        }
        if(k < 0)
        {
            cout << -1 << endl;
        }
        else    
        {
            if(p[k] <= t[i])
            {
            cout << p[k] << endl;
            sold[k] = true;
            }
        }
    }
}