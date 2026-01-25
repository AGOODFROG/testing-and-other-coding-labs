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
    snake,
     food
};



int draw(int board[10][10]){
    printf("\n");
    for(int i = 0; i < 10;i++ ){
        for(int j = 0; j < 10; j++){
            printf("%d ", board[i][j]);
        }     
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
    int snakePos[100][2] = {{1,1},{2,2},{3,3}};
    int board[10][10];
    int snakeSize = sizeof(snakePos) / sizeof(snakePos[0]);
    int foodPos[2] = {3,5};

    for(int i = 0; i < 10;i++ ){
        for(int j = 0; j < 10; j++){
            board[i][j] = 0;
        }     
        
    }



    
    

    int a = 0;
    int startX;
    int startY;
    int x;
    int y;
    while(1)
     {
        startX = snakePos[0][0];
        startY = snakePos[0][1];
       
        board[foodPos[0]][foodPos[1]] = food;
        
         if((keyInput = getchar()))
         {
            //todo add sleep
            while(a < 1000)
            {
                a++;
            }
            a=0; 
            printf("\n");      
        }
             for(int i = sizeof(snakePos)/(sizeof(snakePos[0])) - 1; i > 0; i--)
            {
                snakePos[i][0] = snakePos[i-1][0];
                snakePos[i][1] = snakePos[i-1][1];
            } 
            
            board[startX][startY+1] = snake;
            snakePos[0][0] = startY+1;
            snakePos[0][1] = startX;
            for(int i = 0; i < 10; i++){
                printf("%d ", snakePos[i][0]);
                printf("%d, ", snakePos[i][1]);
            }
            
            if(keyInput == up){printf("up");}
            if(keyInput == down){printf("down");}
            if(keyInput == right){printf("right");}
            if(keyInput == left){printf("left");}
    

        draw(board);
        
        
    }
        //move the player
        //check for input
        //reload screen
}