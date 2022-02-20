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

    int n, c, ans;
    scanf("%d\n", &n);
    int arr[5];
    arr[1] = arr[2] = arr[2] = arr[4] = 0;
    ans=0;

    for (int i = 0; i<n; i++){
        scanf("%d", &c);
        arr[c]++;
    }

    ans = arr[4];
    int tmp = min(arr[1], arr[3]);
    ans += tmp;
    arr[1] -= tmp;
    arr[3] -= tmp;
    ans += arr[1]/4;
    arr[1] %= 4;
    ans += arr[2]/2;
    arr[2] %= 2;

    if (arr[1]){
        if (arr[2]){
            ans += 2;
        } else {
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