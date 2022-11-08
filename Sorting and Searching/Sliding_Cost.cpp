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
signed main()
{
    FASTINOUT;
    int n,k;
    cin >> n >> k;
    vector<int> a(n,0);
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    
    // int upCost = 0,downCost=0,sameNumber = 0;
    int sum = 0;
    multiset<int> windowElements;
    for (int i = 0; i < k; i++)
    {
        sum += a[i];
    //    windowElements.insert(a[i]);
    }
    int sameNumber = (sum%k > k/2)?(sum/k + 1):sum/k;
    // for (int i = 0; i < k; i++)
    // {
    //     if(a[i] > sameNumber)
    //     {
    //         upCost += a[i] - sameNumber;
    //     }
    //     else
    //     {
    //         downCost += sameNumber - a[i];
    //     }
    // }
    // vector<int> ans(n,0);
    
    // ans[0] = upCost + downCost;
    // printVectorArray(ans);
    // for (int i = 0; i < n-k; i++)
    // {
    //     //now we discard a[i] and add a[i+k] to the window.
    //     //gotta compute the new average
    //     sum += a[i+k] - a[i];
    //     int newSameNumber = (sum%k > k/2)?(sum/k + 1):sum/k;

    //     //first we discard the costs due to a[i]
    //     if(a[i] >= sameNumber)
    //             upCost -= a[i] - sameNumber;
    //         else
    //             downCost -= sameNumber - a[i];
    //     //and then we add the costs due to a[i+k]
    //     if(a[i+k] >= sameNumber)
    //             upCost += a[i+k] - sameNumber;
    //         else
    //             downCost += sameNumber - a[i+k];
    //     //then we consider the rest of the costs
    //     if(newSameNumber > sameNumber)
    //     {
    //         //we need to first check how many numbers now went above or below 

    //     }
    // }
    int cost = 0;
    for (int i = 0; i < k; i++)
    {
        cost += abs(a[i] - sameNumber);
    }
    cout << cost << " ";
    for (int i = 0; i < n-k; i++)
    {
        sum += a[i+k] - a[i];
        int newSameNumber = (sum%k > k/2)?(sum/k + 1):sum/k;
        cost += abs(a[i+k]-newSameNumber) - abs(a[i] - sameNumber);
        sameNumber = newSameNumber;
        cout << cost << " ";
    }
    
    
 
}