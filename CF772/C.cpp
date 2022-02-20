#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<cmath>
#include<vector>
#include <tuple>
using namespace std;

typedef long long ll;

int arr[200010];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    for (int i=0; i<200010; i++){
        arr[i] = 0;
    }

    int t,n,cmp;
    bool impos=false;
    vector< vector<int> > vect;
    scanf("%d\n", &t);
    while(t--){
        scanf("%d\n", &n);
        for (int i=0; i<n; i++){
            scanf("%d", &arr[i]);
        }

        for (int i=0;i<n;i++){
            if (arr[i]>arr[i+1]){
                cmp=arr[i+1];
                impos=true;
                for (int j=i+2;j<n;j++){
                    if (arr[j]>cmp && !(cmp<0 && arr[j]<0)){
                        vector<int> v;
                        v.push_back(i);
                        v.push_back(i+1);
                        v.push_back(j);
                        vect.push_back(v);
                        impos=false;
                        break;
                    }
                }    
            }
            if(impos){
               break;
            }
        }

        if(impos){
            printf("-1\n");
        }else{
            printf("%d\n", vect.size());
            for (int i=0;i<vect.size();i++){
                vector<int> v = vect[i];
                printf("%d %d %d\n", v[0], v[1], v[2]);
            }
        }
        vect.clear();
    }

    return 0;
}

/*

You can replace ax with ay-az as long as |ax|<10^18

Array should be non-decreaing
So a[i] <= a[i+1]

a[i] > a[i+1]


Impossible if entire array is in decreasing order

x<y<z
A[x]>A[y]<A[z]
Literally any A[z]>A[y] will work where both aren't negative

-4 - -1 = -3

5 -4 2 -1 2

1 2 3
5 = -4 - 2 = -6

-6 -4 2 -1 2

*/