#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include "myDS.h"
#include "myIO.h"
#include "myAlgo.h"
#include "tree.h"
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

    if (strlen(buffer) == MAX_SONG_NAME)
    {

        buffer[length - 1] = '.';
        buffer[length - 2] = '.';
        buffer[length - 3] = '.';
    }
    char *result = malloc(length * sizeof(char));
    //printf("%p\n", result);
    strcpy(result, buffer);
    return result;
}

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

void Inorder_traverse(song *root)
{
    if (root == NULL)
    {
        return;
    }
    Inorder_traverse(root->left_child);
    fprintf(outputSongFile, "%s,", root->song_name);
    fprintf(outputSongFile, "%s,", root->artist);
    fprintf(outputSongFile, "%.2f,", root->length);
    fprintf(outputSongFile,"%d/%d/%d %d:%d",root->times.year,root->times.month,root->times.day,root->times.hour,root->times.minute);
    fprintf(outputSongFile, "\n");
    Inorder_traverse(root->right_child);
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

void read_SongFile(song **song_data)
{
    FILE *songFile;

    /* allocation of the buffer for every line in the File */
    char buf[300];
    /* if the space could not be allocated, return an error */
    if ((songFile = fopen("songFile.csv", "r")) == NULL) // Reading a filemnnnnn
    {
        printf("File could not be opened.\n");
    }

    while (fgets(buf, 255, songFile) != NULL)
    {
        // printf("buf:%s",buf);
        if ((strlen(buf) > 0) && (buf[strlen(buf) - 1] == '\n'))
            buf[strlen(buf) - 1] = '\0';
        song *songs = malloc(sizeof(song));
        upload_time(&(songs->times));
        //print_systimes(songs->times);
        // Define the delimeter of the string
        char delim[] = ",";

        // Call the wcstok() method
        char *tmp = strtok(buf, delim);
        songs->song_name = (char *)malloc(sizeof(char) * (strlen(tmp) + 1));
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

        float time = atof(tmp);
        songs->length = time;

        songs->left_child = NULL;
        songs->right_child = NULL;
        songs->parent = NULL;

        build_song_data(song_data, songs);
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
    if (cur_songlist == NULL)
    {
        return;
    }
    output_song(cur_songlist->left_child);
    printf("%s\n", cur_songlist->song_name);
    //print_systimes(cur_songlist->times);
    output_song(cur_songlist->right_child);
}

void output_songlist(node *songlist_tree)
{
    // output all songlist name in songlist_tree
    // char *filename;
    // wcstombs(filename, songlist_tree->songlist_name, 101);
    // outputSongFile = fopen(filename, "w");
    if (songlist_tree == NULL)
    {
        return;
    }
    output_songlist(songlist_tree->left_child);
    printf("%s\n", songlist_tree->songlist_name);
    output_songlist(songlist_tree->right_child);
}

void Export_songlist(song *cur_songlist, char *Filename)
{
    // Export cur_songlist's song as .csv file.
    char filename[MAX_SONG_NAME+1];
    strcpy(filename,Filename);
    strcat(filename, ".csv");
    //printf("filenames:'%s'\n",filename);
    
    outputSongFile = fopen(filename, "w");
    if (cur_songlist == NULL)
    {
        return;
    }
    //fprintf(outputSongFile,"Title,Artist,Song,length(min),last Edited time\n");
    Inorder_traverse(cur_songlist);
    fclose(outputSongFile);
    return;
}

void Import_songlist(node **songlist_tree, char songlist_name[])
{
    /*
        Import a .csv file which file name is {songlist_name}.csv, as a songlist.
        if there's not , print "Missing File : {songlist_name}\n".
    */
    FILE *songFile;
    char filename[MAX_SONG_NAME+1];
    strcpy(filename,songlist_name);
    strcat(filename, ".csv");
    //printf("%s\n",filename);
    /* if the space could not be allocated, return an error */
    if ((songFile = fopen(filename, "r")) == NULL) // Reading a file
    {
        printf("Missing File : {%s}\n", songlist_name);
        return;
    }
    char buf[300];
    build_songlist(songlist_tree, songlist_name);
    //printf("haha\n");
    while (fgets(buf, 255, songFile) != NULL)
    {
        //printf("buf:'%s'\n",buf);
        if ((strlen(buf) > 0) && (buf[strlen(buf) - 1] == '\n'))
            buf[strlen(buf) - 1] = '\0';
        song *songs = malloc(sizeof(song));
        // Define the delimeter of the string
        char delim[5] = ",/:";
        //printf("buf2:'%s'\n",buf);
        //printf("songs:'%p'\n",songs);
        // Call the wcstok() method
        char *tmp = strtok(buf, delim);
        //song name
        songs->song_name = (char *)malloc(sizeof(char) * (strlen(tmp) + 1));
        strcpy(songs->song_name, tmp);
        //printf("tmp1:'%s'\n",tmp);
        //artist
        tmp = strtok(NULL, delim);
        songs->artist = (char *)malloc(sizeof(char) * (strlen(tmp) + 1));
        strcpy(songs->artist, tmp);
        //printf("tmp2:'%s'\n",tmp);
        //length
        tmp = strtok(NULL, delim);
        float time = atof(tmp);
        songs->length = time;
        //time
        strcat(delim," ");
        tmp = strtok(NULL, delim);
        int year = atoi(tmp);
        songs->times.year=year;
        
        tmp = strtok(NULL, delim);
        int month = atoi(tmp);
        songs->times.month = month;

        tmp = strtok(NULL, delim);
        int day = atoi(tmp);
        songs->times.day =day;

        tmp = strtok(NULL, delim);
        int hour = atoi(tmp);
        songs->times.hour =hour;

        tmp = strtok(NULL, delim);
        int minute = atoi(tmp);
        songs->times.minute =minute;

        songs->left_child = NULL;
        songs->right_child = NULL;
        songs->parent = NULL;
        //printf("hehe\n");
        build_song_data((&(*songlist_tree)->data),songs);
        //printf("howow\n");
    }
    fclose(songFile);
    printf("'%s.csv' has successfully imported.\n",songlist_name);
    return;

}
void print_systimes(systime upload_time){
    printf("%02d/%02d/%d ", upload_time.day, upload_time.month, upload_time.year);
    // 打印當地時間
    if (upload_time.hour < 12) {    // 中午之前
        printf("%02d:%02d:%02d am\n", upload_time.hour, upload_time.minute,upload_time.second);
    }
    else {    // 中午之後
        printf("%02d:%02d:%02d pm\n", upload_time.hour - 12, upload_time.minute,upload_time.second);
    }
 
    //打印當前日期
    
}