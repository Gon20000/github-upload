#include <bits/stdc++.h>
using namespace std;

const int max_size{10001};
bool prime[max_size] = {true};

void build() {
    memset(prime, true, max_size);
    prime[0] = false;
    prime[1] = false;

    for (int i{2}; i <= sqrt(max_size); ++i) {
        if (!prime[i]) 
            continue;
        
        for (int j{i * i}; j < max_size; j += i) {
            prime[j] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (prime[0]) {
        build();
    }

    int start{}, end{};
    cin >> start >> end;

    for(; start <= end; ++start) {
        bool res{ true };
        for (int k{start}; k > 0; k /= 10) {
            if (!prime[k]) {
                res = false;
            }
        }

        if (res) 
            cout << start << '\n';
    }

    return 0;    
}