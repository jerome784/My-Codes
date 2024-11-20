/*Problem Statement



Lithish is working on a project that involves analyzing the connectivity of various data points represented as vertices in a graph. He needs to perform Depth First Traversal (DFS) on the given graph (connected undirected graph) to explore its vertices and understand the relationships between them.



Write a program to help Lithish perform DFS on the given graph.

Input format :
The first line of input consists of the two integers V and E, separated by a space. V represents the number of vertices, and E represents the number of edges in the graph.

The next E lines consist of two integers, v and w, separated by a space, indicating an edge between vertex v and vertex w.

The last line of input consists of the startVertex, representing the starting vertex for DFS traversal.

Output format :
The output should print the Depth First Traversal of the graph starting from a specified vertex, following format:

"Depth First Traversal starting from vertex [vertex]:

[u1] [u2] [u3]... [un]".*/
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
void DFS(int startvertex,vector<vector<int>> &adj,vector<bool> &visited){
  visited[startvertex]=true;
  cout<<startvertex<<" ";
  
  sort(adj[startvertex].begin(),adj[startvertex].end());
  
  for(int neighbour: adj[startvertex]){
      if(!visited[neighbour]){
          DFS(neighbour,adj,visited);
      }
 }
   
}
int main(){
    int v,e;
    cin>>v>>e;
    vector<vector<int>> adj(v);
    for(int i=0;i<e;i++){
        int w,u;
        cin>>w>>u;
        
        adj[w].push_back(u);
    }
    int startvertex;
    cin>>startvertex;
    
    vector<bool> visited(v,false);
    cout<<"Depth First Traversal starting from vertex"<<startvertex<<":"<<endl;
    DFS(startvertex,adj,visited);
    
}