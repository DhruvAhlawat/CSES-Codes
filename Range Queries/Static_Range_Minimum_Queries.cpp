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

class SegmentTree
{
    public:
    vector<int> verts;

    SegmentTree(vector<int> inputArr)
    {
        verts = vector<int>(4*inputArr.size()+1,0);
        //then call the build function
        buildTree(inputArr, 0, 0, inputArr.size()-1);
    }

    void buildTree(vector<int> &toReach,int curPos, int curL, int curR)
    {
        if(curL == curR)
        {
            verts[curPos] = toReach[curL];
        }
        else
        {
            //divide into two halfs
            int mid = (curL + curR)/2;
            buildTree(toReach,2*curPos+1,curL,mid); //the child is at 2*curpos+1
            buildTree(toReach,2*curPos+2,mid+1,curR); //the second child is at 2*curpos+2
            verts[curPos] = min(verts[2*curPos+1],verts[2*curPos+2]);
        }
    }
    
    int calculate(int curPos, int curL, int curR, int rangeL, int rangeR)
    {
        if(rangeR < rangeL)
        {
            return MOD*MOD; //returning the maximum value when this happens
        }
        if(rangeR == curR && rangeL == curL)
        {
            return verts[curPos];
        }
        else
        {
            int mid = (curL + curR)/2;
            return (min(calculate(2*curPos+1,curL,mid,rangeL,min(rangeR,mid)),
             calculate(2*curPos+2,mid+1,curR,max(mid+1,rangeL),rangeR)));
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
    
    SegmentTree bruh(a);
    for (int i = 0; i < q; i++)
    {
        int a,b; cin >> a >> b;
        a--; b--;
        cout << bruh.calculate(0,0,n-1,a,b) << endl;
    }
    
 
}