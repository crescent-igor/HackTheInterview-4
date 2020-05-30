#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> boys(n);
        vector<int> girls(n);
        for (int i = 0; i < n; i++)
        {
            cin >> boys[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> girls[i];
        }
        sort(boys.begin(), boys.end());
        sort(girls.begin(), girls.end());
        bool possibility1 = true, possibility2 = true;
        if (boys[0] <= girls[0])
        {
            for (int i = 1; i < n; i++)
            {
                if (boys[i] >= girls[i - 1] && boys[i] <= girls[i])
                {
                    continue;
                }
                possibility1 = false;
                break;
            }
        }
        else
        {
            possibility1 = false;
        }
        if (girls[0] <= boys[0])
        {
            for (int i = 1; i < n; i++)
            {
                if (girls[i] >= boys[i - 1] && girls[i] <= boys[i])
                {
                    continue;
                }
                possibility2 = false;
                break;
            }
        }
        else
        {
            possibility2 = false;
        }
        if (possibility1 || possibility2)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}