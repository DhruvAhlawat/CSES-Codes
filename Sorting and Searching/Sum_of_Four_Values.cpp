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
    cout << "IMPOSSIBLE" << endl;
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
bool comparingPairs(pint A,pint B)
{
    int s1 = A.first + A.second;
    int s2 = B.first + B.second;
    return s1 < s2;
}
signed main()
{
    FASTINOUT;
    int n,x;
    cin >> n >> x;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int temp; //we can also simply delete elements which appear more than once
        cin >> temp; a.push_back(temp);
    }
    //now make sum of all possible pairs
    set<int> pairSums;
    map<int,vector<pint>> nums; 
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            int s = a[i] + a[j];
            pairSums.insert(s);
            if(nums.count(s) == 0)
            {
                nums.insert({s,{{i,j}}});
            }
            else
            {
                nums[s].push_back({i,j});
            }
        }
    }
    //now we have this set which we can convert to a vector for easy accessing
    vector<int> sumsVector(all(pairSums));
    //printVectorArray(sumsVector);
    if(sumsVector.size() == 1)
    {
        if(sumsVector[0]*2 == x)
        {
            cout << "1 2 3 4" << endl;
            return 0;
        }
        else
        {
            No();
        }
        return 0;
    }
    else if(sumsVector.size() == 2)
    {
        //only possible when there's only one different element among the rest of em
        

    }
    int l = 0,r = sumsVector.size() - 1;
    bool CanDo = false;
    int ans[4];
    while(l < r)
    {
        int curSum = sumsVector[l] + sumsVector[r];
        if(curSum == x)
        {
            //we have the required sum, now to just check if it is allowed
            for (int i = 0; i < nums[sumsVector[l]].size(); i++)
            {
                set<int> duplicates; 
                duplicates.insert(nums[sumsVector[l]][i].first); //stores the indices of the one making this sum
                duplicates.insert(nums[sumsVector[l]][i].second);
                for (int j = 0; j < nums[sumsVector[r]].size(); j++)
                {
                    if(duplicates.count(nums[sumsVector[r]][j].first) == 0)
                    {
                        if(duplicates.count(nums[sumsVector[r]][j].second) == 0)
                        {
                            CanDo = true;
                            //set the answers and break
                            ans[0] = nums[sumsVector[l]][i].first;
                            ans[1] = nums[sumsVector[l]][i].second;
                            ans[2] = nums[sumsVector[r]][j].first;
                            ans[3] = nums[sumsVector[r]][j].second;
                            //cout << "found sum of " << sumsVector[l] << " and " << sumsVector[r] << endl;
                            break;
                        }
                    }
                }
                if(CanDo)
                    break;
            }
            if(CanDo)
                break;
            //else
            r--;
            continue;
        }
        //otherwise we keep checking
        if(curSum > x)
        {
            r--;
        }
        else if(curSum < x)
        {
            l++;
        }
    }
    if(CanDo == false)
    {
        No();
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            cout << ans[i]+1 << " ";
        }
    }

    
}