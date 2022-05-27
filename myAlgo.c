#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myDS.h"
#include "myIO.h"


node *search(node *root, item *target)
{
    node *curr = (node *)malloc(sizeof(curr));
    curr = root;

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