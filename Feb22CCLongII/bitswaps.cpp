#include<iostream>
using namespace std;

class elem{
public:
    int val;
    int ind;
    elem(int val, int ind){
        this->val = val;
        this->ind = ind;
    }        
};

class elemcomp{
public:
    bool operator() (const elem& a, const elem& b){
        return a.val < b.val;
    }
};

int arr[300000];
elem check[300000];

int main(){

    int t, n;
    elemcomp cmp;
    scanf("%d\n", &t);
    while(t--){
        scanf("%d\n", &n);
        for (int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
            check[i] = elem(arr[i], i);
        }
        check.sort(cmp);
    }
}