#include<bits/stdc++.h>
using namespace std;

int solve(string s) {
    int ans = 0;
    int n = s.length();
    
    for (int i = 0; i < n; ++i) 
    {
        if (s[i] == '1') 
        {
            ans++;
            while (i < n && s[i] == '1') 
            {
                i++;
            }
        }
    }
    return ans;
}

int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        int result=solve(s);
        cout <<result<< endl;
    }
    
    return 0;
}
