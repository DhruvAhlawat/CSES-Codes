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

const long long MOD = 1000000007
#define all(x) (x).begin(), (x).end()
#define FASTINOUT cin.tie(0); ios::sync_with_stdio(false);
;ll BINARY_SEARCH(vector<ll> dp , ll n , ll key) {
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
/* void printVectorArray(vector<ll> a)
{
    for(int i = 0;i < a.size();i++)
    {
        cout << a[i] << " "; 
    }
    cout << "\n";
} */
void FullSort(vector<int> &a)
{
    sort(a.begin(),a.end());
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
vector<vector<int>> MatrixMultiply(const vector<vector<int>> &a,const vector<vector<int>> &b, int Mod)
{
    //lets assume both the matrices are multipliable
    int n = a.size(),  m = b.size();
    if(m*n == 0)
    {
        return vector<vector<int>>(0,vector<int>(0,0));
    }
    int r = b[0].size();
    vector<vector<int>> ans(n,vector<int>(r,0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            int sum = 0;
            for (int k = 0; k < m; k++)
            {
                sum += (a[i][k]*b[k][j])%Mod;
                sum %= Mod;
            }
            ans[i][j] = sum;
        }
    }
    return ans;
}

//dont input n=0 from the start, will not MODulo
vector<vector<int>> MatrixExponentiation(const vector<vector<int>> &a,int n,int Mod)
{
    if(n == 0)
    {
        return a;
    }
    if(n == 1)
    {
        return a; //assumes that we have previously modded all the elements in previous recursions
    }
    if(n%2 == 1)
    {
        return MatrixMultiply(MatrixExponentiation(a,n-1,Mod),a,Mod);
    }
    else
    {
        vector<vector<int>> temp = MatrixExponentiation(a,n/2,Mod);
        return MatrixMultiply(temp,temp,Mod);
    }
    return a;
}
signed main()
{
    FASTINOUT;
    int n,m,k;
    cin >> n >> m>> k;
    vector<vector<int>> adjacencyMatrix(n,vector<int>(n,0));
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a >> b;
        adjacencyMatrix[a-1][b-1]++;
    }
    //now the adjacency matrix has been formed
    //then we do
    cout << MatrixExponentiation(adjacencyMatrix,k,MOD)[0][n-1];
    //cout << finalGrid[0][n-1];
}