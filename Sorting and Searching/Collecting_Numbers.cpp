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
void Yes()
{
    cout << "YES" << endl;
}
void No()
{
    cout << "NO" << endl;
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
void FullSort(vector<int> &a)
{
    sort(a.begin(),a.end());
}
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
    int n,m;
    cin >> n >> m;
    vector<int> a(n,0);
    vector<pair<int,int>> stuff;
    vector<int> valueAt(n+1,0);
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
        stuff.push_back({a[i],i+1});
        valueAt[i+1] = a[i]-1; //position in the list stuff
    }
    sort(stuff.begin(),stuff.end());
    int count = 0;
    int i = 0;
    while(i < n-1)
    {
        if(stuff[i].second < stuff[i+1].second)
        {
            i++;
            continue;
        }
        count++;
        i++;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << stuff[i].first << " " << stuff[i].second << endl;
    // }
    //cout << count + 1 << endl;
    int initialCount = count+1;
    
    for (int query = 0; query < m; query++)
    {
        int a,b,offset = 0;
        cin >> a >> b;
        // if(a < b)
        // {
        //     int temp = b;
        //     b = a;
        //     a = temp;
        // }
        //exchange numbers at ath positon and mth position
        pint posa = stuff[valueAt[a]];
        pint posb = stuff[valueAt[b]];

        if(valueAt[a] + 1 == valueAt[b])
        {
           //then consider the behind case of a, the front case of b, and the inbetween case
           if(valueAt[a] != 0) //behind case of a
            {
                if(stuff[valueAt[a]-1].second < posa.second && stuff[valueAt[a]-1].second >= posb.second)
                {
                    //then we had not added but we should add
                    offset++;
                }
                else if(stuff[valueAt[a]-1].second >= posa.second && stuff[valueAt[a]-1].second < posb.second)
                {
                    //then we had added but we should NOT add
                    offset--;
                }
            }
            //the front case of b
            if(valueAt[b] != n-1) { //only then we can check for the next element
            if(posa.second < stuff[valueAt[b]+1].second && (posb.second >= stuff[valueAt[b]+1].second))
            {
                //then it wasn dded to count, but we should not add incase
                offset--; 
            }
            else if(posa.second >= stuff[valueAt[b]+1].second && (posb.second < stuff[valueAt[b]+1].second))
            {
                //then it was not added to count, but we should have added
                offset++; 
            }}

            //and the in between case
            if(posa.second > posb.second)
                offset--;
            else
                offset++;
            
            initialCount += offset; //count updated
            //also gotta update the list
            stuff[valueAt[a]].second = b;
            stuff[valueAt[b]].second = a;
            int temp = valueAt[a];
            valueAt[a] = valueAt[b];
            valueAt[b] = temp;
            cout << initialCount << endl;
            continue;
        }
        else if(valueAt[b] + 1 == valueAt[a])
        {
            if(valueAt[a] != n-1) { //only then we can check for the next element
            if(posa.second < stuff[valueAt[a]+1].second && (posb.second >= stuff[valueAt[a]+1].second))
            {
                //then it wasn't added to count, but we should add incase
                offset++; 
            }
            else if(posa.second >= stuff[valueAt[a]+1].second && (posb.second < stuff[valueAt[a]+1].second))
            {
                //then it was added to count, but we should not have added
                offset--; 
            }}

            if(valueAt[b] != 0)
            {
                if(stuff[valueAt[b]-1].second < posa.second && stuff[valueAt[b]-1].second >= posb.second)
                {
                    //then we had not added but we should add
                    offset--;
                }
                else if(stuff[valueAt[b]-1].second >= posa.second && stuff[valueAt[b]-1].second < posb.second)
                {
                    //then we had added but we should NOT add
                    offset++;
                }
            }

            if(posa.second > posb.second)
                offset++;
            else
                offset--;

            initialCount += offset; //count updated
            //also gotta update the list
            stuff[valueAt[a]].second = b;
            stuff[valueAt[b]].second = a;
            int temp = valueAt[a];
            valueAt[a] = valueAt[b];
            valueAt[b] = temp;
            cout << initialCount << endl;
            continue;
        }
        if(valueAt[a] != n-1) { //only then we can check for the next element
        if(posa.second < stuff[valueAt[a]+1].second && (posb.second >= stuff[valueAt[a]+1].second))
        {
            //then it wasn't added to count, but we should add incase
            offset++; 
        }
        else if(posa.second >= stuff[valueAt[a]+1].second && (posb.second < stuff[valueAt[a]+1].second))
        {
            //then it was added to count, but we should not have added
            offset--; 
        }}
        //then we check for its previous element
        if(valueAt[a] != 0)
        {
            if(stuff[valueAt[a]-1].second < posa.second && stuff[valueAt[a]-1].second >= posb.second)
            {
                //then we had not added but we should add
                offset++;
            }
            else if(stuff[valueAt[a]-1].second >= posa.second && stuff[valueAt[a]-1].second < posb.second)
            {
                //then we had added but we should NOT add
                offset--;
            }
        }
        //hence all changes in a's position have been accounted for
        //similarly for b
        if(valueAt[b] != n-1) { //only then we can check for the next element
        if(posa.second < stuff[valueAt[b]+1].second && (posb.second >= stuff[valueAt[b]+1].second))
        {
            //then it wasn dded to count, but we should not add incase
            offset--; 
        }
        else if(posa.second >= stuff[valueAt[b]+1].second && (posb.second < stuff[valueAt[b]+1].second))
        {
            //then it was not added to count, but we should have added
            offset++; 
        }}

        if(valueAt[b] != 0)
        {
            if(stuff[valueAt[b]-1].second < posa.second && stuff[valueAt[b]-1].second >= posb.second)
            {
                //then we had not added but we should add
                offset--;
            }
            else if(stuff[valueAt[b]-1].second >= posa.second && stuff[valueAt[b]-1].second < posb.second)
            {
                //then we had added but we should NOT add
                offset++;
            }
        }
        initialCount += offset; //count updated
        //also gotta update the list
        stuff[valueAt[a]].second = b;
        stuff[valueAt[b]].second = a;
        int temp = valueAt[a];
        valueAt[a] = valueAt[b];
        valueAt[b] = temp;
        cout << initialCount << endl;
    }
     
 
}