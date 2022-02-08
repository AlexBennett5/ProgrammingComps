#include <iostream>
#include <vector>
using namespace std;

// This is the editorial solution to BITBLEND on CodeChef by akshitm16, annotated with my notes

int arr[100000];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n;
    scanf("%d\n", &t);
    while(t--){
        scanf("%d\n", &n);
        bool all_even = 1;
        
        for (int i = 0; i < n; i++){
            scanf("%d\n", &arr[i]);
            if (arr[i]%2) all_even = 0;
        }

        // Since O^O = E and E^O = O, the only configuration that can't be solved is all evens
        if (all_even){
            printf("-1\n");
            continue;
        }

        // Checking how many are out of place if we try even index = even number
        int x = 0, delta = 0;
        for (int i = 0; i < n; i++){
            if((arr[i]%2)!=(i%2)) x++;
        }

        // n - x is the number of out of place elements if even index = odd number
        if (x > n - x) delta = 1;
        
        // Check for the first odd number in the right index
        // Delta tells us what the "right" index is: odd to odd, or even to odd 
        int ind = -1;
        for(int i=0; i<n; i++){
            if((arr[i]%2) && ((i+delta)%2)){
                ind = i;
                break;
            }
        }

        // We use our chosen odd number for every necessary transformation
        vector<pair<int, int> > ops;
        for(int i=0; i<n; i++){
            if((arr[i]%2)!=((i+delta)%2)){
                ops.push_back(make_pair(i+1, ind+1));
            }
        }

        printf("%d\n", (int)ops.size());
        for (auto ind : ops){
            printf("%d %d\n", ind.first, ind.second);
        }
    }

    return 0;
}
