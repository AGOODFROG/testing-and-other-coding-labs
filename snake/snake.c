#include <inttypes.h>
# include <stdio.h>
# include <termios.h>

struct game{
    int keyInput;
};

int main() {
    struct game gm;
    struct termios info;
    tcgetattr(0, &info);
    info.c_lflag &= ~ICANON;
    info.c_cc[VMIN] = 1;          
    info.c_cc[VTIME] = 0;        
    tcsetattr(0, TCSANOW, &info);
    

    int a = 0;
    while(1) {
         if((gm.keyInput = getchar())){
            //todo add sleep
            while(a < 1000){
                a++;
            }
            a=0;   
            printf("%d",gm.keyInput);
        }
        
    }
        //move the player
        //check for input
        //reload screen
}