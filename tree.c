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
void Choose_a_songlist(song **cur_songlist)
{
    /*
        In a songlist,it is the UI.
    */
    // Operate
    //wchar_t *song_name;
    song *target_song = NULL;
   
    char *song_options[7] = {"[a]Add a song","[d]Delete a song","[o]Output all songlists","[e]Export as .csv","[s]Sort","[r]Random","[<]Back to main page"};
    int operater = 0;
    char song_name[300];
    while (operater != 6)
    {
        operater = button(7,song_options);
       
        switch (operater){
        case 0:
            // Add song.
            //Inorder_traverse_song((*cur_songlist));
            //song_name = read_wstring();
            
            fgets(song_name,300,stdin);
            song_name[strlen(song_name)-1] = '\0';
            printf("-.%s.-\n",song_name);
            //printf("read: _%s_\n", song_name);
            target_song = search_song(*cur_songlist, song_name);
            
            if (target_song == NULL)
            {   
                printf("Add song : %s\n", song_name);
                build_song(cur_songlist, song_name);
                printf("build finish\n");
            }
            else
            {
                printf("Invalid operation\n");
            }
            printf("_%s_\n", (*cur_songlist)->song_name);
            //output_song((*cur_songlist));
            break;
        case 1:
            // Delete song.
            //song_name = read_wstring();
            fgets(song_name,300,stdin);
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
            output_song((*cur_songlist));
            break;
        case 3:
            // Export this songlist as .csv
            //Export_songlist(*cur_songlist);
            break;
        // case 's':
        //     //Sort and output all song(?)
        //     break;
        // case 'r':
        //     //Random all song(?)
        //     break;
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
    output_song(song_data);
    //- Preload songdata end

    node *songlist_tree = NULL;   // the root of songlist tree.
    node *target_songlist = NULL; // point to the songlist.
    // select oprerater
    //printf("[a]Add a songlist\n[d]Delete a songlist\n"
           //"[c]Choose a songlist\n[o]Output all songlists\n[i]import a .csv songlist\n[e]Exit\nEnter your operater:\n");
    char *songlist_options[6] ={"[a]Add a songlist","[d]Delete a songlist","[c]Choose a songlist","[o]Output all songlists","[i]import a .csv songlist","[e]Exit"}; 
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
            //fgets(songlist_name,300,stdin);
            printf("name:_%s_\n", songlist_name);
            // find
            target_songlist = search_songlist(songlist_tree, songlist_name);
            printf("point:_%p_\n", target_songlist);
            if (target_songlist == (node *)NULL)
            {
                build_songlist(&songlist_tree, songlist_name);
                printf("Add songlist : %s\n", songlist_name); 
            }
            else
            {
                printf("Invalid operation: THE NAME HAS BEEN USED\n");
            }
            free(songlist_name);
            break;
        case 1:
            // Delete target songlist.
            songlist_name = read_wstring();
            // find
            target_songlist = search_songlist(songlist_tree, songlist_name);
            if(target_songlist == NULL)
            {
                printf("There is not any playlist\n");
                break;
            }
            else
            {
                output_songlist(songlist_tree);
                printf("Enter the playlist you want to delete: ");
                //  Delete target songlist.
                songlist_name = read_wstring();
                // find
                target_songlist = search_songlist(songlist_tree, songlist_name);

                if (target_songlist != NULL)
                {
                    delete_songlist(&target_songlist, songlist_name);
                    printf("Delete playlist: %s\n", songlist_name);
                }
                else
                {
                    printf("Invalid operation: THE PLAYLIST DOES NOT EXIST\n");
                }
                free(songlist_name);
                break;
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
                Choose_a_songlist(&(target_songlist->data));
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
    /* -----OLD DATA------
    scanf("%d", &input_Choose);
    if (input_Choose == 1)
    {
        // read_SongFile();
    }
    else if (input_Choose == 2)
    {
        scanf(" %d", &data_num);
        while (data_num--)
        {

            song *temp = (song *)malloc(sizeof(temp));
            read_line(temp);
            build_tree(&root, temp, root, &error);
            if (error)
                data_num++;
            error = 0;
        }
    }
    else
    {
        return 0;
    }

    printf("[1] Output the data in csv file. [2] Output the data on terminal. [3] Search by song name. [4] Delete a node by name:");
    scanf("%d", &output_Choose);
    if (output_Choose == 1)
    {
        // write_SongFile(root);
    }
    else if (output_Choose == 2)
    {
        printf("[1] Preorder traverse [2] Inorder traverse [3] Preorder_traverse :");
        int choose;
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            printf("Preorder traverse :\n");
            Preorder_traverse(root, output_Choose);
            break;

        case 2:
            printf("Inorder traverse :\n");
            Inorder_traverse(root, output_Choose);
            break;

        case 3:
            printf("Postorder traverse :\n");
            Postorder_traverse(root, output_Choose);
            break;
        }
    }
    else if (output_Choose == 3)
    {
        printf("[1] Search by artist [2] Search by title :");
        scanf("%d", &search_Choose);
        if (search_Choose == 1)
        {
            getchar();
            printf("Enter the artist:");
            wchar_t buf[MAX_SONG_NAME + 1];
            read_song_name(buf);
            song *target = (song *)malloc(sizeof(target));
            target->artist = (wchar_t *)malloc(sizeof(buf));
            wcsncpy(target->artist, buf, MAX_SONG_NAME);

            node *result = (node *)malloc(sizeof(result));
            result = search(root, target, 1);

            if (result != NULL)
            {
                printf("%s %s\n", result->data->song_name, result->data->artist);
            }
            else
            {
                printf("No result\n");
            }
            free(target);
            free(result);
        }
        else if (search_Choose == 2)
        {
            getchar();
            printf("Enter the title:");
            wchar_t buf[MAX_SONG_NAME + 1];
            read_song_name(buf);
            song *target = (song *)malloc(sizeof(target));
            target->song_name = (wchar_t *)malloc(sizeof(buf));
            wcsncpy(target->song_name, buf, MAX_SONG_NAME);

            node *result = (node *)malloc(sizeof(result));
            result = search(root, target, 2);

            if (result != NULL)
            {
                printf("%s %s\n", result->data->song_name, result->data->artist);
            }
            else
            {
                printf("No result\n");
            }
            free(target);
            free(result);
        }
    }
    else if (output_Choose == 4)
    {
        //printf("[1] Delete by artist [2] Delete by title :");
        //scanf("%d", &search_Choose);
        wchar_t s[MAX_SONG_NAME + 1];
        wscanf(L"%s", s);
        song *target = (song *)malloc(sizeof(target));
        target->song_name = s;
        delete_name(&root, target, search_Choose);
        Inorder_traverse(root, 2);
        free(target);
    }
    else
    {
        return 0;
    }
    */
}