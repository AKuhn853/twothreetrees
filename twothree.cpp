#include <iostream>
#include <fstream>
#include "node.cpp"
#include "tree.cpp"
using namespace std;

Node * summonUzi();
void obliterateUzi(Node * root);

int main(){
    // Reading Uzi nodes from txt file
    fstream infile;
    infile.open("uziTree.txt");

    int numLeaves;
    infile >> numLeaves;
    
    int * leaves =  new int[numLeaves];

    Tree * clive;
    Node ** leafnodes = new Node*[numLeaves];

    // Creating our friendly tree, Clive
    for(int i = 0; i < numLeaves; i++){
        infile >> leaves[i];
        leafnodes[i] = new Node(leaves[i]);
        if(i==0){
            cout << "Creating Clive's root with value " << leaves[i] << endl; 
            clive = new Tree(leafnodes[0]);
        }
        else{
            cout << "\nAbsorbing " << leaves[i] << " into Clive" << endl;
            clive->root = clive->insert(leaves[i], clive->root);
        }   
    }

    infile.close();

    // Printing Clive for proof of insertion
    cout << "\nHere is Clive in his full beauty: " << endl;
    clive->print(clive->root);
    cout << endl;

    // Killing some of Clive's nodes
    cout << "Killing node 39:"<< endl;
    clive->root = clive->kill(39, clive->root);
    clive->print(clive->root);
    cout << endl;

    cout << "Killing node 19:"<< endl;
    clive->root = clive->kill(19, clive->root);
    clive->print(clive->root);
    cout << endl;

    cout << "Killing node 1:"<< endl;
    clive->root = clive->kill(1, clive->root);
    clive->print(clive->root);
    cout << endl;

    // Killing the rest of Clive
    for(int i = 0; i<numLeaves; i++){
        if(clive->root){
            cout << endl;
            cout << "Killing node "<< leaves[i] << endl;
            clive->root = clive->kill(leaves[i], clive->root);
            clive->print(clive->root);
        }
    }

    // Now, we can bid Clive farewell
    delete clive;
    return 0;
}
