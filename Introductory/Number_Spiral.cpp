#include<iostream>
#include<vector>
#include<cmath>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll x,y;
        cin >> y >> x;
        y--;x--; //using 0 indexing, so the starting cell is now 0,0 instead of 1,1
        ll ans = 0;
        bool colMax = (y > x)?false:true; //if column is greater than row
        if(colMax)
        {
            //if column is bigger, use method from columns
            if(x%2 == 0)
            {
                ans = (x+1)*(x+1) - y;
            }
            else
            {
                ans = x*x + 1 + y;
            }
        }
        else
        {
            if(y%2 == 0)
            {
                ans = y*y + 1 + x;
            }
            else
            {
                ans = (y+1)*(y+1) - x;
            }
        }
        cout << ans << endl;
    }
}