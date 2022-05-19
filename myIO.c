#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myDS.h"
#include "myIO.h"
static FILE *outputSongFile;
void read_song_name(char buffer[MAX_SONG_NAME + 1])
{
    char c;
    int length = 0;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (length < MAX_SONG_NAME)
        {
            buffer[length++] = c;
        }
    }
    buffer[length] = '\0';
    if (strlen(buffer) == MAX_SONG_NAME)
    {

        buffer[length - 1] = '.';
        buffer[length - 2] = '.';
        buffer[length - 3] = '.';
    }
    return;
}
void read_line(item *data)
{
    char c;
    char buf[MAX_SONG_NAME + 1];
    scanf(" %d ", &data->index);
    read_song_name(buf);
    data->song_name = (char *)malloc(sizeof(buf));
    strncpy(data->song_name, buf, MAX_SONG_NAME);
    return;
}
void Preorder_traverse(node *root, int output_choose)
{
    if (root == NULL)
    {
        return;
    }
    if (output_choose == 1)
    {
        fprintf(outputSongFile, "%d ", root->data->index);
        fprintf(outputSongFile, "%s", root->data->song_name);
        fprintf(outputSongFile, "\n");
    }
    else if (output_choose == 2)
    {
        printf("%d %s\n", root->data->index, root->data->song_name);
    }
    Preorder_traverse(root->left_child, output_choose);
    Preorder_traverse(root->right_child, output_choose);
}

void Inorder_traverse(node *root, int output_choose)
{
    if (root == NULL)
    {
        return;
    }
    if (output_choose == 1)
    {
        Inorder_traverse(root->left_child, output_choose);
        fprintf(outputSongFile, "%d ", root->data->index);
        fprintf(outputSongFile, "%s", root->data->song_name);
        fprintf(outputSongFile, "\n");
    }
    else if (output_choose == 2)
    {
        Inorder_traverse(root->left_child, output_choose);
        printf("%d %s\n", root->data->index, root->data->song_name);
    }
    Inorder_traverse(root->right_child, output_choose);
}

void Postorder_traverse(node *root, int output_choose)
{
    if (root == NULL)
    {
        return;
    }
    if (output_choose == 1)
    {
        Postorder_traverse(root->left_child, output_choose);
        Postorder_traverse(root->right_child, output_choose);
        fprintf(outputSongFile, "%d ", root->data->index);
        fprintf(outputSongFile, "%s", root->data->song_name);
        fprintf(outputSongFile, "\n");
    }
    else if (output_choose == 2)
    {
        Postorder_traverse(root->left_child, output_choose);
        Postorder_traverse(root->right_child, output_choose);
        printf("%d %s\n", root->data->index, root->data->song_name);
    }
}

int read_SongFile()
{
    FILE *songFile;

    /* allocation of the buffer for every line in the File */
    char *buf = malloc(MAX_SONG_NAME + 10);
    char *tmp;

    /* if the space could not be allocaed, return an error */
    if (buf == NULL)
    {
        printf("No memory\n");
        return 1;
    }

    if ((songFile = fopen("songFile.csv", "r")) == NULL) // Reading a file
    {
        printf("File could not be opened.\n");
    }

    while (fgets(buf, 255, songFile) != NULL)
    {
        if ((strlen(buf) > 0) && (buf[strlen(buf) - 1] == '\n'))
            buf[strlen(buf) - 1] = '\0';

        item *song = (item *)malloc(sizeof(song));
        tmp = strtok(buf, ",");
        song->index = atoi(tmp);

        tmp = strtok(NULL, ",");
        song->song_name = (char *)malloc(sizeof(tmp));
        strcpy(song->song_name, tmp);

        build_tree(&root, song, root, 0);
    }
    fclose(songFile);
    return 0;
}

int write_SongFile(node *root)
{
    outputSongFile = fopen("output.csv", "w");
    if (root == NULL)
    {
        return 0;
    }
    Inorder_traverse(root, 1);
    fclose(outputSongFile);
    return 0;
}

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