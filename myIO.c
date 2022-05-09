#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myDS.h"
#include "myIO.h"
static FILE *outputSongFile;
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
        Inorder_traverse(root->right_child, output_choose);
    }
    else if (output_choose == 2)
    {
        Inorder_traverse(root->left_child, output_choose);
        printf("%d %s\n", root->data->index, root->data->song_name);
        Inorder_traverse(root->right_child, output_choose);
    }
}

int read_SongFile()
{
    FILE *songFile;

    /* allocation of the buffer for every line in the File */
    char *buf = malloc(MAX_SONG_NAME);
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
        strcpy(song->song_name, tmp);

        build_tree(&root, song);
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