#include <stdio.h>
#include <stdlib.h>
#include "myDS.h"
#include "myIO.h"

int main(){
    int data_num;
    scanf(" %d",&data_num);
    while(data_num--){
        item *temp = (item *)malloc(sizeof(temp));
        scanf(" %d ",&temp->index);
        fgets(temp->song_name,MAX_SONG_NAME,stdin);
        build_tree(&root,temp);
    }
    Inorder_traverse(root);
    
}