#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t, a, b, x, y;
    scanf("%d\n", &t);
    while(t--){
        scanf("%d %d %d %d\n", &a, &b, &x, &y);
        if (a*b<=x*y){
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}