using ll = long long;

class Solution {
  public:
    bool isPerfectSquare(int num) {
      ll l{}, r{ll(1 << 16)};

      while(l <= r) {
        ll mid{l + (r-l) / 2};

        if(mid * mid < num) {
          l = mid + 1;
        }
        else if(mid * mid > num) {
          r = mid - 1;
        }
        else {
          return true;
        }
      }
      return false;
    }
};
