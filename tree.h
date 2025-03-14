#ifndef TREE
#define TREE

// typedef int TreeItem;
typedef struct Tree{
    int value; // TreeItem data;
    struct Tree* left;
    struct Tree* right;
} Tree;

// Tree *tree_create(TreeItem value);
Tree* createTree(int value); // OK
int addNode(Tree* parent, int value); // OK
int removeNode(Tree** nodePointer, int value); // OK
// void printNode(int value);
void printTree(Tree* tree, int depth); // OK
void freeTree(Tree* tree); // OK
int nodesCount(Tree* tree); // OK

#endif
