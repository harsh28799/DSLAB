#include<bits/stdc++.h>
using namespace std;

class Topology
{
    vector <int> myGraph[50];
    unordered_map <int, string> its;
    unordered_map <string, int> sti;

    int s, r, t;

    int m;

    void printList();
    void createRing(int n);
    void createStar(int n);
    void createTree(int n);
    void createHybrid();
public:
    Topology()
    {
        s=0;
        r=0;
        t=0;
        m=s+t+r;
    }
    void process();
};

void Topology::printList()
{
    for(int i=0;i<m;i++)
    {
        string a=its[i];
        cout<<a<<": ";
        for(int j=0;j<myGraph[i].size();j++)
        {
            string b=its[myGraph[i][j]];
            cout<<b<<" ";
        }
        cout<<endl;
    }
}

void Topology::createRing(int n)
{
    for(int i=0;i<n;i++)
    {
        if(i<n-1)
        {
            myGraph[i+m].push_back(i+1+m);
            myGraph[i+1+m].push_back(i+m);
        }
        else
        {
            myGraph[i+m].push_back(m);
            myGraph[m].push_back(i+m);
        }
    }
    for(int i=0;i<n;i++)
    {
        string str="r"+to_string(r)+to_string(i);
        int k=m+i;
        its[k]=str;
        sti[str]=k;
    }

    m=m+n;
    r++;
}

void Topology::createStar(int n)
{
    for(int i=1;i<n;i++)
    {
        myGraph[i+m].push_back(m);
        myGraph[m].push_back(i+m);
    }

    for(int i=0;i<n;i++)
    {
        string str="s"+to_string(s)+to_string(i);
        int k=m+i;
        its[k]=str;
        sti[str]=k;
    }

    m=m+n;
    s++;
}

void Topology::createTree(int n)
{
    bool flag=true;
    int k=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<2;j++)
        {
            myGraph[i+m].push_back(k+m);
            myGraph[k+m].push_back(i+m);
            k++;
            if(k>=n)
            {
                flag=false;
                break;
            }
        }
        if(flag==false)
            break;
    }

    for(int i=0;i<n;i++)
    {
        string str="t"+to_string(t)+to_string(i);
        int k=m+i;
        its[k]=str;
        sti[str]=k;
    }

    m=m+n;
    t++;
}

void Topology::createHybrid()
{
    char ch;
    do{
        cout<<"enter the two nodes you desire communicate"<<endl;
        string a;
        string b;
        cin>>a>>b;

        if(sti.find(a)==sti.end()||sti.find(b)==sti.end())
            cout<<"The nodes you entered do not exist"<<endl;
        else
        {
            int x=sti[a];
            int y=sti[b];
            myGraph[x].push_back(y);
            myGraph[y].push_back(x);
        }

        cout<<"Do you need more communication links?(Y/N)"<<endl;
        cin>>ch;

    }while(ch=='y'||ch=='Y');
}

void Topology::process()
{
    int choice;
    char ch;
    cout<<"Enter your choice:"<<endl<<"1:Star Topology"<<endl<<"2:Ring Topology"<<endl<<"3:Tree Topology"<<endl;
    do{
        int n;
        cout<<"Enter your choice:";
        cin>>choice;
        cout<<"Enter the number of nodes:";
        cin>>n;
        if(choice>=1&&choice<=3)
        {
            switch(choice)
            {
            case 1:createRing(n);
            break;
            case 2:createStar(n);
            break;
            case 3:createTree(n);
            break;
            default: break;
            }
        }
        else cout<<"Wrong choice"<<endl;
        cout<<"Do you want to add more fundamental topologies?(Y/N)"<<endl;
        cin>>ch;
    }while(ch=='Y'||ch=='y');

    cout<<"Your fundamental topologies look thus"<<endl;

    printList();

    cout<<"Now we move towards the creation of hybrid topologies by establishing communication links"<<endl;
    cout<<"Refer the above while entering link nodes"<<endl;
    createHybrid();

    cout<<"The final hybrid topology look thus"<<endl;
    printList();
}

int main()
{
    Topology obj;
    obj.process();
    return 0;
}
