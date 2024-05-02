#include<iostream>
#include <algorithm>
using namespace std;

struct activity{
    int start;
    int finish;
};

bool compare(activity a, activity b){
    return a.finish<b.finish;
}
int main(){
    int n;
    cin>>n;
    activity arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i].start;
        cin>>arr[i].finish;
    }
    sort(arr, arr+n,compare);
    int j=0;
    cout<<arr[j].start<<" "<<arr[j].finish<<" ,";
    for(int i=1;i<n;i++){
        if(arr[i].start>=arr[j].finish){
            cout<<arr[i].start<<" "<<arr[i].finish<<" ,";
            j=i;
        }
    }
    return 0;
}