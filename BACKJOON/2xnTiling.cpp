#include<bits/stdc++.h>
using namespace std;

int d[60001];

int foo(int i){
    if(i==1) return 1;
    if(i==2) return 2;
    if(d[i]!=-1) return d[i];
    return d[i]=(foo(i-1)+foo(i-2))%1000000007;
}

int solution(int n) {
    memset(d,-1,sizeof(d));
    return foo(n);
}