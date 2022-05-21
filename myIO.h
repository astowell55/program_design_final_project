#ifndef MYIO_H
#define MYIO_H
#include "myDS.h"

// preorder traverse the tree and print out the value of every node
void Preorder_traverse(node *root, int output_choose);
// inorder traverse the tree and print out the value of every node
void Inorder_traverse(node *root, int output_choose);
// postorder traverse the tree and print out the value of every node
void Postorder_traverse(node *root, int output_choose);

void read_line(item *data);
int read_SongFile();
int write_SongFile(node *root);

// search by song_name
node *search(node *root, item *target);

#endif