#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N{}, X{};
    std::cin >> N >> X;

    bool answerAvailable{ false };
    map<int, int> nums{};

    for(int i{1}; i <= N; ++i) {
        int num{};
        cin >> num;
        
        if(nums.count(X - num) == 1) {
            answerAvailable = true;
            std::cout << nums[X - num] << ' ' << i << '\n';
            break;
        }
        nums[num] = i;
    }

    if (!answerAvailable) 
        std::cout << "IMPOSSIBLE";
 
    return 0;
}