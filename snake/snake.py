
import time
import random
class Game:
    def __init__(self):
        self.snake_pos = []
        self.board = []
       
        
        for i in range(10):
            self.board.append([])
            for j in range(10):
                self.board[i].append(0)
        self.foodPos = self.addFood()
    def draw(self):
        line = ""
        for i in self.board:
            for j in i:
                line += str(j) + " "
            print(line)
            line = ""
    def addPos(self, x, y):
        self.snake_pos.insert(0,[x,y])
        self.board[y][x] = 1
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
            print(self.snake_pos[-1])
            self.snake_pos.pop()
    

    def gameLoop(self):
        self.addPos(1,2)
        self.addPos(1,1)
        keyPressed = "w"
      
        while True:
            self.draw()
            keyPressed = input()
            eating = False
            startX= self.snake_pos[0][0]
            startY= self.snake_pos[0][1]
            time.sleep(1)
            print(self.foodPos, self.snake_pos)
            if(self.snake_pos[0] == self.foodPos):
                print("chomps")
                eating = True
                self.foodPos = self.addFood()
                

            if(keyPressed == "w" and startX > 0):
                self.addPos(startX,startY-1)
            elif(keyPressed == "s" and startX < len(self.board)):
                self.addPos(startX,startY+1)
            elif(keyPressed == "a" and startY > 0):
                self.addPos(startX-1,startY)
            elif(keyPressed == "d" and startY < len(self.board)):
                self.addPos(startX+1,startY)

            if not eating:
                self.removeEnd()

            
           

   
    


                
        

snake = Game()
snake.gameLoop()

