#include <bits/stdc++.h>

int main() {
    int N{};
    std::cin >> N;
    int x[N];
    int y[N];
    for(int i{}; i < N; ++i) 
        scanf("%d", &x[i]);
    for(int i{}; i < N; ++i) 
        scanf("%d", &y[i]);

    int max{};

    for(int i{}; i < N; ++i) {
        for(int j{i + 1}; j < N; ++j) {
            int xs{x[i] - x[j]};
            int ys{y[i] - y[j]};
            max = std::max(max, xs*xs + ys*ys);
        }
    }

    printf("%d", max);
}