// . . . Bismillahir Rahmanir Rahim . . .
 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#ifdef local
     #define debug(x) cerr << '{' << #x << " = " << (x) << '}' << "\n";
#else
    #define debug(x) // lol ojs
#endif
 
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string s;
	cin >> s;
	
	int ans = -1;
	for(int K = 0; K < (int)s.length(); K++) if(s[K] == 'a') ans = K+1;
	
	cout << ans << "\n";
	
	return 0;
}
 
 
 
 
 
 
 
 
