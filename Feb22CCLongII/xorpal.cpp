#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t, n, set, unset;
    char k;
    scanf("%d\n", &t);
    while(t--){
        scanf("%d\n", &n);
        set = unset = 0;
        for (int i = 0; i<n; i++){
            scanf("%c", &k);
            if (k=='0'){
                unset++;
            } else {
                set++;
            }
        }

        if (set != unset && set%2==1 && unset%2==1){
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
    return 0;
}