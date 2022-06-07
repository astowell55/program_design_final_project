#ifndef MYALGO_H
#define MYALGO_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include "myDS.h"
#include "myIO.h"

// search by song_name
node *search(node *root, item *target, int search_Choose);
node *search_songlist(node *songlist_tree,wchar_t songlist_name[]);
node *search_song(song *cur_songlist,wchar_t song_name[]);
#endif
