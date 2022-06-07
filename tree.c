#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myDS.h"
#include "myIO.h"
#include "myAlgo.h"

void Choose_a_songlist(const node *cur_songlist){
    
    //Operate
    wchar_t song_name[MAX_SONG_NAME+1];
    printf("[a]Add a song\n[d]Delete a song\n" \
    "[o]Output all songlists\n[e]Export as .csv\n[s]Sort\n[r]Random\n" \ 
    "[<]Back to main page\nEnter your operater:\n");
    char operater;
    while(scanf("%c",&operater)!=EOF){
        switch (operater)
        {
        case 'a':
            //Add song.
            read_wstring(song_name);
            if(/*the song haven't added yet*/){
                build_song(cur_songlist,song_name);
                printf("Add song : %s\n",song_name);
            }else{
                printf("Invalid operation\n");
            }
            break;
        case 'd':
            //Delete song.
            read_wstring(song_name);
            if(/*the song has added*/){
                delete_song(cur_songlist,song_name);
                printf("Delete song : %s\n",song_name);
            }else{
                printf("Invalid operation\n");
            }
            break;
        case 'o':
            //Output all song in this list.
            output_song(cur_songlist);
            break;
        case 'e':
            //Export this songlist as .csv
            Export_songlist(cur_songlist);
            break;
        case 's':
            //Sort and output all song(?)
            break;
        case 'r':
            //Random all song(?)
            break;
        case '<':
            return;//Back
            break;
        default:
            printf("Invalid operation\n");
            printf("[a]Add a song\n[d]Delete a song\n" \
        "[o]Output all songlists\n[e]Export as .csv\n[s]Sort\n[r]Random\n" \ 
        "[<]Back to main page\nEnter your operater:\n");
            break;
        }
    }
}

int main()
{
    int data_num, input_Choose, output_Choose, search_Choose;
    
    int error = 0;
    printf("Welcome to use this project!\n");
    //- Preload songdata
    //read_SongFile("songFile.csv");
    //- Preload songdata end
    
    node *songlist_tree;//the root of songlist tree.
    node *target_songlist;//point to the songlist.
    //select oprerater
    printf("[a]Add a songlist\n[d]Delete a songlist\n" \
    "[c]Choose a songlist\n[o]Output all songlists\n[i]import a .csv songlist\nEnter your operater:\n");
    char operater;
    wchar_t songlist_name[MAX_SONG_NAME+1];
    //Operate
    while(scanf("%c",&operater)!=EOF){
        switch (operater)
        {
        case 'a':
            //Build or Add songlist into tree.
            read_wstring(songlist_name);
            //find
            node *target_songlist = search_songlist(songlist_tree,songlist_name);
            if(/*songlist haven't built yet*/){
                build_songlist(songlist_tree,songlist_name);
                printf("Add songlist : %s\n",songlist_name);
            }else{
                printf("Invalid operation\n");
            }
            break;
        case 'd':
            //Delete target songlist.
            read_wstring(songlist_name);
            //find
            node *target_songlist = search_songlist(songlist_tree,songlist_name);
            if(/*the songlist has built*/){
                delete_songlist(target_songlist);
                printf("Delete songlist : %s\n",songlist_name);
            }else{
                printf("Invalid operation\n");
            }
            break;
        case 'c':
            //Enter the target songlist, going to another UI.
            read_wstring(songlist_name);
            //find
            node *target_songlist = search_songlist(songlist_tree,songlist_name);
            if(/*the songlist haven't built yet*/){
                Choose_a_songlist(target_songlist);
                printf("Choose songlist : %s\n",songlist_name);
            }else{
                printf("Invalid operation\n");
            }
            
            break;
        case 'o':
            //Output all songlist name.
            output_songlist(songlist_tree);
            break;
        default:
            printf("Invalid operater\n");
            printf("[a]Add a songlist\n[d]Delete a songlist\n[c]Choose a songlist\n" \
    "[o]Output all songlists\n[i]import a .csv songlist\nEnter your operater:\n");
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

            item *temp = (item *)malloc(sizeof(temp));
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
            item *target = (item *)malloc(sizeof(target));
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
            item *target = (item *)malloc(sizeof(target));
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
        item *target = (item *)malloc(sizeof(target));
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