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

int charToInt(char c)
{
    return c - 'a';
}

signed main()
{
    FASTINOUT;
    int t;
    cin >> t;
    for(int testCase = 0;testCase < t;testCase++)
    {
        int q;
        cin >> q;
        vector<int> s(26,0);
        int sSize = 0;
        int lowestFilled = 26;
        vector<int> t(26,0);
        int tSize = 0;
        int highestFilled = -1;
        for (int i = 0; i < q; i++)
        {
            int d,k; cin >> d >> k;
            if(d == 1)
            {
                string a; cin >> a;
                //string linear check
                for (int i = 0; i < a.size(); i++)
                {
                    int j = charToInt(a[i]);
                    s[j] += k;
                    if(j < lowestFilled)
                        lowestFilled = j;
                }
                sSize += k*a.size();
            }
            else
            {
                string a; cin >> a;
                //string linear check
                for (int i = 0; i < a.size(); i++)
                {
                    int j = charToInt(a[i]);
                    t[j] += k;
                    if(j > highestFilled)
                        highestFilled = j;
                }
                tSize += k*a.size();
            }

            //now the comparing part
            //firstly, if
            //cout << lowestFilled << " " << highestFilled << " ";
            if(sSize == 0)
            {
                Yes();
                continue;
            }
            if(tSize == 0)
            {
                No();
                continue;
            }
            if(lowestFilled < highestFilled)
            {
                //then we can simply keep the smaller element at the start of a, and largest element at start of t
                Yes();
                continue;
            }
            else if(lowestFilled > highestFilled)
            {
                //anything you keep at the s's start, qould be greater than t's element
                //soooOOO Can't do
                No();
                continue;
            }
            else {
                //this is the tricky part
                //here lowest filled = highestFilled
                //important is to consider edge cases, they may be problematic
                //simply, we form the lowest possible string of a, and similarly highest possible string of b
                //or eh just hypothesize and submit multiple, who cares its unrated
                if(s[lowestFilled] == sSize)
                {
                    if(sSize < t[highestFilled])
                    {
                        Yes();
                    }
                    else
                    {
                        No();
                    }
                }
                else
                {
                    No();
                }
            }
        }
        
    }
 
}