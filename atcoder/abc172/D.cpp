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
#define fi first
#define se second
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


vector<int> primes;
vector<bool> mark(10002);
void sieve(int n)
{
    int i, j, limit = sqrt(n*1.) + 2;

    mark[1] = 1;

    for(i = 4; i<=n; i+=2) mark[i] = 1;

    primes.push_back(2);

    for(i = 3; i <= n; i += 2)
    {
        if(!mark[i])
        {
            primes.push_back(i);

            if(i<=limit)
            {
                for(j = i*i; j <= n; j += i*2)
                {
                    mark[j] = 1;
                }
            }
        }
    }
}
int divs(int n) {
	int cnt, tot=1, i;
	
	for(i=0; i<(int)primes.size() && (primes[i]*primes[i])<=n; i++) {
		if(n%primes[i]==0) {
			cnt=1;
			
			while(n%primes[i]==0) {
				n/=primes[i];
				cnt++;
			}
			
			tot*=cnt;
		}
	}
	
	if(n>1) {
		tot*=2;
	}
	
	return tot;
}
void task()
{
    //code here...
    
    ll n, ans=0, mid;
    
    cin >> n;
    
    sieve((int)sqrt(n+1));
    
    for(ll K=1; K<=n; K++){
		mid = n/K;
		ans += K*mid*(mid+1)/2;
	}
	
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


