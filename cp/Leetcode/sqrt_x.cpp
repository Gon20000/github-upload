using ll = long long;
class Solution {
public:
    int mySqrt(int x) {
        ll l{}, r{ll(1 << 16)};

        while (l < r) {
            ll mid{l + (r - l) / 2};

            if (mid * mid < x) {
                l = mid + 1;
            } else if (mid * mid >= x) {
                r = mid - 1;
            }
        }

        return l;
    }
};
