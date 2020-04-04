//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 04 04 2020

#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

void task()
{
    int n, m;
    long int sum=0;
    int value;

    cin>>n>>m;
    vector<int> ara(n);

    for(int K=0; K<n; K++){
        cin>>ara[K];
        sum += ara[K];
    }

    value= sum / (4*m);

    int count=0;
    for(int K=0; K<n; K++){
        if(sum%4==0 || sum%m==0){
            if(ara[K]>=value){
                count++;
            }
        }
        else{
            if(ara[K]>value){
                count++;
            }
        }
    }

    if(count>=m) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

int main()
{
    task();

    return 0;
}
