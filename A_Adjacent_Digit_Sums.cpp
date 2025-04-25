#include<bits/stdc++.h>
using namespace std;
int main() 
{
    int tc;
    cin >> tc;
    while (tc--) 
    {
        int a,b;
        cin >>a>>b;
        int ans=a-b;
        int res= ans+ 1;
        if (res>= 0 && res% 9 == 0) 
        {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}