
class Tree {
    public:
        Node * root;
        void print(Node * start);
        Tree(); // constructor
        Node * search(int valToFind);
        bool insert(int valToAdd);
        bool kill(int valToKill); // changed delete to kill b/c delete keyword
        void print();
};
