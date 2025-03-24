#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int n;
int arr[300005];
int pos[300005];
//int gotta_change[300005];

int seg[300005];

int query(int idx, int ql, int qr, int l, int r)
{
    if(ql <= l && r <= qr)
        return seg[idx];
    else if(qr < l || r < ql)
        return 0;
    int mid = (l + r) / 2;
    int a = query(idx * 2, ql, qr, l, mid);
    int b = query(idx * 2 + 1, ql, qr, mid + 1, r);
    return a + b;
}

void update(int idx, int k, int l, int r)
{
    if(l == k && k == r)
    {
        seg[idx]++;
        return;
    }
    else if(r < k || k < l)
        return;
    int mid = (l + r) / 2;
    update(idx * 2, k, l, mid);
    update(idx * 2 + 1, k, mid + 1, r);
    seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
}

int main ()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        pos[arr[i]] = i;
    }
    int cost = n;
    vector<int> gotta_change;
    for(int i = n - 1; i >= 0; i--)
    {
        if(arr[i] == cost)
            cost--;
        else
            gotta_change.push_back(i);//gotta_change[i]++;
    }
    set<ii> ans;
    for(int i = 0; i < gotta_change.size(); i++)
    {
        int idx = gotta_change[i];
        int ans1 = query(1, arr[idx], n, 1, n);
        update(1, arr[idx], 1, n);
        ans.insert(ii(-arr[idx], ans1 + 1));
    }
    printf("%d %d\n", ans.size(), ans.size());
    for(auto c:ans)
        printf("%d %d\n", pos[-c.first] + c.second, 1);
}
/*
4
1 2 4 3
*/

