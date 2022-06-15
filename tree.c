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
void Choose_a_songlist(song **cur_songlist,char *songlist_name)
{
    /*
        In a songlist,it is the UI.
    */
    // Operate
    //wchar_t *song_name;
    song *target_song = NULL;
   
    char *song_options[7] = {"[a]Add a song","[d]Delete a song","[o]Output all songlists","[e]Export as .csv","[<]Back to main page"};
    int operater = 0;
    char song_name[300];
    while (operater != 6)
    {
        operater = button(7,song_options);
        getchar();
        switch (operater){
        case 0:
            // Add song.
            printf("Enter the title of the song you want to add: ");
            //Inorder_traverse_song((*cur_songlist));
            //song_name = read_wstring();
            fgets(song_name,300,stdin);
            song_name[strlen(song_name)-1] = '\0';

            //printf("-.%s.-\n",song_name);
            //printf("read: _%s_\n", song_name);
            target_song = search_song(*cur_songlist, song_name);

            if (target_song == NULL)
            {   
                printf("Add song : %s\n", song_name);
                build_song(cur_songlist, song_name);
                
                //printf("build finish\n");
                output_song(*cur_songlist);
            }
            else
            {
                printf("Invalid operation\n");
            }
            //free(song_name);
            //printf("_%s_\n", (*cur_songlist)->song_name);
            //output_song((*cur_songlist));
            break;
        case 1:
            // Delete song.
            printf("Enter the title of the song you want to delete: ");
            //song_name = read_wstring();
            fgets(song_name,300,stdin);
            song_name[strlen(song_name)-1] = '\0';
            target_song = search_song(*cur_songlist, song_name);
            if (target_song != NULL)
            {
                delete_song(cur_songlist, song_name);
                printf("Delete song : %s\n", song_name);
            }
            else
            {
                printf("Invalid operation\n");
            }
            
            break;
        case 2:
            // Output all song in this list.
            printf("All of your song(s):\n");
            output_song((*cur_songlist));
            break;
        case 3:
            // Export this songlist as .csv
            Export_songlist(*cur_songlist,songlist_name);
            printf("The file is created\n");
            break;
        case 6:
            return; // Back
            break;
        default:
            printf("Invalid operation\n");
            break;
        }

    }
}

int main(){
    int data_num, input_Choose, output_Choose, search_Choose;

    int error = 0;
    
    // setlocale(LC_ALL,"");
    //- Preload songdata
    song *song_data=NULL;
    read_SongFile(&song_data);
    printf("song_data:%p\n",song_data);    
    //output_song(song_data);
    //- Preload songdata end

    node *songlist_tree = NULL;   // the root of songlist tree.
    node *target_songlist = NULL; // point to the songlist.
    // select oprerater
    //printf("[a]Add a songlist\n[d]Delete a songlist\n"
           //"[c]Choose a songlist\n[o]Output all songlists\n[i]import a .csv songlist\n[e]Exit\nEnter your operater:\n");
    char *songlist_options[6] ={"[a]Add a playlist","[d]Delete a playlist","[c]Choose a playlist","[o]Output all playlists","[i]Import a .csv playlist","[e]Exit"}; 
    int operater = 0;
    char *songlist_name;
    while ( operater != 5){
        
        operater = button(6,songlist_options);
        // Operate
        switch (operater)
        {
        case 0:
            // Build or Add songlist into tree.
            printf("Enter the new playlist name: ");
            // scanf("%s",songlist_name);
            songlist_name = read_wstring();
            //printf("name:_%s_\n", songlist_name);
            // find
            target_songlist = search_songlist(songlist_tree, songlist_name);
            //printf("point:_%p_\n", target_songlist);
            if (target_songlist == (node *)NULL)
            {
                build_songlist(&songlist_tree, songlist_name);
                printf("Add songlist: %s\n", songlist_name); 
            }
            else
            {
                printf("Invalid operation: THE NAME HAS BEEN USED\n");
            }
            free(songlist_name);
            break;
        case 1:
            // Delete target songlist.
            printf("Enter the playlist name you want to delete: ");
            songlist_name = read_wstring();
            // find
            target_songlist = search_songlist(songlist_tree, songlist_name);
            if(target_songlist != NULL)
            {
                delete_songlist(&target_songlist, songlist_name);
                printf("Delete playlist: %s\n", songlist_name);
                
                break;
            }
            else
            {
                printf("There is not any playlist\n");
            }
            free(songlist_name);
            break;
        case 2:
            // Enter the target songlist, going to another UI.
            // printf("read\n");
            songlist_name = read_wstring();
            printf("name:_%s_\n", songlist_name);
            // find
            target_songlist = search_songlist(songlist_tree, songlist_name);
            printf("point:_%p_\n", target_songlist);
            if (target_songlist != NULL)
            {
                Choose_a_songlist(&(target_songlist->data),(target_songlist->songlist_name));
                break;

            }
            else
            {
                printf("There is not any playlist\n");
            }
            free(songlist_name);
            break;
        case 3:
            // Output all songlist name.
            output_songlist(songlist_tree);
            break;
        case 4:
            // Import a songlist.
            songlist_name = read_wstring();
            Import_songlist(songlist_tree, songlist_name);
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