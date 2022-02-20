#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<cmath>
#include<vector>
using namespace std;

typedef long long ll;

char arr[110];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t, len;
    scanf("%d\n", &t);
    while(t--){
        scanf("%s\n", arr);
        len = strlen(arr);
        if (len>10){
            printf("%c%d%c\n", arr[0], len-2, arr[len-1]);
        } else {
            printf("%s\n", arr);
        }
    }

    return 0;
}