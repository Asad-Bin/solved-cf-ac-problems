//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
 
#include <bits/stdc++.h>
 
using namespace std;
 
// typedefs...
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
 
// constants...
const double PI = acos(-1);
const int MOD = 1e9+7; // 998244353;
const int MXS = 2e5+5;
const int MXI = 1e9+5;
const ll MXL = 1e15+5;
 
// defines...
#define MP make_pair
#define PB push_back
#define fi first
#define se second
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define sl(a) scanf("%lld", &a)
#define sll(a, b) scanf("%lld%lld", &a, &b)
#define slll(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
 
// chess moves...
// int dx[] = {+0, +0, -1, +1}; ///Up-down, Left-Right
// int dy[] = {+1, -1, +0, +0};
// int dx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's Move
// int dy[] = {-1,+1,+0,+0,+1,+1,-1,-1};
// int dx[] = {-2, -2, -1, -1,  1,  1,  2,  2}; ///Knight's Move
// int dy[] = {-1,  1, -2,  2, -2,  2, -1,  1};
 
// structs...
struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 
 
// functions...
ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
ll lcm(ll a, ll b)
{
    return (a/gcd(a, b)*b);
}
ll comb(ll a, ll b)
{
    ll x = max(a-b, b), ans=1;
 
    for(ll K=a, L=1; K>=x+1; K--, L++){
        ans *= K;
        ans /= L;
    }
 
    return ans;
}


bool func(pair<pll, ll> a, pair<pll, ll> b)
{
	return a.fi.fi<b.fi.fi;
}
void task()
{
	// Code here...
	
	ll n, t, w, s, p;
	vector<pair<pll, ll> > ara;
	
	cin >> n >> w;
	
	for(int K=0; K<n; K++){
		cin >> s >> t >> p;
		ara.PB(MP(MP(s, 1), p));
		ara.PB(MP(MP(t, 0), p));
	}
	
	sort(all(ara), func);
	//for(int K=0; K<2*n; K++)
		//cout << ara[K].fi.fi << ' ' << ara[K].fi.se << ' ' << ara[K].se << "\n";
	
	ll cnt = 0;
	for(int K=0; K<2*n; K++){
		if(K<2*n-1 && ara[K].fi.fi!=ara[K+1].fi.fi){
			if(ara[K].fi.se) cnt += ara[K].se;
			else cnt -= ara[K].se;
			
			if(cnt>w){
				cout << "No\n";
				return;
			}
			continue;
		}
		
		if(ara[K].fi.se) cnt += ara[K].se;
		else cnt -= ara[K].se;
		//cout << ara[K].fi.fi << ' ' << cnt << "\n";
	}
	
	cout << "Yes\n";
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	
	task();
 
    return 0;
}
