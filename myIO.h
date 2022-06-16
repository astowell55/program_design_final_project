#ifndef MYIO_H
#define MYIO_H
#include "myDS.h"

// preorder traverse the tree and print out the value of every node
void Preorder_traverse(node *root, int output_choose);
// inorder traverse the tree and print out the value of every node
void Inorder_traverse(song *root);
// postorder traverse the tree and print out the value of every node
void Postorder_traverse(node *root, int output_choose);


void read_SongFile(song **song_data);


void output_song(song *cur_songlist);
void output_songlist(node *songlist_tree);

//void write_SongFile(node *root);
void Export_songlist(song *cur_songlist, char *Filename);
void Import_songlist(node **songlist_tree, char songlist_name[]);
void read_song_name(char *buffer);
char *read_wstring();

void print_systimes(systime upload_time);
#endif