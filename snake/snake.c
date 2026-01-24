#include <inttypes.h>
# include <stdio.h>
# include <termios.h>



int main() {
    
    struct termios info;
    tcgetattr(0, &info);
    info.c_lflag &= ~ICANON;
    info.c_cc[VMIN] = 1;          
    info.c_cc[VTIME] = 0;        
    tcsetattr(0, TCSANOW, &info);


}
    
    
    
   
    
 