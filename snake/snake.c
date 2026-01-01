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

void move(){
    
}



int main() {
    // make the board
    int x = 10;// todo use
    int y = 1;
    int foodX = 10;
    int foodY = 10;
    int endX = x;
    int endY = y;
    
    char board[20][20];
    int sankeSize = 1;
    int snake_pos[(20*20)+1][2];

    enum place_states{ empty, snake, food};
    enum directions{left=68, right=67, up=65, down=66};
    int direction = left;
    int inputWindow = 500; //iterations of a loop

    struct termios info;
    tcgetattr(0, &info);
    info.c_lflag &= ~ICANON;
    info.c_cc[VMIN] = 1;          
    info.c_cc[VTIME] = 0;        
    tcsetattr(0, TCSANOW, &info);

    int keyInput;

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
        if((keyInput = getchar())){
            direction = keyInput;
            //printf("%d\n", keyInput);
        }
        //printf("%d\n",keyInput);
        if (direction == right && x < 19){ x++;}
        if (direction == left && x > 0){ x--; }
        if (direction == down && y < 19 ){ y++;}
        if (direction == up && y > 0){ y--; }
        
        printf("%d %d\n", x, y );
        if(board[y][x] == food){
           printf("chome\n");
           board[y][x] == snake;

        }else{
            printf("not chomp");
            board[y][x] = snake;
            board[endY][endX] = empty;
            endX = x;
            endY = y;
        }
    }
        //move the player
        //check for input
        //reload screen
}