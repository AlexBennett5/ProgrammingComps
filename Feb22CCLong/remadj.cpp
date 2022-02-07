#include <iostream>
#include <climits>
using namespace std;

int arr[30000];

int solve(int n){
    int ans = INT_MAX;
    int curr, comp, combines;
    curr = comp = combines = 0;
    for (int i = 0; i < n; i++){
        comp += arr[i];
        curr = 0;
        combines = i;
        for (int j = i+1; j < n; j++){
            curr += arr[j];

            if (curr == comp){
                curr = 0;
            } else {
                combines++;
            }
        }

        if (curr == 0){
            ans = min(ans, combines);
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n, ans;
    scanf("%d\n", &t);
    while(t--){
        scanf("%d\n", &n);
        for (int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }

        if (n==2){
            ans = arr[0] == arr[1] ? 0 : 1;
        } else {
            ans = solve(n);
        }
        printf("%d\n", ans);
    }
}