#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myDS.h"
#include "myIO.h"
#include "myAlgo.h"

int main()
{
    int data_num, input_Choose, output_Choose, search_Choose;
    int error = 0;
    printf("[1] Input a csv file. [2] Input the data on terminal. :");
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
}