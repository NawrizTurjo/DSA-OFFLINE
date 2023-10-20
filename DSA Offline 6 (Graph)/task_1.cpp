#include <bits/stdc++.h>
#include "vertex.cpp"
using namespace std;

void printShortestPath(vertex *source, vertex *destination)
{
    if (destination->getIndex() == source->getIndex())
    {
        cout << source->getIndex() << " ";
        return;
    }

    printShortestPath(source, destination->getParent());
    cout << destination->getIndex() << " ";
}

void bfs(vector<vertex *> graph, int source, int destination)
{
    queue<vertex *> q;

    graph[source]->setColor(GRAY);
    graph[source]->setDistance();
    graph[source]->setParent(NULL);
    vertex *v;
    vertex *dest;
    q.push(graph[source]);
    bool isVisited = false;
    while (!q.empty())
    {
        vertex *u = q.front();
        q.pop();
        for (int i = 0; i < u->getSize(); i++)
        {
            v = u->getAdj(i);
            if (v->getColor() == WHITE)
            {
                v->setColor(GRAY);
                v->setDistance(u->getDistance() + 1);
                q.push(v);
                if (v->getIndex() == destination)
                {
                    isVisited = true;
                    dest = v;
                }
                v->setParent(u);
            }
        }
        u->setColor(BLACK);
    }
    if (isVisited)
    {
        cout << dest->getDistance() << endl;
        printShortestPath(graph[source], dest);
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
    bfs(graph, source, destination);
    fclose(stdin);
    fclose(stdout);
    return 0;
}