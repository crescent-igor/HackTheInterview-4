// This code does not work

#include <bits/stdc++.h>
using namespace std;
string s;
string t;
int MOD = 1000000007;
int dp1[1000][2][1000];
int dp2[1000][2][1000];
int getNum(int pos, int tight, int count)
{
    // cout << pos << " " << count << " " << tight << endl;
    if (count == 0)
    {
        return 1;
    }
    if (pos == s.length())
    {

        return 0;
    }
    long long int ans = 0;
    if (tight)
    {

        if (s[pos] - '0' == 0)
        {
            if (dp1[pos + 1][1][count] == -1)
            {
                dp1[pos + 1][1][count] = getNum(pos + 1, 1, count) % MOD;
            }
            ans = (ans + dp1[pos + 1][1][count]) % MOD;
        }
        else
        {
            // cout << "here" << dp1[pos + 1][0][count] << endl;
            if (dp1[pos + 1][0][count] == -1)
            {
                dp1[pos + 1][0][count] = getNum(pos + 1, 0, count) % MOD;
            }
            ans = (ans + dp1[pos + 1][0][count]) % MOD;
            if (dp1[pos + 1][0][count - 1] == -1)
                dp1[pos + 1][0][count - 1] = getNum(pos + 1, 0, count - 1) % MOD;
            ans = (ans + ((s[pos] - '0' - 1) * dp1[pos + 1][0][count - 1]) % MOD) % MOD;
            if (dp1[pos + 1][1][count - 1] == -1)
                dp1[pos + 1][1][count - 1] = getNum(pos + 1, 1, count - 1) % MOD;
            ans = (ans + dp1[pos + 1][1][count - 1]) % MOD;
        }
    }
    else
    {
        if (dp1[pos + 1][0][count] == -1)
            dp1[pos + 1][0][count] = getNum(pos + 1, 0, count) % MOD;
        ans = (ans + dp1[pos + 1][0][count]) % MOD;
        if (dp1[pos + 1][0][count - 1] == -1)
            dp1[pos + 1][0][count - 1] = getNum(pos + 1, 0, count - 1) % MOD;
        ans = (ans + (9 * dp1[pos + 1][0][count - 1]) % MOD) % MOD;
    }
    return ans;
}
int getNumT(int pos, int tight, int count)
{
    // cout << pos << " " << count << " " << tight << endl;
    if (count == 0)
    {
        return 1;
    }
    if (pos == t.length())
    {

        return 0;
    }
    long long int ans = 0;
    if (tight)
    {

        if (t[pos] - '0' == 0)
        {
            if (dp2[pos + 1][1][count] == -1)
                dp2[pos + 1][1][count] = getNumT(pos + 1, 1, count) % MOD;
            ans = (ans + dp2[pos + 1][1][count]) % MOD;
        }
        else
        {
            if (dp2[pos + 1][0][count] == -1)
                dp2[pos + 1][0][count] = getNumT(pos + 1, 0, count) % MOD;
            ans = (ans + dp2[pos + 1][0][count]) % MOD;
            if (dp2[pos + 1][0][count - 1] == -1)
                dp2[pos + 1][0][count - 1] = getNumT(pos + 1, 0, count - 1) % MOD;
            ans = (ans + ((t[pos] - '0' - 1) * dp2[pos + 1][0][count - 1]) % MOD) % MOD;
            if (dp2[pos + 1][1][count - 1] == -1)
                dp2[pos + 1][1][count - 1] = getNumT(pos + 1, 1, count - 1) % MOD;
            ans = (ans + dp2[pos + 1][1][count - 1]) % MOD;
        }
    }
    else
    {
        if (dp2[pos + 1][0][count] == -1)
            dp2[pos + 1][0][count] = getNumT(pos + 1, 0, count) % MOD;
        ans = (ans + dp2[pos + 1][0][count]) % MOD;
        if (dp2[pos + 1][0][count - 1] == -1)
            dp2[pos + 1][0][count - 1] = getNumT(pos + 1, 0, count - 1) % MOD;
        ans = (ans + (9 * dp2[pos + 1][0][count - 1]) % MOD) % MOD;
    }
    return ans;
}

int main()
{
    // cout << MOD;
    int K;
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            dp1[i][0][j] = -1;
            dp1[i][1][j] = -1;
            dp2[i][0][j] = -1;
            dp2[i][1][j] = -1;
        }
    }
    cin >> s >> t >> K;
    // cout << (((getNumT(0, 1, K) % MOD) - (getNum(0, 1, K) % MOD)) % MOD);
    // cin >> s >> K;

    int ans2 = getNum(0, 1, K);
    int ans1 = getNumT(0, 1, K);
    int ans = ((ans1 % MOD) - (ans2 % MOD)) % MOD;
    // cout << ans1 << " " << ans2 << " " << ans << endl;
    // if (ans < 0)
    // {
        // cout << MOD + ans << endl;
    // }
    // else
    // {
        cout << ans << endl;
    // }
    return 0;
}