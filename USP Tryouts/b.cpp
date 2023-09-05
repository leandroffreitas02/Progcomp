#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    ll n; cin >> n;

    vector<ll> v;

    for(ll i = 0; i < n; i++){
        ll x; cin >> x;

        if(x % 2) v.pb(i);
    }

    ll l, r; cin >> l >> r;

    if(v.size() % 2){
        cout << -1 << endl;
        return 0;
    }
    int m = (v.size());

    ll ans1 = 0, ans2 = 0;
    



    for(ll i = 0; i < m; i += 2){
        
        ll dist1 = min(abs(v[i]+ (n - v[(m + i - 1)%m])), abs(v[i]-v[(m + i - 1)%m]));
        ll dist2 = min(abs(v[i] + n - v[i + 1]), abs(v[i] - v[i+1]));

        ans1 += min(dist1*l, dist1*r);
        ans2 += min(dist2*l, dist2*r);
    }

    cout << min(ans1, ans2) << endl;
}