/*Problem Statement



Nila is in the process of developing a web crawling application aimed at mapping the structure of a website. In this representation, the website is depicted as a graph, where each webpage serves as a node and the hyperlinks connecting webpages act as edges.



Your task is to create a program that utilizes Breadth-First Search (BFS) traversal to explore and map the structure of a website, starting from a given URL and discovering all linked pages within the website.

Input format :
The first line of input consists of two space-separated integers, V and E, representing the number of webpages and hyperlinks on the website.

The next lines of input consists of two space-separated integers, Details about each hyperlink are represented by two integers u and v, indicating a hyperlink from webpage u to webpage v.

Output format :
The output displays the order in which webpages were visited during the BFS traversal, separated by spaces. The traversal order serves as a map of the website structure, indicating how webpages are connected.

Code constraints :
The test cases will fall under the following constraints:

1 <= V <= 10

0 <= E <= V*(V-1)/2

0 <= u, v < V

Sample test cases :
Input 1 :
4 4
0 1
0 2
1 3
2 3
Output 1 :
0 1 2 3 
Input 2 :
5 6
0 1
0 2
1 3
1 4
2 3
3 4
Output 2 :
// 0 1 2 3 4 */
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void bfs(int start, vector<vector<int>> &adj, vector<int>&visited){
    queue<int> q;
    q.push(start);
    visited[start]=1;
    
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cout<<node<<" ";
        for(int neighbour: adj[node]){
            if(!visited[neighbour]){
                visited[neighbour]=1;
                q.push(neighbour);
            }
        }
        
    }
}
int main(){
    int vertics,edges;
    cin>>vertics>>edges;
    vector<vector<int>> adj(vertics);
    for(int i=0;i<edges;i++){
        int v,u;
        cin>>v>>u;
        adj[v].push_back(u);
        
    }
    vector<int> visited(vertics,0);
    
    for(int i=0;i<vertics;i++){
        if(!visited[i]){
            bfs(i,adj,visited);
        }
    }
    
}