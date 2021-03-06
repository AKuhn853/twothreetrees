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

        Node * absorb(Node * a, Node * root){ 
            // cout << "this: " << this->value[0] << " " << this->value[1] << " " << this->value[2] << endl;
            // cout << "a: " << a->value[0] << " " << a->value[1] << " " << a->value[2] << endl;
            if(this==root){
                if(this->numChildren()==0){
                    Node ** children = new Node*[2];
                    children[0] = a;
                    children[1] = this;

                    Node * mr;
                    mr = new Node(a->value[0],-1,this->value[0]);
                    
                    children[0]->parent = mr;
                    children[1]->parent = mr;

                    mr->child[0] = children[0];
                    mr->child[2] = children[1];

                    root = mr;
                    cout << root << endl;
                }else{
                    Node ** children = new Node*[2];

                    children[0] = a;
                  
                    children[0]->child[0] = a->child[0];
                    children[0]->child[1] = a->child[1];
                    children[0]->child[2] = a->child[2];

                    children[1] = this;
                    children[1]->child[0] = this->child[0];
                    children[1]->child[1] = this->child[1];
                    children[1]->child[2] = this->child[2];

                    Node * mr;
                    if(a->numChildren()>1){
                        mr = new Node(a->value[2],-1,this->value[2]);
                    }else{
                        mr = new Node(a->value[0],-1,this->value[0]);
                    }

                    mr->child[0] = children[0];
                    mr->child[2] = children[1];
                    mr->child[0]->parent = mr;
                    mr->child[2]->parent = mr;

                    if(mr->child[0]->numChildren()==2){
                        mr->child[0]->child[0]->parent = mr->child[0];
                        mr->child[0]->child[2]->parent = mr->child[0];
                    }else{
                        mr->child[0]->child[0]->parent = mr->child[0];
                        mr->child[0]->child[1]->parent = mr->child[0];
                        mr->child[0]->child[2]->parent = mr->child[0];
                    }

                    if(mr->child[2]->numChildren()==2){
                        mr->child[2]->child[0]->parent = mr->child[2];
                        mr->child[2]->child[2]->parent = mr->child[2];
                    }else{
                        mr->child[2]->child[0]->parent = mr->child[2];
                        mr->child[2]->child[1]->parent = mr->child[2];
                        mr->child[2]->child[2]->parent = mr->child[2];
                    }
                    

                    root = mr;
                }   
            }else{
                Node * p = this->parent;
                // cout << "this: " << this->value[0] <<" " << this->value[1] << " " << this->value[2]<< endl;
                // cout << "this parent: " << p->value[0] <<" " << p->value[1] << " " << p->value[2]<< endl;
                Node * left;
                if(p->numChildren()<3){
                    // cout << "a: " << a->value[0] << " " << a->value[1] << " "<< a->value[2] << endl;
                    
                    a->parent = p;
                    // cout << "a's parent: " << a->parent->value[0] << " " << a->parent->value[1] << " "<< a->parent->value[2] << endl;
                    if(a->value[0]<p->value[0]){
                        p->value[1] = p->value[0];
                        p->child[1] = p->child[0];
                        p->child[0] = a;
                        if(a->numChildren()==0){
                            p->value[0] = a->value[0];
                        }else{
                            p->value[0] = a->value[2];
                        }
                    }else if(a->value[0]<p->value[2]){
                        p->child[1] = a;
                        if(a->numChildren()==0){
                            p->value[1] = a->value[0];
                        }else{
                            p->value[1] = a->value[2];
                        }
                    }else{
                        p->value[1] = p->value[2];
                        p->child[1] = p->child[2];
                        // p->value[2] = a->value[0];
                        p->child[2] = a;
                        if(a->numChildren()==0){
                            p->value[2] = a->value[0];
                        }else{
                            p->value[2] = a->value[2];
                        }
                    }

                    if(p->parent){
                        Node * grandpa = p->parent;
                        if(grandpa->child[0]==p){
                            grandpa->value[0] == p->value[2];
                        }else if(grandpa->child[1]==p){
                            grandpa->value[1] == p->value[2];
                        }else{
                            grandpa->value[2] == p->value[2];
                        }  
                    }
                     
                }else{
                    if(this==p->child[0]){   
                        // we won't be adding a leaf to a node that isn't a leaf
                        // so this logic should be sufficient?
                        if(this->numChildren()>1){ 
                            left = new Node(a->value[2], -1, this->value[2]);
                        }else {
                            left = new Node(a->value[0], -1, this->value[0]);
                        }
                        
                        left->child[0] = a;
                        left->child[2] = this; 
                        this->parent = left;
                        a->parent = left;
                        p->child[0] = p->child[1];
                        p->value[0] = p->value[1];
                        
                        p->child[1]= NULL;  // p no longer has a middle child
                        
                        p->value[1] = -1;
                        root = p->absorb(left, root);
                    }else if(this==p->child[1]){
                        if(p->child[0]->numChildren()>1){
                            left = new Node(p->child[0]->value[2],-1,a->value[2]);
                        }
                        else{   // leaf case
                            left = new Node(p->child[0]->value[0],-1,a->value[0]);
                        }
                        left->child[2] = a;
                        left->child[0] = p->child[0]; 
                        left->child[0]->parent = left;
                        this->parent = p; //questionable
                        left->child[2]->parent = left;
                        p->child[0] = this;
                        p->child[1] = NULL;  // p no longer has a middle child
                        p->value[0] = p->value[1];
                        p->value[1] = -1;
                        root = p->absorb(left, root);
                    }else if(this==p->child[2]){
                        if(p->child[0]->numChildren()>1){
                            left = new Node(p->child[0]->value[2],-1,p->child[1]->value[2]);
                        }else{
                            left = new Node(p->child[0]->value[0],-1,p->child[1]->value[0]);
                        }
                        left->child[2] = p->child[1];
                        left->child[0] = p->child[0]; 
                        this->parent = p; // questionable
                        a->parent = p;
                        p->child[0] = a;
                        p->child[1] = NULL;  // p no longer has a middle child
                        if(a->numChildren()>1){
                            p->value[0] = a->value[2];
                        }else{
                            p->value[0] = a->value[0];
                        }
                        p->value[1] = -1;
                        root = p->absorb(left, root);
                    } 
                }
                if(a->numChildren()==3){
                    a->child[0]->parent = a;
                    a->child[1]->parent = a;
                    a->child[2]->parent = a;
                }else if(a->numChildren()==2){
                    a->child[0]->parent = a;
                    a->child[2]->parent = a;
                }else if(a->numChildren()==1){
                    a->child[0]->parent = a;
                }
            }
            
            return root;
        }

        Node * discard(Node * removeChild, Node * root){
            if(removeChild==root && removeChild->numChildren()==0){
                cout << "You have deleted the only value in this tree, therefore the tree will be removed." << endl;
                return NULL;
            }
            
            Node * p = removeChild->parent;

            // severing connection between p and removeChild
            removeChild->parent = NULL;
    
            // easy case; removing leaf of full parent
            if(p->numChildren()==3){
                int killVal = removeChild->value[0];
                if(removeChild==p->child[0]){
                    p->child[0] = p->child[1];
                    p->child[0]->parent = p;
                    p->child[2]->parent = p;
                    p->value[0] = p->child[1]->value[0];
                    p->value[1] = -1;
                    p->child[1] = NULL;
                }else if (removeChild==p->child[1]){
                    p->child[1] = NULL;
                    p->value[1] = -1;
                }else if(removeChild==p->child[2]){
                    p->child[2] = p->child[1];
                    p->child[2]->parent = p;
                    p->value[2] = p->child[1]->value[0];
                    p->child[1] = NULL;
                    p->value[1] = -1;
                }
                // Frank is a helpful fellow. 
                // He exists to bubble up and fill in new values if necessary
                Node * frank = p;
                if(removeChild->numChildren()!=0){
                    while(frank->parent){ 
                        frank = frank->parent; 
                        if(frank->value[2]==killVal){
                            frank->value[2]= frank->child[2]->value[2];
                        }else if(frank->value[1]==killVal){
                            frank->value[1]= frank->child[1]->value[2];
                        }else if(frank->value[0]==killVal){
                            frank->value[0]= frank->child[0]->value[2];
                        }
                    }
                }
                return root;
            }

            // If root does not have three children, we can't delete one of its two children.
            if(p==root){
                if(removeChild==p->child[0])
                    root=p->child[2];
                else
                    root=p->child[0];
                cout << "Your tree is now a single leaf." << endl;
                return root;
            }

            // harder case: have to do some reshuffling
            if(removeChild==p->child[0]){
                p->child[0] = p->child[2];
                p->value[0] = p->value[2];
                p->child[0]->value[0] = p->child[2]->value[0];
                p->child[2] = NULL;
                p->value[2] = -1;
            }else if(removeChild==p->child[2]){
                p->child[2] = NULL;
                p->value[2] = -1;
            }
            
            // to get the number of children between p and its siblings,
            // we need to know how many siblings p has
            Node * grandpa = p->parent;

            int numSiblings = grandpa->numChildren();
            int totChildren = 0;

            // now we can count the number of children
            if(numSiblings==3){
                for(int i = 0; i<3; i++){
                    totChildren += grandpa->child[i]->numChildren();
                }
            }else if(numSiblings==2){
                totChildren = grandpa->child[0]->numChildren() + grandpa->child[2]->numChildren();
            }


            if(totChildren>=4){
                Node ** children = new Node*[totChildren];
                int i = 0;
                
                // generalize the indicies; things may change depending on what node is deleted
                if(grandpa->child[0]->numChildren()==1){
                    if(grandpa->child[0]->child[0]){
                        children[i++] = grandpa->child[0]->child[0];
                    }else{
                        children[i++] = grandpa->child[0]->child[2];
                    }
                    grandpa->child[0]->child[0] = NULL;
                }else if(grandpa->child[0]->numChildren()==2){
                    children[i++] = grandpa->child[0]->child[0];
                    children[i++] = grandpa->child[0]->child[2];
                    grandpa->child[0]->child[0] = NULL;
                    grandpa->child[0]->child[2] = NULL;
                } else{
                    children[i++] = grandpa->child[0]->child[0];
                    children[i++] = grandpa->child[0]->child[1];
                    children[i++] = grandpa->child[0]->child[2];
                    grandpa->child[0]->child[0] = NULL;
                    grandpa->child[0]->child[1] = NULL;
                    grandpa->child[0]->child[2] = NULL;
                }
                if(grandpa->numChildren()==3){
                    if(grandpa->child[1]->numChildren()==1){
                        if(grandpa->child[1]->child[0]){
                            children[i++] = grandpa->child[1]->child[0];
                        }else{
                            children[i++] = grandpa->child[1]->child[2];
                        }
                        grandpa->child[1]->child[0] = NULL;
                    }else if(grandpa->child[1]->numChildren()==2){
                        children[i++] = grandpa->child[1]->child[0];
                        children[i++] = grandpa->child[1]->child[2];
                        grandpa->child[1]->child[0] = NULL;
                        grandpa->child[1]->child[2] = NULL;
                    } else{
                        children[i++] = grandpa->child[1]->child[0];
                        children[i++] = grandpa->child[1]->child[1];
                        children[i++] = grandpa->child[1]->child[2];
                        grandpa->child[1]->child[0] = NULL;
                        grandpa->child[1]->child[1] = NULL;
                        grandpa->child[1]->child[2] = NULL;
                    }
                }
                if(grandpa->child[2]->numChildren()==1){
                    children[i++] = grandpa->child[2]->child[0];
                    grandpa->child[2]->child[0] = NULL;
                }else if(grandpa->child[2]->numChildren()==2){
                    children[i++] = grandpa->child[2]->child[0];
                    children[i++] = grandpa->child[2]->child[2];
                    grandpa->child[2]->child[0] = NULL;
                    grandpa->child[2]->child[2] = NULL;
                } else{
                    children[i++] = grandpa->child[2]->child[0];
                    children[i++] = grandpa->child[2]->child[1];
                    children[i++] = grandpa->child[2]->child[2];
                    grandpa->child[2]->child[0] = NULL;
                    grandpa->child[2]->child[1] = NULL;
                    grandpa->child[2]->child[2] = NULL;
                }

                grandpa->child[0] = NULL;
                grandpa->child[1] = NULL;
                grandpa->child[2] = NULL;

                if(totChildren == 4){
                    if(children[0]->value[2]==-1)
                        grandpa->child[0] = new Node(children[0]->value[0],-1,children[1]->value[0]);
                    else
                        grandpa->child[0] = new Node(children[0]->value[2],-1,children[1]->value[2]);
                    grandpa->child[0]->parent = grandpa;
                    grandpa->child[0]->child[0] = children[0];
                    grandpa->child[0]->child[0]->parent = grandpa->child[0];
                    grandpa->child[0]->child[2] = children[1];
                    grandpa->child[0]->child[2]->parent = grandpa->child[0];
                    

                    grandpa->child[1] = NULL;

                    if(children[2]->value[2]==-1)
                        grandpa->child[2] = new Node(children[2]->value[0],-1,children[3]->value[0]);
                    else
                        grandpa->child[2] = new Node(children[2]->value[2],-1,children[3]->value[2]);
                    grandpa->child[2]->parent = grandpa;
                    grandpa->child[2]->child[0] = children[2];
                    grandpa->child[2]->child[0]->parent = grandpa->child[2];
                    grandpa->child[2]->child[2] = children[3];
                    grandpa->child[2]->child[2]->parent = grandpa->child[2];

                    grandpa->value[0] = grandpa->child[0]->value[2];
                    grandpa->value[2] = grandpa->child[2]->value[2];
                    
                }else if(totChildren == 5){
                    if(children[0]->value[2]==-1)
                        grandpa->child[0] = new Node(children[0]->value[0],-1,children[1]->value[0]);
                    else
                        grandpa->child[0] = new Node(children[0]->value[2],-1,children[1]->value[2]);
                    grandpa->child[0]->parent = grandpa;
                    grandpa->child[0]->child[0] = children[0];
                    grandpa->child[0]->child[0]->parent = grandpa->child[0];
                    grandpa->child[0]->child[2] = children[1];
                    grandpa->child[0]->child[2]->parent = grandpa->child[0];
                    if(children[2]->value[2]==-1){
                        grandpa->child[2] = new Node(children[2]->value[0],children[3]->value[0],children[4]->value[0]);
                    }else{
                        grandpa->child[2] = new Node(children[2]->value[2],children[3]->value[2],children[4]->value[2]);
                    }

                    grandpa->child[2]->parent = grandpa;
                    grandpa->child[2]->child[0] = children[2];
                    grandpa->child[2]->child[0]->parent = grandpa->child[2];
                    grandpa->child[2]->child[1] = children[3];
                    grandpa->child[2]->child[1]->parent = grandpa->child[2];
                    grandpa->child[2]->child[2] = children[4];
                    grandpa->child[2]->child[2]->parent = grandpa->child[2];
                    grandpa->value[0] = grandpa->child[0]->value[2];
                    grandpa->value[2] = grandpa->child[2]->value[2];                    
                }else if(totChildren == 6){
                    if(children[0]->value[2]==-1)
                        grandpa->child[0] = new Node(children[0]->value[0],children[1]->value[0], children[2]->value[0]);
                    else
                        grandpa->child[0] = new Node(children[0]->value[2],children[1]->value[2], children[2]->value[2]);
                    grandpa->child[0]->parent = grandpa;
                    grandpa->child[0]->child[0] = children[0];
                    grandpa->child[0]->child[0]->parent = grandpa->child[0];
                    grandpa->child[0]->child[1] = children[1];
                    grandpa->child[0]->child[1]->parent = grandpa->child[0];
                    grandpa->child[0]->child[2] = children[2];
                    grandpa->child[0]->child[2]->parent = grandpa->child[0];

                    grandpa->child[1] = NULL;
                    grandpa->value[1] = -1;

                    if(children[3]->value[2]==-1)
                        grandpa->child[2] = new Node(children[3]->value[0],children[4]->value[0], children[5]->value[0]);
                    else
                        grandpa->child[2] = new Node(children[3]->value[2],children[4]->value[2], children[5]->value[2]);
                    grandpa->child[2]->parent = grandpa;
                    grandpa->child[2]->child[0] = children[3];
                    grandpa->child[2]->child[0]->parent = grandpa->child[2];
                    grandpa->child[2]->child[1] = children[4];
                    grandpa->child[2]->child[1]->parent = grandpa->child[2];
                    grandpa->child[2]->child[2] = children[5];
                    grandpa->child[2]->child[2]->parent = grandpa->child[2];

                    grandpa->value[0] = grandpa->child[0]->value[2];
                    grandpa->value[2] = grandpa->child[2]->value[2];
                }else{
                    if(children[0]->value[2]==-1)
                        grandpa->child[0] = new Node(children[0]->value[0],-1,children[1]->value[0]);
                    else
                        grandpa->child[0] = new Node(children[0]->value[2],-1,children[1]->value[2]);
                    grandpa->child[0]->parent = grandpa;
                    grandpa->child[0]->child[0] = children[0];
                    grandpa->child[0]->child[0]->parent = grandpa->child[0];
                    grandpa->child[0]->child[2] = children[1];
                    grandpa->child[0]->child[1]->parent = grandpa->child[0];

                    if(children[2]->value[2]==-1)
                        grandpa->child[1] = new Node(children[2]->value[0],-1,children[3]->value[0]);
                    else
                        grandpa->child[1] = new Node(children[2]->value[2],-1,children[3]->value[2]);
                    grandpa->child[1]->parent = grandpa;
                    grandpa->child[1]->child[0] = children[2];
                    grandpa->child[1]->child[0]->parent = grandpa->child[1];
                    grandpa->child[1]->child[2] = children[3];
                    grandpa->child[1]->child[2]->parent = grandpa->child[1];

                    if(children[4]->value[2]==-1)
                        grandpa->child[2] = new Node(children[4]->value[0],children[5]->value[0], children[6]->value[0]);
                    else
                        grandpa->child[2] = new Node(children[4]->value[2],children[5]->value[2], children[6]->value[2]);
                    grandpa->child[2]->parent = grandpa;
                    grandpa->child[2]->child[0] = children[4];
                    grandpa->child[2]->child[0]->parent = grandpa->child[2];
                    grandpa->child[2]->child[1] = children[5];
                    grandpa->child[2]->child[1]->parent = grandpa->child[2];
                    grandpa->child[2]->child[2] = children[6];
                    grandpa->child[2]->child[2]->parent = grandpa->child[2];

                    grandpa->value[0] = grandpa->child[0]->value[2];
                    grandpa->value[1] = grandpa->child[1]->value[2];
                    grandpa->value[2] = grandpa->child[2]->value[2];
                } 
            }
            else if(totChildren==3){
                if(grandpa->child[0]==p){
                    grandpa->child[2]->value[1] = grandpa->child[2]->value[0];
                    grandpa->child[2]->child[1] = grandpa->child[2]->child[0];
                    grandpa->child[2]->child[0] = p->child[0];
                    p->child[0]->parent = grandpa->child[2];
                    if(p->value[2]==-1)
                        grandpa->child[2]->value[0] = p->value[0];
                    else
                        grandpa->child[2]->value[0] = p->value[2];
                    if(grandpa==root){
                        root=grandpa->child[2];
                        return root;
                    }
                    root = discard(p, root);                    
                    
                }else{
                    grandpa->child[0]->child[1] = grandpa->child[0]->child[2];
                    grandpa->child[0]->value[1] = grandpa->child[0]->value[2];
                    grandpa->child[0]->child[2] = p->child[0];
                    p->child[0]->parent = grandpa->child[0];
                    if(p->value[2]==-1)
                        grandpa->child[0]->value[2] = p->value[0];
                    else
                        grandpa->child[0]->value[2] = p->value[2];
                    grandpa->value[0] = grandpa->child[0]->value[2];
                    if(grandpa==root){
                        root=grandpa->child[0];
                        return root;
                    }
                    root = discard(p, root);
                }
            }
            return root;
        }
};
