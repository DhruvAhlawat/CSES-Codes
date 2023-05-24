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
signed main()
{
    FASTINOUT;
    int n,m; cin >> n >> m;
    vector<vector<pint>> flight(n);
    for (int i = 0; i < m; i++)
    {
        int a,b,c; cin >> a >> b >> c;
        flight[a-1].push_back({b-1,c}); // {destination,price}
    }
    //gotta find minimum price path from syrjala to Metsala (0 to n-1).
    //important thing to note is that Djikstra's algorithm cannot be applied straightaway here
    //due to the discount coupon.

    //what is Djikstra's algorithm. We start at the source node, and we keep on updating the minimum distance
    //to each node from the source node. We do this by relaxing the edges. We relax the edges by checking if
    //the distance to the node from the source node is less than the distance to the node from the current node
    //plus the weight of the edge. If it is, then we update the distance to the node from the source node.

    //simply what I will do is hold a pair. a Pair that can hold both the actual min distance, and the discounted min distance.
    //then while calculating for the next node, I will check if the distance to the node from the source node is less than
    //the distance to the node from the current node plus the weight of the edge. If it is, then I will update the distance
    //to the node from the source node. If it is not, then I will check if the distance to the node from the source node

    vector<int> updated(n,0); // 0 means not updated, 1 means updated
    //each node will have a corresponding pair element to store the min distance and the min discounted distance
    //till it. This is essentially like dp but over graphs.
    vector<pint> dp(n,{1e18,1e18}); // {min distance, min discounted distance}
    priority_queue<pair<pint,int>,vector<pair<pint,int>>,greater<pair<pint,int>>> pq; //the greater ensures that it is a min heap.
    pq.push({{0,0},0}); //this is the original starting node.
    updated[0] = 1;
    while(pq.size() > 0)
    {
        int cur = pq.top().second;
        pint curVal = pq.top().first;
        pq.pop();
        if(updated[cur] == 0) continue; //we do not want to recheck this incase it hasn't even been updated.
        //now for all of its neighbours, we shall check 2 things. The discounted price AND the Original price.
        for (int i = 0; i < flight[cur].size(); i++)
        {
            int price = flight[cur][i].second;
            int dest = flight[cur][i].first;
            //now we shall check if the price is less than the original price.
            bool shouldPush = false;
            if(curVal.first + price < dp[dest].first)
            {
                //if it is, then we shall update the original price.
                dp[dest].first = curVal.first + price;
                //now we shall update the discounted price.
                //now we shall push this into the priority queue.
                shouldPush = true;
            }
            if(curVal.first + price/2 < dp[dest].second)
            {
                //if it is, then we shall update the discounted price.
                dp[dest].second = curVal.first + price/2;
                //now we shall push this into the priority queue.
                shouldPush = true;
            }
            if(curVal.second + price < dp[dest].second)
            {
                //essentially having used a discount coupon before is more worth it in this case.
                dp[dest].second = curVal.second + price;
                //now we shall push this into the priority queue.
                shouldPush = true;
            }
            if(shouldPush)
            {
                updated[dest] = 1;
                pq.push({dp[dest],dest});
            }  
        }
        updated[cur] = 0;

        


    }

    //at the end we would have the required value
    cout << dp[n-1].second << endl;
    
 
}