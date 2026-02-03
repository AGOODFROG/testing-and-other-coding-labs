# include <inttypes.h>
# include <stdio.h>
# include <sys/select.h>
# include <termios.h>
# include <unistd.h>
#include "raylib.h"

int width = 20;

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

int get_char()
{
    fd_set rfds;
    struct timeval tv;
    int ch = 0;
    FD_ZERO(&rfds);
    FD_SET(0, &rfds);
    tv.tv_sec = 0;
    tv.tv_usec = 10; 							// Set up waiting time timeout
	if (select(1, &rfds, NULL, NULL, &tv) > 0)  // Detect whether the keyboard has input
    {
        ch = getchar(); 
    }
    return ch;
}

int draw(int board[width][width]){
    usleep(50000);
    printf("\n");
    for(int i = 0; i < width;i++ ){
        for(int j = 0; j < width; j++){
            printf("%d ", board[i][j]);
        }     
        printf("\n");
    }
 }
 // thx linuxVox
 

// thx linux vox


int main() {
    //set up input
    
    struct termios info;
    tcgetattr(0, &info);
    info.c_lflag &= ~ICANON;
    info.c_cc[VMIN] = 1;          
    info.c_cc[VTIME] = 0;        
    tcsetattr(0, TCSANOW, &info);
    
    // game stuff
    int snakePos[(width*width)][2] = {};
    snakePos[0][0] = 1;
    snakePos[0][1] = 1;
    int board[width][width];
    
    int foodPos[2] = {3,5};
    int eaten = 0;

    for(int i = 0; i < width;i++ ){
        for(int j = 0; j < width; j++){
            board[i][j] = 0;
        }       
    }
   
    int a = 0;
    int startX;
    int startY;
    int x;
    int y;
    int snakeSize;
    int keyInput = down;
    int prevKeyInput = keyInput;
    
    while(1)
     {
        //printf("%d\n",keyInput);
        startX = snakePos[0][1];
        startY = snakePos[0][0];

        snakeSize = sizeof(snakePos)/(sizeof(snakePos[0]));
       
        board[foodPos[0]][foodPos[1]] = food;
        prevKeyInput = keyInput;
       
        keyInput = get_char();
        usleep(500000);
           
        
        a=0;

        if(keyInput > 68 || keyInput < 65){
            keyInput = prevKeyInput;
        }
            
        
        
        
        
        printf(" key input%d\n",keyInput);
        
        //todo add sleep
      
                  
        for(int i = snakeSize - 1; i > 0; i--)
        {
            snakePos[i][0] = snakePos[i-1][0];
            snakePos[i][1] = snakePos[i-1][1];  
        } 
         snakePos[0][0] == -1;
         snakePos[1][0] == -1;
        if(!eaten)
        {
            //snakePos[0][0] = snakePos[snakeSize-1][0];
            //snakePos[0][1] = snakePos[snakeSize-1][1];
        }
        
        if(keyInput == up)
        {
            startY--;
        }
        if(keyInput == down)
        {
            startY++;
        }
        if(keyInput == right)
        {
            startX--;
        }
        if(keyInput == left)
        {
            startX++;
        }
        // checks to see if the input in the same as the last input(index 1)
            if((snakePos[0][1] != startY || snakePos[0][0] != startX) && keyInput != -1)
            {
                snakePos[0][0] = startY;
                snakePos[0][1] = startX;
                board[startY][startX] = snake;
            }
           
        
            
        
        for(int i = 0; i < width;i++){ printf("(%d,%d)", snakePos[i][1], snakePos[i][0]);}
        draw(board);
        
        
        

        
        
        
    }
        //move the player
        //check for input
        //reload screen
}