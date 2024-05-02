#include<iostream>
#include<cmath>
#include<climits>
using namespace std;




int maxsub(int arr[], int l, int r){
    if(l==r)
        return arr[l];
        int m = (l+r)/2;
        int lmss = maxsub(arr, l , m);
        int rmss = maxsub(arr,m+1,r);

        int lsum = INT_MIN, rsum= INT_MIN, sum=0;
        for(int i=m;i>=l;i--){
            sum+=arr[i];
            if(sum>lsum){
                lsum=sum;
            }
        }
        sum=0;
        for(int i=m+1;i<=r;i++){
            sum+=arr[i];
            if(sum>rsum){
                rsum=sum;
            }
        }
        int overlapping = lsum+rsum;
        return max(lmss,max(rmss,overlapping));
}
int main(){
    int n;
    cin>>n;
    cout<<"enter the array";
    int a[n] ;  
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    cout<<"the maximum subarray sum is "<<maxsub(a,0,n-1);

    return 0;
}