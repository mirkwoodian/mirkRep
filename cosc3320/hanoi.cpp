#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include <sstream>
#include <math.h>
#include <array>

using namespace std;

struct node //used to create node start, node end, and all the aux nodes
{
    int count = 0;
    string name;
    bool isused = false;
};

void move (node* source, node* dest) { //parameters: source and destination nodes. Might as well print each move too
    source->count--;
    dest->count++;
    cout << "Move disk from " << source->name << " to " << dest->name << "." << endl;
}

void Hanoi (int n, node* f, node* t, node* aux, node* start, node* last) { //parameters: n is #ofNodes, f is moving from this node, t is to that node, aux is the in between
    if (f->count == 0 && start->count > 0) {
        move (start, f);
    }
    if (n >= 1) { //the pattern is shift n-1 disks to a3, shift last disk onto a2, //shift n-1 disks onto a1, shift last disk from a2 to dest
        Hanoi (n - 1, f, aux, t, start, last); //from f, to t, through aux
        move (f, aux); //from f to a2
        if (start->count == 0) move (aux, last);
        Hanoi (n-1, t, f, aux, start, last); //move back from f to a1
        
    }
}
int main(int argc, char *argv[]) //Input:  n-disks. Ouput: each step the algorithm takes to complete the Hanoi. Parameters: arguements given from arbitary source
{
    node* start = new node; //create the nodes
    node* end = new node;
    node* a1 = new node;
    node* a2 = new node;
    node* a3 = new node;
    node* a4 = new node;
    start->name = "start";
    end->name = "end";
    a1->name = "a1";
    a2->name = "a2";
    a3->name = "a3";
    a4->name = "a4";
    
    for (int n = 1; n <= 10; n++){
        start->count = n; //all the other nodes have 0 disks and now the start node can begin with n disks
        Hanoi (n, start, end, a1, start, end);
    }
}