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


const int inf = 1e9+7;
const int N = 2e5;
int ara[N+5], mn[4*N+5], mx[4*N+5]; //tree is 1-indexed


void update(int at, int l, int r, int idx, int val)
{
	if(l == r){
		mx[at] = idx-val;
		mn[at] = idx+val;
		
		return;
	}
	
	int mid = (l + r)/2;
	
	if(idx <= mid) update(at*2, l, mid, idx, val);
	else update(at*2+1, mid+1, r, idx, val);
	
	mx[at] = min(mx[at*2], mx[at*2+1]);
	mn[at] = max(mn[at*2], mn[at*2+1]);
}
int query_mx(int at, int l, int r, int L, int R)
{
	if(r < L || R < l) return inf;
	if(L <= l && r <= R) return mx[at];
	
	int mid = (l + r)/2;
	
	int x = query_mx(at*2, l, mid, L, R);
	int y = query_mx(at*2+1, mid+1, r, L, R);
	
	return min(x, y);
}
int query_mn(int at, int l, int r, int L, int R)
{
	if(r < L || R < l) return 0;
	if(L <= l && r <= R) return mn[at];
	
	int mid = (l + r)/2;
	
	int x = query_mn(at*2, l, mid, L, R);
	int y = query_mn(at*2+1, mid+1, r, L, R);
	
	return max(x, y);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	
	int n; cin  >> n;
	
	for(int K = 1; K <= n; K++) cin >> ara[K];
	
	for(int K = 0; K <= 4*N; K++) mx[K] = inf;
	
	int ans[n+1];
	map<pair<int, int>, int> sm, bg;
	
	ans[1] = inf;
	//sm[{ara[1], ara[1]-1}]++;
	//bg[{ara[1], ara[1]+1}]++;
	update(1, 1, n, ara[1], 1);
	
	for(int K = 2; K <= n; K++){
		ans[K] = inf;
		
		// bigger value
		int mid = query_mx(1, 1, n, ara[K]+1, n);
		if(mid != inf) ans[K] = min(ans[K], K-ara[K] + mid);
		
		// smaller value
		mid = query_mn(1, 1, n, 1, ara[K]-1);
		if(mid != 0) ans[K] = min(ans[K], ara[K]+K - mid);
		
		//sm[{ara[K], ara[K]-K}]++;
		//bg[{ara[K], ara[K]+K}]++;
		update(1, 1, n, ara[K], K);
	}
	
	reverse(ara+1, ara+n+1);
	reverse(ans+1, ans+n+1);
	//sm.clear();
	//bg.clear();
	
	//for(int K = 1; K <= n; K++) cout << ans[K] << " ";
	//cout << "\n";
	
	for(int K = 0; K <= 4*N; K++) mx[K] = inf;
	memset(mn, 0, sizeof mn);
	
	update(1, 1, n, ara[1], 1);
	
	for(int K = 2; K <= n; K++){
		//ans[K] = inf;
		
		// bigger value
		int mid = query_mx(1, 1, n, ara[K]+1, n);
		if(mid != inf) ans[K] = min(ans[K], K-ara[K] + mid);
		
		// smaller value
		mid = query_mn(1, 1, n, 1, ara[K]-1);
		if(mid != 0) ans[K] = min(ans[K], ara[K]+K - mid);
		
		//sm[{ara[K], ara[K]-K}]++;
		//bg[{ara[K], ara[K]+K}]++;
		update(1, 1, n, ara[K], K);
	}
	
	//sm[{ara[1], ara[1]-1}]++;
	//bg[{ara[1], ara[1]+1}]++;
	
	//for(int K = 2; K <= n; K++){
		//auto it = sm.lower_bound({ara[K], K});
		//if(it != sm.end()) ans[K] = min(ans[K], K-ara[K] + it->first.second);
		//if(ara[K] > bg.begin()->first.first) ans[K] = min(ans[K], ara[K]+K - bg.begin()->first.second);
		
		//sm[{ara[K], ara[K]-K}]++;
		//bg[{ara[K], ara[K]+K}]++;
	//}
	
	
	reverse(ans+1, ans+n+1);
	for(int K = 1; K <= n; K++) cout << ans[K] << " ";
	cout << "\n";
	
	return 0;
}










































