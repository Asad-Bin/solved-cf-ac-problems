#include <bits/stdc++.h>

using namespace std;

void task()
{
    char str[100];

    scanf(" %[^\n]", str);

    int len = strlen(str);

    bool flag=0;
    for(int i=0; i*2<len+2; i++){
        if(str[i]!=str[len-i-1]){
            cout<<"No"<<endl;
            return;
        }
    }
    int mid = (len-1)/2;
    for(int i=0; i<mid; i++){
        if(str[i]!=str[mid-i-1]){
            cout<<"No"<<endl; //cout<<"hi"<<endl;
            return;
        }
    }
    mid = (len+3)/2;
    for(int i=mid-1; i<len; i++){
        if(str[i]!=str[len-i-1]){
            cout<<"No"<<endl;
            return;
        }
    }

    cout<<"Yes"<<endl;
}

int main()
{
    task();

    return 0;
}
