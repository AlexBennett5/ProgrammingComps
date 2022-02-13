#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t, n, j, k;
    scanf("%d\n", &t);
    while(t--){
        scanf("%d\n", &n);
        j = 1;
        for (int i = 0; i < n; i++){
            scanf("%d", &k);
            if (k==j){
                j++;
            }
            j++;
        }
        printf("%d\n", j - n - 1);
    }
    return 0;
}