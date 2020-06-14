//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 14 06 2020

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


void bruce()
{
    //cout << "\nExpected answer:\n";
    //cout << "\nAnswer recieved:\n";
}

void task()
{
    //code here...

    int x, n, m=0, s=1000;
    cin >> x >> n;
    vi ara(n);
    if(n==0){
        cout << x << "\n";
        return;
    }

    for(int K=0; K<n; K++){
        cin >> ara[K];
        m = max(m, ara[K]);
        s = min(s, ara[K]);
    }

    int ans=1000, lol=-1;
    for(int K=s-1; K<=m+1; K++){
        if(find(ara.begin(), ara.end(), K)==ara.end()){
            if(abs(x-K)<ans){
                ans = abs(x-K);
                lol = K;
            }
        }
    }

    if(lol==-1) cout << min(x, n+1-x) << "\n";
    else cout << lol << "\n";
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