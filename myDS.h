#ifndef MYDS_H
#define MYDS_H
#define MAX_SONG_NAME 100
#include <wchar.h>
// the struct store all the information of song.
struct song
{
    wchar_t *song_name;
    wchar_t *artist;
    wchar_t *length;
    struct song *parent;
    struct song *left_child;
    struct song *right_child;
};

typedef struct song song;

// the node and the root of songlist_tree
struct node
{
    song *data;
    wchar_t *songlist_name;
    struct node *parent;
    struct node *left_child;
    struct node *right_child;
}*root;
typedef struct node node;
// compare input index and build the binary search tree
void build_tree(node **root, song *data, node *cur, int *error);
void build_song(song **cur_songlist,wchar_t song_name[], song *par);
void build_songlist(node **songlist_tree,wchar_t songlist_name[],node *par);
void delete_name(node **root, song *data, int search_Choose);
void delete_song(song *cur_songlist,wchar_t song_name[]);
void delete_songlist(node *songlist_tree,wchar_t songlist_name[]);
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