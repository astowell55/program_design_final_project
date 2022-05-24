# program_design_final_project

## Getting Started 使用指南

使用make指令編譯，並執行tree:
```
make
./tree
```
用clean來清除.o檔:
```
make clean
```
## Usage example 使用示範
首先輸入有n首歌，再輸入歌曲的index跟歌曲的name，如果取名有重複則輸出"歌曲名稱 already exist"接著輸出中序走訪的結果(歌曲依照strcmp排序)，範例如下:
### 輸入:
```
4
1 helloasddddddddddddddddddddddddddddddddddddjoiajidjiajsddddddddddddddddddddddddddddddddddddoiajsdijasijdajdsi
5 ddd
6 abcd
6 abcd
6 yyds
```
### 輸出:
```
abcd already exist
6 abcd
5 ddd
1 helloasddddddddddddddddddddddddddddddddddddjoiajidjiajsddddddddddddddddddddddddddddddddddddoiajsd...
6 yyds
```
## Release History 版本歷史

* 0.0.1
    * CHANGE: Create build_tree and Inorder_traverse function
* 0.0.2
    * CHANGE: Create read_songFile and write_songFile function
* 0.0.3
    * CHANGE: Optimize read_songFile and write_songFile function
* 0.0.4
    * CHANGE: Update the read_line and read _song name function for reading limit number of letter
* 0.0.5
    * CHANGE: Create delete_index function
    * CHANGE: Create traverse and search
* 0.0.6
    * CHANGE: Optimize and update build_tree function compare node with string
    * CHANGE: Update build_tree to link pareant node;
* 0.0.7
    * CHANGE: Update search function from searching by index to by song_name
* 0.0.8
    * Change: Rivese search function and move to myAlgo
    * Change: Put traversal functions and search funtion into tree.c
* 0.0.9
    * Change: Update delete_name function(there are some overused malloc() and didn't free() it. wtf= =)
## target 每周目標

### 第二周
