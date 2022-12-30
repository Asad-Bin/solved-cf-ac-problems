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
const int MX = 2e5+5;
const ll INF = 1e18;

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


int ara[MX];
pll calc(int at, bool cond)
{
	if(cond){
		for(int K=at; K>0; K--){
			if(ara[K]<ara[K-1]){
				pll res = calc(K-1, 0);
				//cout << "K = " << K << " ara[K] = " << ara[K] << "\n";
				ll money = res.fi;
				ll num = money / ara[K];
				money = num * ara[K];
				//cout << "at = " << at << ' ' << '{' << res.fi-money << ' ' << num << '}' << "\n";
				return MP(res.fi-money, num);
			}
		}
		
		//cout << "at = " << at << ' ' << '{' << 1000-ara[0]*((int)1000/ara[0]) << ' ' << (int)1000/ara[0] << "}\n";
		return MP(1000-ara[0]*((ll)1000/ara[0]), (ll)1000/ara[0]);
	}
	else{
		for(int K=at; K>0; K--){
			if(ara[K]>ara[K-1]){
				pll res = calc(K-1, 1);
				//cout << "K = " << K << " ara[K] = " << ara[K] << "\n";
				ll money = res.fi + ara[K]*res.se;
				//cout << "at = " << at << ' ' << '{' << money << ' ' << 0 << '}' << "\n";
				return MP(money, 0);
			}
		}
		
		//cout << "at = " << at << ' ' << '{' << 1000 << ' ' << 0 << '}' << "\n";
		return MP(1000, 0);
	}
}
void task()
{
    //code here...
    
    int n;
    
    cin >> n;
    for(int K=0; K<n; K++) cin >> ara[K];
    
    pll ans = calc(n-1, 0); // 0 for sell..
    
    cout << ans.fi << "\n";
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
