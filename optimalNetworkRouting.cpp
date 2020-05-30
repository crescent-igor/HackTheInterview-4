#include <bits/stdc++.h>
using namespace std;
bool compare(vector<int> a, vector<int> b)
{
    return a[2] >= b[2];
}
int main()
{
    int n, m;
    vector<int> val;
    cin >> n >> m;
    int matrix[n][m];
    bool visited[n][m];
    int dis[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
            visited[i][j] = false;
            dis[i][j] = INT_MAX;
        }
    }
    dis[0][0] = 0;

    priority_queue<vector<int>, std::vector<vector<int>>, decltype(&compare)> pq(compare);
    pq.push({0, 0, 0});
    while (!visited[n - 1][m - 1] && !pq.empty())
    {
        val = pq.top();
        pq.pop();

        if (visited[val[0]][val[1]])
        {
            continue;
        }
        visited[val[0]][val[1]] = true;

        if (val[0] + 1 < n)
        {
            dis[val[0] + 1][val[1]] = min(max(dis[val[0]][val[1]], abs(matrix[val[0] + 1][val[1]] - matrix[val[0]][val[1]])), dis[val[0] + 1][val[1]]);
            pq.push({val[0] + 1, val[1], dis[val[0] + 1][val[1]]});
        }
        if (val[1] + 1 < m)
        {

            dis[val[0]][val[1] + 1] = min(max(dis[val[0]][val[1]], abs(matrix[val[0]][val[1] + 1] - matrix[val[0]][val[1]])), dis[val[0]][val[1] + 1]);
            pq.push({val[0], val[1] + 1, dis[val[0]][val[1] + 1]});
        }
        if (val[1] - 1 > -1)
        {

            dis[val[0]][val[1] - 1] = min(max(dis[val[0]][val[1]], abs(matrix[val[0]][val[1] - 1] - matrix[val[0]][val[1]])), dis[val[0]][val[1] - 1]);
            pq.push({val[0], val[1] - 1, dis[val[0]][val[1] - 1]});
        }
        if (val[0] - 1 > -1)
        {

            dis[val[0] - 1][val[1]] = min(max(dis[val[0]][val[1]], abs(matrix[val[0] - 1][val[1]] - matrix[val[0]][val[1]])), dis[val[0] - 1][val[1]]);
            pq.push({val[0] - 1, val[1], dis[val[0] - 1][val[1]]});
        }
    }
    cout << dis[n - 1][m - 1];
    return 0;
}