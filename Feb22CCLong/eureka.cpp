#include <iostream>
#include <cmath>
using namespace std;

double binexp(double a, int b){
    double res = 1;
    do{
        if (b&1){
            res *= a;
        }
        a = a*a;
        b >>= 1;
    } while (b>0);
    return res;
}

int calc(int n){
    double x = binexp(0.143*n, n);
    if (x - floor(x) < 0.5){
        return floor(x);
    } else {
        return floor(x) + 1;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n;
    scanf("%d\n", &t);
    while(t--){
        scanf("%d\n", &n);
        printf("%d\n", calc(n));
    }
}