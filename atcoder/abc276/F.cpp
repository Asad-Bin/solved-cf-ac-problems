// . . . Bismillahir Rahmanir Rahim . . .
 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#ifdef local
     #define debug(x) cerr << '{' << #x << " = " << (x) << '}' << "\n";
#else
    #define debug(x) // lol ojs
#endif


const ll N = 2e5;
ll tree[4*N+5], sum[4*N+5];

void update(ll at, ll l, ll r, ll pos)
{
	if(l == r)
	{
		tree[at]++;
		//sum[at] = tree[at]*l;
		return;
	}
	
	ll mid = (l + r) /2;
	
	if(pos<= mid) update(at*2, l, mid, pos);
	else update(at*2+1, mid+1, r, pos);
	
	tree[at] = tree[at*2] + tree[at*2+1];
	//sum[at] = sum[at*2] + sum[at*2+1];
}
void update_s(ll at, ll l, ll r, ll pos)
{
	if(l == r)
	{
		//tree[at]++;
		sum[at] += l;;
		return;
	}
	
	ll mid = (l + r) /2;
	
	if(pos<= mid) update_s(at*2, l, mid, pos);
	else update_s(at*2+1, mid+1, r, pos);
	
	//tree[at] = tree[at*2] + tree[at*2+1];
	sum[at] = sum[at*2] + sum[at*2+1];
}
ll query(ll at, ll l, ll r, ll L, ll R)
{
	if(r < L || R < l) return 0;
	if(L <= l && r <= R) return tree[at];
	
	ll mid = (l + r) /2;
	
	ll ans = 0;
	ans += query(at*2, l, mid, L, R);
	ans += query(at*2+1, mid+1, r, L, R);
	
	return ans;
}
ll query_s(ll at, ll l, ll r, ll L, ll R)
{
	if(r < L || R < l) return 0;
	if(L <= l && r <= R) return sum[at];
	
	int mid = (l + r) /2;
	
	ll ans = 0;
	ans += query_s(at*2, l, mid, L, R);
	ans += query_s(at*2+1, mid+1, r, L, R);
	
	return ans;
}

const ll mod = 998244353;
ll bigmod(ll a, ll p, ll M)
{
    // If 'M' is a prime number, then we can speed up it just by calculating "a^(p%(M-1))";
	//p %= (M-1);
	
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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll n; cin >> n;
	ll ara[n];
	for(ll K = 0; K < n; K++) cin >> ara[K];
	
	//ll pre[n];
	//pre[0] = ara[0];
	//for(ll K = 1 ; K < n; K++) pre[K] = ara[K] + pre[K-1];
	
	
	ll s = 0;
	for(ll K = 0; K < n; K++){
		
		s += (2*query(1, 1, N, 1, ara[K])+1)*ara[K]%mod;
		s %= mod;
		update(1, 1, N, ara[K]);
		s += 2*query_s(1, 1, N, ara[K]+1, N)%mod;
		s %= mod;
		update_s(1, 1, N, ara[K]);
		
		
		cout <<(s*(inverse((K+1), mod)*inverse(K+1, mod)%mod)%mod) << "\n";
	}
	
	return 0;
}
 
 
 
 
 
 
 
 
