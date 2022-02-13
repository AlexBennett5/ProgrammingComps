#include<iostream>
using namespace std;

char arr[14];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    for (int i = 0; i < 14; i++){
        arr[i] = 'a';
    }
    int t, x, c, n;
    scanf("%d\n", &t);
    while(t--){
        scanf("%d\n", &x);
        scanf("%s\n", arr);
        c = n = 0;

        for (int i = 0; i < 14; i++){
            if (arr[i]=='C'){
                c++;
            } else if (arr[i]=='N'){
                n++;
            } else {
                c++;
                n++;
            }
        }

        if (c==n){
            printf("%d\n", x*55);
        } else if (c<n) {
            printf("%d\n", x*40);
        } else {
            printf("%d\n", x*60);
        }
    }
    return 0;
}