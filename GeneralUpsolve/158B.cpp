#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<cmath>
#include<vector>
using namespace std;

typedef long long ll;

int arr[5] = {0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n,d,ans;
    scanf("%d\n", &n);
    for (int i=0;i<n;i++){
        scanf("%d", &d);
        arr[d]++;
    }

    ans=arr[4];
    int tmp=min(arr[1],arr[3]);
    ans += tmp;
    arr[1] -= tmp;
    arr[3] -= tmp;

    ans += arr[2]/2;
    arr[2] %= 2;

    if (arr[1]){
        if (arr[1]>2&&arr[2]==1){
            ans++;
            arr[1] -= 2;
        }
        ans += arr[1]/4;
        if (arr[1]%4){
            ans++;
        }
    } else if (arr[3]){
        ans += (arr[3] + arr[2]);
    } else if (arr[2]){
        ans++;
    }
    printf("%d\n", ans);


    return 0;
}