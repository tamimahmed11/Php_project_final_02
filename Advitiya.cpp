#include<bits/stdc++.h>
using namespace std;
int solve(string s) 
{
    string str = "ADVITIYA";
    int intial= 0;
    int n = s.length();
    for (int i = 0; i < n; ++i) 
    {
        char cnt =s[i];
        char final=str[i];
        int dif = (final - cnt + 26) % 26;
        intial=intial+ dif;
    }
    return intial;
}

int main() 
{
    int tc;
    cin >>tc;
    while (tc--) 
    {
        string s;
        cin >>s;
        int ans =solve(s);
        cout <<ans<<"\n";
    }
    return 0;
}
