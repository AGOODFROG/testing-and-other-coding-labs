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
    int snake_poses[20*30][2] = {{y,x}};
    char board[20][20];

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
    board[y][x] = snake;
    int startX = snake_poses[0][1];
    int startY = snake_poses[0][0];
  

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
        if (direction == right && x < 19){
            //board[y][x+1] = snake;
            x++; 
        }
        if (direction == left && x > 0){
            //board[y][x-1] = snake;
            x--; 
        }
        if (direction == down && y < 19 ){
            //board[y+1][x] = snake;
            y++; 
        }
        if (direction == up && y > 0){
            //board[y-1][x] = snake;
            y--; 
        }
        printf("test\n");

        
        if(board[x][y] == food){
            printf("chomp\n");
            board[x][y] = snake;
        }else{
            /*
            board[y][x] = snake;
            board[startY][startX] = empty;
            startX = x;
            startY = y;
            */
            // add new x and y to snake_poeps
                //shift everything to the right
                
                for(int i = sizeof(snake_poses)-1/*max len*/; i > 0; i--){
                    
                    snake_poses[i-1][0] = snake_poses[i][0];
                    snake_poses[i-1][1] = snake_poses[i][1];
                }
                
                // add to index 0
            // clear out old end 
            //set new x and y start / end
        }
       

    }
        
       
}