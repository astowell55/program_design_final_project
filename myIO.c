#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

    int i = 0;
    while (fgets(buf, 255, songFile) != NULL)
    {
        if ((strlen(buf) > 0) && (buf[strlen(buf) - 1] == '\n'))
            buf[strlen(buf) - 1] = '\0';

        tmp = strtok(buf, ",");
        song[i].index = atoi(tmp);

        tmp = strtok(NULL, ",");
        strcpy(song[i].song_name, tmp);

        // song.index = atoi(buf);
        printf("index i= %d  ID: %i, %s\n", i, song[i].index, song[i].song_name);
        i++;
    }
    fclose(songFile);
    return 0;
}

int write_SongFile()
{
    FILE *songFile;
    songFile = fopen("output.csv", "w");
    
    for (int i = 0; i < 100  ; i++)
    {
        fprintf(songFile, "%d,", song[i].index);
        fprintf(songFile, "%s", song[i].song_name);
        fprintf(songFile, "\n"); 
    }
    fclose(songFile);
    return 0;
}