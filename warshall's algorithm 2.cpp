/*Megna is assigned a project consisting of multiple tasks, and each task may depend on other tasks. Your goal is to help Megna write a program that determines whether there exists a chain of dependencies that connects one task to another within the project.



Write a program using Warshall's Algorithm to find out if there exists a chain of dependencies that connects two tasks.

Input format :
The first line of input consists of an integer N, representing the number of tasks in the project.

The following N lines consist of N space-separated integers (0 or 1), representing the matrix of task dependencies.

The last line consists of two space-separated integers, task1 and task2, for which the presence of a chain of dependencies needs to be determined.

Output format :
If there exists a chain of dependencies from task1 to task2, print "There is a chain of dependencies."

Otherwise, print "There is no chain of dependencies."



Refer to the sample output for the formatting specifications.

Code constraints :
The test cases will fall under the following constraints:

1 ≤ N ≤ 10

Each element of the adjacency matrix is either 0 or 1.

0 ≤ task1, task2 < N

Sample test cases :
Input 1 :
6
0 1 0 1 0 0
0 0 1 0 0 1
0 0 0 0 1 0
0 0 0 0 0 1
0 0 0 0 0 1
0 0 0 0 0 0
2 4
Output 1 :
There is a chain of dependencies.
Input 2 :
5
0 1 1 0 0
0 0 0 1 0
1 0 0 1 0
1 0 0 0 1
0 0 1 0 0
2 5
Output 2 :
There is no chain of dependencies.*/
#include <iostream>
using namespace std;

#define MAX_TASKS 100
// You are using GCC
bool hasChainOfDependencies(int n, int dependencies[MAX_TASKS][MAX_TASKS], int task1, int task2) {
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dependencies[i][j]==dependencies[i][j] || (dependencies[i][k] && dependencies[k][j]);
            }
        }
    }
    return dependencies[task1][task2]==1;
}
int main() {
    int n; // Number of tasks
    cin >> n;

    int dependencies[MAX_TASKS][MAX_TASKS] = {0};

    // Taking input for task dependencies
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> dependencies[i][j];
        }
    }

    int task1, task2;
    cin >> task1 >> task2;

    if (hasChainOfDependencies(n, dependencies, task1, task2)) {
        cout << "There is a chain of dependencies.";
    } else {
        cout << "There is no chain of dependencies.";
    }

    return 0;
}