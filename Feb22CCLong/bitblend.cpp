#include <iostream>
#include <vector>
using namespace std;

int arr[100000];
vector<int> ans;

void blend(int n){
    for (int i = 0; i < n - 1; i++){
        if (arr[i]%2 == arr[i+1]%2){
            if (arr[i]%2 == 1){
                arr[i] ^= arr[i+1];
                ans.push_back(i+1);
                ans.push_back(i+2);
            } else {
                for (int j = 0; j < n; j++){
                    if (arr[j]%2 == 1){
                        arr[i] ^= arr[j];
                        ans.push_back(min(j, i)+1);
                        ans.push_back(max(j, i)+1);
                        break;
                    }
                }

                if (arr[i]%2 == arr[i+1]%2){
                    ans.clear();
                    ans.push_back(-1);
                    return;
                }
            }
        }
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
        for (int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }
        blend(n);

        if (ans[0] == -1){
            printf("-1\n");
        } else {
            printf("%lu\n", ans.size()/2);
            for (int i = 0; i < ans.size() - 1; i += 2){
                printf("%d %d\n", ans[i], ans[i+1]);
            }
        }
        ans.clear();
    }

    return 0;
}