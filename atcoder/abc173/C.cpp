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

// defines...
#define MP make_pair
#define PB push_back
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define sl(a) scanf("%lld", &a)
#define sll(a, b) scanf("%lld%lld", &a, &b)
#define slll(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
ll lcm(ll a, ll b)
{
    return (a*b/gcd(a, b));
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


int n, m, pop, ans=0;
bool used_row[7], used_col[7];
string s[6];
void backtrack(int k, int x, bool f)
{
	//cout << k << ' ' << x << ' ' << f << ' ' << ans << "\n";
	
	if(k==m+1 && f){
		int mid = 0;
		
		//for(int K=1; K<=n; K++) cout << used_row[K] << ' ';
		//cout << "\n";
		//for(int K=1; K<=m; K++) cout << used_col[K] << ' ';
		//cout << "\n";
		
		for(int K=0; K<n; K++){
			if(used_row[K+1]) continue;
			
			for(int L=0; L<m; L++){
				if(used_col[L+1]) continue;
				
				if(s[K][L]=='#') mid++;
				//cout << "[" << K << "][" << L << "] ";
			}
		}
		
		if(mid==pop) ans++;
		//cout << ans << "\n";
		return;
	}
	
	if(k==n+1 && !f){
		k = 1;
		x = m;
		f = 1;
	}
	
	//for(int K=k; K<=x; K++){
		backtrack(k+1, x, f);
		
		
		if(!f) used_row[k] = 1;
		else used_col[k] = 1;
		
		backtrack(k+1, x, f);
		
		if(!f) used_row[k] = 0;
		else used_col[k] = 0;
	//}
}

void task()
{
    //code here...
    
    cin >> n >> m >> pop;
    
    for(int K=0; K<n; K++) cin >> s[K];
    
    memset(used_col, 0, sizeof used_col);
    memset(used_row, 0, sizeof used_row);
    
    backtrack(1, n, 0);
    
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}


