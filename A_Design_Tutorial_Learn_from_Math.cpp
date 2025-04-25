#include<bits/stdc++.h>
using namespace std;
bool isComposite(int num) 
{
    if (num <= 1) return false;
    if (num <= 3) return false; 
    if (num % 2 == 0 || num % 3 == 0) return true;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return true;
    }
    return false;
}


pair<int, int> findCompositesSum(int n) {
    for (int x = n-1; x >= 4; --x) {
        if (isComposite(x) && isComposite(n - x)) {
            return {x, n - x};
        }
    }
    return {-1, -1}; 
}

int main() {
    int n;
    cin >> n;
    
    pair<int, int> result = findCompositesSum(n);
    
    cout << result.first << " " << result.second << endl;
    
    return 0;
}
