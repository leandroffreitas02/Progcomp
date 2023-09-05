#include <bits/stdc++.h>

using namespace std;

vector<vector<long long>> p(50);

void pascal(){
    for(int i = 1; i < 50; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0 || j == i)
                p[i].push_back(1);
            
            else{
                p[i].push_back(p[i-1][j-1] + p[i-1][j]);
            }
        }
    }
}

int main(){
    p[0].push_back(1);

    pascal();

    for(auto i: p){
        for(auto j: i)
            cout << j << ' ';
        cout << endl;
    }
    cout << endl;
}