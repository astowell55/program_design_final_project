#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include "myDS.h"
#include "myIO.h"

node *search(node *root, song *target, int search_Choose)
{
    node *curr = root;

    if (search_Choose == 1)
    {
        while (curr != NULL && wcscmp(target->artist, curr->data->artist) != 0)
        {

            if (wcscmp(curr->data->artist, target->artist) > 0)
            {
                curr = curr->left_child;
            }
            else
            {
                curr = curr->right_child;
            }
        }
        return curr;
    }
    else if (search_Choose == 2)
    {
        while (curr != NULL && wcscmp(target->song_name, curr->data->song_name) != 0)
        {

            if (wcscmp(curr->data->song_name, target->song_name) > 0)
            {
                curr = curr->left_child;
            }
            else
            {
                curr = curr->right_child;
            }
        }
        return curr;
    }
}
node *search_songlist(node *songlist_tree, wchar_t songlist_name[])
{
    /*
        search songlist_name in songlist_tree.
        if found, return the pointer of songlist_name.
        if not, return NULL.
    */
    node *curr = songlist_tree;
    while (curr != NULL && wcscmp(songlist_name, curr->songlist_name) != 0)
    {
        //printf("while: _%p_\n",curr);
        if (wcscmp(songlist_name, curr->songlist_name) > 0)
        {
            curr = curr->left_child;
        }
        else
        {
            curr = curr->right_child;
        }
    }
    return curr;
}
song *search_song(song *cur_songlist, wchar_t song_name[])
{
    /*
        search song_name in cur_songlist.
        if found, return the pointer of the song.
        if not, return NULL.
    */
    song *curr = cur_songlist;
    while (curr != NULL && wcscmp(song_name, curr->song_name) != 0)
    {
        //printf("while: _%p_\n",curr);
        if (wcscmp(song_name, curr->song_name) > 0)
        {
            curr = curr->left_child;
        }
        else
        {
            curr = curr->right_child;
        }
    }
    return curr;
}
