#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include "myDS.h"
#include "myIO.h"
#include "myAlgo.h"
void build_tree(node **root, song *data, node *cur, int *error)
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
        if (strcmp(((*root)->data->song_name), (data->song_name)) > 0)
        {
            build_tree(&((*root)->left_child), data, (*root), error);
        }
        else if (strcmp(((*root)->data->song_name), (data->song_name)) < 0)
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
void build_song(song **cur_songlist,char *target){
    /*
        Add a song named song_name[] into cur_songlist.
        Also store the artist and time.
        if there's no tree, build one.
    */
    song *par=NULL;
    song *cur=NULL;
    song *build_node = malloc(sizeof(song));
    char *name = malloc((strlen(target) + 1));
    strcpy(name,target);
    //char_t *name = malloc(sizeof(target)*sizeof(wchar_t));
    //wcscpy(name,target);
    //build_node->song_name = name;
    //wcscpy(build_node->song_name,target);
    /*
        song *target = search_song(song_data,song_name);
        wcscpy(build_node->artist ,target->artist);
        wcscpy(build_node->length ,target->length);
    */

    cur = *cur_songlist;
    while(cur!=NULL){
        par = cur;
        if(strcmp(((*cur_songlist)->song_name), (target)) > 0){
            //cur = cur->right_child;
            cur = cur->left_child;
        }else{
            //cur = cur->left_child;
            cur = cur->right_child;
        }
    }
    //printf("%p",build_node);
    build_node->parent = par;
    if(par==NULL){
        *cur_songlist = build_node;
    }else if(strcmp(((*cur_songlist)->song_name), (target)) > 0){
        //par->right_child = build_node;
        par->left_child = build_node;
    }else{
        //par->left_child = build_node;
        par->right_child = build_node;
    }
    // if ((*cur_songlist) == NULL)
    // {
    //     song *target = search_song(*cur_songlist,song_name); //still wrong, it should be search_song(song_data,song_name);
    //     song *new_node = (song *)malloc(sizeof(song));
    //     wcscpy(new_node->song_name,song_name);
    //     wcscpy(new_node->artist,target->artist);
    //     wcscpy(new_node->length,target->length);
    //     new_node->left_child = NULL;
    //     new_node->right_child = NULL;
    //     new_node->parent = par;
    //     *cur_songlist = new_node;
    //     return;
    // }
    // else
    // {
    //     if (wcscmp(((*cur_songlist)->song_name), (song_name)) > 0)
    //     {
    //         build_song(&((*cur_songlist)->left_child), song_name, (*cur_songlist));
    //     }
    //     else if (wcscmp(((*cur_songlist)->song_name), (song_name)) < 0)
    //     {
    //         build_song(&((*cur_songlist)->right_child), song_name, (*cur_songlist));
    //     }
    //     else
    //     {
    //         printf("%ls already exist\n", song_name);
    //         return;
    //     }
    // }
}
void build_songlist(node **songlist_tree,char *target){
    /*
        Add a pointer of songlist named songlist_name[] into songlist_tree.
        if there's no tree, build one.
    */
    //printf("lol\n");

    node *par=NULL;
    node *cur=NULL;
    node *build_node = malloc(sizeof(node));
    strcpy(build_node->songlist_name,target);
    build_node->data = NULL;

    cur = *songlist_tree;
    while(cur!=NULL){
        par = cur;
        if(strcmp(((*songlist_tree)->songlist_name), (target)) > 0){
            //cur = cur->right_child;
            cur = cur->left_child;
        }else{
            //cur = cur->left_child;
            cur = cur->right_child;
        }
    }

    build_node->parent = par;
    if(par==NULL){
        *songlist_tree = build_node;
    }else if(strcmp(((*songlist_tree)->songlist_name), (target)) > 0){
        //par->right_child = build_node;
        par->left_child = build_node;
    }else{
        //par->left_child = build_node;
        par->right_child = build_node;
    }

    // if ((*songlist_tree) == NULL)
    // {
    //     node *new_node = (node *)malloc(sizeof(node));
    //     //printf("new_node\n");
    //     wcscpy(new_node->songlist_name,target);
    //     //printf("cpy\n");
    //     new_node->data = NULL;
    //     new_node->left_child = NULL;
    //     new_node->right_child = NULL;
    //     new_node->parent = par;
    //     *songlist_tree = new_node;
    //     //printf("Builded\n");
    //     return;
    // }
    // else
    // {
    //     if (wcscmp(((*songlist_tree)->songlist_name), (target)) > 0)
    //     {
    //         if((*songlist_tree)->left_child!=NULL) {
    //             build_song(&((*songlist_tree)->left_child), target, (*songlist_tree));
    //         }else{
    //             build_song(NULL, target, (*songlist_tree));
    //         }
    //     }
    //     else if (wcscmp(((*songlist_tree)->songlist_name), (target)) < 0)
    //     {
    //         if((*songlist_tree)->right_child!=NULL) 
    //         {
    //             build_song(&((*songlist_tree)->right_child), target, (*songlist_tree));
    //         }else 
    //         {
    //             build_song(NULL, target, (*songlist_tree));
    //         }
    //     }
    //     else
    //     {
    //         printf("%ls already exist\n", target);
    //         return;
    //     }
    // }
}
void build_song_data(song **song_data,song *songs){
    song *par=NULL;
    song *cur=NULL;
    
    cur = *song_data;

    while(cur!=NULL){
        par = cur;
        if(strcmp(((*song_data)->song_name), (songs->song_name)) > 0){
            cur = cur->right_child;
        }else{
            cur = cur->left_child;
        }
    }
    //printf("%ls",songs->song_name);

    songs->parent = par;
    if(par==NULL){
        *song_data = songs;
    }else if(strcmp(((*song_data)->song_name), (songs->song_name)) > 0){
        par->right_child = songs;
    }else{
        par->left_child = songs;
    }
}
// void delete_name(node **root, song *data, int search_Choose)
// {
//     node *target = search(*root, data, search_Choose);
//     if (target == NULL)
//     {
//         printf("'%ls' not found.\n", data->song_name);
//     }
//     node *y;
//     node *x;
//
//     if (target->left_child == NULL && target->right_child == NULL)
//     {
//         y = target;
//     }
//     else
//     {
//         if (target->right_child != NULL)
//         {
//             y = target->right_child;
//         }
//         else
//         {
//             y = target->left_child;
//         }
//     }
//
//     if (y->left_child != NULL)
//     {
//         x = y->left_child;
//     }
//     else
//     {
//         x = y->right_child;
//     }
//
//     if (x != NULL)
//     {
//         x->parent = y->parent;
//     }
//
//     if (y->parent == NULL)
//     {
//         *root = x;
//     }
//     else if (y == y->parent->left_child)
//     {
//         y->parent->left_child = x;
//     }
//     else
//     {
//         y->parent->right_child = x;
//     }
//
//     if (y != target)
//     {
//         target->data->index = y->data->index;
//         target->data->song_name = y->data->song_name;
//     }
//
//     free(y);
//     return;
// }
static void delete_all_song(song *songlist_root){
    /*
        using recursive to free all song of a songlist.
    */
    if(songlist_root==NULL) return;
    if(songlist_root->left_child!=NULL) delete_all_song(songlist_root->left_child);
    if(songlist_root->right_child!=NULL) delete_all_song(songlist_root->right_child);
    free(songlist_root);
    return;
}
void delete_song(song **cur_songlist,char song_name[]){
    /*
        search song_name in cur_songlist. 
        if found, free it.
        if not found, print error and return. 
    */
   song *target = search_song(*cur_songlist,song_name);
   if (target == NULL)
    {
        printf("'%ls' not found.\n", song_name);
    }
    song *y;
    song *x;

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
        *cur_songlist = x;
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
        strcpy( target->artist, y->artist);
        strcpy(target->song_name, y->song_name);
        target->length = y->length;
    }

    free(y);
    return;
    
}
void delete_songlist(node **songlist_tree,char songlist_name[]){
    /*
        search songlist_name in songlist_tree. 
        if found, free it and its all song.
        if not found, print error and return.
    */
    node *target = search_songlist(*songlist_tree,songlist_name);
    if (target == NULL)
    {
        printf("'%ls' not found.\n", songlist_name);
        return;
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
        *songlist_tree = x;
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
        target->data = y->data;
       strcpy(target->songlist_name,y->songlist_name);
    }
    
    delete_all_song(y->data);
    free(y);
    return;
}