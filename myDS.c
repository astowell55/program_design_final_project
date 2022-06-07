#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myDS.h"
#include "myIO.h"
#include "myAlgo.h"
void build_tree(node **root, item *data, node *cur, int *error)
{
    if ((*root) == NULL)
    {
        node *new_node = (node *)malloc(sizeof(node));
        new_node->data = data;
        new_node->left_child = NULL;
        new_node->right_child = NULL;
        new_node->parent = cur;
        (*root) = new_node;
        return;
    }
    else
    {
        if (wcscmp(((*root)->data->song_name), (data->song_name)) > 0)
        {
            build_tree(&((*root)->left_child), data, (*root), error);
        }
        else if (wcscmp(((*root)->data->song_name), (data->song_name)) < 0)
        {
            build_tree(&((*root)->right_child), data, (*root), error);
        }
        else
        {
            printf("%ls already exist\n", data->song_name);
            *error = 1;
            return;
        }
    }
}
void build_song(node *cur_songlist,wchar_t song_name[]){
    /*
        Add a song named song_name[] into cur_songlist.
        Also store the artist and time.
        if there's no tree, build one.
    */
}
void build_songlist(node *songlist_tree,wchar_t songlist_name[]){
    /*
        Add a pointer of songlist named songlist_name[] into songlist_tree.
        if there's no tree, build one.
    */
}

void delete_name(node **root, item *data, int search_Choose)
{
    node *target = search(*root, data, search_Choose);
    if (target == NULL)
    {
        printf("'%ls' not found.\n", data->song_name);
    }
    node *y;
    node *x;

    if (target->left_child == NULL && target->right_child == NULL)
    {
        y = target;
    }
    else
    {
        if (target->right_child != NULL)
        {
            y = target->right_child;
        }
        else
        {
            y = target->left_child;
        }
    }

    if (y->left_child != NULL)
    {
        x = y->left_child;
    }
    else
    {
        x = y->right_child;
    }

    if (x != NULL)
    {
        x->parent = y->parent;
    }

    if (y->parent == NULL)
    {
        *root = x;
    }
    else if (y == y->parent->left_child)
    {
        y->parent->left_child = x;
    }
    else
    {
        y->parent->right_child = x;
    }

    if (y != target)
    {
        target->data->index = y->data->index;
        target->data->song_name = y->data->song_name;
    }

    free(y);
    return;
}
void delete_song(node *cur_songlist,wchar_t song_name[]){
    /*
        search song_name in cur_songlist. if found, free it. 
    */
}
void delete_songlist(node *songlist_tree,wchar_t songlist_name[]){
    /*
        search songlist_name in songlist_tree. if found, free it and its all song.
    */
   
}