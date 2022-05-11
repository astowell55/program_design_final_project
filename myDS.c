#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myDS.h"
#include "myIO.h"
int build_tree(node **root,item *data){
    if((*root) == NULL){
        node *new_node = (node*)malloc(sizeof(node));
        new_node->data = data;
        new_node->left_child = NULL;
        new_node->right_child = NULL;
        (*root) = new_node;
        return 0;
    }else{
        if(strcmp(((*root)->data->song_name) ,(data->song_name)) > 0) build_tree(&((*root)->left_child),data);
        else if(strcmp(((*root)->data->song_name) ,(data->song_name)) < 0) build_tree(&((*root)->right_child),data);
        else{
            printf("%s already exist\n",data->song_name);
            return 1;
        }

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