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



vector<vector<int>> dp;
int editDistance(string &a,string &b, int l1, int r1, int l2, int r2)
{
    //if the first characters of both the string are the same, we can just continue
    if(l1 > r1 || l2 > r2) return MOD;
    if(l1 == r1 && l2 == r2) return 0;
    if(dp[l1][l2] != -1) return dp[l1][l2];
    if(a[l1] == b[l2])
    {
        return editDistance(a,b,l1+1,r1,l2+1,r2);
    }
    //if the first characters are not equal
    
    //then what we can do is, try out replace AND remove both once
    int moves[3] = {0};
    moves[0] = 1 + editDistance(a,b,l1+1,r1,l2,r2); moves[1] = 1 + editDistance(a,b,l1,r1,l2+1,r2);
    //the above correspond to removal and insert
    moves[2] = 1 + editDistance(a,b,l1+1,r1,l2+1,r2); //this corresponds to replacing

    sort(moves, moves + 3);
    dp[l1][l2] = moves[0];
    return moves[0];
}
signed main()
{
    FASTINOUT;
    string a,b; cin >> a >> b;
    //need to find the edit distance between a and b
    //replace, insert and remove are the operations we have been given, 
    //each costing one operation. so the ideal method to follow after this would be
    //to
    dp = vector<vector<int>>(a.size()+1,vector<int>(b.size()+1, -1));
    cout << editDistance(a,b,0,a.size(),0,b.size()) << endl;

 
}