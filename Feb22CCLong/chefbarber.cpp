#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, t;
    scanf("%d\n", &t);
    while(t--){
        scanf("%d %d\n", &n, &m);
        printf("%d\n", n*m);
    }
}