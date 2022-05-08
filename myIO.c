#include <stdio.h>
#include "myDS.h"
#include "myIO.h"


void Inorder_traverse(node *root){
    if(root == NULL){
        return;
    } 
    Inorder_traverse(root->left_child);
    printf("%d %s",root->data->index,root->data->song_name);
    Inorder_traverse(root->right_child);
}