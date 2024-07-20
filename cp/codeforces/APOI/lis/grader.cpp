#include <bits/stdc++.h>
#include "lis.h"
using namespace std;

static int n;
static vector<int> sequence;

static long long num_queries = 0;
static long long max_queries = 0;
static int error_flag = 0;

static int lis(const vector<int> &p){
	vector<int> v;
	for(int x: p){
		auto it = lower_bound(v.begin(), v.end(), x);
		if(it == v.end())v.push_back(x);
		else *it = x;
	}
	return v.size();
}
int get_lis_length(const vector<int> &permutation){
	num_queries++;
	max_queries = max(max_queries, num_queries);
	if(permutation.size() != n){
		cout << -1 << endl;
		exit(0);
	}

	vector<int> cnt(n);
	for(int i = 0; i < n; ++i){
		if(permutation[i] < 0 || permutation[i] >= n){
			cout << -2 << endl;
			exit(0);
		}
		++cnt[permutation[i]];
		if(cnt[permutation[i]] >= 2){
			cout << -3 << endl;
			exit(0);
		}
	}

	vector<int> new_seq(n);
	for(int i = 0; i < n; ++i)
		new_seq[i] = sequence[permutation[i]];
	return lis(new_seq);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int correct = true;
	int t;
	cin >> t;

	while(t--){
		num_queries = 0;

		cin >> n;
		sequence.resize(n);
		for(int i = 0; i < n; ++i){
			cin >> sequence[i];
		}

		int position = find_maximum(n);
		correct &= sequence[position] == n - 1;
	}

	if(error_flag){
		cout << "WA : ";
		if(error_flag == -1)cout << "The size of the sent vector is not equal to n" << endl;
		if(error_flag == -2)cout << "The vector sent is not a permutation, it contains a number that is not in the range [0,n-1]" << endl;
		if(error_flag == -3)cout << "The vector sent is not a permutation, it contains duplicates" << endl;
		
		return 0;
	}
	if(!correct){
		cout << "WA : Incorrect guess" << endl;
		return 0;
	}
	cout << "OK : " << max_queries << " calls made." << endl;
}
