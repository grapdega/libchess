#include <stdlib.h>
#include <stdio.h>
#include <item.c>

item *items;
void init_items();
void set_item(int x,int y, char* type);
char* get_item(int x,int y);
void print_board();
int move(int x, int y , int xx, int yy);

void init_items(){
    items=malloc(64*sizeof *items);
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            items[(i*8)+j].x = (int)malloc(sizeof(int));
            items[(i*8)+j].y = (int)malloc(sizeof(int));
            items[(i*8)+j].type = (char*)malloc(sizeof(int));
            items[(i*8)+j]=new_item(i,j,nn);
            //printf("init: %d x %d\n",i,j);
        }
    }
    set_item(0,0,wr);
    set_item(0,1,wh);
    set_item(0,2,wb);
    set_item(0,3,wq);
    set_item(0,4,wk);
    set_item(0,5,wb);
    set_item(0,6,wh);
    set_item(0,7,wb);
    
    set_item(1,0,wp);
    set_item(1,1,wp);
    set_item(1,2,wp);
    set_item(1,3,wp);
    set_item(1,4,wp);
    set_item(1,5,wp);
    set_item(1,6,wp);
    set_item(1,7,wp);

    set_item(7,0,br);
    set_item(7,1,bh);
    set_item(7,2,bb);
    set_item(7,3,bq);
    set_item(7,4,bk);
    set_item(7,5,bb);
    set_item(7,6,bh);
    set_item(7,7,bb);
    
    set_item(6,0,bp);
    set_item(6,1,bp);
    set_item(6,2,bp);
    set_item(6,3,bp);
    set_item(6,4,bp);
    set_item(6,5,bp);
    set_item(6,6,bp);
    set_item(6,7,bp);
}

void set_item(int x,int y, char* type){
    items[x*8+y]=new_item(x,y,type);
}

char* get_item(int x,int y){
    return items[x*8+y].type;
}

void print_board(){
    int k=0;
    char* ee="\x1b[40;1m";
    char* aa="\x1b[41;1m";
    putc('\n',stdout);
    for(int i=0;i<8;i++){
        printf(" %d",i);
    }
    putc('\n',stdout);
    for(int i=0;i<8;i++){
        printf("\x1b[;0m%d",i);
        for(int j=0;j<8;j++){
            k=i+j;
            if(k%2){
                printf("%s%s\x1b[;0m ",ee,get_item(i,j));
            }else{
                printf("%s%s\x1b[;0m ",aa,get_item(i,j));
            }
        }
        putc('\n',stdout);
    }
}

int move(int x, int y , int xx, int yy){
    char *type=get_item(x,y);
    if(get_player(get_item(x,y))!=get_player(get_item(xx,yy))){
        set_item(x,y,nn);
        set_item(xx,yy,type);
        return 1;
    }
    return 0;
}
