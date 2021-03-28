#include <chess.h>
#include <stdio.h>
int main(){
    init_items();
    int x,y,xx,yy;
    while(1){
        print_board();
        printf("=> ");
        scanf("%d %d %d %d",&x,&y,&xx,&yy);
        move(y,x,yy,xx); //ncurses logic
    }
}
