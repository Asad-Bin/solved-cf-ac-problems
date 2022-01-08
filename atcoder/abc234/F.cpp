// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
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


const ll mod = 998244353;
const ll MX = 5000;
ll cnt[30];
ll fact[MX+5], inv[MX+5];
ll bigmod(ll a, ll p, ll M)
{
    // If 'M' is a prime number, then we can speed up it just by calculating "a^(p%(M-1))";
	p %= (M-1);
	
    ll result = 1LL;
    while(p>0LL){
        if(p&1LL) result = result * a % M;
        a = a * a % M;
        p>>=1LL;
    }
    return result;
}
ll inverse(ll a, ll M){
    if(gcd(a, M)==1) return bigmod(a, M-2, M) % M; // (ax)%M = 1
    return 1;
}
void factorial()
{
	fact[0] = fact[1] = 1;
	for(ll K=1; K<=MX; K++) fact[K] = fact[K-1] * K % mod;
	
	inv[MX] = inverse(fact[MX], mod);
	for(ll K=MX-1; K>=1; K--) inv[K] = inv[K+1] * (K+1) % mod;
	inv[0] = 1;
}

ll dp[30][6000];
ll calc(ll at, ll sum)
{
    if(at == 26){
        //debug(sum);
        return fact[sum];
    }
    
    if(dp[at][sum] != -1LL) return dp[at][sum];
    
    ll ans = 0;
    
    for(ll K = 0; K <= cnt[at]; K++){
        ans = (ans+(calc(at+1, sum+K)*inv[K]%mod)+mod)%mod;
    }
    
    return dp[at][sum] = ans;
}
int main()
{
	#ifdef LOCAL
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
	
    factorial();
    
    string s;
    cin >> s;
    
    // cout << (fact[5]*inv[2]%mod)*inv[3]%mod << "\n";
    
    ll n = sz(s);
    for(ll K = 0; K < n; K++) cnt[s[K]-'a']++;
    
    // for(int K = 0; K < 16; K++) cout << cnt[K] << ' ';
    // cout << "\n";
    
    memset(dp, -1LL, sizeof dp);
    ll ans = calc(0, 0)-1;
    cout << (ans+mod)%mod << "\n";
	
    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}














































