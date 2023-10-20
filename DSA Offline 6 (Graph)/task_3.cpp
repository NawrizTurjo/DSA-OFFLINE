#include <bits/stdc++.h>
using namespace std;

bool isValid(int x, int y, vector<vector<bool>> &isVisited, int n, int m)
{
    return (x >= 0 && x < n && y >= 0 && y < m && !isVisited[x][y]);
}

void bfsRider(int sourceX, int sourceY, vector<vector<pair<int, vector<int>>>> &graph, int n, int m)
{
    int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
    vector<vector<bool>> isVisited(n, vector<bool>(m, false));
    vector<vector<int>> distance(n, vector<int>(m, -1));    
    queue<pair<int, int>> q;
    q.push(make_pair(sourceX, sourceY));
    isVisited[sourceX][sourceY] = true;
    graph[sourceX][sourceY].first += 1;
    distance[sourceX][sourceY] = 0;
    graph[sourceX][sourceY].second.push_back(0); 
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        for (int i = 0; i < 8; i++)
        {
                int next_x = x +  dx[i];
                int next_y = y +  dy[i];
                if (isValid(next_x, next_y, isVisited, n, m))
                {
                    isVisited[next_x][next_y] = true;
                    graph[next_x][next_y].first += 1;
                    distance[next_x][next_y] = distance[x][y] + 1;
                    graph[next_x][next_y].second.push_back(distance[next_x][next_y]);
                    q.push(make_pair(next_x, next_y));
                }
        }
    }
}

int main()
{
    freopen("in3.txt","r",stdin); 
    freopen("out3.txt","w",stdout); 
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<pair<int, vector<int>>>> graph(n, vector<pair<int, vector<int>>>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            graph[i][j].first = 0;
            graph[i][j].second = vector<int>();
        }
    }

    int t1, t2;
    int *k = new int[q];
    for (int i = 0; i < q; i++)
    {
        cin >> t1 >> t2 >> k[i];
        bfsRider(t1, t2, graph, n, m);
    }
    int min = INT16_MAX;
    bool isAvailable = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j].first == q)
            {
                isAvailable = true;
                int sum = 0;
                for (int i1 = 0; i1 < graph[i][j].second.size(); i1++)
                {
                    sum += ceil(1.0 * graph[i][j].second[i1]/(1.0 * k[i1]));
                }
                if (sum < min)
                {
                    min = sum;
                }
            }
        }
    }
    if (isAvailable)
    {
        cout << min << endl;
    }
    else
    {
        cout << "-1" << endl;
    }
    delete k;
    fclose (stdin);
    fclose (stdout);
    return 0;
}
