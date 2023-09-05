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
    int n, f; cin >> n >> f;

    bool ans = true;

    while(n--){
        int a, b; cin >> a >> b;

        if(a <= f && b <= f)
            f += max(a, b);
        
        else if(a <= f || b <= f)
            f += min(a, b);
        
        else ans = 0;
    }

    cout << (ans ? "S" : "N") << endl;
}
