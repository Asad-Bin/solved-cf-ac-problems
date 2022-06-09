// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MX = 1.5e5;
vector<int> ara[MX+5];
int main()
{
	int n, m, a, b;
	
	cin >> n >> m;
	
	for(int K = 0; K < m; K++){
		cin >> a >> b;
		
		ara[a].push_back(b);
		ara[b].push_back(a);
	}
	
	int k;
	cin >> k;
	
	map<int, int> level;
	vector<int> v;
	queue<int> q;
	
	while(k--){
		cin >> a >> b;
		
		while(!q.empty()) q.pop();
		level.clear();
		v.clear();
		
		q.push(a);
		level[a] = 0;
		
		while(!q.empty()){
			int u = q.front();
			q.pop();
			
			//cout << u << ' ' << level[u] << ' ' << (int)ara[u].size() << "\n";
			v.push_back(u);
			if(level[u] == b) continue;
			
			for(int K = 0; K < (int)ara[u].size(); K++){
				//cout << "xxxx" << ' ' << ara[u][K] << "\n";
				if(level.find(ara[u][K]) == level.end()){
					//cout << "yyyy\n";
					level[ara[u][K]] = level[u] + 1;
					q.push(ara[u][K]);
				}
			}
		}
		
		int ans = 0;
		for(auto it:v) ans += it;
		
		cout << ans << "\n";
	}
	
	return 0;
}




















































