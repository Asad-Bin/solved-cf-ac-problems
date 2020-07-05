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



void task()
{
    //code here...
    
    ll n, ans=0;
    cin >> n;
    ll ara[n];
    
    for(ll K=0; K<n; K++) cin >> ara[K];
    
    sort(ara, ara+n);
    
    ans += ara[n-1];
    //if(n>2) ans += ara[n-2];
    //if(n>3) ans += ara[n-2];
    //n-=2;
    ll i = 2;
    for(int K=1; K<=(n-2)/2; K++){
		ans += 2*ara[n-i];
		i++;
		//cout << n << "\n";
		/*ans += ara[n-i];
		n--;
		if(n==0 || i>=n) break;
		ans += ara[n-i];
		n--;
		i++;*/
	}
	if(n%2==1) ans += ara[n-i];
    
    //for(int K=n-5; K>=0; K--) ans += ara[K+2];
    
    //ans += (n-2)*(ara[n-2]);
    
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


