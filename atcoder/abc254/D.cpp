// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


	
const int MX = 2e5;
long long ara[MX+5];
	
vector<bool> mark(MX+5);
vector<long long> primes;
void sieve(int n)
{
	mark[1] = 1;
	primes.push_back(2);
	
	for(int K = 4; K <= n; K += 2) mark[K] = 1;
	
	for(int K = 3; K <= n; K += 2){
		if(!mark[K]){
			primes.push_back(K);
			
			for(long long L = (long long)K*K; L <= n; L += K){
				mark[L] = 1;
			}
		}
	}
}
map<int, int> mp;
void calc(int at, long long y, long long n)
{
	if(mp[y]) return;
	mp[y]++;
	ara[y]++;
		
	for(int K = at; K < (int)primes.size() && y*primes[K]*primes[K] <= n; K++){
		calc(at, y*primes[K]*primes[K], n);
		calc(at+1, y*primes[K]*primes[K], n);
	}
}
int main()
{
	int n;
	sieve(MX+1);
	
	cin >> n;
	
	memset(ara, 0LL, sizeof ara);
	
	for(long long K = 1; K <= n; K++){
		long long x = K, y = 1;
		
		for(int L = 0; L < (int)primes.size() && primes[L]*primes[L] <= x; L++){
			if(x % primes[L] == 0){
				int cnt = 0;
				while(x % primes[L] == 0){
					x /= primes[L];
					cnt++;
				}
				
				if(cnt%2==1) y *= primes[L];
			}
		}
		if(x > 1) y *= x;
		
		//ara[K]++;
		
		if(y > n) continue;
		
		//ara[K]++;
		//cout << K << ' ' << y << "\n";
		
		mp.clear();
		calc(0, y, n);
	}
	
	long long ans = 0;
	for(int K = 1; K <= n; K++) ans += ara[K];
	
	cout << ans << "\n";
	
	return 0;
}




















































