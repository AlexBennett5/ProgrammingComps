#include <iostream>
#include <vector>
using namespace std;

int evens[100000];
int odds[100000];
vector<int> evenfirst;
vector<int> oddfirst;

void evenblend(int n){
    if (evens[0]%2==1){
        for (int j = 1; j < n; j++){
            if (evens[j]%2==1){
                evens[0] ^= evens[j];
                evenfirst.push_back(1);
                evenfirst.push_back(j+1);
                break;
            }
        }
    }

    if (evens[0]%2==1){
        evenfirst.clear();
        evenfirst.push_back(-1);
        return;
    }

    for (int i = 0; i < n - 1; i++){
        if (evens[i]%2 == evens[i+1]%2){
            if (evens[i]%2 == 1){
                evens[i+1] ^= evens[i];
                evenfirst.push_back(i+1);
                evenfirst.push_back(i+2);
            } else {
                for (int j = 0; j < n; j++){
                    if (evens[j]%2 == 1){
                        evens[i+1] ^= evens[j];
                        evenfirst.push_back(min(j, i+1)+1);
                        evenfirst.push_back(max(j, i+1)+1);
                        break;
                    }
                }

                if (evens[i]%2 == evens[i+1]%2){
                    evenfirst.clear();
                    evenfirst.push_back(-1);
                    return;
                }
            }
        }
    }
}

void oddblend(int n){
    if (odds[0]%2==0){
        for (int j = 1; j < n; j++){
            if (odds[j]%2==1){
                odds[0] ^= odds[j];
                oddfirst.push_back(1);
                oddfirst.push_back(j+1);
                break;
            }
        }
    }

    if (odds[0]%2==0){
        oddfirst.clear();
        oddfirst.push_back(-1);
        return;
    }

    for (int i = 0; i < n - 1; i++){
        if (odds[i]%2 == odds[i+1]%2){
            if (odds[i]%2 == 1){
                odds[i+1] ^= odds[i];
                oddfirst.push_back(i+1);
                oddfirst.push_back(i+2);
            } else {
                for (int j = 0; j < n; j++){
                    if (odds[j]%2 == 1){
                        odds[i+1] ^= odds[j];
                        oddfirst.push_back(min(j, i+1)+1);
                        oddfirst.push_back(max(j, i+1)+1);
                        break;
                    }
                }

                if (odds[i]%2 == odds[i+1]%2){
                    oddfirst.clear();
                    oddfirst.push_back(-1);
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
            scanf("%d", &evens[i]);
            odds[i] = evens[i];
        }
        evenblend(n);
        oddblend(n);

        if (evenfirst.empty() || oddfirst.empty()){
            printf("0\n");
        } else if (evenfirst[0] == -1 && oddfirst[0] == -1){
            printf("-1\n");
        } else if ((evenfirst.size() < oddfirst.size() && evenfirst[0] != -1) || oddfirst[0] == -1){
            printf("%lu\n", evenfirst.size()/2);
            for (int i = 0; i < evenfirst.size() - 1; i += 2){
                printf("%d %d\n", evenfirst[i], evenfirst[i+1]);
            }
        } else if ((oddfirst.size() <= evenfirst.size() && oddfirst[0] != -1) || evenfirst[0] == -1){
            printf("%lu\n", oddfirst.size()/2);
            for (int i = 0; i < oddfirst.size() - 1; i += 2){
                printf("%d %d\n", oddfirst[i], oddfirst[i+1]);
            }
        }        
        oddfirst.clear();
        evenfirst.clear();
    }
    return 0;
}