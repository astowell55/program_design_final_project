#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "myDS.h"
#include "myIO.h"
#include "myAlgo.h"
#include "myUI.h"
void Choose_a_songlist(song **cur_songlist, wchar_t *songlist_name)
{
    /*
        In a songlist,it is the UI.
    */
    // Operate
    wchar_t *song_name;
    song *target_song = NULL;
    printf("[a]Add a song\n[d]Delete a song\n"
           "[o]Output all songlists\n[e]Export as .csv\n[s]Sort\n[r]Random\n"
           "[<]Back to main page\nEnter your operater:\n");
    char operater;
    while (scanf(" %c\n", &operater) != EOF)
    {
        switch (operater)
        {
        case 'a':
            // Add song.
            song_name = read_wstring();
            printf("read: _%ls_\n", song_name);
            target_song = search_song(*cur_songlist, song_name);
            printf("point:_%p_\n", target_song);

            if (target_song == NULL)
            {
                build_song(cur_songlist, song_name);
                printf("Add song : %ls\n", song_name);
            }
            else
            {
                printf("Invalid operation\n");
            }
            free(song_name);
            printf("_%ls_\n", (*cur_songlist)->song_name);
            break;
        case 'd':
            // Delete song.
            song_name = read_wstring();
            target_song = search_song(*cur_songlist, song_name);
            if (target_song != NULL)
            {
                delete_song(cur_songlist, song_name);
                printf("Delete song : %ls\n", song_name);
            }
            else
            {
                printf("Invalid operation\n");
            }
            free(song_name);
            break;
        case 'o':
            // Output all song in this list.
            output_song(*cur_songlist);
            break;
        case 'e':
            // Export this songlist as .csv
            Export_songlist(*cur_songlist, songlist_name);
            break;
        // case 's':
        //     //Sort and output all song(?)
        //     break;
        // case 'r':
        //     //Random all song(?)
        //     break;
        case '<':
            return; // Back
            break;
        default:
            printf("Invalid operation\n");
            break;
        }
        printf("[a]Add a song\n[d]Delete a song\n"
               "[o]Output all songlists\n[e]Export as .csv\n[s]Sort\n[r]Random\n"\
               "[<]Back to main page\nEnter your operater:\n");
    }
}

int main()
{
    int data_num, input_Choose, output_Choose, search_Choose;

    int error = 0;
    // setlocale(LC_ALL,"");
    printf("Welcome to use this project!\n");
    //- Preload songdata
    read_SongFile();
    //- Preload songdata end
    node *songlist_tree = NULL;   // the root of songlist tree.
    node *target_songlist = NULL; // point to the songlist.
    // select oprerater
    printf("[a]Add a songlist\n[d]Delete a songlist\n"
           "[c]Choose a songlist\n[o]Output all songlists\n[i]import a .csv songlist\n[e]Exit\nEnter your operater:\n");
    char operater;
    wchar_t *songlist_name;

    // Operate
    while (scanf(" %c\n", &operater) != EOF)
    {
        switch (operater)
        {
        case 'a':
            // Build or Add songlist into tree.
            // scanf("%ls",songlist_name);
            songlist_name = read_wstring();
            printf("name:_%ls_\n", songlist_name);
            // find
            target_songlist = search_songlist(songlist_tree, songlist_name);
            printf("point:_%p_\n", target_songlist);
            if (target_songlist == (node *)NULL)
            {
                build_songlist(&songlist_tree, songlist_name);
                printf("Add songlist : %ls\n", songlist_name);
            }
            else
            {
                printf("Invalid operation: EXIST SONGLIST\n");
            }
            free(songlist_name);
            break;
        case 'd':
            // Delete target songlist.
            songlist_name = read_wstring();
            // find
            target_songlist = search_songlist(songlist_tree, songlist_name);

            if (target_songlist != NULL)
            {
                delete_songlist(&target_songlist, songlist_name);
                printf("Delete songlist : %ls\n", songlist_name);
            }
            else
            {
                printf("Invalid operation: NULL SONGLIST\n");
            }
            free(songlist_name);
            break;
        case 'c':
            // Enter the target songlist, going to another UI.
            // printf("read\n");
            songlist_name = read_wstring();
            printf("name:_%ls_\n", songlist_name);
            // find
            target_songlist = search_songlist(songlist_tree, songlist_name);
            printf("point:_%p_\n", target_songlist);
            if (target_songlist != NULL)
            {
                printf("Choose songlist : %ls\n", songlist_name);
                Choose_a_songlist(&(target_songlist->data), target_songlist->songlist_name);
            }
            else
            {
                printf("Invalid operation: NULL SONGLIST\n");
            }
            free(songlist_name);
            break;
        case 'o':
            // Output all songlist name.
            output_songlist(songlist_tree);
            break;
        case 'i':
            // Import a songlist.
            songlist_name = read_wstring();
            Import_songlist(songlist_tree, songlist_name);
            free(songlist_name);
            break;
        case 'e':
            return 0;
        default:
            printf("Invalid operater\n");
            break;
        }
        printf("[a]Add a songlist\n[d]Delete a songlist\n[c]Choose a songlist\n"
               "[o]Output all songlists\n[i]import a .csv songlist\n[e]Exit\nEnter your operater:\n");
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
                printf("%ls %ls\n", result->data->song_name, result->data->artist);
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
                printf("%ls %ls\n", result->data->song_name, result->data->artist);
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
        wscanf(L"%ls", s);
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