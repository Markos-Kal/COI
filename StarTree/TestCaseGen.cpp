#include "TreeGenerator.cpp"
using namespace std;

int n;

int ans[1000001];
vector<int> al[1000001];

int main() {
    int T = 20;
    while(T--)
    {
        string tci = to_string(20 - T);
        tci += "_in.txt";
        generateRandomTree(1000000, tci);
        ifstream fin(tci);
        fin >> n;
        for(int i = 0; i < n - 1; i++)
        {
            int x, y;
            fin >> x >> y;
            al[x].push_back(y);
            al[y].push_back(x);
        }
        cout << "READ TREE" << endl;
        string tco = to_string(20 - T);
        tco += "_out.txt";
        ofstream fout(tco);
        /*for(int i = 1; i <= n; i++)
        {
            dfs(i, i, -1, 0);
            fout << ans[i] << endl;
        }*/
        for(int i = 1; i <= n; i++){
            ans[i] = n - 1 - al[i].size();
            fout << ans[i] << endl;
            al[i].clear();
        }
        for (int i = 1; i <= 5000; i++)
            ans[i] = 0;
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
