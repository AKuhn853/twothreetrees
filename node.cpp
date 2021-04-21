#include <iostream>
#include <fstream>
using namespace std;

class Node{
    public:
        Node * parent;
        int value[6] = {-1,-1,-1,-1,-1,-1};
        Node * child[6];
    
        // Node(int val){

        // }
        Node(int val){ // constructor
            if(val<value[0]){
                value[0] = val;
            }else if(val<value[1]){
                value[1] = val;
            }else if(val<value[2]){
                value[2] = val;
            }else{
                value[3] = val;
            }
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

    Node marty = Node(3);
    cout << marty.value[3] << endl;
    // Node canireadtheleaves[numLeaves];
    // for(int i = 0; i<numLeaves; i++){
    //     canireadtheleaves[i] = Node(leaves[i]); 
    // }

    return 0;
}
