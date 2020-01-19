#include<bits/stdc++.h>
using namespace std;

class PathFinders
{
    vector <pair<int, int>> PathFinders::createGraph();
    void printList(vector <pair<int, int>> myGraph);
    void printMatrix(vector <pair<int, int>> myGraph);
    void dijkstra(vector <pair<int, int>> myGraph);
    void belmann(vector <pair<int, int>> myGraph);
    void allNode(vector <pair<int, int>> myGraph);
public:
    void process();
};

void PathFinders::printList(vector <pair<int, int>> myGraph);
{
    cout<<"The adjacency list for the graph entered is:"<<endl;
    for(int i=0;i<myGraph.size();i++)
    {
        cout<<i<<": ";
        for(int j=0;j<myGraph[i].size();j++)
        {
            cout<<"("<<myGraph[i][j].first<<":"<<myGraph[i][j].second<<")"<<"   ";
        }
        cout<<endl;
    }
}

void PathFinders::printMatrix(vector <pair<int, int>> myGraph);
{
    int n=myGraph.size();
    vector <vector <int>> arr(n, vector <int> (n, 0));

    cout<<"The adjacency matrix for the graph entered is:"<<endl;

    for(int i=0;i<myGraph.size();i++)
        for(int j=0;j<myGraph[i].size();j++)
            arr[i][myGraph[i][j].first]=myGraph[i][j].second;

    for(int i=0;i<n;i++)
    {
        cout<<i<<": ";
        for(int j=0;j<n;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }

}

void PathFinder::process()
{
    vector <pair<int, int>> myGraph=createGraph();

    int c2;
    cout<<"you want to adjacency list or matrix?(1/2)"<<endl;
    cin>>c2;

    if(c2==1)
        printList(myGraph);
    else printMatrix(myGraph);

    int c1;
    cout<<"Enter the algorithm you desire to execute"<<endl;
    cin>>c1;

    switch(c1)
    {
    case 1:dijkstra(myGraph);
        break;
    case 2:belmann(myGraph);
        break;
    case 3:allPath(myGraph);
        break;
    default:    cout<<"Wrong choice"<<endl;
                return;
    }
}

vector <pair<int, int>> PathFinders::createGraph()
{
    int n, e, d, a, b, w;

    cout<<"enter the number of nodes and edges"<<endl;
    cin>>n>>e;

    vector <pair<int, int>> myGraph[n];

    cout<<"Directed graph or undirected graph?(1/0)"<<endl;
    cin>>d;

    if(d==1)
    {
        for(int i=0;i<e;i++)
        {
            cin>>a>>b>>w;
            myGraph[a].push_back(make_pair(b, w));
            myGraph[b].push_back(make_pair(a, w));
        }
    }
    else
    {
        for(int i=0;i<e;i++)
        {
            cin>>a>>b>>w;
            myGraph[a].push_back(make_pair(b, w));
            myGraph[b].push_back(make_pair(a, w));
        }
    }
    return myGraph;
}

int main()
{
    PathFinders obj1;
    obj1.process();
    return 0;
}
