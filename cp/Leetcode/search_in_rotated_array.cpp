#include <bits/stdc++.>
using namespace std;

int search(vector<int>& nums, int target) {
  int l{}, r{nums.size() - 1};

  while (l <= r) {
    int mid{l + (r - l) / 2};

    if(nums[mid] == target)
      return mid;
    else if(nums[mid] > target) {
      if(nums[r] < nums[mid] && nums[r] >= target)
        l = mid + 1;
      else {
        r = mid - 1;
      }
    }
    else {
      if(nums[r] > nums[mid] && nums[r] >= target)
        l = mid + 1;
      else {
        r = mid - 1;
      }
    }
  }

  return -1;
}

int main() {
  int n{};
  cin >> n >> target;

  vector<int> nums(n);

  for (size_t i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << search(nums, target) << '\n';

  return 0;
}
