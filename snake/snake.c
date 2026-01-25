#include <inttypes.h>
# include <stdio.h>
# include <termios.h>


enum directions {
    right = 68,
    left = 67,
    down = 66,
    up = 65
};
enum boardStates{
    space,
    food,
    snake
}

int startGame(){
    printf("TODO");
}

int draw(int board[10][10]){
    printf("\n");
    for(int i = 0; i < 10;i++ ){
        for(int j = 0; j < 10; j++){printf("%d ", 0);}     
        printf("\n");
    }
    printf("\n");
    }
    



int main() {
    //set up input
    struct termios info;
    int keyInput;
    tcgetattr(0, &info);
    info.c_lflag &= ~ICANON;
    info.c_cc[VMIN] = 1;          
    info.c_cc[VTIME] = 0;        
    tcsetattr(0, TCSANOW, &info);
    // game stuff
    int snakePos[100][2] =  {1,1};
    int board[10][10];
    int prevSnakeSize = 1;



    
    

    int a = 0;
    while(1) {
         if((keyInput = getchar())){
            //todo add sleep
            while(a < 1000){
                a++;
            }
            a=0;   
            if(keyInput == up){printf("up");}
        }
        draw(board);
        
    }
        //move the player
        //check for input
        //reload screen
}