#include <iostream>
#include <fstream>
using namespace std;

class Node {
        Node * parent;
        int value[6];
        Node * child[6];
    public:
        // Node(int val){

        // }
        Node(int val0, int val1 = -1, int val2 = -1){ // constructor
            // parent = max(val0,val1,val2);
            value[0] = val0;
            if(val1!=-1)
                value[1] = val1;
            if(val2!=-1)
                value[2] = val2; 
            // if(val1==-1 && val2==-1){
            //     for(int i = 0; i<6; i++){
            //         child[i] = Node(-1);
            //     }
            // }
            // else{
            //     child[0] = Node(val0);
            //     if(val1!=-1){
            //         child[1] = Node(val1);
            //     }
            //     if(val2!=-1){
            //         child[2] = Node(val2); 
            //     }
                    
            // }
        }

        bool numChildren(){


        }

        void absorb(Node * newChild){


        }

        void discard(Node * removeChild){


        }
};

// Node(int val); // constructor
// bool numChildren();
// void absorb(Node * newChild);
// void discard(Node * removeChild);

int main(){
    fstream infile;
    infile.open("uziTree.txt");

    int numLeaves = 0;
    while(infile >> numLeaves){
        numLeaves++;
    }

    infile.close();

    int leaves [numLeaves];

    fstream infile2;
    infile2.open("uziTree.txt");
    int i = 0;
    while(infile2 >> leaves[i]){
        cout << leaves[i] << endl;
    }

    infile2.close();

    
    Node canireadtheleaves[numLeaves];
    for(int i = 0; i<numLeaves; i++){
        canireadtheleaves[i] = Node(leaves[i]); 
    }

    return 0;
}
