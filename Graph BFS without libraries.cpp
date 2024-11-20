/*Rohan is in the process of creating a delivery route optimization application tailored for a courier company. The primary goal of this application is to identify the most efficient route for delivering packages to multiple destinations situated within a city. In this city representation, delivery points serve as vertices, and the streets connecting them are depicted as edges in a graph.



Your task is to develop a program that utilizes the Breadth-First Search (BFS) algorithm to calculate the shortest delivery route, starting from the company's warehouse and passing through all specified delivery locations before returning to the warehouse.

Input format :
The first line consists of an integer v, representing the number of locations within the city.

The second line consists of an integer e, representing the number of streets connecting these locations.

The next e-line consists of two space-separated integers src and dest, representing streets connecting location "src" to location "dest."

The next line consists of an integer, representing the starting location (source), which corresponds to the company's warehouse.

The last line consists of an integer, destination, which represents the list of delivery locations that the courier needs to visit, arranged in the order they should be visite*/
#include <iostream>
#include <climits>
using namespace std;
// You are using GCC
void add_edge(int adj[][100], int src, int dest)
{
    adj[src][dest]=1;
    adj[dest][src]=1;
    
}

bool BFS(int adj[][100], int src, int dest, int v, int pred[], int dist[])
{
    int visited[100]={0};
    int queue[100];
    int front=0;
    int rear=0;
    
    for(int i=0;i<v;i++){
        dist[i]=INT_MAX;
        pred[i]=-1;
    }
    visited[src]=1;
    dist[src]=0;
    queue[rear++]=src;
    
    while(front<rear){
        int curr=queue[front++];
        
        for(int i=0;i<v;i++){
            if(adj[curr][i]==1 && !visited[i]){
                visited[i]=1;
                dist[i]=dist[curr]+1;
                pred[i]=curr;
                queue[rear++]=i;
                if(i==dest)return true;
            }
        }
    }
    return false;
}

void printShortestDistance(int adj[][100], int s, int dest, int v, int pred[], int dist[])
{
    int path[100];
    int path_index=0;
    
    int crawl=dest;
    path[path_index++]=crawl;
    while(pred[crawl]!=-1){
        path[path_index++]=pred[crawl];
        crawl=pred[crawl];
        
    }
    
    cout<<"Shortest path length is: "<<dist[dest]<<endl;
    cout<<"Path is: ";
    for(int i=path_index-1;i>=0;i--){
        cout<<path[i]<<" ";
         
    }
    cout<<endl;
    
}
int main()
{
    int v, e;
    cin >> v;

    int adj[100][100] = {0};

    cin >> e;

    for (int i = 0; i < e; i++)
    {
        int src, dest;
        cin >> src >> dest;
        add_edge(adj, src, dest);
    }

    int source, dest;
    cin >> source >> dest;

    int pred[v], dist[v];

    if (BFS(adj, source, dest, v, pred, dist))
        printShortestDistance(adj, source, dest, v, pred, dist);
   
    return 0;
}