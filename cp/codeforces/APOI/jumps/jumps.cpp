#include <bits/stdc++.h>
// #include "grader.cpp"
#include "jumps.h"
using namespace std;
using ll = long long;

long long max_prize(vector<int>A){
	vector<ll> res(A.size());
  res[A.size() - 3] = A.back();
  for(int i{A.size() - 4}; i >= 0; --i) {
    res[i] = max(max((ll)A[i + 2], (ll)A[i + 3]), max(A[i + 2] + res[i + 2], A[i + 3] + res[i + 3]));
    if(res[i + 2] * 2 > res[i]) {
      res[i] = 2 * res[i + 2];
    }
    if(res[i + 3] * 3 > res[i]) {
      res[i] = res[i + 3] * 3;
    }
  }

	return res[0];
}
