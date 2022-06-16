#ifndef MYDS_H
#define MYDS_H
#define MAX_SONG_NAME 100
#include <wchar.h>
#include <time.h>
#include <stdbool.h>
struct systime{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};
typedef struct systime systime;
// the struct store all the information of song.
struct song
{
    char *song_name;
    char *artist;
    float length;
    bool like;
    systime times;
    struct song *parent;
    struct song *left_child;
    struct song *right_child;
};

typedef struct song song;

// the node and the root of songlist_tree
struct node
{
    song *data;
    char songlist_name[MAX_SONG_NAME+1];
    struct node *parent;
    struct node *left_child;
    struct node *right_child;
}*root;
typedef struct node node;
// compare input index and build the binary search tree
//void build_tree(node **root, song *data, node *cur, int *error);
void build_song(song **cur_songlist,char song_name[]);
void build_songlist(node **songlist_tree,char *target);
void build_song_data(song **song_data,song *songs);
void delete_name(node **root, song *data, int search_Choose);
void delete_song(song **cur_songlist,char song_name[]);
void delete_songlist(node **songlist_tree,char songlist_name[]);
#endif
//
//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \\|     |// '.
//                 / \\|||  :  |||// \
//                / _||||| -:- |||||- \
//               |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='
//
//
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//               佛祖保佑         永無BUG