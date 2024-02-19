#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums{1,3,-1,-3,5,3,6,7};
    int k{3};

    map<int, int> x{};
    vector<int> res{};
        for(int i{}; i < k; ++i)
            ++x[nums[i]];
        
        for(int i{}; i + k <= nums.size(); ++i) {
            res.push_back((--x.end())->first);

            if(nums[i + k])
                ++x[nums[i + k]];
            
            --x[nums[i]];
            if(x[nums[i]] <= 0)
                x.erase(nums[i]);
        }

        for(int x : res)
            cout << x << ' ';
        cout <<'\n';

    return 0;
}