#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#include "jumps.h"
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin>>N;
	vector<int>A(N);
	for(int&x:A)cin>>x;
	cout<<max_prize(A)<<endl;
}
