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
#define endl "\n"
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
signed main()
{
    FASTINOUT;
    int t;
    cin >> t;
    for(int testCase = 0;testCase < t;testCase++)
    {
        int n; cin >> n; string s; cin >> s;
        vector<vector<int>> freq(26);
        vector<pint> indFreq;
        set<int> diff;
        for (int i = 0; i < n; i++)
        {
            freq[s[i]-'a'].push_back(i);
        }

        for (int i = 0; i < 26; i++)
        {
            indFreq.push_back({freq[i].size(),i});
            if(freq[i].size() != 0)
            diff.insert(freq[i].size());
        }
        if(diff.size() == 1)
        {
            cout << 0 << endl << s << endl;
            continue;
        }
        sort(all(indFreq), greater<pint>());
        //now the freq array is complete
        //the frequency should be a factor of n, that much is obvious
        // vector<pint> Primefactors = primeFactorisationNormal(n);
        // //although we can have any factors instead of just prime factors
        // for (int i = 0; i < Primefactors.size(); i++)
        // {
        //     cout << Primefactors[i].first << " ";
        // }
        // cout << endl;
        //why not just check for each letter
        //first off, to make each the same we have
        int eachSame = MOD;
        for (int i = 0; i < 26; i++)
        {
            eachSame = min(n-(long long)freq[i].size(), eachSame);
        }
        if(eachSame == 0)
        {
            cout << 0 << endl << s << endl; continue;
        }
        //perhaps we should keep minCost as this one instead
        int balance = 0;
        int minPoint = 1; int minCost = MOD;
        for (int i = 1; i <= n/2; i++)
        {
            //make all of them have this many stuff
            //calculate the cost
            if(n%i != 0)
                continue;
            if((n/i) > 26)  continue;
            int curCost = 0;
            for (int j = 0; j < 26; j++)
            {
                int curAlph = indFreq[j].second;
                // if(indFreq[j].first == 0 && balance == 0)
                // {
                //     break; //since we are done
                // }
                //else we must
                if(j >= (n/i))
                {
                    //then its a separate matter, we must reduce these ones to 0
                    curCost += indFreq[j].first;
                    balance -= indFreq[j].first; //reducing the balance
                    continue;
                }
                if(indFreq[j].first > i)
                {
                    balance += indFreq[j].first - i; curCost += indFreq[j].first - i;
                }
                else if(indFreq[j].first < i)
                {
                    balance += indFreq[j].first - i;
                }
            }
            //cout << curCost << " " << i << endl;
            if(minCost > curCost)
            {
                minCost = curCost; minPoint = i;
            }
            balance = 0;
        }
        if(minCost >= eachSame)
        {
            cout << eachSame << endl;
            cout << string(n,'a' + indFreq[0].second) << endl;
            continue;
        }
        else
        {
            //at the minPoint
            balance = 0;
            vector<int> removalPositions;
            for (int i = n/minPoint; i < 26; i++)
            {
                if(indFreq[i].first == 0) continue; //or break perhaps;
                for (int j = 0; j < freq[indFreq[i].second].size(); j++)
                {
                    removalPositions.push_back(freq[indFreq[i].second][j]);
                    balance++;
                }
            }
            for (int i = 0; i < n/minPoint; i++)
            {
                if(indFreq[i].first > minPoint)
                {
                    balance += indFreq[i].first - minPoint;
                    for (int j = 0; j < freq[indFreq[i].second].size() - minPoint; j++)
                    {
                        removalPositions.push_back(freq[indFreq[i].second][j]);
                    }
                }
                else if(indFreq[i].first < minPoint)
                {
                    //then we insert the places here
                    int fs = removalPositions.size();
                    int k = fs + (indFreq[i].first - minPoint);
                    for (int j = fs - 1; j >= k; j--)
                    {
                        s[removalPositions[j]] = (char)('a' + indFreq[i].second); //nice
                        balance--;
                        removalPositions.pop_back();
                    }
                }
            }
            cout << minCost << endl;
            cout << s << endl; 
        }
    }
 
}