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
	
	for(int K = 0; K < n; K++) cin >> ara[K] ;
	
	int two[n], three[n];
	for(int K = 0; K < n; K++){
		int cnt = 0;
		while(ara[K]%2==0){
			ara[K]/= 2;
			cnt++;
		}
		two[K] = cnt;
		
		cnt = 0;
		while(ara[K]%3==0){
			ara[K]/= 3;
			cnt++;
		}
		three[K] = cnt;
	}
	
	sort(two, two+n);
	sort(three, three+n);
	
	int ans = 0;
	for(int K = 1; K < n; K++) ans += two[K]-two[0] + three[K]-three[0];
	
	for(int K = 0; K < n-1; K++) {
		if(ara[K] != ara[K+1]) {
			cout << -1 << "\n";
			return 0;
		}
	}
	
	cout << ans << "\n";
	
	
	return 0;
}
 
 
 
 
 
 
 
 
