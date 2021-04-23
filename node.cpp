#include <iostream>
using namespace std;

class Node{
    public:
        Node * parent;
        int value[6] = {-1,-1,-1,-1,-1,-1};
        Node * child[6];

        Node() {}
        Node(int val0, int val1=-1, int val2=-1){ // constructor
            value[0] = val0;
            value[1] = val1;
            value[2] = val2;
        }

        int numChildren(){
            int count = 0;
            for(int i = 0; i<6; i++){
                if(child[i]==NULL){}
                else{
                    count++;
                }
            }
            return count;
        }

        void absorb(Node * a, Node * root){
            cout << "this: "<< this->value[0] << endl;
            if(this==root){
                Node * mr  = new Node(a->value[0],-1,this->value[0]);
                this->parent = mr;
                a->parent = mr;
                mr->child[0] = a;
                mr->child[2] = this;
            }
            Node * p = this->parent;
            cout << "parent = " << p->value[0] << " " << p->value[1] << " " << p->value[2] << endl;
            if(p->numChildren()<3){
                if(a->value[0]<p->value[0]){
                    p->value[1] = p->value[0];
                    p->value[0] = a->value[0];
                }else if(a->value[0]<p->value[2]){
                    // cout << "here" << endl;
                    p->value[1] = a->value[0];
                    // cout << p->value[0] << " " << p->value[1] << " " << p->value[2] << endl;
                }else{
                    p->value[1] = p->value[2];
                    p->value[2] = a->value[0];
                }
                cout << "new parent = " << p->value[0] << " " << p->value[1] << " " << p->value[2] << endl;
            }
            else{
                Node * left = new Node;
                if(this==p->child[0]){
                    // we won't be adding a leaf to a node that isn't a leaf
                    // so this logic should be sufficient?
                    if(this->numChildren()>1){ 
                        *left = Node(a->value[2], -1, this->value[2]);
                    }
                    else {
                        *left = Node(a->value[0], -1, this->value[0]);
                    }
                    left->child[0] = a;
                    left->child[2] = this; 
                    p->child[0] = p->child[1];
                    delete p->child[1];  // p no longer has a middle child
                    p->value[0] = p->value[1];
                    p->value[1] = -1;
                    p->absorb(left, root);
                }else if(this==p->child[1]){
                    if(p->child[0]->numChildren()>1){
                        *left =  Node(p->child[0]->value[2],-1,a->value[2]);
                    }
                    else{   // leaf case
                        *left = Node(p->child[0]->value[0],-1,a->value[0]);
                    }
                    left->child[2] = a;
                    left->child[0] = p->child[0]; 
                    p->child[0] = this;
                    delete p->child[1];  // p no longer has a middle child
                    p->value[0] = p->value[1];
                    p->value[1] = -1;
                    p->absorb(left, root);
                }else if(this==p->child[2]){
                    if(p->child[0]->numChildren()>1){
                        *left = Node(p->child[0]->value[2],-1,p->child[1]->value[2]);
                    }
                    else{
                        *left = Node(p->child[0]->value[0],-1,p->child[1]->value[0]);
                    }
                    left->child[2] = p->child[1];
                    left->child[0] = p->child[0]; 
                    p->child[0] = a;
                    delete p->child[1];  // p no longer has a middle child
                    if(a->numChildren()>1){
                        p->value[1] = a->value[2];
                    }
                    else{
                        p->value[1] = a->value[0];
                    }
                    
                    p->value[1] = -1;
                    p->absorb(left, root);
                } 
                cout << "left: " << left->value[0] << " " << left->value[1] << " " << left->value[2] << endl;
                cout << "p: " << p->value[0] << " " << p->value[1] << " " << p->value[2] << endl;

            }

        }

        void discard(Node * removeChild){}

};

// Node(int val); // constructor
// bool numChildren();
// void absorb(Node * newChild);
// void discard(Node * removeChild);

