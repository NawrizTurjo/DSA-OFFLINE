#include <bits/stdc++.h>
#include "vertex.cpp"
using namespace std;


int t = 0;
vertex *final = NULL;
bool dfsVisit(vector<vertex *> graph, vertex *u, int destination, vector<int> &vct)
{
    u->setColor(GRAY);
    u->setDistance(t);
    t++;
    vct.push_back(u->getIndex());
    if (u->getIndex() == destination)
    {
        final = u;
        return true;
    }
    bool found = false;
    for (int i = 0; i < u->getSize(); i++)
    {
        vertex *v = u->getAdj(i);
        if (v->getColor() == WHITE)
        {
            v->setParent(u);
            found = dfsVisit(graph, v, destination, vct);
            if (found)
                break;
        }
    }
    u->setColor(BLACK);
    return found;
}

void dfs(vector<vertex *> graph, int source, int destination, vector<int> &vct)
{
    vertex *u;
    u = graph[source];
    u->setDistance(0);
    bool found = dfsVisit(graph, u, destination, vct);
    if (found)
    {
        int vctSize = vct.size();
        cout << final->getDistance() << endl;
        for (int i = 0; i < vctSize; i++)
        {
            cout << vct[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "-1" << endl;
    }
}

int main()
{
    freopen("in1.txt","r",stdin); 
    freopen("out1.txt","w",stdout); 
    vector<vertex *> graph;
    int V, E;
    cin >> V >> E;
    for (int i = 0; i < V; i++)
    {
        graph.push_back(new vertex(i));
    }
    int s, d;
    for (int i = 0; i < E; i++)
    {
        cin >> s >> d;
        graph[s]->addEdge(graph[d]);
    }
    int source, destination;
    cin >> source >> destination;
    bool *vis = new bool[V];
    for (int i = 0; i < V; i++)
    {
        vis[i] = true;
    }
    vector<int> vct;
    dfs(graph, source, destination, vct);
    fclose(stdin);
    fclose(stdout);
    return 0;
}