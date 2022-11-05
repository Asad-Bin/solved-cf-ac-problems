// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#ifdef local
     #define debug(x) cerr << '{' << #x << " = " << (x) << '}' << "\n";
#else
    #define debug(x) // lol ojs
#endif


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, m;
	
	cin >> n >> m;
	vector<int> ara[n+1];
	for(int K = 0;  K< m; K++){
		int a, b;
		cin >> a >> b;
		ara[a].push_back(b);
		ara[b].push_back(a);
	}
	
	for(int K = 1; K <= n; K++) sort(ara[K].begin(), ara[K].end());
	
	for(int K = 1; K <= n; K++) {
		cout << (int )ara[K].size() << ' ' ;
		for(auto x:ara[K]) cout << x << ' ';
		cout << "\n";
	}
	
	return 0;
}





































