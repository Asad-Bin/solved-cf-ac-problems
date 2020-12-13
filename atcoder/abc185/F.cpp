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
#define all(x) x.begin(), x.end()
 
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


int sum[1200001], num[1200001];
void build(int at, int L, int R)
{
	sum[at] = 0;
	
	if(L==R){
		// keeping the sum...
		// Or, maybe other queries...
		sum[at] = num[L];
		
		return;
	}
	
	int mid = (L+R)/2;
	build(at*2, L, mid);
	build(at*2+1, mid+1, R);
	
	// keeping the sum...
	// Or, maybe other queries...
	sum[at] = sum[at*2]^sum[at*2+1];
}
void update(int at, int L, int R, int pos, int u)
{
	if(L==R){
		sum[at]^=u;
		return;
	}
	
	int mid = (L+R)/2;
	
	// instead of if-else
	// we can use 
	// if(pos < L || R < pos) return;
	if(pos<=mid) update(at*2, L, mid, pos, u);
	else update(at*2+1, mid+1, R, pos, u);
	
	sum[at] = sum[at*2]^sum[at*2+1];
}
int query(int at, int L, int R, int l, int r)
{
	// query from l to r.
	if(r < L || l > R) return 0;
	if(l <= L && R <= r) return sum[at];
	
	int mid = (L+R)/2;
	int x = query(at*2, L, mid, l, r);
	int y = query(at*2+1, mid+1, R, l, r);
	
	return x^y;
}
void task()
{
	// Code here...
	
	int n, q, t, x, y;
	
	cin >> n >> q;
	
	for(int K=1; K<=n; K++) cin >> num[K];
	
	build(1, 1, n);
	
	while(q--){
		cin >> t >> x >> y;
		
		if(t==1){
			num[x] ^= y;
			update(1, 1, n, x, y);
		}
		else{
			cout << query(1, 1, n, x, y) << "\n";
		}
	}
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
