#include <bits/stdc++.h>
using namespace std;

int n;

vector<int> al[100001];

int ans[100001];
int depth[100001];
int anc[50][100001];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n - 1; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        al[x].push_back(y);
        al[y].push_back(x);
    }
    for(int i = 1; i <= n; i++){
        ans[i] = n - 1 - al[i].size();
        printf("%d\n", ans[i]);
    }
}

/*
5
1 2
2 3
3 4
4 5

6
1 3
1 6
2 5
3 5
4 5
*/
