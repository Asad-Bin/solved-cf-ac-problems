// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#ifndef ONLINE_JUDGE
#define dbg_out cout
#define debug(...) dbg_out << "DBG )> "; __f(#__VA_ARGS__, __VA_ARGS__);
template<typename T1, typename T2> ostream& operator<<(ostream& out, pair<T1, T2> pr) { out << "{ " << pr.first << ", " << pr.second << " }"; return out; }
template<typename T1> ostream& operator<<(ostream& out, vector<T1> vec) { out << "{ "; for (auto &x: vec) out << x << ", "; out << "}"; return out; }
template<typename T1, size_t size> ostream& operator<<(ostream& out, array<T1, size> arr) { out << "{ "; for (auto &x: arr) out << x << ", "; out << "}"; return out; }
template<typename T1, typename T2> ostream& operator<<(ostream& out, map<T1, T2> mp) { out << "{ ";for (auto &x: mp) out << x.first << ": " << x.second <<  ", "; out << "}"; return out; }
template <typename Arg1> void __f(const char* name, Arg1&& arg1) { while (isspace(name[0])) name++; (isalpha(name[0]) || name[0] == '_') ? dbg_out << name << ": " << arg1 << "\n" : dbg_out << arg1 << "\n"; dbg_out.flush();}
template <typename Arg1, typename... Args> void __f (const char* names, Arg1&& arg1, Args&&... args) { const char *comma = strchr(names + 1, ','); while (isspace(names[0])) names++; (isalpha(names[0]) || names[0] == '_') ? dbg_out.write(names, comma - names) << ": " << arg1 << " | " : dbg_out << arg1 << " | "; __f(comma + 1, args...);}
#else
#define debug(...)
#endif

ll gcd(ll a, ll b){ while (b){ a %= b; swap(a, b);} return a;}
ll lcm(ll a, ll b){ return (a/gcd(a, b)*b);}
ll ncr(ll a, ll b){ ll x = max(a-b, b), ans=1; for(ll K=a, L=1; K>=x+1; K--, L++){ ans = ans * K; ans /= L;} return ans;}
ll bigmod(ll a,ll b,ll mod){ if(b==0){ return 1;} ll tm=bigmod(a,b/2,mod); tm=(tm*tm)%mod; if(b%2==1) tm=(tm*a)%mod; return tm;}
ll egcd(ll a,ll b,ll &x,ll &y){ if(a==0){ x=0; y=1; return b;} ll x1,y1; ll d=egcd(b%a,a,x1,y1); x=y1-(b/a)*x1; y=x1; return d;}
ll modpow(ll a,ll p,ll mod) {ll ans=1;while(p){if(p%2)ans=(ans*a)%mod;a=(a*a)%mod;p/=2;} return ans;}
ll inverse_mod(ll n,ll mod) {return modpow(n,mod-2,mod);}


vector<bool> mark(10005);
vector<int> primes;
void sieve(int n)
{
	primes.push_back(2);
	for(int K = 2; K <= n; K += 2) mark[K] = 1;
	
	for(int K = 3; K <= n; K += 2){
		if(!mark[K]){
			primes.push_back(K);
			for(int L = K*K; L <= n; L += K) mark[L] = 1;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	sieve(10000);
	
	int t; cin >> t;
	while(t--){
		ll a, b;
		cin>> a >> b;
		
		ll g = gcd(a, b);
		//if(a > b) swap(a, b);
		
		if(g > 1){
			cout << 0 << "\n";
		}
		else if(a%2==1 && b % 2 == 1){
			cout << 1 << "\n";
		}
		else if(a+1 == b || a == b+1){
			cout << -1 << "\n";
		}
		else{
			if(a > b){
				a %= b;
				swap(a, b);
			}
			ll d = b-a;
			ll ans = 1e9+7;
			
			for(int K = 0; K < (int)primes.size() && primes[K]*primes[K] <= d; K++){
				if(d % primes[K] == 0){
					while(d % primes[K] == 0){
						d /= primes[K];
					}
					
					ans = min(ans, ((a/primes[K])+1)*primes[K]-a);
				}
			}
			if(d > 1){
				ans = min(ans, ((a/d)+1)*d-a);
			}
			//for(ll K = 2; K*K <= d; K++){
				//if(d % K == 0){
					//d = K;
					
					//ans = min(ans, ((a/K)+1)*K-a);
					////break;
				//}
			//}
			//if(d >= a){
				//cout << d-a <<"\n";
			//}
			//else{
				cout << ans << "\n";
			//}
		}
	}
	
	return 0;
}





































