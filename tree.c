#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>
#include "myDS.h"
#include "myIO.h"
#include "myAlgo.h"
#include "myUI.h"
#include "myUI.h"
#include "tree.h"
song *song_data=NULL;

void Choose_a_songlist(song **cur_songlist,char *songlist_name)
{
    /*
        In a songlist,it is the UI.
    */
    // Operate
    // wchar_t *song_name;
    song *target_song = NULL;
   
    char *song_options[6] = {"[a]Add a song","[d]Delete a song","[o]Output all the songs in the list","[e]Export as .csv","[s]Search a song","[<]Back to main page"};
    int operater = 0;
    char song_name[300];
    while (operater != 5)
    {
        operater = button(6,song_options);
       
        switch (operater){ 
        case 0:
            // Add song.
            printf("Enter the title of the song you want to add: ");
            // Inorder_traverse_song((*cur_songlist));
            // song_name = read_wstring();
            fgets(song_name, 300, stdin);
            song_name[strlen(song_name) - 1] = '\0';

            //printf("-.%s.-\n",song_name);
            //printf("read: _%s_\n", song_name);
            target_song = search_song(*cur_songlist, song_name);

            if (target_song == NULL)
            {
                build_song(cur_songlist, song_name);
                printf("build finish\n");
                //output_song(*cur_songlist);
            }
            else
            {
                printf("Invalid operation : SONG EXIST\n");
            }
            // free(song_name);
            // printf("_%s_\n", (*cur_songlist)->song_name);
            // output_song((*cur_songlist));
            break;
        case 1:
            output_song((*cur_songlist));
            // Delete song.
            printf("Enter the title of the song you want to delete: ");
            // song_name = read_wstring();
            fgets(song_name, 300, stdin);
            song_name[strlen(song_name) - 1] = '\0';
            target_song = search_song(*cur_songlist, song_name);
            if (target_song != NULL)
            {
                delete_song(cur_songlist, song_name);
                printf("Delete song : %s\n", song_name);
            }
            else
            {
                printf("Invalid operation : SONG DOESN'T EXIST\n");
            }

            break;
        case 2:
            // Output all song in this list.
            if ((*cur_songlist) != NULL)
            {
                printf("All of your song(s):\n");
                output_song((*cur_songlist));
                break;
            }
            else
            {
                printf("There's no song!\n");
                break;
            }
        case 3:
            // Export this songlist as .csv
            Export_songlist(*cur_songlist, songlist_name);
            printf("The file created as '%s.csv'\n",songlist_name);
            break;
        case 4:
            printf("Enter the title of the song you want to find: ");
            fgets(song_name, 300, stdin);
            song_name[strlen(song_name) - 1] = '\0';
            target_song = search_song(*cur_songlist,song_name); // Back
            if(target_song == NULL){
                printf("Song %s not found\n",song_name);
            }else{
                printf("Do you want to like this song ?");
                char *like_options[2] = {"❤","X"};
                int choose = button(2,like_options);
                switch(choose){
                    case 0: 
                        target_song ->like = 1;
                        break;
                    case 1: 
                        target_song ->like = 0;
                        break;
                }
            }
            break;
        case 5:
            return;
            break;
        default:
            printf("Invalid operater\n");
            break;
        }
    }
}

int main()
{
    int data_num, input_Choose, output_Choose, search_Choose;

    int error = 0;

    // setlocale(LC_ALL,"");
    //- Preload songdata
    printf("Preloading song data...\n");
    read_SongFile(&song_data);
    printf("Preload done.\n");
    //printf("song_data:%p\n", song_data);
    // output_song(song_data);
    //- Preload songdata end

    node *songlist_tree = NULL;   // the root of songlist tree.
    node *target_songlist = NULL; // point to the songlist.
    // select oprerater
    // printf("[a]Add a songlist\n[d]Delete a songlist\n"
    //"[c]Choose a songlist\n[o]Output all songlists\n[i]import a .csv songlist\n[e]Exit\nEnter your operater:\n");
    char *songlist_options[6] = {"[a]Add a playlist", "[d]Delete a playlist", "[c]Choose a playlist", "[o]Output all playlists", "[i]Import a .csv playlist", "[e]Exit"};
    int operater = 0;
    char *songlist_name;
    while (operater != 5)
    {

        operater = button(6, songlist_options);
        // Operate
        switch (operater)
        {
        case 0:
            // Build or Add songlist into tree.
            printf("Enter the new playlist name: ");
            // scanf("%s",songlist_name);
            songlist_name = read_wstring();
            // printf("name:_%s_\n", songlist_name);
            //  find
            target_songlist = search_songlist(songlist_tree, songlist_name);
            // printf("point:_%p_\n", target_songlist);
            if (target_songlist == (node *)NULL)
            {
                build_songlist(&songlist_tree, songlist_name);
                printf("Add playlist: %s\n", songlist_name);
            }
            else
            {
                printf("Invalid operation: THE NAME HAS BEEN USED\n");
            }
            free(songlist_name);
            break;
        case 1:
            output_songlist(songlist_tree);
            // Delete target songlist.
            printf("Enter the playlist name you want to delete: ");
            songlist_name = read_wstring();
            // find
            target_songlist = search_songlist(songlist_tree, songlist_name);
            if (target_songlist != NULL)
            {
                delete_songlist(&target_songlist, songlist_name);
                printf("Delete playlist: %s\n", songlist_name);

                break;
            }
            else
            {
                printf("Invalid operation: PLAYLIST DOESN'T EXIST\n");
            }
            free(songlist_name);
            break;
        case 2:
            output_songlist(songlist_tree);
            // Enter the target songlist, going to another UI.
            printf("Enter a playlist name : ");
            // printf("read\n");
            songlist_name = read_wstring();
            //printf("name:_%s_\n", songlist_name);
            // find
            target_songlist = search_songlist(songlist_tree, songlist_name);
            //printf("point:_%p_\n", target_songlist);
            if (target_songlist != NULL)
            {
                Choose_a_songlist(&(target_songlist->data), (target_songlist->songlist_name));
                break;
            }
            else
            {
                printf("Invalid operation: PLAYLIST DOESN'T EXIST\n");
            }
            free(songlist_name);
            break;
        case 3:
            // Output all songlist name.
            if (songlist_tree == NULL)
            {
                printf("There is not any playlist\n");
                break;
            }
            else
            {
                printf("All of your playlist(s):\n");
                output_songlist(songlist_tree);
            }
            break;
        case 4:
            // Import a songlist.
            printf("Enter a playlist file you want to import: ");
            songlist_name = read_wstring();
            target_songlist = search_songlist(songlist_tree, songlist_name);
            if(target_songlist==NULL){
                Import_songlist(&songlist_tree, songlist_name);
            }else{
                printf("Invalid operation: THE NAME HAS BEEN USED\n");
            }
            
            
            free(songlist_name);
            break;
        case 5:
            return 0;
        default:
            printf("Invalid operater\n");
            break;
        }
    }
    return 0;
}