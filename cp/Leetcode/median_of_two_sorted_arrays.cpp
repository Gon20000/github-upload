#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{ 
  if(nums1.size() > nums2.size())
    swap(nums1, nums2);
  
  int parity{static_cast<int>(nums1.size() % 2 == nums2.size() % 2)};
  int median{(int)ceil((nums1.size() + nums2.size()) / 2.0) - 1};
  if (nums1.empty())
    swap(nums2, nums1);
  if (nums2.empty())
  {
    return parity == 0 ? nums1[median]
    : (nums1[median] + nums1[median + 1]) / 2.0;
  }

  auto getDist = [&](int idx) -> int
    {
      auto it{lower_bound(nums2.begin(), nums2.end(), nums1[idx])};
      int dist{idx + (int)distance(nums2.begin(), it)};

      if (dist < median && it != nums2.end() && *it == nums1[idx])
      {
        dist += max(
          0, (int)distance(it, upper_bound(nums2.begin(), nums2.end(),
                                           nums1[idx])));
        if (dist >= median)
          dist = median;
      }

      return dist;
    };

  int l{}, r{(int)nums1.size() - 1};
  pair<int, int> med{};
  while (l <= r)
  {
    int mid{l + (r - l) / 2};

    auto midIt{lower_bound(nums2.begin(), nums2.end(), nums1[mid])};
    int dist{getDist(mid)};

    if (dist < median)
    {
      if (mid < r)
      {
        int rDist{getDist(mid + 1)};
        if (abs(rDist - median) <= abs(dist - median))
          l = mid + 1;
      }
    }
    else if (mid > l)
    {
      int lDist{getDist(mid - 1)};
      if (abs(lDist - median) <= abs(dist - median))
        r = mid - 1;
    }

    if (l != mid + 1 && r != mid - 1)
    {
      med = {mid, dist - mid};
      break;
    }
  }

  int midIdx{med.first + med.second};
  int bIdx{med.second + median - midIdx};

  if(parity == 0) {
    if(midIdx == median)
      return nums1[med.first];

    // [3,3,3] [2,2,2,2]
    // cout << med.first << ' ' << med.second << '\n';
    return midIdx < median ? nums2[median - 1 - med.first] : nums2[bIdx];
  }

  // EVEN LENGTHED ARRAY 
  if(midIdx == median) {
    int second{INT_MAX};
    if(med.first + 1 < nums1.size())
      second = nums1[med.first + 1];
    if(med.second < nums2.size())
      second = min(second, nums2[med.second]);

    return (nums1[med.first] + second) / 2.0;
  }
  else if (midIdx < median) {
    int second{INT_MAX};
    if(med.first + 1 < nums1.size())
      second = nums1[med.first + 1];
    if(median - med.first < nums2.size())
      second = min(second, nums2[median - med.first]);

    return (nums2[median - 1 - med.first] + second) / 2.0;
  }

  return (bIdx + 1 < nums2.size() ? nums2[bIdx] + min(nums1[med.first], nums2[bIdx + 1]) : nums2[bIdx] + nums1[med.first]) / 2.0;
  
}

int main()
{
  int n{}, m{};
  cin >> n >> m;

  vector<int> a(n), b(m);
  for (size_t i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  for (size_t i = 0; i < m; i++)
  {
    cin >> b[i];
  }

  cout << findMedianSortedArrays(a, b) << '\n';
}

/*
[2,2,4,4]
[2,2,4,4]

[0,0]
[0,0]

[1,3]
[2]

[100001]
[100000]

[2,3,4]
[1]

[1,2]
[3,4]

[2]
[1,3,4,5]

[2,3,4,5,6]
[1]*/

