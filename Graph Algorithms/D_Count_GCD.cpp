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


//very quick for finding prime factorisation for many numbers, prime calculation works in O(nloglogn) 
//and finding prime factorisation for each element works in O(logn)
vector<pint> primeFactorisationThroughSieve(int x)
{
    vector<pint> p;
    if(PRIMES_vec.size() < x)
    {
        //then we gotta run the sieve again
        SetPrimesEratosthenes(x);
    }
    if(PRIMES.count(x) == 1) //if it is a prime itself
    {
        return {{x,1}};
    }

    int k = 0; int cur = x;
    while(PRIMES_vec[k]*PRIMES_vec[k] <= cur)
    {
        if(cur%PRIMES_vec[k] == 0)
        {
            p.push_back({PRIMES_vec[k],1});
            cur /= PRIMES_vec[k];
        }
        while(cur%PRIMES_vec[k] == 0)
        {
            cur /= PRIMES_vec[k];
            p[p.size()-1].second++; //increase the power
        } 
        k++; //go to the next prime
    }
    if(cur != 1)
    {
        p.push_back({cur,1});
    }
    //now the prime factorisation is complete, probably.
    return p;
}

//quick for finding prime factorisation of few large numbers, works in O(sqrt(n));
vector<pint> primeFactorisationNormal(int x)
{
    vector<pint> p;
    int cur = x;
    if(cur%2 == 0)
    {
        p.push_back({2,1});
        cur /= 2;
    }
    while(cur%2 == 0)
    {
        p[p.size()-1].second++;
        cur /= 2;
    }

    for (int i = 3; i*i <= cur; i+= 2) //since now primes must occur at an odd number only
    {
        if(cur%i == 0)
        {
            p.push_back({i,1});
            cur /= i;
        }
        while(cur%i == 0)
        {
            p[p.size()-1].second++;
            cur /= i;
        }
    }
    if(cur != 1)
    {
        p.push_back({cur,1}); //as the remaining cur itself must be a prime number
    }
    return p;
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
signed main()
{
    FASTINOUT;
    int t;
    cin >> t;
    for(int testCase = 0;testCase < t;testCase++)
    {
        int n,m;
        cin >> n >> m;
        vector<int> a(n,0);
        for(int i = 0;i < n;i++)
        {
            cin >> a[i];
        }
        bool canDo = true;
        for (int i = 0; i < n-1; i++)
        {
            if(a[i]%(a[i+1]) != 0) {
                canDo = false; break; }
        }
        if(!canDo)
        {
            cout << 0 << endl;
            continue;
        }
        //else

        //notice that for each bi, it must be a multiple of ai, obviously
        //since gcd(ai-1,bi) = ai, therefore assume bi = k*ai;
        //how many ways of choosing such a k?
        //if we just multiply everything with the ways of choosing a k we would overshoot
        //the correct answer since sometimes with a particular k, the gcd would change
        //therefore we must skip some multiples of certain numbers
        //to avoid getting a higher gcd
        //notice that gcd(a[i-1],k*a[i]) = a[i];
        //therefore a[i-1] must not have a factor of k, after dividing by a[i],
        //or conversely a[i-1]/a[i] and b[i]/a[i] must be coprime numbers
        //for each number we can calculate this division

        int cnt = 1; vector<int> b(n,0); b[0] = a[0];
        vector<int> consDivision(n,0); //consecutiveDivision
        for (int i = 1; i < n; i++)
        {
            consDivision[i] = a[i-1]/a[i]; 
        }
        //now we can find factors of this consecitiveDivision term, 
        //and remove them using a sieve method, 
        //BuTTt that would take O(m) time
        //would inclusion exclusion be better? m can go to 10^, hence only 9 factors maximum per number
        //moreover a1 can have 9 factors, but the rest of them, being numbers that divide a1, 
        //might have lesser too, and only from a1's prime factors, so problem becomes easier
        //time for primefactorisation of all of them

        //first O(sqrt(m)) factorisation for a1
        vector<pint> a =  primeFactorisationNormal(a[0]); //stores both powers and factors
        //now similarly find prime factors for the rest of the numbers

        
    }
 
}