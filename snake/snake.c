#include <inttypes.h>
# include <stdio.h>
# include <termios.h>


void make(char board[20][20]){
    for(int i = 0; i < sizeof(board[0]); i++){
        for(int j = 0; j < sizeof(board[i]);j++){
            board[i][j] = 0;
        }  
    }
}

void render(char board[20][20]){
    for(int i = 0; i < sizeof(board[0]); i++){
        for(int j = 0; j < sizeof(board[i]);j++){
            printf("%d", board[i][j]);
            printf("  ");
        }
        printf("\n");
    }
    printf("\n");
}





int main() {
    // make the board
    int x = 10;// todo use
    int y = 1;
    int foodX = 10;
    int foodY = 10;
    int endX = x;
    int endY = y;
    int isTurning = 0;
    int sankeSize = 1;
    enum place_states{ empty, snake, food};
    enum directions{left=68, right=67, up=65, down=66};
    int direction = left;
    int prevDirection;
    int keyInput;
    
    char board[20][20];
   
    int snake_pos[(20*20)+1][2];

    struct termios info;
    tcgetattr(0, &info);
    info.c_lflag &= ~ICANON;
    info.c_cc[VMIN] = 1;          
    info.c_cc[VTIME] = 0;        
    tcsetattr(0, TCSANOW, &info);


    //printf("%ld", sizeof(board[0]));
    make(board);
    printf("\n");
    
    // add the player to the board
    snake_pos[0][0] = 0;
    snake_pos[0][1] = 10;

    // add the food 
    board[foodX][foodY] = food;
    int a = 0;
    while(1) {
        render(board);
        isTurning = 0;
         if((keyInput = getchar())){
            prevDirection = direction;
            direction = keyInput;
            while(a < 1000){
                a++;
            }
            a=0;
            if(prevDirection =! direction){
                isTurning = 1;
            }
            
        }
        if(!isTurning){
            if (direction == right && x < 19){ x++;}
            if (direction == left && x > 0){ x--; }
            if (direction == down && y < 19 ){ y++;}
            if (direction == up && y > 0){ y--; }
        }

        printf("%d %d\n", x, y );
        if(board[y][x] == food){
            printf("chump");
            board[endY][endX] = snake;
            board[y][x] = snake;
            sankeSize++;
        }else{
            board[endY][endX] = empty;
            endX = x;
            endY = y;
            if(sankeSize > 1){
                printf("%d %d\n", endX,endY);
                if (direction == right){ 
                    x = x++;
                    board[endY][endX-sankeSize+1] = snake;
                    board[y][endX-sankeSize-1] = empty;
                }
                if (direction == left){ 
                    x = x--;
                    board[endY][endX+sankeSize-1] = snake;
                    board[y][endX+sankeSize+1] = empty;
                 }
                if (direction == down){ 
                     y= y++;
                    board[endY-sankeSize+1][endX] = snake;
                    board[endY-sankeSize+1][endX] = empty;
                }
                if (direction == up){
                    y = y--;
                    board[endY+sankeSize-1][endX] = snake;
                    board[endY+sankeSize+1][endX] = empty;     
                }
                board[y][x] = snake;
                
            }else{
                board[y][x] = snake;//good
            }
            
        }
    }
        //move the player
        //check for input
        //reload screen
}