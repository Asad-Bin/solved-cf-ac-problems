// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int n;
	cin >> n;
	int ara[n+1][n+1];
	
	for(int K = 1; K <= n; K++){
		for(int L = 1; L <= K; L++){
			if(L == 1 || L == K) ara[K][L] = 1;
			else ara[K][L] = ara[K-1][L-1] + ara[K-1][L];
		}
	}
	
	for(int K = 1; K <= n; K++){
		for(int L = 1; L <= K; L++) cout << ara[K][L] << ' ';
		cout << "\n";
	}
	
	return 0;
}




















































