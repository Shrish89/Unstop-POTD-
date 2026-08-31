#include<bits/stdc++.h>
using namespace std;
#define   mod         1000000007ll
#define   md          998244353ll
#define   eps         1e-12
#define   INF         1000000000000000000
#define   ll          long long
#define   ull         unsigned long long
#define   ld          long double
#define   v           vector<long long>
#define   vv          vector<vector<long long>>
#define   pl          pair<long long,long long>
#define   vp          vector<pair<long long,long long>>
#define   vpp         vector<pair<long long,pair<long long,long long>>>
#define   vvp         vector<vector<pair<long long,long long>>>
#define   sl          set<long long>
#define   sp          set<pair<long long>>
#define   pb          push_back
#define   mp          make_pair
#define   eb          emplace_back
#define   ft          first
#define   sd          second
#define   all(x)      x.begin() , x.end()
#define   f(i,a,b)    for(ll i=a;i<b;i++)
#define   bb(i,a,b)   for(ll i=a;i>=b;i--)
#define   test        ll tt{0};cin>>tt;while(tt--)

ll mult(ll x,ll y,ll m) {
    return (x * y) % m;
}

ll binpow(ll x,ll n,ll m) {
    if (n == 0)return 1;
    if (n & 1)return mult(x, binpow(x, n - 1, m), m);
    return binpow(mult(x, x, m), n / 2, m);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n{0},d{0};
    cin>>n>>d;

    ll ans{0},z=1,x{0};
    if(d==1) {
        ans = binpow(2,n+1,md) - 4;
        if(ans<0)ans+=md;
        cout<<ans;
        return 0;
    }
    x = binpow(2,d-2,md);
    f(i,0,n){
        if(2*(n-1-i)>=d){
            if(n-1-i>=d){
                ans = (ans + z*((d+3)*x%md))%md;
            }
            else {
                ans = (ans + z*((2*(n-i-1)-d+1)*x%md))%md;
            }
        }
        z=(z*2)%md;
    }

    cout<<(2*ans)%md;

    return 0;
}