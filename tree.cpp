
class Tree {
    public:
        Node * root;
        void print(Node * start){
            // cout << "outside of logic: { " << start->value[0] << " " << start->value[1] << " " << start->value[2] << " }" << endl;
            if(start->numChildren()==3){
                cout << "{ " << start->value[0] << " " << start->value[1] << " " << start->value[2] << " }" << endl;
                for(int i = 0; i < 3; i++){
                    print(start->child[i]);
                }
            }
            else if(start->numChildren()==2){
                cout << "{ " << start->value[0] << " " << start->value[2] << " }" << endl;
                print(start->child[0]);

                print(start->child[2]);
            }
            else if (start->numChildren()==0){
                cout << "{ " << start->value[0] << " } "<< endl;
            }
        }

        // constructor
        Tree(Node * r){
            root = r;
        } 

        Node * search(Node * node, int a){
            if(node->numChildren()==0){
                if(node==root){
                    Node * bigGuy = new Node(1000, -1, -1);
                    return bigGuy;
                }
                return node;
            }
            if(a<=node->value[0]){
                return(search(node->child[0],a));
            }
            else if(a<=node->value[1] && node->value[1]!=-1){
                return(search(node->child[1],a));
            }
            else if(a<=node->value[2]){
                return(search(node->child[2],a));
            }
            else{
                Node * bigGuy = new Node(1000, -1, -1);
                return bigGuy;
            }
        }
        Node * insert(int valToAdd, Node * root){
            cout <<"absorbing " << valToAdd << endl;
            Node * b = search(root, valToAdd);
            cout << "search val: " << b->value[0] << endl;
            cout << endl;
            if(b->value[0]==valToAdd){
                return root;
            }

            if(b->value[0]==1000){
                int maxVal = root->value[2];
                if(maxVal==-1){
                    root->child[2] = new Node(valToAdd);
                    root->child[0] = new Node(root->value[0]);
                    root->child[2]->parent = root;
                    root->child[0]->parent = root;
                    root->value[2] = valToAdd;
                    return root;
                }

                Node * kid2 = root->child[2];
                root->value[2] = valToAdd;

                while(kid2->numChildren()>0){
                    kid2->value[2] = valToAdd;
                    kid2 = kid2->child[2];
                }
                kid2->value[0] = valToAdd;

                return this->insert(maxVal, root);
            }
            
            Node * a = new Node(valToAdd);
            root =  b->absorb(a, root);

            return root;
        }

        // changed delete to kill b/c delete keyword
        bool kill(int valToKill, Node * root){
            Node * b = search(root, valToKill);
            if(b->value[0]==valToKill){
                root->discard(b, root);
                return this;
            } 
            else{
                return this;
            }
        } 
        void print();
};
