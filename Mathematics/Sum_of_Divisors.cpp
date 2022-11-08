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

set<int> primes;
void SetPrimesEratosthenes(int n)
{
    set<int> p;
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
            done[i] = true;
            //and remove all of its multiples
            for (int j = 0; j <= n; j+=i)
            {
                done[j] = true;
            }
        }
    }
    primes = p;
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
        int k = (binExpMod(n,(r/2),modulus));
        return ((k)*(k))%modulus;
    }
    else
    {
        return ((binExpMod(n,r-1,modulus)*n)%modulus);
    }
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
const int TWO_MOD_INV = 500000004;
long long total_sum(long long start, long long end) {
	return (
		(((end - start + 1) % MOD) * ((start + end) % MOD) % MOD)
		* TWO_MOD_INV % MOD
	);
}

int totSum(int s,int e)
{
    return ((((((e-s+1)%MOD)*((e+s)%MOD))%MOD)*(TWO_MOD_INV)%MOD)%MOD);
}
signed main()
{
    FASTINOUT;
    int n;
    cin >> n;
    //vector<int> sumDiv(n+1,0);
    int sum = 0;
    for (int i = 1; i <= n;)
    {
        // for (int j = i; j <= n; j+= i)
        // {
        //     sum += i%MOD;
        //     sum %= MOD;
        // }
        int k = (n/i); //this k will remain same from i = i to i = i + (f*i/k)
        int lastPos = (n/k);
        //int repetitions = (lastPos-i);
        k %= MOD;
        // sum += ((k*(((lastPos+i)%MOD)*((lastPos-i+1)%MOD)))/2)%MOD;
        sum += k*totSum(i,lastPos);
        sum %= MOD;
        i = lastPos + 1;
    }
    //after i gets to MOD-1, then it will repeat
    cout << sum << endl;
    //cout << binExpMod(2,MOD-2,MOD);
    
}