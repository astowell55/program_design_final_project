#ifndef MYDS_H
#define MYDS_H
#define MAX_SONG_NAME 100
#include <wchar.h>
// the struct store all the infomation of song
struct item
{
    int index;
    wchar_t *song_name;
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