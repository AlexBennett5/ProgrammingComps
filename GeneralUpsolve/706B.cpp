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

    int n,q,m,ans;
    scanf("%d\n", &n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    sort(arr,arr+n);
    scanf("%d\n", &q);
    while(q--){
        scanf("%d\n", &m);
        ans=upper_bound(arr,arr+n,m)-arr;
        printf("%d\n", ans);
    }

    return 0;
}