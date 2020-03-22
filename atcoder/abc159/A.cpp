#include <bits/stdc++.h>

using namespace std;

void task()
{
    int n, m, sum=0, calc;

    cin>>n>>m;

    //calc=1;
    if(n==2) sum++;
    if(n>2){
        calc=1;
        for(int K=n; K>=n-1; K--){
            calc *= K;
        }
        calc /= 2;
        sum += calc;
    }

    //calc = 1;
    if(m==2) sum++;
    if(m>2){
        calc=1;
        for(int K=m; K>=m-1; K--){
            calc *= K;
        }
        calc /= 2;
        sum += calc;
    }

    cout<<sum<<endl;
}

int main()
{
    task();

    return 0;
}
