#include <bits/stdc++.h>
#include "vertex.cpp"
using namespace std;
#define MAX 52
bool isVisited[MAX];
bool isVisitedTranspose[MAX];
stack<vertex *> s;

void dfs(vector<vertex *> &graph, int u)
{
    if (isVisited[u])
        return;
    isVisited[u] = true;
    for (int i = 0; i < graph[u]->getSize(); i++)
        dfs(graph, graph[u]->getAdj(i)->getIndex());
    s.push(graph[u]);
}

void dfsTranspose(vector<vertex *> &transpose, int u, vector<int> &vct)
{
    if (isVisitedTranspose[u])
        return;
    isVisitedTranspose[u] = true;
    vct.push_back(u);
    for (int i = 0; i < transpose[u]->getSize(); i++)
        dfsTranspose(transpose, transpose[u]->getAdj(i)->getIndex(), vct);
}
bool isValidVct(vector<int> &vct)
{
    bool isValid = true;
    for (int i = 0; i < vct.size(); i++)
    {
        if (vct[i]%2)
        {
            for (int j = 0; j < vct.size(); j++)
            {
                if (vct[j] == vct[i] - 1)
                {
                    isValid = false;
                    return isValid;
                }
            }
        }
    }
    return isValid;
}

void checkValue(vector<vector<int>> &vct, int n1, int n2)
{
    int i1=0, i2=0;
    for (int i = 0; i < vct.size(); i++)
    {
        for (int j = 0; j < vct[i].size(); j++)
        {
            if (vct[i][j] == n1)
            {
                i1 = i;
            }
            if (vct[i][j] == n2)
            {
                i2 = i;
            }
        }
    }
    char ch = (n1)/2+'a';
    if (i1 > i2)
    {
        cout << ch << " True" << endl;
        return;
    }
    cout << ch << " False" << endl;
}

void kosaraju(vector<vertex *> &graph, vector<vertex *> &transpose)
{
    for (int i = 0; i < MAX; i++)
    {
        if (!isVisited[i])
            dfs(graph, i);
    }
    int i = 0;
    bool isValid = true;
    vector<vector<int>> vct;
    while (!s.empty())
    {
        vertex *u = s.top();
        s.pop();

        if (!isVisitedTranspose[u->getIndex()])
        {
            vector<int> curr;
            dfsTranspose(transpose, u->getIndex(), curr);
            if (!isValidVct(curr))
            {
                cout << "No assignment possible";
                return;
            }
            vct.push_back(curr);
            i++;
        }
    }
    for (int i = 0; i <= 52; i += 2)
    {
        if (graph[i]->getSize() > 0 || transpose[i]->getSize() > 0)
        {
            checkValue(vct, i, i + 1);
        }
    }
}

void toNum(string s1, string s2, vector<vertex *> &graph, vector<vertex *> &transpose)
{
    int num1 = 0;
    if (s1[0] == '~')
    {
        num1 = ((s1[1] - 'a') * 2) + 1;
    }
    else
    {
        num1 = (s1[0] - 'a') * 2;
    }
    int num2 = 0;
    if (s2[0] == '~')
    {
        num2 = ((s2[1] - 'a') * 2) + 1;
    }
    else
    {
        num2 = (s2[0] - 'a') * 2;
    }
    if (num1 % 2 == 0 && num2 % 2 == 0)
    {
        graph[num1 + 1]->addEdge(graph[num2]);
        graph[num2 + 1]->addEdge(graph[num1]);
        transpose[num1]->addEdge(transpose[num2 + 1]);
        transpose[num2]->addEdge(transpose[num1 + 1]);
    }
    else if (num1 % 2 == 1 && num2 % 2 == 0)
    {
        graph[num1 - 1]->addEdge(graph[num2]);
        graph[num2 + 1]->addEdge(graph[num1]);
        transpose[num1]->addEdge(transpose[num2 + 1]);
        transpose[num2]->addEdge(transpose[num1 - 1]);
    }
    else if (num1 % 2 == 0 && num2 % 2 == 1)
    {
        graph[num1 + 1]->addEdge(graph[num2]);
        graph[num2 - 1]->addEdge(graph[num1]);
        transpose[num1]->addEdge(transpose[num2 - 1]);
        transpose[num2]->addEdge(transpose[num1 + 1]);
    }
    else
    {
        graph[num1 - 1]->addEdge(graph[num2]);
        graph[num2 - 1]->addEdge(graph[num1]);
        transpose[num1]->addEdge(transpose[num2 - 1]);
        transpose[num2]->addEdge(transpose[num1 - 1]);
    }
}
void toNum(string s, vector<vertex *> &graph, vector<vertex *> &transpose)
{
    int num = 0;
    if (s[0] == '~')
    {
        num = ((s[1] - 'a') * 2) + 1;
    }
    else
    {
        num = (s[0] - 'a') * 2;
    }
    if (num % 2)
    {
        graph[num - 1]->addEdge(graph[num]);
        transpose[num]->addEdge(transpose[num - 1]);
    }
    else
    {
        graph[num + 1]->addEdge(graph[num]);
        transpose[num]->addEdge(transpose[num + 1]);
    }
}

void formatString(string str, vector<vertex *> &graph, vector<vertex *> &transpose)
{
    stringstream ss(str);
    vector<string> words;
    while (ss >> str)
    {
        words.push_back(str);
    }
    if (words.size() == 1)
    {
        toNum(words[0], graph, transpose);
    }
    else
    {
        toNum(words[0], words[1], graph, transpose);
    }
}

int main()
{
    freopen("in48_.txt","r",stdin);
    freopen("myout.txt","w",stdout);
    int n;
    cin >> n;
    cin.ignore(1, '\n');
    string input;
    vector<vertex *> graph;
    vector<vertex *> transpose;
    for (int i = 0; i < 52; i++)
    {
        graph.push_back(new vertex(i));
        transpose.push_back(new vertex(i));
    }
    for (int i = 0; i < n; i++)
    {
        getline(cin, input);
        formatString(input, graph, transpose);
    }
    kosaraju(graph, transpose);
    for (int i = 0; i < 52; i++)
    {
        delete graph[i];
        delete transpose[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*

5
~a ~b 
b c 
~c d
a d
d ~a

4
~a b
~b c
~c ~d
~d a


5
z ~t
a h
l ~q
~h ~a
t h

*/