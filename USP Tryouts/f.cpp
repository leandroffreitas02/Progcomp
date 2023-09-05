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

    int n, q; cin >> n >> q;

    map<int, set<int>> m;
    vector<int> v;

    for(int i = 0; i < n; i++){
        int x; cin >> x;

        m[x].pb[i];
    }

    while(q--){
        int c; cin >> c;

        if(c == 0){
            int i, x; cin >> i >> x;
            i--;

            m[x].insert(i);

            m[v[i]].erase(i);
            v[i] = x;
        }
        else{
            int l, r; cin >> l >> r;
            l--;
            r--;
            int pares=0;

            for (auto posicoes : m)
            {
                int encontrados=0;
                for (auto pos : posicoes)
                {
                    if (pos>=l & pos<=r)
                    {
                        encontrados++;    
                        pares=floor(encontrados/2.0);
                    }
                }
                if (pares>=2)
                {
                    break;
                }
                
            }
            if (pares>=2)
            {
                cout << "S" << endl;
            }
            else
            {
                cout << "N" << endl;
            }
        }
    }
}