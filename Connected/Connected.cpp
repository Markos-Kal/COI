#include "Grader.h"
using namespace std;

string encode(string con, string q, int a, int b)
{
    for(int i = a; i <= b; i++)
    {
        if(con[i] == '1')
            b++;
        else
            q[i] = '1';
    }
    return q;
}

string encode2(string q, set<int> s)
{
    for(auto c:s)
        q[c] = '1';
    return q;
}

int ith(string q, int k)
{
    for(int i = 0; i < q.size(); i++)
    {
        if(q[i]=='0')
            k--;
        if(k == 0)
            return i;
    }
}

void solve(int n)
{
    int deg[200];
    string q="", mt="";
    for(int i = 0; i < n; i++)
        q+="0";
    mt = q;
    for(int i = 0; i < n; i++)
    {
        q[i] = '1';
        deg[i] = ask(q);
        q[i] = '0';
    }
    for(int i = 0; i < n; i++)
        printf("%d\n", deg[i]);
    q = mt;
    q[0] = '1';
    set<int> connected;
    connected.insert(0);
    for(int i = 0; i < n && connected.size() < n; i++)
    {
        cout << i << " " << encode2(mt, connected) << endl;
        int degc = ask(encode2(mt, connected));
        int l = 1, r = n - i - 1;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            string temp = mt;
            temp = encode(encode2(mt, connected), temp, l, mid);
            int dept = ask(temp);
            cout << l << " " << r << " " << temp << " " << dept << endl;
            temp = encode2(temp, connected);
            int deptot = ask(temp);
            cout << "new temp: " << temp << " " << deptot << " degc: " << degc << endl;
            if((degc + dept - 2 >= deptot))
            {
                cout << "Connected, going deeper" << endl;
                if (l == mid){
                    cout << "Connected with node, breaking" << endl;
                    connected.insert(ith(encode2(mt, connected), mid));
                    break;
                }
                r = mid;
            }
            else{
                cout << "Not connected, going other way" << endl;
                l = mid + 1;
            }
        }
        if(connected.size() != i + 2)
        {
            tell(0);
            return;
        }
    }
    tell(1);

}

int main()
{
    int n = init();
    solve(n);
}
