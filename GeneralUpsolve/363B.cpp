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

    int n,k;
    scanf("%d %d\n", &n, &k);
    int arr[n+1];

    int currmin=0, minsofar=0,mindex=1;
    for (int i=1;i<=n;i++){
        scanf("%d\n", &arr[i]);
        if(i<=k){
            currmin += arr[i];
        }
    }
    minsofar=currmin;

    for (int i=k+1;i<=n;i++){
        currmin = currmin - arr[i-k] + arr[i];
        if (currmin<minsofar){
            minsofar=currmin;
            mindex=i-k+1;
        }
    }
    printf("%d\n", mindex);

    return 0;
}