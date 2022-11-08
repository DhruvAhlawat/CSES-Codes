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

#define MOD 1000000007
#define FASTINOUT cin.tie(0); ios::sync_with_stdio(false);
ll BINARY_SEARCH(vector<ll> dp , ll n , ll key) {
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
void printVectorArray(vector<int> a)
{
    for(int i = 0;i < a.size();i++)
    {
        cout << a[i] << " "; 
    }
    cout << "\n";
}
/* void printVectorArray(vector<ll> a)
{
    for(int i = 0;i < a.size();i++)
    {
        cout << a[i] << " "; 
    }
    cout << "\n";
} */
void printVectorGrid(vector<vector<ll>> a)
{
    for(int j = 0;j < a.size();j++) {
        for(int i = 0;i < a[i].size();i++)
        {
            cout << a[j][i] << " "; 
        }
        cout << "\n";
    }
}
signed main()
{
    FASTINOUT;
    int n;
    cin >> n;
    set<int> UsefulDays;
    vector<tuple<int,int,int>> projects;
    for (int i = 0; i < n; i++)
    {
        int a,b,x;
        cin >> a >> b >> x;
        UsefulDays.insert(a);
        UsefulDays.insert(b);
        projects.push_back(make_tuple(a,b,x));
    }
    sort(projects.begin(),projects.end());
    vector<int> dp(UsefulDays.size(),0);
    for (int i = 0; i < n; i++)
    {
        //now we gotta check for each project, make it the max only if the previous day's 
        int a,b,x;
        tie(a,b,x) = projects[i];
        //now we can find location of a in the useful days, and check for a-1.
        auto ita = UsefulDays.find(a); //finds the location of the a in the set
        auto itb = UsefulDays.find(b);
        int indexa = distance(UsefulDays.begin(),ita);
        int indexb = distance(UsefulDays.begin(),itb);
        int j = 1;
        if(indexa == 0)
        {
            dp[indexb] = max(x,dp[indexb]);
            continue;
        }
        // while(dp[indexa - j] == 0)
        // {
        //     if(indexa - j == 0)
        //     {
        //         break;
        //     }
        //     j++;
        // }
        
        
        // int prevMax = *max(dp.begin(),dp.begin() + indexa);
        //dp[indexa-1] = prevMax;
        int cur = max(dp[indexa-1] + x,dp[indexb]);
        for (int k = indexb; k < UsefulDays.size(); k++)
        {
            dp[k] = cur; //sets the indexb'th day to the max of not taking the ith project, and taking the ith project
        }
        
        
    }
    cout << dp[UsefulDays.size()-1] << endl;
    // printVectorArray(dp);
    // for(auto k: UsefulDays)
    // {
    //     cout << k << " ";
    // }
}