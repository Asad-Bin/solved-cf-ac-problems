// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#ifndef ONLINE_JUDGE
#define dbg_out cout
#define debug(...) dbg_out << "DBG )> "; __f(#__VA_ARGS__, __VA_ARGS__);
template<typename T1, typename T2> ostream& operator<<(ostream& out, pair<T1, T2> pr) { out << "{ " << pr.first << ", " << pr.second << " }"; return out; }
template<typename T1> ostream& operator<<(ostream& out, vector<T1> vec) { out << "{ "; for (auto &x: vec) out << x << ", "; out << "}"; return out; }
template<typename T1, size_t size> ostream& operator<<(ostream& out, array<T1, size> arr) { out << "{ "; for (auto &x: arr) out << x << ", "; out << "}"; return out; }
template<typename T1, typename T2> ostream& operator<<(ostream& out, map<T1, T2> mp) { out << "{ ";for (auto &x: mp) out << x.first << ": " << x.second <<  ", "; out << "}"; return out; }
template <typename Arg1> void __f(const char* name, Arg1&& arg1) { while (isspace(name[0])) name++; (isalpha(name[0]) || name[0] == '_') ? dbg_out << name << ": " << arg1 << "\n" : dbg_out << arg1 << "\n"; dbg_out.flush();}
template <typename Arg1, typename... Args> void __f (const char* names, Arg1&& arg1, Args&&... args) { const char *comma = strchr(names + 1, ','); while (isspace(names[0])) names++; (isalpha(names[0]) || names[0] == '_') ? dbg_out.write(names, comma - names) << ": " << arg1 << " | " : dbg_out << arg1 << " | "; __f(comma + 1, args...);}
#else
#define debug(...)
#endif

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> ara(n);
		for(int K = 0; K < n; K++) cin >> ara[K];
		
		int ans = 0;
		while((int)ara.size() > 2){
			bool ok = 0;
			for(int K = 0; K < n; K++){
				if(ara[K] != ara[(K+2)%n] && ara[(K+1)%n] == ara[(K+3)%n]){
					ans++;
					ok = 1;
					ara.erase(ara.begin()+(K+1)%n);
					n--;
					break;
				}
			}
			
			debug(ara);
			
			if(!ok){
				ara.erase(ara.begin());
				ans++;
				n--;
			}
			
				if(ara.back() == *ara.begin()){
					ara.erase(ara.begin());
					n--;
				}
		}
		
		
		if((int)ara.size() == 2 && ara[0] == ara[1]) ara.erase(ara.begin());
		cout << ans+(int)ara.size() << "\n";
	}
	
	return 0;
}





































