#include<bits/stdc++.h>

using namespace std;

class Topology
{

    vector <int> myGraph[25];

    void print(int n);

public:
    void star1();
    void star2();
    void ring1();
    void ring2();
    void tree1();
    void cube1();
    void hypercube1();
    void hybrid1();

};

void Topology::print(int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<i<<": ";
        for(int j=0;j<myGraph[i].size();j++)
        {
            cout<<myGraph[i][j]<<" ";
        }
        cout<<endl;
    }
}

void Topology::star1()
{

    int n;
    cout<<"enter the number of nodes:";
    cin>>n;

    for(int i=1;i<n;i++)
    {

        myGraph[i].push_back(0);
        myGraph[0].push_back(i);

    }

    cout<<"The adjacency list for the desired topology is:"<<endl;
    print(n);

}

void Topology::star2()
{

    int n, c;

    cout<<"enter the number of nodes:";
    cin>>n;

    cout<<"enter the central node:";
    cin>>c;

    for(int i=0;i<n;i++)
    {

        if(i!=c)
        {
            myGraph[i].push_back(c);
            myGraph[c].push_back(i);
        }

    }

    cout<<"The adjacency list for the desired topology is:"<<endl;
    print(n);

}

void Topology::ring1()
{

    int n;
    cout<<"enter the number of nodes:";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        if((i+1)<n)
        {
            myGraph[i].push_back(i+1);
            myGraph[i+1].push_back(i);
        }
        else
        {
            myGraph[i].push_back((i+1)%n);
            myGraph[(i+1)%n].push_back(i);
        }
    }

    cout<<"The adjacency list for the desired topology is:"<<endl;
    print(n);

}

void Topology::ring2()
{

    int n;
    cout<<"enter the number of nodes:";
    cin>>n;

    cout<<"enter the nodes you want to be adjacent:"<<endl;

    vector <int> track(n, 0);

    for(int i=0;i<n;i++)
    {
        int a, b;
        cin>>a>>b;

        if(a>=0&&a<n&&b>=0&&b<n&&track[a]<2&&track[b]<2)
        {
            track[a]++;
            track[b]++;
            myGraph[a].push_back(b);
            myGraph[b].push_back(a);
        }
        else
        {
            cout<<"Your input violates ring topology. Try Again"<<endl;
            i--;
        }
    }

    cout<<"The adjacency list for the desired topology is:"<<endl;
    print(n);

}

void Topology::tree1()
{
    int n;
    cout<<"enter the number of nodes:";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int k=i+1;
        int a=2*k;
        int b=a+1;

        if(a<=n)
        {
            myGraph[a-1].push_back(i);
            myGraph[i].push_back(a-1);
        }
        if(b<=n)
        {
            myGraph[b-1].push_back(i);
            myGraph[i].push_back(b-1);
        }
    }

    cout<<"The adjacency list for the desired topology is:"<<endl;
    print(n);

}

void Topology::cube1()
{
    for(int i=0;i<8;i++)
    {
        int a=i+1;
        if(i<4&&a>=4)
            a=a-4;
        else if(i>=4&&a>=8)
            a=a-4;

        int b;
        if(i<4)
            b=i+4;
        else b=i-4;

        int c=i-1;
        if(i<4&&c<0)
            c=c+4;
        else if(i>=4&&c<4)
            c=c+4;

        myGraph[i].push_back(a);
        myGraph[i].push_back(b);
        myGraph[i].push_back(c);
    }

    cout<<"The adjacency list for the desired topology is:"<<endl;
    print(8);

}

void Topology::hypercube1()
{
    for(int i=0;i<8;i++)
    {
        int a=i+1;
        if(i<4&&a>=4)
            a=a-4;
        else if(i>=4&&a>=8)
            a=a-4;

        int b;
        if(i<4)
            b=i+4;
        else b=i-4;

        int c=i-1;
        if(i<4&&c<0)
            c=c+4;
        else if(i>=4&&c<4)
            c=c+4;

        myGraph[i].push_back(a);
        myGraph[i].push_back(b);
        myGraph[i].push_back(c);
        myGraph[i].push_back(i+8);

        myGraph[i+8].push_back(a+8);
        myGraph[i+8].push_back(b+8);
        myGraph[i+8].push_back(c+8);
        myGraph[i+8].push_back(i);
    }

    cout<<"The adjacency list for the desired topology is:"<<endl;
    print(16);

}

void Topology::hybrid1()
{

}

int main()
{

    int choice;

    cout<<"Menu:\n1.Auto generated star topology\n2.User defined star topology\n3.Auto generated ring topology\n4.User defined ring topology\n5.Auto generated tree topology\n6.Auto generated cube topology\n7.Auto generated hypercube topology\n8.User defined Hybrid topology\n"<<endl;

    char ch;

    do{

        cout<<"Enter your choice"<<endl;
        cin>>choice;

        if(choice>=1&&choice<=8)
        {
            Topology obj;

            switch(choice)
            {
            case 1:obj.star1();
                    break;
            case 2:obj.star2();
                    break;
            case 3: obj.ring1();
                    break;
            case 4:obj.ring2();
                    break;
            case 5:obj.tree1();
                    break;
            case 6:obj.cube1();
                    break;
            case 7:obj.hypercube1();
                    break;
            case 8:obj.hybrid1();
                    break;
            default:break;
            }
        }

        else
            cout<<"Invalid choice"<<endl;

        cout<<"Do you want to try another topology?(Y/N)"<<endl;
        cin>>ch;

    }while(ch=='Y'||ch=='y');

    return 0;

}
