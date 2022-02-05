#include <iostream>
using namespace std;

bool palindrome(char str[], int n, int k){
    int i, j, ops;
    i = 0;
    j = n - 1;
    ops = 0;
    while(i<j){
        if (str[i] != str[j]){
            ops++;
        }
        i++;j--;
    }
    if (ops > k){
        return false;
    } else if (ops == k){
        return true;
    } else {
        if ((k - ops)%2 == 0){
            return true;
        } else {
            if (n%2 == 1){
                return true;
            } else {
                return false;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k, t;
    scanf("%d\n", &t);
    while(t--){
        scanf("%d %d\n", &n, &k);
        char str[n];
        scanf("%s\n", str);
        if (palindrome(str, n, k)){
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}