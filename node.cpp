#include <iostream>
#include <fstream>
using namespace std;

void summonUzi();

class Node{
    public:
        Node * parent;
        int value[6] = {-1,-1,-1,-1,-1,-1};
        Node * child[6];

        // Node() {}
        Node(int val0, int val1=-1, int val2=-1){ // constructor
            value[0] = val0;
            value[1] = val1;
            value[2] = val2;
        }

        int numChildren(){}

        void absorb(Node * newChild){}

        void discard(Node * removeChild){}

};

// Node(int val); // constructor
// bool numChildren();
// void absorb(Node * newChild);
// void discard(Node * removeChild);

int main(){
    fstream infile;
    infile.open("uziTree.txt");

    int numLeaves;
    infile >> numLeaves;
    
    int * leaves =  new int[numLeaves];

    for(int i = 0; i < numLeaves; i++){
        infile >> leaves[i];
    }

    infile.close();

    for(int i = 0; i < numLeaves; i++)
        cout << leaves[i] << endl;

    Node ** leafnodes = new Node*[numLeaves];
    for(int i = 0; i<numLeaves; i++){
        cout << "leaves[" << i << "]: " << leaves[i] << endl;
        *leafnodes[i] = Node(leaves[i]);
        cout << "is the problem here?" << endl;
        // cout << leafnodes[i]->value[0] << endl;
    }

    /**
     * array of node pointers
     * Node ** leafnodes = new Node*[numLeaves];
    **/

    return 0;
}


void summonUzi(){
    Node root = Node(17, 28, 39);

    Node lvl2Node1 = Node(3,8,17);
    lvl2Node1->parent = root;
    Node lvl2Node2 = Node(21, -1, 28);
    lvl2Node2->parent = root;
    Node lvl2Node3 = Node(33, -1, 39);
    lvl2Node3->parent = root;
    root->child[0] = lvl2Node1;
    root->child[1] = lvl2Node2;
    root->child[2] = lvl2Node3;

    // root->child[4] instead of *root.child ((*root).child is also better)

    Node lvl3Node1 = Node(1,-1,3);
    lvl3Node1->parent = lvl2Node1;
    Node lvl3Node2 = Node(5, -1, 8);
    lvl3Node2->parent = lvl2Node1;
    Node lvl3Node3 = Node(11,14,17);
    lvl3Node3->parent = lvl2Node1;
    lvl2Node1->child[0] = lvl3Node1;
    lvl2Node1->child[1] = lvl3Node2;
    lvl2Node1->child[2] = lvl3Node3;

    Node lvl3Node4 = Node(19, -1, 21);
    lvl3Node4->parent = lvl2Node2;
    Node lvl3Node5 = Node(24, -1, 28);
    lvl3Node5->parent = lvl2Node2;
    lvl2Node2->child[0] = lvl3Node4;
    lvl2Node2->child[2] = lvl3Node5;

    Node lvl3Node6 = Node(31, -1, 33);
    lvl3Node6->parent = lvl2Node3;
    Node lvl3Node7 = Node(36, -1, 39);
    lvl3Node7->parent = lvl2Node3;
    lvl2Node3->child[0] = lvl3Node6;
    lvl2Node3->child[2] = lvl3Node7;

}
