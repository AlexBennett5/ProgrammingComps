#include <iostream>
using namespace std;
typedef long long ll;

ll mod = 1000000007;
ll n,k,m;

// This is the editorial solution to DIGMULK on CodeChef by daanish_adm, annotated with my notes

// Key insight: this is a matrix multiplication problem
// If cnt(i, c) represents the number of digit c in the string after iteration i
// And F(c, j) represents the number of digit j in the string c*K
// Then cnt(i+1,j) = (sum from 0 to 9) cnt(i,c)*F(c,j)
// Or in matrix form, cnt(i+1) = cnt(i)*F
// Thus cnt(M) = cnt(0)*F^M

void multiply(ll a[][10], ll b[][10]){
    ll x[10][10] = {0};
    for (ll i = 0; i < 10; i++){
        for (ll j = 0; j < 10; j++){
            for (ll k = 0; k < 10; k++){
                x[i][j] += (a[i][k]*b[k][j])%mod;
                x[i][j] %= mod;
            }
        }
    }

    for(ll i = 0; i < 10; ++i)
        for(ll j = 0; j < 10; ++j)
            a[i][j] = x[i][j];
}

// Use binexp to speed up the matrix multiplication
void power(ll F[][10], ll n){
    ll res[10][10] = {0};
    for(ll i = 0; i < 10; ++i)
        res[i][i] = 1;
    while(n){
        if(n&1)
            multiply(res,F);
        n >>= 1;
        multiply(F,F);
    }
    for(ll i = 0; i < 10; ++i)
        for(ll j = 0; j < 10; ++j)
            F[i][j] = res[i][j];
}

void solve(){
    scanf("%lld %lld %lld\n", &n, &k, &m);
    char s[n];
    scanf("%s\n", s);

    ll F[10][10] = {0};
    for (ll i = 0; i < 10; i++){
        ll p = i*k;
        if (p==0){
            F[0][i]++;
            continue;
        }
        while(p){
            F[p%10][i]++;
            p /= 10;
        }
    }
    power(F, m);
    ll ans = 0;
    ll cnt[10] = {0};

    for(ll i = 0; i < n; i++){
        cnt[s[i] - '0']++;
    }
    for (ll i = 0; i < 10; i++){
        for (ll j = 0; j < 10; j++){
            ans += (cnt[j]*F[i][j])%mod;
            ans %= mod;
        }
    }
    printf("%lld\n", ans);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    scanf("%lld\n", &t);
    while(t--){
        solve();
    }
    return 0;
}