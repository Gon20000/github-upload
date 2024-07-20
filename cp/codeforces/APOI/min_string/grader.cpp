#include <bits/stdc++.h>
#include "min_string.h"
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N,K;
	cin>>N>>K;
	vector<string>S(N);
	for(int i=0;i<N;i++)cin>>S[i];
	cout<<min_string(N,K,S)<<"\n";
	return 0;
}