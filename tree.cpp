
class Tree {
    public:
        Node * root;
        void print(Node * start){
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
                cout << "your value is larger than anything in the tree" << endl;

                return NULL;
            }
        }
        Node * insert(int valToAdd, Node * root){
            Node * b = search(root, valToAdd);
            if(b->value[0]==valToAdd){
                return root;
            }
            Node * a = new Node(valToAdd);
            root =  b->absorb(a, root);

            // cout << "root child 1: " << root->child[0]->value[0] << " " << root->child[0]->value[1] << " " << root->child[0]->value[2] << endl;
                
            // cout << "root child 2: " << root->child[2]->value[0] << " " << root->child[2]->value[1] << " " << root->child[2]->value[2]<< endl;
                
            // cout << "did we change root? " << root->value[0] << " " << root->value[1] << " " << root->value[2] << endl;
            // cout << root << endl;

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
