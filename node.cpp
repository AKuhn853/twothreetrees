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
                Node * mr = new Node;
                if(a->numChildren()>1){
                    cout << a->value[2] << " " << this->value[2] << endl;
                    *mr = Node(a->value[2],-1,this->value[2]);
                }
                else{
                    cout << a->value[0] << " " << this->value[0] << endl;
                    *mr = Node(a->value[0],-1,this->value[0]);
                }
                cout << "first root: " << root->value[0] << " " << root->value[1] << " " << root->value[2] << endl;
            
                this->parent = mr;
                a->parent = mr;
                mr->child[0] = a;
                mr->child[2] = this;
                root = mr;

                cout << "New root child 1: " << mr->child[0]->value[0] << " " << mr->child[0]->value[1] << " " << mr->child[0]->value[2] << endl;
                cout << "New root child 2: " << mr->child[2]->value[0] << " " << mr->child[2]->value[1] << " " << mr->child[2]->value[2]<< endl;
                cout << "New root: " << root->value[0] << " " << root->value[1] << " " << root->value[2] << endl;
                cout << "mr: " << mr->value[0] << " " << mr->value[1] << " " << mr->value[2] << endl;
            }
            else{
                Node * p = this->parent;
            cout << "parent = " << p->value[0] << " " << p->value[1] << " " << p->value[2] << endl;
            if(p->numChildren()<3){
                a->parent = p;
                if(a->value[0]<p->value[0]){
                    cout << "blerg " << endl;
                    p->value[1] = p->value[0];
                    p->child[1] = p->child[0];
                    p->value[0] = a->value[0];
                    p->child[0] = a;
                }else if(a->value[0]<p->value[2]){
                    cout << "schitt" << endl;
                    p->value[1] = a->value[0];
                    p->child[1] = a;
                    // cout << p->value[0] << " " << p->value[1] << " " << p->value[2] << endl;
                }else{
                    cout << "hehehe" << endl;
                    p->value[1] = p->value[2];
                    p->child[1] = p->child[2];
                    p->value[2] = a->value[0];
                    p->child[2] = a;
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
                        p->value[0] = a->value[2];
                    }
                    else{
                        p->value[0] = a->value[0];
                    }
                    
                    p->value[1] = -1;
                    p->absorb(left, root);
                } 
                cout << "left: " << left->value[0] << " " << left->value[1] << " " << left->value[2] << endl;
                cout << "p: " << p->value[0] << " " << p->value[1] << " " << p->value[2] << endl;

            }

            }
            
        }

        void discard(Node * removeChild){}

};

// Node(int val); // constructor
// bool numChildren();
// void absorb(Node * newChild);
// void discard(Node * removeChild);

