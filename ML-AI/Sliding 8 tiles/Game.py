
#importing modules
import pygame
import os ,sys




width=260
height = 250

pygame.init()

pygame.display.set_caption("8-Tiles Sliding Game")


gameDisplay = pygame.display.set_mode((width,height))


Gboard=[
    [5,8,7],
    [4,0,3],
    [2,6,1]]
#empty tile coordinates
Ex=1 
Ey=1

n=3

application_path = os.path.dirname(__file__)
application_path=application_path.replace('\\','/')

Redtile=pygame.image.load(application_path+"/redimg.jpg")

BlankTile=pygame.image.load(application_path+"/blank.jpg")



def navigate(dir,Ex,Ey):
    if(dir=="D"):
        if(Ey+1<n):
            temp=Gboard[Ey+1][Ex]
            Gboard[Ey+1][Ex]=Gboard[Ey][Ex]
            Gboard[Ey][Ex]=temp
           
            Ey+=1
            
    elif(dir=="U"):
        if(Ey-1>=0):
            temp=Gboard[Ey-1][Ex]
            Gboard[Ey-1][Ex]=Gboard[Ey][Ex]
            Gboard[Ey][Ex]=temp
            Ey-=1
    elif(dir=="L"):
        if(Ex-1>=0):
            temp=Gboard[Ey][Ex-1]
            Gboard[Ey][Ex-1]=Gboard[Ey][Ex]
            Gboard[Ey][Ex]=temp
            Ex-=1
    elif(dir=="R"):
        if(Ex+1<n):
            temp=Gboard[Ey][Ex+1]
            Gboard[Ey][Ex+1]=Gboard[Ey][Ex]
            Gboard[Ey][Ex]=temp
            Ex+=1
    return Ex,Ey

        


playing=True
while playing:
   
    for x in range(0,n):
        for y in range(0,n):
        
            font = pygame.font.Font('Action_Man.ttf', 30)
            tileNum=font.render(str(Gboard[x][y]), True, (0, 0, 0)).convert_alpha()
            
            if Gboard[x][y]==0:
                gameDisplay.blit(BlankTile, (y*80+10,x*80+10))
                continue
            else:
                gameDisplay.blit(Redtile, (y*80+10,x*80+10))
               
            gameDisplay.blit(tileNum,(y*80+30,x*80+30) )
            
            
            
    # Capture frame-by-frame
    for event in pygame.event.get():
        if event.type == pygame.QUIT: 
            pygame.quit();sys.exit()
            playing = False
        if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_UP:
                   Ex,Ey=navigate("U",Ex,Ey)
                if event.key == pygame.K_LEFT:
                    Ex,Ey= navigate("L",Ex,Ey)
                if event.key == pygame.K_RIGHT:
                    Ex,Ey=navigate("R",Ex,Ey)
                if event.key == pygame.K_DOWN:
                    Ex,Ey=navigate("D",Ex,Ey)
    
    pygame.display.update()

pygame.quit()    