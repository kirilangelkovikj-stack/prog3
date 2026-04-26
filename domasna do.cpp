#include <bits/stdc++.h>

using namespace std;

int coin_change(int c,vector<int>& coins,vector<int>& used) {
    vector<int>dp(c+1, INT_MAX);
    vector<int>parent(c+1,-1);
    dp[0]=0;
    for (int i=1;i<=c;i++) {
        for (int coin :coins) {
            if (i - coin >= 0 && dp[i -coin] !=INT_MAX) {
                if (dp[i] > dp[i -coin] + 1) {
                    dp[i] = dp[i -coin] + 1;
                    parent[i] = coin;
                }
            }
        }
    }
    if (dp[c]==INT_MAX) return -1;
    int cur=c;
    while (cur > 0) {
        used.push_back(parent[cur]);
        cur -= parent[cur];
    }

    return dp[c];
}
int main() {
    vector<int>coins = {1, 3, 11, 21};
    int n;
    cin >> n;
    while (n--) {
        int c;
        cin>>c;
        vector<int> used;
        int result=coin_change(c, coins, used);
        if (result==-1) {
            return 0;
        } else {
            cout<<result<<endl;
            cout
            <<"Koristeni moneti: ";

            for (int coin:used) {
                cout<<coin<< " ";
            }
            cout<<endl;
        }
        cout<<"-------------------\n";
    }
    return 0;
}
