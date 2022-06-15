#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <time.h>
#include "myDS.h"
#include "myIO.h"

node *search(node *root, song *target, int search_Choose)
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
     return curr;
}
node *search_songlist(node *songlist_tree, char songlist_name[])
{
    /*
        search songlist_name in songlist_tree.
        if found, return the pointer of songlist_name.
        if not, return NULL.
    */
    node *curr = songlist_tree;
    //printf("while: _%p_\n",curr);
    while (curr != NULL && strcmp(songlist_name, curr->songlist_name) != 0)
    {
        // printf("while: _%p_\n",curr);
        if (strcmp(songlist_name, curr->songlist_name) > 0)
        {
            curr = curr->right_child;
        }
        else
        {
            curr = curr->left_child;
        }
    }
    return curr;
}
song *search_song(song *cur_songlist, char song_name[])
{
    /*
        search song_name in cur_songlist.
        if found, return the pointer of the song.
        if not, return NULL.
    */
    song *curr = cur_songlist;
    //printf("before_while: p_%p_ s_%s_\n",curr,song_name);
    while (curr != NULL && strcmp(song_name, curr->song_name) != 0){
        //printf("while: _%p_\n",curr);
        //printf("s_%s\n",curr->song_name);
        if (strcmp(song_name, curr->song_name) > 0){
            curr = curr->right_child;
        }
        else
        {
            curr = curr->left_child;
        }
    }
    return curr;
}
void upload_time(systime *upload_times){
    
    int hours, minutes, seconds, day, month, year;
 
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    upload_times->hour = local->tm_hour;         
    upload_times->minute = local->tm_min; 
    upload_times->second = local->tm_sec;       
    upload_times->day = local->tm_mday;            
    upload_times->month = local->tm_mon + 1;      
    upload_times->year = local->tm_year + 1900;   
    upload_times->day = local->tm_mday;
    // // 打印當地時間
    // if (hours < 12) {    // 中午之前
    //     printf("Time is %02d:%02d am\n", hours, minutes);
    // }
    // else {    // 中午之後
    //     printf("Time is %02d:%02d pm\n", hours - 12, minutes);
    // }
 
    // //打印當前日期
    // printf("Date is: %02d/%02d/%d\n", day, month, year);
}
