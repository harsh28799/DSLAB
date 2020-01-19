#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue <pair<int, int>> pq;
    pq.push(make_pair(20, 100));
    pq.push(make_pair(22, 400));
    pq.push(make_pair(10, 300));
    pq.push(make_pair(12, 200));
    pair <int, int> mp=pq.top();
    cout<<mp.first<<" "<<mp.second<<endl;
    return 0;
}
