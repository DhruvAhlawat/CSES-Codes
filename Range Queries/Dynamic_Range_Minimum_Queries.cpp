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

class SegTree
{
    //v starts from 0, root stored at v = 0
    //children of vertex v stored at - left= 2*v+1, right- 2*v + 2


    public:
    vector<int> arr;
    
    int defaultValue = MOD; //keep a large integer incase we want operations wiht minimum
    SegTree(vector<int> a)
    {
        arr = vector<int>(4*a.size() + 1,defaultValue);
        build(a,0,0,a.size()-1);
    }
    //make a build operation
    int functionToStore(int c1, int c2)
    {
        return (min(c1,c2));
    }

    void build(vector<int> &a, int v, int l, int r)
    {
        if(l == r)
        {
            arr[v] = a[l];
        }
        else
        {
            int mid = (l+r)/2;
            build(a,v*2 + 1,l,mid);
            build(a,2*v + 2,mid+1,r);
            //change this function as needed
            arr[v] = functionToStore(arr[2*v+1], arr[2*v+2]); 
        }
    }

    int calculate(int v, int curL, int curR, int rangeL, int rangeR)
    {
        if(rangeR < rangeL)
            return defaultValue;
        if(rangeR == curR && rangeL == curL)
        {
            return arr[v];
        }
        int mid = (curR + curL)/2;
        return functionToStore(calculate(v*2+1,curL, mid, rangeL, min(rangeR,mid)),
        calculate(2*v+2,mid+1,curR, max(rangeL,mid+1), rangeR));
    }

    // void update(int v, int curL, int curR, int pos, int new_val)
    // {
    //     if(curL == curR)
    //     {
    //         arr[v] = new_val;
    //     }
    //     else
    //     {
    //         int mid = (curL + curR)/2;
    //         if(pos <= mid)
    //         {
    //             update(v*2 + 1,curL, mid,pos,new_val);
    //         }
    //         else
    //         {
    //             update(2*v + 2,mid+1,curR,pos,new_val);
    //         }
    //         arr[v] = functionToStore(arr[2*v+1], arr[2*v+2]); 
    //     }
    // }
    void Update(int v, int curL, int curR, int pos, int newVal)
    {
        if( curL    == curR)
        {
            //should be equal to pos
            arr[v] = newVal;
        }
        else
        {
            int mid = (curL + curR)/2;
            if(pos <= mid)
            Update(2*v+1,curL,mid,pos,newVal); 
            else
            Update(2*v+2, mid+1,curR,pos,newVal);

            arr[v] = functionToStore(arr[2*v+1],arr[2*v+2]);
        }
    }

};



signed main()
{
    FASTINOUT;
    int n,q; cin >> n >> q;
    vector<int> a(n,0);
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    
    SegTree tree(a);
    for (int i = 0; i < q; i++)
    {
        int t,b,c; cin >> t >> b >> c;
        if(t == 1)
        {
            tree.Update(0,0,n-1,b-1,c);
        }
        else
        {
            cout << tree.calculate(0,0,n-1,b-1,c-1) << endl;
        }
    }
    
 
}