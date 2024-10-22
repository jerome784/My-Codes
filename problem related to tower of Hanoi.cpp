/*The Tower of Hanoi is a famous puzzle where we have three rods and N disks. The objective of the puzzle is to move the entire stack to another rod. You are given the number of disks N. Initially, these disks are in rod 1. You need to print all the steps of disk movement so that all the discs reach the 3rd rod. Also, you need to find the total moves.*/
// You are using GCC
#include <iostream>
using namespace std;

int moveDisks(int n, char source, char auxiliary, char destination,int &moves) {
    
    if(n==1){
        cout<<"Move disk 1 from rod "<<source<<" to rod "<<destination<<endl;
        moves++;
        return moves;
    }
    moveDisks(n-1,source,destination,auxiliary,moves);
    cout<<"Move disk "<<n<<" from rod"<<source<<" to rod "<<destination<<endl;
    moves++;
    moveDisks(n-1,auxiliary,source,destination,moves);
    return moves;
    
}

int main() {
    int n;
    cin >> n;
    int moves=0;
    
    int totalMoves = moveDisks(n, '1', '2', '3',moves);
    
    cout << totalMoves << endl;
    
    return 0;
}