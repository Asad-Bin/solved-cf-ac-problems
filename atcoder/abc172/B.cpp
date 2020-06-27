#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n, ans=0;
  string s, t;
  
  cin >> s >> t;
  
  n = max(s.length(), t.length());
  for(int K=0; K<n; K++){
    if(s[K]!=t[K]) ans++; 
  }
  
  cout << ans << "\n";
}