#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myDS.h"
#include "myIO.h"
static FILE *outputSongFile;
wchar_t *read_wstring()
{
    wchar_t c;
    wchar_t buffer[MAX_SONG_NAME + 1];
    int length = 0;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (length < MAX_SONG_NAME)
        {
            buffer[length++] = c;
        }
        else
        {
            break;
        }
    }
    buffer[length] = '\0';
    // if(printf("read_wstring: -%ls-\n", buffer)<0){
    //     perror("printf");
    // }
    if (wcslen(buffer) == MAX_SONG_NAME)
    {

        buffer[length - 1] = '.';
        buffer[length - 2] = '.';
        buffer[length - 3] = '.';
    }
    return buffer;
}
// void read_line(song *data)
// {
//     wchar_t c;
//     wchar_t buf[MAX_SONG_NAME + 1];
//     scanf(" %d ", &data->index);
//     read_song_name(buf);
//     data->song_name = (wchar_t *)malloc(sizeof(buf));
//     wcsncpy(data->song_name, buf, MAX_SONG_NAME);
//     return;
// }
void Preorder_traverse(node *root, int output_choose)
{
    if (root == NULL)
    {
        return;
    }
    if (output_choose == 1)
    {
        // fprintf(outputSongFile, "%d ", root->data->index);
        fprintf(outputSongFile, "%ls", root->data->song_name);
        fprintf(outputSongFile, "\n");
    }
    else if (output_choose == 2)
    {
        // printf("%d %ls\n", root->data->index, root->data->song_name);
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
        // fprintf(outputSongFile, "%d ", root->data->index);
        fprintf(outputSongFile, "%ls", root->data->song_name);
        fprintf(outputSongFile, "\n");
    }
    else if (output_choose == 2)
    {
        Inorder_traverse(root->left_child, output_choose);
        // printf("%d %ls\n", root->data->index, root->data->song_name);
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
        // fprintf(outputSongFile, "%d ", root->data->index);
        fprintf(outputSongFile, "%ls", root->data->song_name);
        fprintf(outputSongFile, "\n");
    }
    else if (output_choose == 2)
    {
        Postorder_traverse(root->left_child, output_choose);
        Postorder_traverse(root->right_child, output_choose);
        // printf("%d %ls\n", root->data->index, root->data->song_name);
    }
}

int read_SongFile()
{
    FILE *songFile;

    /* allocation of the buffer for every line in the File */

    wchar_t *buf = malloc(MAX_SONG_NAME + 10);
    wchar_t *tmp;

    /* if the space could not be allocated, return an error */
    if (buf == NULL)
    {
        printf("No memory\n");
        return 1;
    }

    if ((songFile = fopen("songFile.csv", "r")) == NULL) // Reading a file
    {
        printf("File could not be opened.\n");
    }

    tmp = wcstok(NULL, delim, &ptr);
    song->artist = (wchar_t *)malloc(sizeof(wcslen(tmp) + 1));
    wcscpy(song->artist, tmp);

    tmp = wcstok(NULL, delim, &ptr);
    song->length = (wchar_t *)malloc(sizeof(wcslen(tmp) + 1));
    wcscpy(song->length, tmp);
    int error = 0;
    build_tree(&root, song, root, &error);

    fclose(songFile);
    return;
}

void write_SongFile(node *root)
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

void output_song(song *cur_songlist)
{
    // output all song name,artist,time in cur_songlist
    /*
        Maybe :
        Inorder_traverse(cur_songlist,2);
        I guess...
    */
}
void output_songlist(node *songlist_tree)
{
    // output all songlist name in songlist_tree
}
void Export_songlist(song *cur_songlist)
{
    // Export cur_songlist's song as .csv file.
}
void Import_songlist(node *songlist_tree, wchar_t songlist_name[])
{
    /*
        Import a .csv file which file name is {songlist_name}.csv, as a songlist.
        if there's not , print "Missing File : {songlist_name}\n".
    */
}