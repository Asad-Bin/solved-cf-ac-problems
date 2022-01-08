// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<long long>
#define PB push_back
#define sz(x) (int)x.size()
#define fi first
#define se second
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define sl(a) scanf("%lld", &a)
#define sll(a, b) scanf("%lld%lld", &a, &b)
#define slll(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)
//#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef LOCAL
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

struct ordered_multiset { // multiset supporting duplicating values in set
	ll len = 0;
	const ll ADD = 1000010;
	const ll MAXVAL = 1000000010;
	unordered_map<ll, ll> mp; // hash = 96814
	tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> T;

	ordered_multiset() { len = 0; T.clear(), mp.clear(); }

	inline void insert(ll x){
		len++, x += MAXVAL;
		ll c = mp[x]++;
		T.insert((x * ADD) + c); }

	inline void erase(ll x){
		x += MAXVAL;
		ll c = mp[x];
		if(c) {
			c--, mp[x]--, len--;
			T.erase((x*ADD) + c); } }

	inline ll kth(ll k){        // 1-based index,  returns the
		if(k<1 || k>len) return -1;     // K'th element in the treap,
		auto it = T.find_by_order(--k); // -1 if none exists
		return ((*it)/ADD) - MAXVAL; } 

	inline ll lower_bound(ll x){      // Count of value <x in treap
		x += MAXVAL;
		ll c = mp[x];
		return (T.order_of_key((x*ADD)+c)); } 

	inline ll upper_bound(ll x){      // Count of value <=x in treap
		x += MAXVAL;
		ll c = mp[x];
		return (T.order_of_key((x*ADD)+c)); }

	inline ll size() { return len; }   // Number of elements in treap
};

int main()
{
	#ifdef LOCAL
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
	
    int n, k, x, ans;
    ordered_multiset ss;
    
    cin >> n >> k;
    
    ans = n+1;
    
    for(int K = 0; K < k; K++){
        cin >> x;
        ans = min(ans, x);
        ss.insert(x);
    }
    
    cout << ans << "\n";
    for(int K = k+1; K <= n; K++){
        cin >> x;
        
        ss.insert(x);
        cout << ss.kth(K+1-k) << "\n";
    }
	
    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}














































