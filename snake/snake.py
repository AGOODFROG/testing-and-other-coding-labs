
import time
import random
class Game:
    def __init__(self):
        '''
        make the 10 by 10 gird
        set snake_size to 1
        set board size to 1
        '''
        self.snake_pos = []
        self.board = []
        self.prevSnakeSize = 1
        self.size = 10
       
        for i in range(self.size):
            self.board.append([])
            for j in range(self.size):
                self.board[i].append(0)
        self.foodPos = self.addFood()
    def draw(self):
        '''
        iterate over every val in the board array and print
        '''
        line = ""
        for i in self.board:
            for j in i:
                line += str(j) + " "
            print(line)
            line = ""
    def addPos(self, x, y):
        '''
        check if the snake should die
        add the new pos to the first index of the snakepos list
        set the board to be snake
        set the prevSnakeSize to the len of snake size -1
        '''
        self.deathLogic(x,y)
        self.snake_pos.insert(0,[x,y])
        self.board[y][x] = 1
        self.prevSnakeSize = len(self.snake_pos) -1
    def addFood(self):
        '''
        set food x and y to be random pos on the board
        turn the pos chosen to be food
        return the x and y values
        '''
        foodX = random.randint(0,9)
        foodY = random.randint(0,9)
        self.board[foodY][foodX] = 2
        return [foodX, foodY]
    
    def removeEnd(self):
        '''
        if the snake has one block exit
        else
            set the last x and y val to a var (endX and endY)
            set the end vars to emtry/ not zero
            remove the last elemtn from the snake list
        '''
        if len(self.snake_pos) == 1:
            return
        else:
            endX = self.snake_pos[-1][0]
            endY = self.snake_pos[-1][1]
            self.board[endY][endX] = 0
            self.snake_pos.pop()
    def deathLogic(self, x ,y):
        if(x < 0 or x > self.size or y < 0 or y > self.size):
            raise ValueError("YOU HIT THE WALL YOU FOOOOOL")
        findCount = 0
        pos = [x ,y]
        for i in self.snake_pos:
            if pos == i:
                findCount += 1
        print(findCount)
        if findCount > 0:
            raise ValueError("you have hit yourself and died")
 
    def gameLoop(self):
        self.addPos(1,1)
        keyPressed = "w"
        while True:
           
            self.draw()
            keyPressed = input()
            eating = False
            startX= self.snake_pos[0][0]
            startY= self.snake_pos[0][1]
            time.sleep(1)
            if(self.snake_pos[0] == self.foodPos):
                print("chomps")
                eating = True
                self.foodPos = self.addFood()
                
            
            if(keyPressed == "w" and startX >= 0):
                self.addPos(startX,startY-1)
            elif(keyPressed == "s" and startX <= len(self.board)):
                self.addPos(startX,startY+1)
            elif(keyPressed == "a" and startY >= 0):
                self.addPos(startX-1,startY)
            elif(keyPressed == "d" and startY <= len(self.board)):
                self.addPos(startX+1,startY)
           
            if not eating:
                self.removeEnd()
            

            

            
           

   
    


                
        

snake = Game()
snake.gameLoop()

