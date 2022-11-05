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
	
	int n; cin >> n;
	
	int ara[n];
	for(int K = 0; K < n; K++) cin >>  ara[K];
	
	for(int K = n-1; K > 0; K--){
		if(ara[K] < ara[K-1]){
			int idx = -1, mx = 0;
			for(int L = K; L < n; L++){
				if(ara[L] < ara[K-1]) {
					if(ara[L] > mx){
						mx = ara[L];
						idx = L;
					}
				}
			}
			
			swap(ara[K-1], ara[idx]);
			
			sort(ara+K, ara+n);
			reverse(ara+K, ara+n);
			
			break;
		}
	}
	
	for(int K = 0; K < n; K++) cout << ara[K] << ' ' ;
	cout << "\n";
	
	return 0;
}
 
 
 
 
 
 
 
 
