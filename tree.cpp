
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
        Tree(Node * r){
            root = r;
        } // constructor

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
        bool insert(int valToAdd){
            Node * b = search(root, valToAdd);
            if(b->value[0]==valToAdd){
                return true;
            }
            Node * a = new Node(valToAdd);
            b->absorb(a, root);
            return true;
        }
        bool kill(int valToKill); // changed delete to kill b/c delete keyword
        void print();
};
