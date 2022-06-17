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
You can use w and s to choose the option and use e to enter your option.
### Option 選項:
```
Add a playlist: Create a playlist. 
Delete a playlist: Delete a playlist that you had created.
Choose a playlist: After choose this option, you can choose the following options in current playlist
    Add a song: Add a song from audio library.  
    Delete a song: Delete a song in current playlist.
    Output all the songs in the list: Output all the songs in the current playlist.
    Export as .csv: Export current playlist as a csv file.
    Search a song: You can search a song in current playlist and mark it as a favorite song. 
    Back to main page: 
Output all playlists: Out put all the playlist name on terminal.
Import a .csv playlist: You can import the csv file that you have exported.
Exit: Terminate the program.
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
* 0.1.0
    * Change: Update W_char.
* 0.1.1
    * Change: Add search_Choose for search by artist or title 
              (idk whether this version lost Chinese output in Unix and sorry for not freeing malloc, my bad. J)
    * Change: Add artist, length in struct item (index has not been deleted yet)
* 0.1.2
    * Change: modify tree.c
* 0.1.3
    * Change: Add function name and comment, modify all .c file.
* 0.1.4
    * Change: Replace struct "item" to "song".
* 0.1.5
    * Change: modify all .h file.
* 0.1.6
    * Change: Replace the variable "item" to "song".
    * Change: Comment Out old function.
* 0.1.7
    * Change: complete search_song and search_songlist in myalgo
* 0.1.8
    * Change: complete delete_song and delete_songlist.
    * Change: add delete_all_song function in myDS.c.
* 0.1.9
    * Change: complete build_songlist, half complete build_song in myDS.c
    * Change: Update FILE I/O
* 0.1.10
    * Change: modify delete_song and delete_songlist.
    * Change: modify read_wstring.
    * Change: modify tree.c .
* 0.2.0
    * Change: a lot.
* 0.2.1
    * Change: modify data_type.
* 0.2.2
    * Change: Update File I/O
* 0.2.3
    * Change: Add Inorder_traverse_song in myIO
* 0.2.4
    * Change: Add guide in tree.c
    * Change: Add output_song in myIO
* 1.0.0
    * Change: forgiving wide char.
    * Change: FIX build_song_data.
* 1.0.1
    * Change: FIX build function.
* 1.0.2
    * Change: add system time
    * Change: FIX delete function.
    * Change: remove useless comments.
* 1.0.3
    * Change: modify export function.
    * Change: modify build_song, now it can only accept the song name which existed in song_data.
    * Change: song_data now is a Global variable.
* 1.0.4
    * Change: improve UI.
* 1.0.5
    * Change: File I/O finished.
* 1.1.0
    * Change: like~.
* 1.1.1
    * Change: fix demonstration error.
## target 每周目標

### 第二周
