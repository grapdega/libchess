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

item *items;
void init_items();
void set_item(int x,int y, char* type);
char* get_item(int x,int y);
void print_board();
int move(int x, int y , int xx, int yy);
