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
    // cout << Uzi->child[0]->value[0] << endl;

    int test;
    test = Uzi->numChildren();
    // cout << "Uzi has " << test << " children. "<< endl;

    Tree * clive = new Tree(Uzi);

    cout << "Clive Version 0 " << endl;
    clive->print(clive->root);

    // clive->insert(34, clive->root);

    // cout << "Clive Version 1 (After insert) " << endl;
    // clive->print(clive->root);

    // need to fix kill for 5, works for the rest of the left of the tree
    clive->kill(8, clive->root);

    cout << "Clive Version 2 (After delete) " << endl;
    clive->print(clive->root);

    // Node * searchTest = clive->search(clive->root,7);
    // if(searchTest->value[0]){
    //     cout << "leaf = " << searchTest->value[0] << endl;
    // }


    // cout << "Clive has a root: " <<clive->root->value[0] << " " << clive->root->value[1] << " " << clive->root->value[2] << endl; 

    // clive->root = clive->insert(32, clive->root);
    // clive->root = clive->insert(34, clive->root);

    // clive->print(clive->root);

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
    // Node * lvl3Node7 = new Node(36, 37, 39);
    lvl3Node7->parent = lvl2Node3;
    lvl2Node3->child[0] = lvl3Node6;
    lvl2Node3->child[2] = lvl3Node7;

    Node * lvl4Node1 = new Node(1, -1, -1);
    lvl4Node1->parent = lvl3Node1;
    lvl3Node1->child[0] = lvl4Node1;
    Node * lvl4Node2 = new Node(3, -1, -1);
    lvl4Node2->parent = lvl3Node1;
    lvl3Node1->child[2] = lvl4Node2;
    

    Node * lvl4Node3 = new Node(5, -1, -1);
    lvl4Node3->parent = lvl3Node2;
    lvl3Node2->child[0] = lvl4Node3;
    Node * lvl4Node4 = new Node(8, -1, -1);
    lvl4Node4->parent = lvl3Node2;
    lvl3Node2->child[2] = lvl4Node4;

    Node * lvl4Node5 = new Node(11, -1, -1);
    lvl4Node5->parent = lvl3Node3;
    lvl3Node3->child[0] = lvl4Node5;
    Node * lvl4Node6 = new Node(14, -1, -1);
    lvl4Node6->parent = lvl3Node3;
    lvl3Node3->child[1] = lvl4Node6;
    Node * lvl4Node7 = new Node(17, -1, -1);
    lvl4Node7->parent = lvl3Node3;
    lvl3Node3->child[2] = lvl4Node7;

    Node * lvl4Node8 = new Node(19, -1, -1);
    lvl4Node8->parent = lvl3Node4;
    lvl3Node4->child[0] = lvl4Node8;
    Node * lvl4Node9 = new Node(21, -1, -1);
    lvl4Node9->parent = lvl3Node4;
    lvl3Node4->child[2] = lvl4Node9;

    Node * lvl4Node10 = new Node(24, -1, -1);
    lvl4Node10->parent = lvl3Node5;
    lvl3Node5->child[0] = lvl4Node10;
    Node * lvl4Node11 = new Node(28, -1, -1);
    lvl4Node11->parent = lvl3Node5;
    lvl3Node5->child[2] = lvl4Node11;

    Node * lvl4Node12 = new Node(31, -1, -1);
    lvl4Node12->parent = lvl3Node6;
    lvl3Node6->child[0] = lvl4Node12;
    Node * lvl4Node13 = new Node(33, -1, -1);
    lvl4Node13->parent = lvl3Node6;
    lvl3Node6->child[2] = lvl4Node13;

    Node * lvl4Node14 = new Node(36, -1, -1);
    lvl4Node14->parent = lvl3Node7;
    lvl3Node7->child[0] = lvl4Node14;
    Node * lvl4Node15 = new Node(39, -1, -1);
    lvl4Node15->parent = lvl3Node7;
    lvl3Node7->child[2] = lvl4Node15;

    // Node * lvl4Node16 = new Node(37, -1, -1);
    // lvl4Node16->parent = lvl3Node7;
    // lvl3Node7->child[1] = lvl4Node16;

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