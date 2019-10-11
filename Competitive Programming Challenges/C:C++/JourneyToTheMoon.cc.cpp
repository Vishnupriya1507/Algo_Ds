QUESTION-- 1.) https://www.hackerrank.com/challenges/journey-to-the-moon/problem

#include <iostream>
#include<queue>
#include<list>
#include<map>
using namespace std;


class graph
    {
        public:
            int num;

            //adjency list is created
            map<int,list<int> > m;
            graph(int n)
                {
                    num = n;
                }
            void addEdge(int u, int v)
                {
                    m[u].push_back(v);
                    m[v].push_back(u);
                }
           int DFS_Moon(int src)
            {
                map<int,bool> visited;
                
                
                int componenet = 1;
                int total_ways = num*(num-1)/2;
                
                for(auto i:m)
                    {
                        int top = i.first;
                        
                        if(!visited[top])
                            {
                                int cs = 0;
                                dfsHelper(top,visited,cs);
                                componenet++;
                                cout<<" country_size is "<<cs<<endl;
                                total_ways -= cs*(cs-1)/2;
                            }
                    }
                    return total_ways;
                   //cout<<componenet<<endl;
            }
            
            void dfsHelper(int node, map<int,bool> &visited, int &cs)
                {
                    visited[node] = true;
                    cs++;
                    for(auto i:m[node])
                        {
                            if(!visited[i])
                              {
                                dfsHelper(i,visited,cs);
                              }
                        }
                        return;
                }
        void print()
            {
                for(auto i:m)
                    {
                        cout<<i.first<<" -> ";
                        for(auto j:m[i.first])
                            {
                                cout<<j<<" ,";
                            }
                            cout<<endl;
                    }
            }
    };
int main() {
    int v,e; cin>>v>>e;
    graph g(v);
    g.addEdge(0,1);
    g.addEdge(2,3);
    g.addEdge(0,4);
    cout<<g.DFS_Moon(0);
    cout<<endl;
     g.print();
    return 0;
}