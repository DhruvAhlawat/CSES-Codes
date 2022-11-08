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
inline void getQuery(int i,string &s)
{
    cout << "? 1 " << i+1 << endl; //flushes automatically
    cin >> s[i];
}
inline int getDistinct(int l,int r)
{
    cout << "? 2 " << l+1 << " " << r+1 << endl;
    int ans = 0;
    cin >> ans;
    return ans;
}
signed main()
{
    FASTINOUT;
    int n;
    cin >> n;
    //I like such interactive problems
    vector<int> latestChar(26,-1);
    string s(n,'a');
    getQuery(0,s);
    //newChar.push_back(0); //0th index stores a new character, first appearance of it actually
    latestChar[s[0] - 'a'] = 0;
    int i = 1;
    int prevGetDistinct = 1;
    while(i < n)
    {
        int newDistinct = getDistinct(0,i);
        if(newDistinct == prevGetDistinct)
        {
            //its a number that has already appeared before
            //gotta binary search for it
            vector<int> toCheck;
            for (int i = 0; i < 26; i++)
            {
                if(latestChar[i] != -1)
                    toCheck.push_back(latestChar[i]);
            }//O(26) constant
            sort(all(toCheck));
            int l = 0,r = toCheck.size()-1;
            set<int> possible;
            while(l <= r)
            {
                int mid = (l+r)/2;
                int first = getDistinct(toCheck[mid],i); int second = getDistinct(toCheck[mid],i-1);
                if(first - second == 0) {
                    possible.insert(mid);
                    l = mid+1;
                }
                else if(first - second > 0)
                {
                    r = mid-1;
                }
                else
                {
                    l = mid+1;
                }
            }
            auto it = possible.end(); it--;
            s[i] = s[toCheck[max(*it,0ll)]];
            latestChar[s[i] - 'a'] = i; //updated the latest char, as well as the string
        }
        else
        {
            //else we have now a new number so we shall ask what it is
            getQuery(i,s);
            latestChar[s[i]-'a'] = i; //ith position now has a new character
        }
        prevGetDistinct = newDistinct;
        i++;
    }

    cout << "! " << s << endl;
}