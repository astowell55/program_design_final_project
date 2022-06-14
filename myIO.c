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
    wchar_t *result = malloc(length * sizeof(wchar_t));
    wcscpy(result, buffer);
    return result;
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

void Inorder_traverse_song(song *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        Inorder_traverse_song(root->left_child);
        fprintf(outputSongFile, "%ls", root->song_name);
        fprintf(outputSongFile, "\n");
    }
    Inorder_traverse_song(root->right_child);
}

void read_SongFile()
{
    FILE *songFile;

    /* allocation of the buffer for every line in the File */
    char *FileName;
    scanf("%s", FileName);
    wchar_t *buf = malloc(MAX_SONG_NAME + 10);

    /* if the space could not be allocated, return an error */
    if (buf == NULL)
    {
        printf("No memory\n");
        return;
    }

    if ((songFile = fopen(FileName, "r")) == NULL) // Reading a file
    {
        printf("File could not be opened.\n");
    }

    while (fgetws(buf, 255, songFile) != NULL)
    {
        if ((wcslen(buf) > 0) && (buf[wcslen(buf) - 1] == '\n'))
            buf[wcslen(buf) - 1] = '\0';
        song *songs = malloc(sizeof(song));
        wchar_t *ptr;

        // Define the delimeter of the string
        wchar_t delim[] = L",";

        // Call the wcstok() method
        wchar_t *tmp = wcstok(buf, delim, &ptr);
        songs->song_name = (wchar_t *)malloc(sizeof(wcslen(tmp) + 1));
        wcscpy(songs->song_name, tmp);

        tmp = wcstok(NULL, delim, &ptr);
        songs->artist = (wchar_t *)malloc(sizeof(wcslen(tmp) + 1));
        wcscpy(songs->artist, tmp);

        tmp = wcstok(NULL, delim, &ptr);
        for (int i = 0; i < wcslen(tmp); i++)
        {
            if (tmp[i] == ':')
            {
                tmp[i] = '.';
                break;
            }
        }
        wchar_t *stop;
        float time = wcstof(tmp, &stop);
        songs->length = time;
        build_song_data(&song_data, songs);
    }
    fclose(songFile);
    return;
}

void write_SongFile(node *root)
{
    outputSongFile = fopen("output.csv", "w");
    if (root == NULL)
    {
        return;
    }
    Inorder_traverse(root, 1);
    fclose(outputSongFile);
    return;
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
    char *filename;
    wcstombs(filename, songlist_tree->songlist_name, 101);
    outputSongFile = fopen(filename, "w");
    if (root == NULL)
    {
        return;
    }
    Inorder_traverse(root, 1);
    fclose(outputSongFile);
    return;
}
void Export_songlist(node *cur_songlist)
{
    // Export cur_songlist's song as .csv file.
    char *filename;
    wcstombs(filename, cur_songlist->songlist_name, 101);
    outputSongFile = fopen(filename, "w");
    if (root == NULL)
    {
        return;
    }
    Inorder_traverse(root, 1);
    fclose(outputSongFile);
    return;
}
void Import_songlist(node *songlist_tree, wchar_t songlist_name[])
{
    /*
        Import a .csv file which file name is {songlist_name}.csv, as a songlist.
        if there's not , print "Missing File : {songlist_name}\n".
    */
}