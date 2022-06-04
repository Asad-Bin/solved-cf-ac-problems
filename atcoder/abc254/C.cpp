// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int n, k;
	
	cin >> n >> k;
	
	int ara[n];
	
	for(int K = 0; K < n; K++) cin >> ara[K];
	
	vector<int> v;
	for(int K = 0; K < k; K++){
		v.clear();
		for(int L = K; L < n; L += k){
			v.push_back(ara[L]);
		}
		sort(v.begin(), v.end());
		
		int i = 0;
		for(int L = K; L < n; L += k) ara[L] = v[i++];
	}
	
	bool ok = 1;
	
	for(int K = 0; K < n-1; K++) if(ara[K] > ara[K+1]) ok = 0;
	
	if(ok) cout << "Yes\n";
	else cout << "No\n";
	
	return 0;
}




















































