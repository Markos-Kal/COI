#include <bits/stdc++.h>
using namespace std;

vector<int> al[202];
bool connected;

int init()
{
    int n, m;
    freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        al[x].push_back(y);
        al[y].push_back(x);
        cout<<x<<" "<<y<<endl;
    }
    connected = true;
    return n;
}

int ask(string s)
{
    set<int> ans;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '1')
        {
            for(int j = 0; j < al[i].size(); j++)
            {
                if(s[al[i][j]] == '0')
                    ans.insert(al[i][j]);
            }
        }
    }
    return ans.size();
}

void tell(int ans)
{
    cout << (ans ? ("Connected") : ("Not connected")) << endl;
}

