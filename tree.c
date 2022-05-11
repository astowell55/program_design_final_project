#include <stdio.h>
#include <stdlib.h>
#include "myDS.h"
#include "myIO.h"

int main()
{
    int data_num, input_Choose, output_Choose;
    int error = 0;
    printf("[1] Input a csv file. [2] Input the data on terminal. :");
    scanf("%d", &input_Choose);
    if (input_Choose == 1)
    {
        read_SongFile();
    }
    else if (input_Choose == 2)
    {
        scanf(" %d", &data_num);
        while (data_num--)
        {   
            
            item *temp = (item *)malloc(sizeof(temp));
            read_line(temp);
            build_tree(&root, temp, root, &error);
            if(error) data_num++;
            error = 0;
        }
    }
    else
    {
        return 0;
    }

    printf("[1] Output the data in csv file. [2] Output the data on terminal. :");
    scanf("%d", &output_Choose);
    if (output_Choose == 1)
    {
        write_SongFile(root);
    }
    else if (output_Choose == 2)
    {
        Inorder_traverse(root,output_Choose);
    }
    else
    {
        return 0;
    }
}