#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include "myDS.h"
#include "myIO.h"
static FILE *outputSongFile;
char *read_wstring()
{
    char c;
    char buffer[MAX_SONG_NAME + 1];
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
    if (strlen(buffer) == MAX_SONG_NAME)
    {

        buffer[length - 1] = '.';
        buffer[length - 2] = '.';
        buffer[length - 3] = '.';
    }
    char *result = malloc(length * sizeof(char));
    printf("%p\n",result);
    strcpy(result, buffer);                                  
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
        fprintf(outputSongFile, "%s", root->data->song_name);
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
    Inorder_traverse(root->left_child, output_choose);
    if (output_choose == 1)
    {
        
        // fprintf(outputSongFile, "%d ", root->data->index);
        fprintf(outputSongFile, "%s", root->data->song_name);
        fprintf(outputSongFile, "\n");
    }
    else if (output_choose == 2)
    {
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
    Postorder_traverse(root->left_child, output_choose);
    Postorder_traverse(root->right_child, output_choose);
    if (output_choose == 1)
    {
        // fprintf(outputSongFile, "%d ", root->data->index);
        fprintf(outputSongFile, "%s", root->data->song_name);
        fprintf(outputSongFile, "\n");
    }
    else if (output_choose == 2)
    {

        // printf("%d %ls\n", root->data->index, root->data->song_name);
    }
}

void read_SongFile()
{
    FILE *songFile;

    /* allocation of the buffer for every line in the File */
    char buf[300];
    /* if the space could not be allocated, return an error */
    if ((songFile = fopen("songFile.csv", "r")) == NULL) // Reading a filemnnnnn
    {
        printf("File could not be opened.\n");
    }
    
    while (fgets(buf, 255, songFile) != NULL){
        printf("%s",buf);
        if ((strlen(buf) > 0) && (buf[strlen(buf) - 1] == '\n'))
            buf[strlen(buf) - 1] = '\0';
        song *songs = malloc(sizeof(song));
        // Define the delimeter of the string
        char delim[] = ",";

        // Call the wcstok() method
        char *tmp = strtok(buf, delim);
        songs->song_name = (char*)malloc(sizeof(char) * (strlen(tmp) + 1));
        strcpy(songs->song_name, tmp);
        tmp = strtok(NULL, delim);
        songs->artist = (char *)malloc(sizeof(char) * (strlen(tmp) + 1));
        strcpy(songs->artist, tmp);
        tmp = strtok(NULL, delim);
        for (int i = 0; i < strlen(tmp); i++)
        {
            if (tmp[i] == ':')
            {
                tmp[i] = '.';
                break;
            }
        }
        char *stop;
        float time = atof(stop);
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
    if (root == NULL){   
        return;
    }
    output_song(cur_songlist->left_child);
    printf("%s\n", cur_songlist->song_name);
    output_song(cur_songlist->right_child);

}
void output_songlist(node *songlist_tree)
{
    // output all songlist name in songlist_tree
    char *filename;
    //wcstombs(filename, songlist_tree->songlist_name, 101);
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
    //wcstombs(filename, cur_songlist->songlist_name, 101);
    outputSongFile = fopen(filename, "w");
    if (root == NULL)
    {
        return;
    }
    Inorder_traverse(root, 1);
    fclose(outputSongFile);
    return;
}
void Import_songlist(node *songlist_tree, char songlist_name[])
{
    /*
        Import a .csv file which file name is {songlist_name}.csv, as a songlist.
        if there's not , print "Missing File : {songlist_name}\n".
    */
}