#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int main(){

    string text,pattern;
    cin>>text;
    cin>>pattern;
    int n=text.length();
    int m = pattern.length();
    for(int i=0;i<n-m;i++){
        int j=0;
        for(j=0;j<m;j++){
            if(text[i+j]!=pattern[j]){
                break;
            }
        }

        if(j==m){
            cout<<"Pattern found at index "<< i << endl;
        }
    }


    return 0;
}