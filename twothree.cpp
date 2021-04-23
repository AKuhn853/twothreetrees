#include <iostream>
#include <fstream>
#include "node.cpp"
#include "tree.cpp"
using namespace std;

Node * summonUzi();
void obliterateUzi(Node * root);

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

    Node ** leafnodes = new Node*[numLeaves];
    for(int i = 0; i<numLeaves; i++){
        // cout << "leaves[" << i << "]: " << leaves[i] << endl;
        leafnodes[i] = new Node(leaves[i]);
        // cout << leafnodes[i]->value[0] << endl;
    }

    Node * Uzi = summonUzi();
    cout << Uzi->child[0]->value[0] << endl;

    // Tree * clive = new Tree();
    // clive->root = Uzi;

    obliterateUzi(Uzi);
    return 0;
}


Node * summonUzi(){
    Node * root = new Node(17, 28, 39);

    Node * lvl2Node1 = new Node(3,8,17);
    lvl2Node1->parent = root;
    Node * lvl2Node2 = new Node(21, -1, 28);
    lvl2Node2->parent = root;
    Node * lvl2Node3 = new Node(33, -1, 39);
    lvl2Node3->parent = root;
    root->child[0] = lvl2Node1;
    root->child[1] = lvl2Node2;
    root->child[2] = lvl2Node3;

    Node * lvl3Node1 = new Node(1,-1,3);
    lvl3Node1->parent = lvl2Node1;
    Node * lvl3Node2 = new Node(5, -1, 8);
    lvl3Node2->parent = lvl2Node1;
    Node * lvl3Node3 = new Node(11,14,17);
    lvl3Node3->parent = lvl2Node1;
    lvl2Node1->child[0] = lvl3Node1;
    lvl2Node1->child[1] = lvl3Node2;
    lvl2Node1->child[2] = lvl3Node3;

    Node * lvl3Node4 = new Node(19, -1, 21);
    lvl3Node4->parent = lvl2Node2;
    Node * lvl3Node5 = new Node(24, -1, 28);
    lvl3Node5->parent = lvl2Node2;
    lvl2Node2->child[0] = lvl3Node4;
    lvl2Node2->child[2] = lvl3Node5;

    Node * lvl3Node6 = new Node(31, -1, 33);
    lvl3Node6->parent = lvl2Node3;
    Node * lvl3Node7 = new Node(36, -1, 39);
    lvl3Node7->parent = lvl2Node3;
    lvl2Node3->child[0] = lvl3Node6;
    lvl2Node3->child[2] = lvl3Node7;

    Node * lvl4Node1 = new Node(1, -1, -1);
    Node * lvl4Node2 = new Node(3, -1, -1);

    Node * lvl4Node3 = new Node(5, -1, -1);
    Node * lvl4Node4 = new Node(8, -1, -1);

    Node * lvl4Node5 = new Node(11, -1, -1);
    Node * lvl4Node6 = new Node(14, -1, -1);
    Node * lvl4Node7 = new Node(17, -1, -1);

    Node * lvl4Node8 = new Node(19, -1, -1);
    Node * lvl4Node9 = new Node(21, -1, -1);

    Node * lvl4Node10 = new Node(24, -1, -1);
    Node * lvl4Node11 = new Node(28, -1, -1);

    Node * lvl4Node12 = new Node(31, -1, -1);
    Node * lvl4Node13 = new Node(33, -1, -1);

    Node * lvl4Node14 = new Node(36, -1, -1);
    Node * lvl4Node15 = new Node(39, -1, -1);

    // Node * Uzi[3][9];
    // Uzi[0][0] = root;  
    // should probably return array of nodes
    // but this'll do for now
    return root;
}

void obliterateUzi(Node * root){
    // this should really delete all the nodes
    // and take in an array of nodes to delete
    delete root; 

    // delete Node lvl2Node1;
    // delete Node lvl2Node2;
    // delete Node lvl2Node3;

    // delete Node lvl3Node1;
    // delete Node lvl3Node2;
    // delete Node lvl3Node3;

    // delete Node lvl3Node4;
    // delete Node lvl3Node5;

    // delete Node lvl3Node6;
    // delete Node lvl3Node7;


}