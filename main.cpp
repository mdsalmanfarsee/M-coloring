// N queens

#include <cstring>
#include <bits/stdc++.h>
using namespace std;

bool isSafe(int v,vector<vector<int>>graph,vector<int>&color,int c,int V)
{
    for(int i=0; i<V; i++)
    {
        if(graph[v][i] && c==color[i])
        {
            return false;
        }
    }
    return true;
}

bool graphColoringutil(vector<vector<int>>graph,int m,vector<int>&color,int v,int V)
{
    if(v==V) return true;
    
    for(int c=1; c<=m; c++)
    {
        if(isSafe(v,graph,color,c,V))
        {
            color[v]=c;
            if(graphColoringutil(graph,m,color,v+1,V))
            {
                return true;
            }
            //backtrack
            color[v]=0;
        }
    }
    return false;
}


void graphColoring(vector<vector<int>>graph,int m,int V)
{
    vector<int>color(V,0);
    if(!graphColoringutil(graph,m,color,0,V))
    {
        cout<<"solution does not exist"<<endl;
        return;
    }
    cout<<"solution exist. The coloring of vertices is: "<<endl;
    for(int i=0; i<V; i++)
    {
        cout<<"vertex "<<i<<" is colored with "<<color[i]<<endl;
    }
}

int main() {
  int V,E,m;
  cout<<"enter number of vertices and edges: ";
  cin>>V>>E;
  vector<vector<int>>graph(V,vector<int>(V,0));
  
  cout<<"enter the edges (format: from_vertex to_vertex)"<<endl;
  for(int i=0; i<E; i++)
  {
      int from,to;
      cin>>from>>to;
      graph[from][to]=1;
      graph[to][from]=1; //undirected
  }
  
  cout<<"enter the number of colors (m): ";
  cin>>m;
  graphColoring(graph,m,V);
  return 0;
}
