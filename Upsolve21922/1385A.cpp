#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<cmath>
#include<vector>
using namespace std;

typedef long long ll;

int arr[3];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    scanf("%d\n", &t);
    while(t--){
        scanf("%d %d %d\n", &arr[0], &arr[1], &arr[2]);
        sort(arr, arr+3);

        if (arr[1]!=arr[2]){
            printf("NO\n");
        } else {
            printf("YES\n%d %d %d\n", arr[0], arr[0], arr[2]);
        }
    }

    return 0;
}