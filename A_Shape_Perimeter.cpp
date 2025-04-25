#include <bits/stdc++.h>
using namespace std;
void solve() 
{
    int n, m;
    cin >> n >> m;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; i++) 
    {
        cin >> x[i] >> y[i];
    }
    int ans =2*(accumulate(x.begin(), x.end(), 0) + m - x[0] + accumulate(y.begin(), y.end(), 0)+ m-y[0]);
    cout << ans << '\n';
}
int main() 
{
    int tc;
    cin >>tc;
    while(tc--) 
    {
        solve();
    }
}
int main ()
{
    int a,b;cin>>a>>b;
    int flex;
    int sum;
    accumulate(a.begin(),end());
}