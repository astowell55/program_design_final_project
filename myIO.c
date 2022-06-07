#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myDS.h"
#include "myIO.h"
static FILE *outputSongFile;
void read_wstring(wchar_t buffer[MAX_SONG_NAME + 1])
{
    wchar_t c;
    int length = 0;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (length < MAX_SONG_NAME)
        {
            buffer[length++] = c;
        }else{
            break;
        }
    }
    buffer[length] = '\0';
    if (wcslen(buffer) == MAX_SONG_NAME)
    {

        buffer[length - 1] = '.';
        buffer[length - 2] = '.';
        buffer[length - 3] = '.';
    }
    return;
}
void read_line(item *data)
{
    wchar_t c;
    wchar_t buf[MAX_SONG_NAME + 1];
    scanf(" %d ", &data->index);
    read_song_name(buf);
    data->song_name = (wchar_t *)malloc(sizeof(buf));
    wcsncpy(data->song_name, buf, MAX_SONG_NAME);
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
        fprintf(outputSongFile, "%ls", root->data->song_name);
        fprintf(outputSongFile, "\n");
    }
    else if (output_choose == 2)
    {
        printf("%d %ls\n", root->data->index, root->data->song_name);
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
        fprintf(outputSongFile, "%ls", root->data->song_name);
        fprintf(outputSongFile, "\n");
    }
    else if (output_choose == 2)
    {
        Inorder_traverse(root->left_child, output_choose);
        printf("%d %ls\n", root->data->index, root->data->song_name);
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
        fprintf(outputSongFile, "%ls", root->data->song_name);
        fprintf(outputSongFile, "\n");
    }
    else if (output_choose == 2)
    {
        Postorder_traverse(root->left_child, output_choose);
        Postorder_traverse(root->right_child, output_choose);
        printf("%d %ls\n", root->data->index, root->data->song_name);
    }
}

// int read_SongFile()
// {
//     FILE *songFile;

//     /* allocation of the buffer for every line in the File */

//     wchar_t *buf = malloc(MAX_SONG_NAME + 10);
//     wchar_t *tmp;

//     /* if the space could not be allocaed, return an error */
//     if (buf == NULL)
//     {
//         printf("No memory\n");
//         return 1;
//     }

//     if ((songFile = fopen("songFile.csv", "r")) == NULL) // Reading a file
//     {
//         printf("File could not be opened.\n");
//     }

//     while (fgets(buf, 255, songFile) != NULL)
//     {
//         if ((wcslen(buf) > 0) && (buf[wcslen(buf) - 1] == '\n'))
//             buf[wcslen(buf) - 1] = '\0';

//         item *song = (item *)malloc(sizeof(song));
//         tmp = wcstok(buf, ",");
//         song->index = atoi(tmp);

//         tmp = strtok(NULL, ",");
//         if (strlen(tmp) >= MAX_SONG_NAME)
//         {
//             tmp[MAX_SONG_NAME] = '\0';
//             tmp[MAX_SONG_NAME - 1] = '.';
//             tmp[MAX_SONG_NAME - 2] = '.';
//             tmp[MAX_SONG_NAME - 3] = '.';
//         }
//         song->song_name = (wchar_t *)malloc(sizeof(strlen(tmp) + 1));
//         strcpy(song->song_name, tmp);
//         int error = 0;
//         build_tree(&root, song, root, &error);
//     }
//     fclose(songFile);
//     return 0;
// }

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

void output_song(node *cur_songlist){
    // output all song name,artist,time in cur_songlist
    /*
        Maybe :
        Inorder_traverse(cur_songlist,2);
        I guess...
    */
}
void output_songlist(node *songlist_tree){
    // output all songlist name in songlist_tree
}