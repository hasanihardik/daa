#include<iostream>
#include<cmath>
using namespace std;


int karatsuba(long x, long y){
    if(x<10 || y<10) return x*y;

    int xlen=to_string(x).length();
    int ylen=to_string(y).length();
    int n=max(xlen,ylen);
    int N=n/2;
    int multiplier=pow(10,N);
    long a=x/multiplier;
    long b=x%multiplier;
    long c=y/multiplier;
    long d=y%multiplier;
    long ac=karatsuba(a,c);
    long bd=karatsuba(b,d);
    long adbc=karatsuba(a+b,c+d)-ac-bd;
    long result = 0;
    return ac*pow(10,2*N) + adbc*pow(10,N) + bd;
}


int main(){
    long x;
    cin>>x;
    long y;
    cin>>y;

    cout<<karatsuba(x,y);
    return 0;
}