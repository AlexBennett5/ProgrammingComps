#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<cmath>
#include<vector>
using namespace std;

typedef long long ll;

int arr[200010];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    for (int i=0; i<200010; i++){
        arr[i] = 0;
    }

    int t,n,ans;
    scanf("%d\n", &t);
    while(t--){
        ans = 0;
        scanf("%d\n", &n);
        for (int i=0; i<n;i++){
            scanf("%d\n", &arr[i]);
        }

        for (int i=1;i<n-1;i++){
            if (arr[i]>arr[i-1] && arr[i]>arr[i+1]){
                if (i==n-2){
                    arr[i+1] = arr[i];
                } else {
                    arr[i+1] = max(arr[i], arr[i+2]);
                }
                ans++;
            }
        }
        printf("%d\n", ans);
        for (int i=0;i<n;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
    }

    return 0;
}