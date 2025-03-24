#include "TreeGenerator.cpp"
using namespace std;

int n;

vector<int> al[100001];

int ans[100001];

void dfs(int s, int n, int p, int depth)
{
    for(int i = 0; i < al[n].size(); i++)
    {
        if(al[n][i] != p)
            dfs(s, al[n][i], n, depth + 1);
    }
    if(depth > 1)
        ans[s]++;
}

int main() {
    cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        al[x].push_back(y);
        al[y].push_back(x);
    }
    for(int i = 1; i <= n; i++)
    {
        dfs(i, i, -1, 0);
        cout << ans[i] << endl;
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
