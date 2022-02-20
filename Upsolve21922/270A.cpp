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

    int t, n;
    scanf("%d\n", &t);
    while(t--){
        scanf("%d\n", &n);
        if (360%(180-n)){
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }

    return 0;
}