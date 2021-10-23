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



struct point{
    int x;
    int y;
    // may need 'double' type variable
    
    point() {}
    point(int _x, int _y){
        x = _x;
        y = _y;
    }
};
vector<point> ara;
bool cmp(point a, point b)
{
    return a.x<b.x || (a.x==b.x && a.y<b.y);
}
double area(point a, point b, point c)
{
    long long ans = 0;
    
    ans = a.x*b.y + b.x*c.y + c.x*a.y - b.x*a.y - c.x*b.y - a.x*c.y;
    
    return 1.0*ans/2.0;
}
int ncr(int n)
{
    if(n < 3) return 0;
    
    long long ans = n*(n-1)/2;
    ans = ans*(n-2)/3;
    
    return ans;
}
int main()
{
	#ifdef LOCAL
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
	
    int n, x, y;
    
    si(n);
    for(int K=0; K<n; K++){
        sii(x, y);
        ara.PB(point(x, y));
    }
	
    //sort(ara.begin(), ara.end(), cmp);
    
    int cnt = 0;
    for(int K=2; K<n; K++){
        for(int L = 1; L < K; L++){
            for(int M = 0; M < L; M++){
                if(abs(area(ara[M], ara[L], ara[K])) <= 0.000005) cnt++;
            }
        }
    }
    
    printf("%d\n", ncr(n)-cnt);
    
    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}














































