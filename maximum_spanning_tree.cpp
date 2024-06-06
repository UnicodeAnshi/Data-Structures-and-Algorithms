#include <bits/stdc++.h>
using namespace std;
struct node
{
    int parent;
    int rank;
};
struct edge
{
    int src;
    int dst;
    int wt;
};
bool comparator(const edge &e1, const edge &e2)
{
    return e1.wt > e2.wt;
}
int find(int v, vector<node> &dsuf)
{
    if (dsuf[v].parent == -1)
        return v;
}

void union_op(int fromP, int toP, vector<node> &dsuf)
{
    if (dsuf[fromP].rank > dsuf[toP].rank)
        dsuf[toP].parent = fromP;
    else if (dsuf[fromP].rank < dsuf[toP].rank)
        dsuf[fromP].parent = toP;
    else
    {
        dsuf[fromP].parent = toP;
        dsuf[toP].rank += 1;
    }
}

void kruskals(vector<edge> &Edges, vector<node> &dsuf, int V, int E, vector<edge> &mst)
{
    sort(Edges.begin(), Edges.end(), comparator);
    int i = 0, j = 0;
    while (i < V - 1 && j < E)
    {
        int fromP = find(Edges[j].src, dsuf);
        int toP = find(Edges[j].dst, dsuf);

        if (fromP == toP)
        {
            // Implemented By : ANSHIKA SHARMA ROLL NO : 12 SECTION : A1, CSE(4th) j++;
            continue;
        }
        union_op(fromP, toP, dsuf);
        mst.push_back(Edges[j]);
        i++;
    }
}

void printMst(vector<edge> &mst)
{
    int sum = 0;
    for (auto p : mst)
    {
        sum += p.wt;
    }
    cout << "Maximum Spanning Weight = " << sum << endl;
}

int main()
{
    int V, E;
    cout << "Enter No. of Vertices and Edges: ";
    cin >> V >> E;
    vector<edge> Edges(E);
    vector<node> dsuf(V);

    for (int i = 0; i < V; i++)
    // Implemented By : ANSHIKA SHARMA ROLL NO : 12 SECTION : A1, CSE(4th)
    {
        dsuf[i].parent = -1;
        dsuf[i].rank = 0;
    }
    cout << "Enter Edges along with weight:" << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        Edges[i].src = u;
        Edges[i].dst = v;
        Edges[i].wt = wt;
    }
    vector<edge> mst;
    kruskals(Edges, dsuf, V, E, mst);
    printMst(mst);
    return 0;
}