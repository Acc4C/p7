#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
/*
typedef int TreeItem;

struct _tree {
    TreeItem data;
    Tree *child;
    Tree *sibling;
};
*/
Tree* createTree(int value){
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    if (tree == NULL){ return NULL; }
    tree -> value = value;
    tree -> left = NULL;
    tree -> right = NULL;
    return tree;
}

int addNode(Tree* parent, int value){
    if (value > (parent -> value)){
        if ((parent -> right) != NULL){
            return addNode(parent -> right, value);
        }
        Tree* newNode = createTree(value);
        if (newNode == NULL){ return 1; }
        (parent -> right) = newNode;
        return 0;
    } else if (value < (parent -> value)){
        if ((parent -> left) != NULL){
            return addNode(parent -> left, value);
        }
        Tree* newNode = createTree(value);
        if (newNode == NULL){ return 1; }
        (parent -> left) = newNode;
        return 0;
    }
    return 3;
    /* Tree *res = tree_create(value);
    if (parent->child == NULL) {
        parent->child = res;
    } else {
        Tree *last = parent->child;
        while (last->sibling != NULL) {
            last = last->sibling;
        }
        last->sibling = res;
    }
    return res; */
}

/*void removeNode(Tree* node){
    Tree* nodeForClone;
    int removeType = 0;
    if (((node -> left) != NULL) && ((node -> right) != NULL)){
        Tree* preNode = NULL;
        nodeForClone = (node -> right);
        while ((nodeForClone -> left) != NULL){
            preNode = nodeForClone;
            nodeForClone = (nodeForClone -> left);
        }
        node -> value = (nodeForClone -> value);
        if (preNode == NULL){
            node -> right = (nodeForClone -> right);
        } else{
            preNode -> left = (nodeForClone -> right);
        }
        // node -> value = (nodeForClone -> value);
        free(nodeForClone);
        return;
        /*if ((node -> right -> left) != NULL){
            nodeForClone = (node -> right -> left);
            removeType = 1;
        }
        else{ nodeForClone = (node -> right); }*/
/*    } else if ((node -> left) != NULL){
        nodeForClone = (node -> left);
    } else if ((node -> right) != NULL){
        nodeForClone = (node -> right);
    }
    node -> value = (nodeForClone -> value);
    node -> left = (nodeForClone -> left);
    node -> right = (nodeForClone -> right);
    free(nodeForClone);
}*/

int removeNode(Tree** nodePointer, int value){
    Tree* node = *nodePointer;
    if (value > (node -> value)){
        if ((node -> right) != NULL){
            return removeNode(&(node -> right), value);
        }
        return 4;
    } else if (value < (node -> value)){
        if ((node -> left) != NULL){
            return removeNode(&(node -> left), value);
        }
        return 4;
    }
    Tree* nodeForClone;
    // int removeType = 0;
    if (((node -> left) != NULL) && ((node -> right) != NULL)){
        Tree* preNode = NULL;
        nodeForClone = (node -> right);
        while ((nodeForClone -> left) != NULL){
            preNode = nodeForClone;
            nodeForClone = (nodeForClone -> left);
        }
        node -> value = (nodeForClone -> value);
        if (preNode == NULL){
            node -> right = (nodeForClone -> right);
        } else{
            preNode -> left = (nodeForClone -> right);
        }
        // node -> value = (nodeForClone -> value);
        free(nodeForClone);
        return 0;
        /*if ((node -> right -> left) != NULL){
            nodeForClone = (node -> right -> left);
            removeType = 1;
        }
        else{ nodeForClone = (node -> right); }*/
    } else if ((node -> left) != NULL){
        (*nodePointer) = (node -> left);
    } else if ((node -> right) != NULL){
        (*nodePointer) = (node -> right);
    } else{
        (*nodePointer) = NULL;
    }
    /*node -> value = (nodeForClone -> value);
    node -> left = (nodeForClone -> left);
    node -> right = (nodeForClone -> right);
    free(nodeForClone);*/
    // removeNode(parent);
    free(node);
    return 0;
}
/*
void tree_print_node(TreeItem value, int indent)
{
    for (int i = 0; i < indent; ++i) {
        printf(" ");
    }
    printf("%d\n", value);
}

void tree_show(Tree *t, int indent)
{
    if (t == NULL) {
        return;
    }
    tree_show(t->sibling, indent + 2);
    tree_print_node(t->data, indent);
    tree_show(t->child, indent + 2);
}

void tree_print(Tree *t)
{
    tree_show(t, 0);
} */

void printTree(Tree* tree, int depth){
    if ((tree -> left) != NULL){ printTree(tree -> left, depth + 1); }
    for (int i = 0; i < depth; i++){ printf(" "); }
    printf("%d\n", tree -> value);
    // if ((tree -> left) != NULL){ printTree(tree -> left, depth + 1); }
    if ((tree -> right) != NULL){ printTree(tree -> right, depth + 1); }
}

void freeTree(Tree* tree){
    if ((tree -> left) != NULL){ freeTree(tree -> left); }
    if ((tree -> right) != NULL){ freeTree(tree -> right); }
    free(tree);
}

int nodesCount(Tree* tree){
    int count = 1;
    if ((tree -> left) != NULL){ count += nodesCount(tree -> left); }
    if ((tree -> right) != NULL){ count += nodesCount(tree -> right); }
    return count;
}
