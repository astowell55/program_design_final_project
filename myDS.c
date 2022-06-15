#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include "myDS.h"
#include "myIO.h"
#include "myAlgo.h"
#include "tree.h"
void build_song(song **cur_songlist,char *target){
    /*
        Add a song named song_name[] into cur_songlist.
        Also store the artist and time.
        if there's no tree, build one.
    */
    song *par=NULL;
    song *cur=NULL;
    song *target_data = search_song(song_data,target);
    if(target_data==NULL){
        printf("Can't find this song in song data!\n");
        return;
    }
    song *build_node = malloc(sizeof(song));
    //char *name = malloc((strlen(target) + 1));
    // build_node->song_name = malloc(strlen(target));
    // strcpy(build_node->song_name,target);
    build_node->song_name = target_data->song_name;
    build_node->artist = target_data->artist;
    build_node->length = target_data->length;
    upload_time(&(build_node->times));

    //printf("node:%s\n",build_node->song_name);
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
        if(strcmp(((cur)->song_name), (target)) > 0){
            //cur = cur->right_child;
            cur = cur->left_child;
        }else if(strcmp((cur->song_name), (target)) < 0){
            //cur = cur->left_child;
            cur = cur->right_child;
        }else{
            printf("already exist\n");
            return;
        }
    }
    //printf("%p",build_node);
    build_node->parent = par;
    if(par == NULL){
        *cur_songlist = build_node;
    }else if(strcmp(((par)->song_name), (target)) > 0){
        //par->right_child = build_node;
        par->left_child = build_node;
    }else{
        //par->left_child = build_node;
        par->right_child = build_node;
    }
    printf("Add song : %s\n",target);
}
void build_songlist(node **songlist_tree,char *target){
    /*
        Add a pointer of songlist named songlist_name[] into songlist_tree.
        if there's no tree, build one.
    */
    node *par=NULL;
    node *cur=NULL;
    node *build_node = malloc(sizeof(node));
    strcpy(build_node->songlist_name,target);
    build_node->data = NULL;

    cur = *songlist_tree;
    while(cur!=NULL){
        par = cur;
        if(strcmp(((cur)->songlist_name), (target)) > 0){
            cur = cur->left_child;
        }else{
            cur = cur->right_child;
        }
    }

    build_node->parent = par;
    if(par==NULL){
        *songlist_tree = build_node;
    }else if(strcmp(((par)->songlist_name), (target)) > 0){
        par->left_child = build_node;
    }else{
        par->right_child = build_node;
    }
}
void build_song_data(song **song_data,song *songs){
    song *par=NULL;
    song *cur=NULL;
    
    cur = *song_data;

    while(cur!=NULL){
        par = cur;
        
        if(strcmp(((cur)->song_name), (songs->song_name)) > 0){
            cur = cur->left_child;
        }else{
            cur = cur->right_child;
        }
    }

    songs->parent = par;
    if(par==NULL){
        *song_data = songs;
    }else if(strcmp(((par)->song_name), (songs->song_name)) > 0){
        par->left_child = songs;
    }else{
        par->right_child = songs;
    }
    return;
}

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
static song *leftmost_song(song *cur_songlist){
    while(cur_songlist->left_child!=NULL){
        cur_songlist = cur_songlist->left_child;
    }
    return cur_songlist;
}
static song *Successor_song(song *cur_songlist){
    if(cur_songlist->right_child!=NULL){
        return leftmost_song(cur_songlist);
    }

    song *successor = cur_songlist->parent;
    while (successor != NULL && cur_songlist == successor->right_child) {
        cur_songlist = successor;
        successor = successor->parent;
    }
    return successor;
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
        printf("'%s' not found.\n", song_name);
        return;
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
        //strcpy(target->artist, y->artist);
        strcpy(target->song_name, y->song_name);
        //target->length = y->length;
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
        printf("'%s' not found.\n", songlist_name);
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