#include <iostream>
using namespace std;
const int maxn = 3e4 + 10;
int a[maxn], ps[maxn];

// This is the editorial solution to REMADJ on CodeChef by daanish_adm, annotated with my notes

// Key insight: The length of the final array and the value of each element in the final array
// will be factors of the sum of the original array. 

int calc(int x, int n){
    int mul = 1;
    for (int i=1; i <=n && mul < ps[n]/x; i++){
        // If the prefix is a multiple of the chosen factor, we increment mul
        if (ps[i] == mul*x){
            mul++;
        }
    }
    // If the final value of mul times x doesn't equal the sum, it is not a valid partition
    if (mul != ps[n]/x) mul = 1;
    return n - mul;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n;
    scanf("%d\n", &t);
    while(t--){
        scanf("%d\n", &n);
        int cnt0 = 0;

        for (int i = 1; i<=n; i++){
            scanf("%d", &a[i]);
            ps[i] = ps[i - 1] + a[i];
            cnt0 += ps[i] == 0;
        }

        // If the sum is zero, then the solution is to combine all elements that aren't zero (hence n - cnt0)
        int ans = ps[n] ? n - 1 : n - cnt0;

        for (int i = 1; i*i <= abs(ps[n]); i++){
            // If i is not a factor in the sum, then we don't check
            if(ps[n]%i) continue;

            // We check both i and sum divided by i
            ans = min(ans, min(calc(i*(ps[n]/abs(ps[n])), n), calc(ps[n]/i, n)));
        }
        printf("%d\n", ans);
    }
}