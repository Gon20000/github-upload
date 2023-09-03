#include <bits/stdc++.h>
using namespace std;

int main() {
    int N{}, X{}, res{};
    scanf("%d %d\n", &N, &X);
    int times[N];
    for(int& x : times) 
        cin >> x;
    sort(times, times + N);
    for(; res < N; ++res) {
        if(times[res] > X)
            break;
        X -= times[res];
    }

    printf("%d\n", res);

    return 0;
}