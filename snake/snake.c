# include <inttypes.h>
# include <stdio.h>
# include <sys/select.h>
# include <termios.h>
# include <unistd.h>


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
    int snakePos[100][2] = {{1,1}};
    int board[10][10];
    
    int foodPos[2] = {3,5};
    int eaten = 0;

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
        if(1){

        }
        sleep(1);
        
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
           
        
            
        
        for(int i = 0; i < 10;i++){ printf("(%d,%d)", snakePos[i][1], snakePos[i][0]);}
        draw(board);
        

        
        
        
    }
        //move the player
        //check for input
        //reload screen
}