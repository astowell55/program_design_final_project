#ifndef MYIO_H
#define MYIO_H
#include "myDS.h"

// inorder traverse the tree and print out the value of every node
void Inorder_traverse(node *root, int output_choose);
int read_SongFile();
int write_SongFile(node *root);
#endif