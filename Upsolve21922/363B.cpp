#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<cmath>
#include<vector>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n,k,d;
    scanf("%d %d\n", &n, &k);

    int minsofar=0, mindex=1, currmin=0;
    int arr[n+1];

    for (int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        if(i<=k){
            minsofar+=arr[i];
        }
    }
    currmin=minsofar;
    for (int i=k+1;i<=n;i++){
        currmin = currmin + arr[i] - arr[i-k];
        if(currmin<minsofar){
            mindex=i-k+1;
            minsofar=currmin;
        }
    }
    printf("%d\n",mindex);

    return 0;
}

/*

1 1
100

*/