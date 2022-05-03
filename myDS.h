#ifndef MYDS_H
#define MYDS_H

#include <stdlib.h>

struct node{
    char *song_name;
    struct node *next;
    struct ndoe *prior;
};

#endif