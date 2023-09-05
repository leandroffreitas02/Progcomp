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

    ll s1 = 0, sx = 0, sy = 0, sz = 0;

    for(int i = 0; i < n; i++){
        ll x, y, z, w;

        cin >> x >> y >> z >> w;

        s1 += w;
        sx += x*w;
        sy += y*w;
        sz += z*w;
    }

    double x = (double)sx/s1;
    double y = (double)sy/s1;
    double z = (double)sz/s1;

    if(x - floor(x) <= 0.5) x = floor(x);
    else x = ceil(x);

    if(y - floor(y) <= 0.5) y = floor(y);
    else y = ceil(y);

    if(z - floor(z) <= 0.5) z = floor(z);
    else z = ceil(z);

    cout << (int)x << ' ' << (int)y << ' ' << (int)z << endl;

}