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

    int t,n,a;
    scanf("%d\n", &t);
    while(t--){
        scanf("%d\n", &n);
        vector<int> arr(n);
        for (int i=0;i<n;i++){
            scanf("%d", &a);
            arr[i] = a;
        }

        if (arr[n-1]<0){
            if (is_sorted(arr.begin(), arr.end())){
                printf("0\n");
            } else {
                printf("-1\n");
            }
        } else if (arr[n-1]<arr[n-2]) {
            printf("-1\n");
        } else {
            printf("%d\n", n-2);
            for(int i=1;i<=n-2;i++){
                printf("%d %d %d\n", i, n-1, n);
            }
        }
    }

    return 0;
}