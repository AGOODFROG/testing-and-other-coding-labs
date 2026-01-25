
import time
import random
class Game:
    def __init__(self):
        self.snake_pos = []
        self.board = []
        self.prevSnakeSize = 1
        self.size = 10
        #make
        for i in range(self.size):
            self.board.append([])
            for j in range(self.size):
                self.board[i].append(0)
        self.foodPos = self.addFood()
    #done
    def draw(self):
        line = ""
        for i in self.board:
            for j in i:
                line += str(j) + " "
            print(line)
            line = ""
    def addPos(self, x, y):
        self.deathLogic(x,y)
        self.snake_pos.insert(0,[x,y])
        self.board[y][x] = 1
        self.prevSnakeSize = len(self.snake_pos) -1
    def addFood(self):
        foodX = random.randint(0,9)
        foodY = random.randint(0,9)
        self.board[foodY][foodX] = 2
        return [foodX, foodY]
    
    def removeEnd(self):
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

