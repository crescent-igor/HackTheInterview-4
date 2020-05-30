#include <bits/stdc++.h>
using namespace std;
int main()
{
    int d;
    string s;
    cin >> s >> d;
    int l = s.length();
    int a = 0, b = 0, count = 0;
    while (a < s.length() && b < s.length())
    {
        if (s[b] == '0' && b - a + 1 == d)
        {
            count++;
            b++;
            a = b;
        }
        else if (s[b] == '0' && b - a + 1 < d)
        {
            b++;
        }
        else if (s[b] == '1')
        {
            b++;
            a = b;
        }
    }
    cout << count << endl;

    return 0;
}