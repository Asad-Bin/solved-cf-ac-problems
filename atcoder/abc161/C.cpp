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
    long long n, k, i;

    cin>>n>>k;

    n = n % k;

    while(1){
        if(n==0) break;
        else if(n<abs(k-n)) break;
        n = abs(n-k);
    }

    cout<<n<<endl;
}

int main()
{
    task();

    return 0;
}
