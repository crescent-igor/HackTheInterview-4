dp1 = [[[-1 for x in range(101)] for x in range(2)] for x in range(101)]
dp2 = [[[-1 for x in range(101)] for x in range(2)] for x in range(101)]

l = input()
r = input()
K = int(input())
MOD = int(1e9+7)


def getNuml(pos, tight, count):
    if(count == 0):
        return 1
    if(pos == len(l)):
        return 0
    ans = 0
    if(tight):
        if(int(l[pos]) == 0):
            if(dp1[pos + 1][1][count] == -1):
                dp1[pos + 1][1][count] = getNuml(pos + 1, 1, count) % MOD
            ans = (ans + dp1[pos + 1][1][count]) % MOD
        else:
            if (dp1[pos + 1][0][count] == -1):
                dp1[pos + 1][0][count] = getNuml(pos + 1, 0, count) % MOD
            ans = (ans + dp1[pos + 1][0][count]) % MOD
            if (dp1[pos + 1][0][count - 1] == -1):
                dp1[pos + 1][0][count -
                                1] = getNuml(pos + 1, 0, count - 1) % MOD
            ans = (ans + ((int(l[pos]) - 1) *
                          dp1[pos + 1][0][count - 1]) % MOD) % MOD
            if (dp1[pos + 1][1][count - 1] == -1):
                dp1[pos + 1][1][count -
                                1] = getNuml(pos + 1, 1, count - 1) % MOD
            ans = (ans + dp1[pos + 1][1][count - 1]) % MOD
    else:
        if (dp1[pos + 1][0][count] == -1):
            dp1[pos + 1][0][count] = getNuml(pos + 1, 0, count) % MOD
        ans = (ans + dp1[pos + 1][0][count]) % MOD
        if (dp1[pos + 1][0][count - 1] == -1):
            dp1[pos + 1][0][count - 1] = getNuml(pos + 1, 0, count - 1) % MOD
        ans = (ans + (9 * dp1[pos + 1][0][count - 1]) % MOD) % MOD
    return ans


def getNumr(pos, tight, count):
    if(count == 0):
        return 1
    if(pos == len(r)):
        return 0
    ans = 0
    if(tight):
        if(int(r[pos]) == 0):
            if(dp2[pos + 1][1][count] == -1):
                dp2[pos + 1][1][count] = getNumr(pos + 1, 1, count) % MOD
            ans = (ans + dp2[pos + 1][1][count]) % MOD
        else:
            if (dp2[pos + 1][0][count] == -1):
                dp2[pos + 1][0][count] = getNumr(pos + 1, 0, count) % MOD
            ans = (ans + dp2[pos + 1][0][count]) % MOD
            if (dp2[pos + 1][0][count - 1] == -1):
                dp2[pos + 1][0][count -
                                1] = getNumr(pos + 1, 0, count - 1) % MOD
            ans = (ans + ((int(r[pos]) - 1) *
                          dp2[pos + 1][0][count - 1]) % MOD) % MOD
            if (dp2[pos + 1][1][count - 1] == -1):
                dp2[pos + 1][1][count -
                                1] = getNumr(pos + 1, 1, count - 1) % MOD
            ans = (ans + dp2[pos + 1][1][count - 1]) % MOD
    else:
        if (dp2[pos + 1][0][count] == -1):
            dp2[pos + 1][0][count] = getNumr(pos + 1, 0, count) % MOD
        ans = (ans + dp2[pos + 1][0][count]) % MOD
        if (dp2[pos + 1][0][count - 1] == -1):
            dp2[pos + 1][0][count - 1] = getNumr(pos + 1, 0, count - 1) % MOD
        ans = (ans + (9 * dp2[pos + 1][0][count - 1]) % MOD) % MOD
    return ans


print(((getNumr(0, 1, K) % MOD)-(getNuml(0, 1, K) % MOD)) % MOD)
# print(getNuml(0, 1, K))
