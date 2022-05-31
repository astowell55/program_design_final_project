#ifndef MYDS_H
#define MYDS_H
#define MAX_SONG_NAME 100
<<<<<<< HEAD
//the struct store all the infomation of song
struct item{
    char *song_name;
    int index;
=======
#include <wchar.h>
// the struct store all the infomation of song
struct item
{
    int index;
    wchar_t *song_name;
>>>>>>> 6c31b7d58f9e629a69611e1a25463bfd41ba0548
};
typedef struct item item;
// the node and the root of tree
struct node
{
    item *data;
    struct node *parent;
    struct node *left_child;
    struct node *right_child;
} * root;
typedef struct node node;
// compare input index and build the binary search tree
void build_tree(node **root, item *data, node *cur, int *error);
void delete_name(node **root, item *data);
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