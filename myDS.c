#include <stdio.h>
#include <stdlib.h>
#include "myDS.h"
#include "myIO.h"
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

void delete_index(node **root,item *data){
    node *target = search(data->index);

    node *y;
    node *x;

    if(target->left_child==NULL&&target->right_child==NULL){
        y = target;
    }else{
        if(target->right_child!=NULL){
            y = target->right_child;
        }else{
            y = target->left_child;
        }
    }

    if(y->left_child!=NULL){
        x = y->left_child;
    }else{
        x = y->right_child;
    }

    if(x != NULL){
        x->parent = y->parent;
    }

    if(y->parent == NULL){
        *root = x;
    }else if(y == y->parent->left_child){
        y->parent->left_child = x;
    }else{
        y->parent->right_child = x;
    }
    
    if(y != target){
        target->data->index = y->data->index;
        target->data->song_name = y->data->song_name;
    }

    free(y);
    return;
}