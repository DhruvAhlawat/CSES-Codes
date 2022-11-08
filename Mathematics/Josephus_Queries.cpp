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
        return (((binExpMod(n,(r/2),modulus))*(binExpMod(n,(r/2),modulus)))%modulus);
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

int kthToDie(int n,int k)
{
   //now we can consider 2 cases,
   if(2*k <= n)
   {
        //then simply the 2kth person dies
        return 2*k;
   }
   //else
   if(n%2 == 0)
   {
        //n is even so all the even people will die after the first n/2 rounds, then 
        //we can recursively call the function. the ith person's original position would be
        //2*i-1
        return kthToDie(n/2,k-(n/2))*2 - 1;
   }
   else
   {
        //here once we go through n/2 people, 1 will be deleted itself, and 3 would be the new starter
        //or we can just delete one element and increment the answer by 2
        int f = (kthToDie(n-1,k-1) + 2)%n;
        if(f == 0)
            return n;
        else
            return f;
   }

}

signed main()
{
    FASTINOUT;
    int t;
    cin >> t;
    for(int testCase = 0;testCase < t;testCase++)
    {
        int n,k;
        cin >> n >> k;
        //find the kth person to die, how to do this?????
        //first person to die is 2, after that there are n-1 people and we start from 3,
        //so the n,k is equal to ((n-1,k-1)+2)%n,hopefully
        //

        cout << kthToDie(n,k) << endl;

    }
 
}