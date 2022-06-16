#ifndef MYALGO_H
#define MYALGO_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include "myDS.h"
#include "myIO.h"

//node *search(node *root,song *target, int search_Choose);// search by song_name
node *search_songlist(node *songlist_tree,char songlist_name[]);
song *search_song(song *cur_songlist, char song_name[]);
void upload_time(systime *upload_times);
#endif
