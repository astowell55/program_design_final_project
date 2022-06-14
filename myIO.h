#ifndef MYIO_H
#define MYIO_H
#include "myDS.h"

// preorder traverse the tree and print out the value of every node
void Preorder_traverse(node *root, int output_choose);
// inorder traverse the tree and print out the value of every node
void Inorder_traverse(node *root, int output_choose);
// postorder traverse the tree and print out the value of every node
void Postorder_traverse(node *root, int output_choose);

void read_line(song *data);
void read_SongFile(char *FileName);
void write_SongFile(node *root);
void output_song(song *cur_songlist);
void output_songlist(node *songlist_tree);
void Export_songlist(node *cur_songlist);
void Import_songlist(node *songlist_tree,wchar_t songlist_name[]);
void read_song_name(wchar_t *buffer);
void traverse(song *root, int output_choose);
wchar_t *read_wstring();
#endif