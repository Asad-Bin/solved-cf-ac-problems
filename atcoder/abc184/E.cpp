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
const ll MXL = 1e18+5;
 
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

string s[2000];
vector<vector<pii> > ara(26);
int level[2000][2000];
bool vis[2000][2000];
int bfs(pii st, pii g, int h, int w)
{
	pii u;
	queue<pii> q;
	q.push(st);
	
	level[st.fi][st.se] = 0;
	
	memset(vis, 0, sizeof vis);
	vis[st.fi][st.se] = 1;
	
	while(!q.empty()){
		u = q.front();
		q.pop();
		
		for(int K=0; s[u.fi][u.se]>='a' && s[u.fi][u.se]<='z' && K<sz(ara[s[u.fi][u.se]-'a']); K++){
			if(!vis[ara[s[u.fi][u.se]-'a'][K].fi][ara[s[u.fi][u.se]-'a'][K].se]){
				if(ara[s[u.fi][u.se]-'a'][K]==g) return level[u.fi][u.se]+1;
				
				q.push(ara[s[u.fi][u.se]-'a'][K]);
				level[ara[s[u.fi][u.se]-'a'][K].fi][ara[s[u.fi][u.se]-'a'][K].se] = level[u.fi][u.se] + 1;
				vis[ara[s[u.fi][u.se]-'a'][K].fi][ara[s[u.fi][u.se]-'a'][K].se] = 1;
			}
		}
		if(u.fi<h-1 && s[u.fi+1][u.se]!='#' && !vis[u.fi+1][u.se]){
			if(MP(u.fi+1, u.se)==g) return level[u.fi][u.se]+1;
				
			q.push(MP(u.fi+1, u.se));
			level[u.fi+1][u.se] = level[u.fi][u.se] + 1;
			vis[u.fi+1][u.se] = 1;
		}
		if(u.se+1<w && s[u.fi][u.se+1]!='#' && !vis[u.fi][u.se+1]){
			if(MP(u.fi, u.se+1)==g) return level[u.fi][u.se]+1;
				
			q.push(MP(u.fi, u.se+1));
			level[u.fi][u.se+1] = level[u.fi][u.se] + 1;
			vis[u.fi][u.se+1] = 1;
		}
		if(u.fi>0 && s[u.fi-1][u.se]!='#' && !vis[u.fi-1][u.se]){
			if(MP(u.fi-1, u.se)==g) return level[u.fi][u.se]+1;
				
			q.push(MP(u.fi-1, u.se));
			level[u.fi-1][u.se] = level[u.fi][u.se] + 1;
			vis[u.fi-1][u.se] = 1;
		}
		if(u.se>0 && s[u.fi][u.se-1]!='#' && !vis[u.fi][u.se-1]){
			if(MP(u.fi, u.se-1)==g) return level[u.fi][u.se]+1;
				
			q.push(MP(u.fi, u.se-1));
			level[u.fi][u.se-1] = level[u.fi][u.se] + 1;
			vis[u.fi][u.se-1] = 1;
		}
	}
	
	return -1;
}
void task()
{
	// Code here...
	
	int h, w;
	
	cin >> h >> w;
	for(int K=0; K<h; K++) cin >> s[K];
	
	pii st, g;
	for(int K=0; K<h; K++){
		for(int L=0; L<w; L++){
			if(s[K][L]=='S') st = MP(K, L);
			else if(s[K][L]=='G') g = MP(K, L);
			else if(s[K][L]>='a' && s[K][L]<='z'){
				ara[s[K][L]-'a'].PB(MP(K, L));
			}
		}
	}
	
	int ans = bfs(st, g, h, w);
	
	cout << ans << "\n";
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
