#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> a(m);
        for (int i = 0; i < m; ++i) {
            cin >> a[i];
        }

        vector<int> q(k);
        for (int i = 0; i < k; ++i) {
            cin >> q[i];
        }

        int unknown = n - k;

        if (unknown == 0) {
            cout << string(m, '1') << '\n';
        } else if (unknown == 1) {
            ll total = (ll)n * (n + 1) / 2;
            ll sum_q = accumulate(q.begin(), q.end(), 0LL);
            int x = total - sum_q;

            string res;
            for (int ai : a) {
                res.push_back(ai == x ? '1' : '0');
            }
            cout << res << '\n';
        } else {
            cout << string(m, '0') << '\n';
        }
    }

    return 0;
}