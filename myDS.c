#include <stdio.h>
#include <stdlib.h>
#include "myDS.h"

void build_tree(node **root,item *data){
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->left_child = NULL;
    new_node->right_child = NULL;
    if((*root) == NULL){
        (*root) = new_node;
        return;
    }else{
        if(((*root)->data->index) > (data->index)) build_tree(&((*root)->left_child),data);
        else build_tree(&((*root)->right_child),data);
    }
}

