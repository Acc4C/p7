#ifndef TREE
#define TREE

typedef struct Tree{
    int value;
    struct Tree* left;
    struct Tree* right;
} Tree;

Tree* createTree(int value);
int addNode(Tree* parent, int value);
int removeNode(Tree** nodePointer, int value);
void printTree(Tree* tree, int depth);
void freeTree(Tree* tree);
int nodesCount(Tree* tree);

#endif
