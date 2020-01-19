#include<bits/stdc++.h>
using namespace std;

class PathFinders
{
    int n;
    vector <pair<int, int>> myGraph[25];

    void createGraph();
    void printList();
    void printMatrix();
    void dijkstra();
    void belmann();
    void allPath();
    void print1(int, int, vector <int>);
    void print2(int,int,vector <int>);
public:
    PathFinders(){}
    PathFinders(char);
    void process();
};

PathFinders::PathFinders(char ch)
{
    cout<<"An example"<<endl;
    n=5;
    myGraph[0].push_back(make_pair(1,3));
    myGraph[0].push_back(make_pair(2,8));
    myGraph[0].push_back(make_pair(4,-4));
    myGraph[1].push_back(make_pair(3,1));
    myGraph[1].push_back(make_pair(4,7));
    myGraph[2].push_back(make_pair(1,4));
    myGraph[3].push_back(make_pair(2,-5));
    myGraph[3].push_back(make_pair(0,2));
    myGraph[4].push_back(make_pair(3,6));
    printList();
    cout<<"For Dijkstra algorithm"<<endl;
    dijkstra();
    cout<<"For Belmann Ford algorithm"<<endl;
    belmann();
    cout<<"For Floyd Warshall algorithm"<<endl;
    allPath();
}

void PathFinders::printList()
{
    cout<<"The adjacency list for the graph entered is:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<i<<": ";
        for(int j=0;j<myGraph[i].size();j++)
        {
            cout<<"("<<myGraph[i][j].first<<":"<<myGraph[i][j].second<<")"<<"   ";
        }
        cout<<endl;
    }
}

void PathFinders::printMatrix()
{
    vector <vector <int>> arr(n, vector <int> (n, 0));

    cout<<"The adjacency matrix for the graph entered is:"<<endl;

    for(int i=0;i<n;i++)
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

void PathFinders::process()
{
    char ch;

    createGraph();

    int c2;
    cout<<"you want to adjacency list or matrix?(1/2)"<<endl;
    cin>>c2;

    if(c2==1)
        printList();
    else printMatrix();

    do{
        int c1;
        cout<<"Enter the algorithm you desire to execute"<<endl;
        cin>>c1;

        switch(c1)
        {
        case 1:dijkstra();
            break;
        case 2:belmann();
            break;
        case 3:allPath();
            break;
        default:cout<<"Wrong choice"<<endl;
        }

        cout<<"Do you want to execute another algorithm on the same graph?(Y/N)"<<endl;
        cin>>ch;

    }while(ch=='Y'||ch=='y');
    return;
}

void PathFinders::createGraph()
{
    int e, d, a, b, w;

    cout<<"enter the number of nodes and edges"<<endl;
    cin>>n>>e;

    cout<<"Directed graph or undirected graph?(1/0)"<<endl;
    cin>>d;

    if(d==1)
    {
        cout<<"enter the nodes of the edges along with thier weights (n1, n2, w)"<<endl;
        for(int i=0;i<e;i++)
        {
            cin>>a>>b>>w;
            myGraph[a].push_back(make_pair(b, w));
        }
    }
    else
    {
        cout<<"enter the nodes of the edges (n1, n2)"<<endl;
        for(int i=0;i<e;i++)
        {
            cin>>a>>b;
            myGraph[a].push_back(make_pair(b, 1));
            myGraph[b].push_back(make_pair(a, 1));
        }
    }
}

void PathFinders::print1(int source,int d,vector <int> parent)
{
    if(source==d)
    {
        return;
    }
    else if(parent[d]==-1)
    {
        cout<<" No path exists";
        return;
    }
    else
    {
        print1(source,parent[d],parent);
        cout<<"-->"<<parent[d];
    }
}

void PathFinders::print2(int i,int j,vector <int> parent)
{
    if(parent[j]<0)
    {
        return;
    }
    else if(i==parent[j])
    {
        return;
    }
    else
    {
        print2(i,parent[j],parent);
        cout<<"-->"<<parent[j];
    }
}

void PathFinders::dijkstra()
{
    int start;
    cout<<"Enter the starting node:";
    cin>>start;

    vector <int> dist(n, INT_MAX);
    vector <int> parent(n, -1);
    vector <int> status(n, 0);

    dist[start]=0;

    for(int i=0;i<n;i++)
    {
        int val=INT_MAX;
        int m;
        for(int i=0;i<n;i++)
        {
            if(status[i]==0)
            {
                if(dist[i]<=val)
                {
                    m=i;
                    val=dist[m];
                }
            }
        }
        int k=m;
        status[k]=1;

        for(int i=0;i<myGraph[k].size();i++)
        {
            int a=myGraph[k][i].first;
            int b=myGraph[k][i].second;
            if(status[a]==0)
            {
                if(dist[k]+b<dist[a])
                {
                    dist[a]=dist[k]+b;
                    parent[a]=k;
                }
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<i<<"  "<<dist[i]<<"  "<<parent[i]<<"  "<<endl;
    }

    for(int i=0;i<n;i++)
    {
        cout<<"Shortest path from "<<start<<" to "<<i<<" is of weight: "<<dist[i]<<" as follows : ";
        print1(start,i,parent);
        cout<<"-->"<<i<<endl;
    }
}

void PathFinders::belmann()
{
    vector <vector <int>> myArr;

    int e=0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<myGraph[i].size();j++)
        {
            vector <int> temp;
            temp.push_back(i);
            temp.push_back(myGraph[i][j].first);
            temp.push_back(myGraph[i][j].second);
            myArr.push_back(temp);
            e++;
        }
    }

    vector <int> dist(n, 1000);
    vector <int> parent(n, -1);

    int start;

    cout<<"enter the source node:";
    cin>>start;

    dist[start]=0;

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<e;j++)
        {
            int a=myArr[j][0];
            int b=myArr[j][1];
            int c=myArr[j][2];
            if(dist[a]==1000&&dist[b]==1000&&c<0)
                continue;
            if(dist[a]+c<dist[b])
            {
                dist[b]=dist[a]+c;
                parent[b]=a;
            }
        }
    }

    bool flag=false;
    for(int j=0;j<myArr.size();j++)
    {
        int a=myArr[j][0];
        int b=myArr[j][1];
        int c=myArr[j][2];

        if(dist[a]==1000&&dist[b]==1000&&c<0)
                continue;

        if(dist[a]+c<dist[b])
        {
            dist[b]=dist[a]+c;
            parent[b]=a;
            flag=true;
        }
    }

    if(flag==false)
    {
        for(int i=0;i<n;i++)
        {
            cout<<i<<"  "<<dist[i]<<"  "<<parent[i]<<"  "<<endl;
        }

        for(int i=0;i<n;i++)
        {
            cout<<"Shortest path from "<<start<<" to "<<i<<" is of weight: "<<dist[i]<<" as follows : ";
            print1(start,i,parent);
            cout<<"-->"<<i<<endl;
        }
    }
    else
        cout<<"negetive weighted cycle identified"<<endl;
}

void PathFinders::allPath()
{
    vector <vector <int>> dist(n, vector <int> (n, 1000));
    vector <vector <int>> parent(n, vector <int> (n, -1));

    for(int i=0;i<n;i++)
        dist[i][i]=0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<myGraph[i].size();j++)
        {
            int a=myGraph[i][j].first;
            int b=myGraph[i][j].second;
            dist[i][a]=b;
            parent[i][a]=i;
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if((dist[j][i]+dist[i][k])<dist[j][k])
                {
                    dist[j][k]=dist[j][i]+dist[i][k];
                    if(i>=1)
                        parent[j][k]=parent[i][k];
                }
            }
        }
    }

    cout<<"Minimum distance matrix is"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<dist[i][j]<<"\t";
        }
        cout<<endl;
    }

    cout<<"Path determinant matrix is"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<parent[i][j]<<"\t";
        }
        cout<<endl;
    }

    for(int i=0;i<n;i++)
    {
        vector <int> temp;
        temp=parent[i];

        for(int j=0;j<n;j++)
        {
            cout<<"The minimum distance from "<<i<<" to "<<j<<":"<<dist[i][j]<<" path: ";
            print2(i,j,temp);
            cout<<"-->"<<j<<endl;
        }
    }
}

int main()
{
    PathFinders obj2('*');
    cout<<"Now its your turn"<<endl;
    PathFinders obj1;
    obj1.process();
    return 0;
}
