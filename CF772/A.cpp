#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<cmath>
#include<vector>
#include<map>
#include<set>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t,n,a,ans;
    scanf("%d\n", &t);
    while(t--){
        ans=0;
        scanf("%d\n", &n);
        for (int i=0;i<n;i++){
            scanf("%d", &a);
            ans |= a;
        }
        printf("%d\n", ans);
    }

    return 0;
}