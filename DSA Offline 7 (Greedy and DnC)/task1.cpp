#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define UP 1
#define DOWN -1
#define INVALID 0

vector<pair<int, int>> v;
vector<pair<int, int>> s;

int getDistance(pair<int, int> p1, pair<int, int> p2, pair<int, int> p)
{
    return abs((p.second - p1.second) * (p1.first - p2.first) - (p.first - p1.first) * (p1.second - p2.second));
}

int getDirection(pair<int, int> p1, pair<int, int> p2, pair<int, int> p)
{
    int side = ((p.second - p1.second) * (p1.first - p2.first) - (p.first - p1.first) * (p1.second - p2.second));
    if (side > 0)
        return UP;
    if (side < 0)
        return DOWN;
    return INVALID;
}

void recurFindFences(vector<pair<int, int>> v, pair<int, int> p1, pair<int, int> p2, int side)
{
    bool flag = false;
    int maxDistance = 0;
    int maxDistanceIndex = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int dist = getDistance(p1, p2, v[i]);
        if (getDirection(p1, p2, v[i]) == side && dist > maxDistance)
        {
            maxDistanceIndex = i;
            flag = true;
            maxDistance = dist;
        }
    }
    if (!flag)
    {
        s.push_back(p1);
        s.push_back(p2);
        return;
    }
    recurFindFences(v, p1, v[maxDistanceIndex], -getDirection(p1, v[maxDistanceIndex], p2));
    recurFindFences(v, p2, v[maxDistanceIndex], -getDirection(p2, v[maxDistanceIndex], p1));
}

void findFences(vector<pair<int, int>> v)
{
    int maxXIndex = 0, minXIndex = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].first > v[maxXIndex].first)
        {
            maxXIndex = i;
        }
        if (v[i].first < v[minXIndex].first)
        {
            minXIndex = i;
        }
    }
    s.push_back(v[maxXIndex]);
    s.push_back(v[minXIndex]);
    
    recurFindFences(v, v[maxXIndex], v[minXIndex], UP);
    recurFindFences(v, v[maxXIndex], v[minXIndex], DOWN);
    
    sort(s.begin(), s.end());
    auto i = unique(s.begin(), s.end());
    s.erase(i, s.end());
    for (pair p : s)
    {
        cout << p.first << " " << p.second << endl;
    }
}

int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int n;
    cin >> n;
    pair<int, int> p;
    for (int i = 0; i < n; i++)
    {
        cin >> p.first >> p.second;
        v.push_back(p);
    }
    findFences(v);
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}