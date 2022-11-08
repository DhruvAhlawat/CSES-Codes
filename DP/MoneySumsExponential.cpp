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
#define int long long // for huge inputs,outputs, can be removed for space
using namespace std;

#define MOD 1000000007
#define FASTINOUT cin.tie(0); ios::sync_with_stdio(false);
ll BINARY_SEARCH(ll dp[] , ll n , ll key) {
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
set<int> valuesPossible;
vector<int> coins;
vector<vector<bool>> done;
int posval(int n,int curval)
{
    if(n <= 0)
    {
        return curval;
    }
    else if(done[n][curval] == true)
    {
        return curval;
    }
    else{
        valuesPossible.insert(curval+coins[n-1]);
        valuesPossible.insert(curval); //not taking the nth coin.
        
        //valuesPossible.insert(posval(n-1,curval+coins[n-1]));
        //valuesPossible.insert(posval(n-1,curval));
        posval(n-1,curval);
        posval(n-1,curval+coins[n-1]);
        done[n][curval] = true;
    }
    return curval;
}

signed main()
{
    FASTINOUT;
    int n;
    cin >> n;
    int sum = 0;
    for(int i = 0;i < n;i++)
    {
        int temp;
        cin>>temp;
        coins.push_back(temp);
        sum += temp;
    }

    vector<bool> temp(n+1,false);
    vector<vector<bool>> a(sum+1,temp);

    done = a;
    posval(n,0);
    //set<int> valuesPossible;
    cout << valuesPossible.size()-1 << endl;
    // auto it = valuesPossible.begin();
    // it++;
    
    // while(it != valuesPossible.end())
    // {
    //     cout << *it << " ";
    //     it++;
    // }
 
}