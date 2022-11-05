// . . . Bismillahir Rahmanir Rahim . . .
 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#ifdef local
     #define debug(x) cerr << '{' << #x << " = " << (x) << '}' << "\n";
#else
    #define debug(x) // lol ojs
#endif


const int N = 1e6;
	int x[] = {1, -1, 0, 0};
	int y[] = {0, 0, 1, -1};

pair<int, int> st;
vector<vector<int> > vis;
	int n, m;
	string s[N+5];
bool dfs(pair<int, int> u, int h)
{
	//cout << u.first << ' ' << u.second << ' ' << h << "\n";
	if(u != st) vis[u.first][u.second] = 1;
	for(int K = 0; K < 4; K++){
		if(u.first+x[K] < n && u.first+x[K] >= 0 && u.second+y[K] < m && u.second+y[K] >= 0 && s[u.first+x[K]][u.second+y[K]] != '#' && vis[u.first+x[K]][u.second+y[K]] == 0){
			if(make_pair(u.first+x[K], u.second+y[K]) == st){
				if(h >= 3){
					//cout << "Yes\n";
					return 1;
				}
				
				continue;
			}
			
			//level[{u.first+x[K], u.second+y[K]}] = level[u] + 1;
			bool ok = dfs({u.first+x[K], u.second+y[K]}, h+1);
			if(ok) return ok;
		}
	}
	
	////vis[u.first][u.second] = 0;
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	vis.resize(n, vector<int> (m));
	//for(int K = 0; K < n; K++) vis[K].resize(m);
	
	for(int K = 0; K < n; K++) cin >> s[K];
	
	//pair<int, int> st = {-1, -1};
	for(int K = 0; K < n; K++){
		for(int L = 0; L < m; L++){
			if(s[K][L] == 'S'){
				st = {K, L};
				break;
			}
		}
	}
	
	if(dfs(st, 0)) cout << "Yes\n";
	else cout << "No\n";
	
	
	//queue<pair<int, int> > q;
	//q.push(st);
	
	//map<pair<int, int>, int> level;
	
	//int x[] = {1, -1, 0, 0};
	//int y[] = {0, 0, 1, -1};
	//while(!q.empty()){
		//pair<int, int > u;
		//u = q.front();
		//q.pop();
		
		//for(int K = 0; K < 4; K++){
			//if(u.first+x[K] < n && u.first+x[K] >= 0 && u.second+y[K] < m && u.second+y[K] >= 0 && s[u.first+x[K]][u.second+y[K]] != '#' && level[{u.first+x[K], u.second+y[K]}] == 0){
				//if(make_pair(u.first+x[K], u.second+y[K]) == st){
					//if(level[u] >= 3){
						//cout << "Yes\n";
						//return 0;
					//}
					
					//continue;
				//}
				
				//level[{u.first+x[K], u.second+y[K]}] = level[u] + 1;
				//q.push({u.first+x[K], u.second+y[K]});
			//}
		//}
	//}
	
	//cout << "No\n";
	
	
	return 0;
}
 
 
 
 
 
 
 
 
