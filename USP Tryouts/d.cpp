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

    int n, k; cin >> n >> k;

    int count = 1;

    vector<queue<ii>> v(k);
    vector<ii> exit;

    for(int i = 0; i < 2*n; i++){
        int c; cin >> c;

        if(c == 1){
            int p, q; cin >> p >> q;

            v[q-1].push(mp(count++, p));
        }
        if(c == 2){
            int q; cin >> q;

            ii p = v[q-1].front(); v[q-1].pop();

            exit.pb(p);
        }
    }

    int aux = 1;
    vector<int> ans;

    for(auto e: exit){
        aux = max(aux, e.f);

        if(aux > e.f)
            ans.pb(e.s);
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << endl;

    for(auto i: ans)
        cout << i << ' ';
    cout << endl;
}