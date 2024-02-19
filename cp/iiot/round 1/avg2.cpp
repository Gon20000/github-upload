// NOTE: it is recommended to use this even if you don't understand the following code.
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N;
    long long K;
    ll sum{}, curr{};

    cin >> N >> K;

    vector<long long> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
        sum += P[i];
    }
    sort(P.begin(), P.end());

    curr = (sum - (N * K));
    ll res{};

    while (curr != 0) {
        ll sub{curr > 0
                   ? ceil(curr / static_cast<long double>(N))
                   : floor(curr / static_cast<long double>(N))};
        res += sub;
        
        for (int i{P.size() - N}; i < P.size(); ++i) {
            if (curr == 0 || abs(curr) < abs(sub)) {
                curr = 0;
                break;
            }

            if (P[i] > sub) {
                P[i] -= sub;
                curr -= sub;
            }
            else {
                curr -= P[i] - 1;
                P[i] = 1;
            }

            if (P[i] == 1)
                --N;
        }
    }

    cout << abs(res) << '\n';

    return 0;
}
