#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include "myDS.h"
#include "myIO.h"

node *search(node *root, item *target, int search_Choose)
{
    node *curr = root;

    if (search_Choose == 1)
    {
        while (curr != NULL && strcmp(target->artist, curr->data->artist) != 0)
        {

            if (strcmp(curr->data->artist, target->artist) > 0)
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
        while (curr != NULL && strcmp(target->song_name, curr->data->song_name) != 0)
        {

            if (strcmp(curr->data->song_name, target->song_name) > 0)
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