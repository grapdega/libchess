#include <string.h>

typedef struct {
    int x; // x axis
    int y; // y axis
    char *type; //♜ ♞ ♝ ♛ ♚ ♟ or ♖ ♘ ♗ ♕ ♔ ♙
} item;

//define unicode char 
#define wr "♖"
#define br "♜"
#define wh "♘"
#define bh "♞"
#define wb "♗"
#define bb "♝"
#define wk "♔"
#define bk "♚"
#define wq "♕"
#define bq "♛"
#define wp "♙"
#define bp "♟"
#define nn " "

#define black 1
#define none  0 
#define white 2

item new_item(int x, int y, char* type);
int get_player(char* type);

item new_item(int x, int y, char* type){
    item new;
    new.x=x;
    new.y=y;
    new.type=type;
    return new;
}
int get_player(char* type){
    if(strstr("♜♞♝♛♚♟",type) != NULL) {
        return 1;
    }if(strstr("♕♔♗♘♖♙",type) != NULL) {
        return 2;
    }
    return 0;
}
