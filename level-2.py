#%%
import pygame
import random

# Initialize the game engine
pygame.init()
frame_count = 0
frame_rate = 20
start_time = 30
font = pygame.font.Font(None, 25)
bullet=[]
bulletx=[]
bullety=[]
BLUE=[0,0,255]
BLACK = [0, 0, 0]
WHITE = [255, 255, 255]
GREEN=[255,0,0]
update=0
flag=False
# Set the height and width of the screen
SIZE = [400, 400]

screen = pygame.display.set_mode(SIZE)
pygame.display.set_caption("Snow Game level-2")

# Create an empty array
ball_list = []

# Loop 50 times and add a snow flake in a random x,y position
for i in range(70):
    x = random.randrange(0, 400)
    y = random.randrange(0, 360)
    ball_list.append([x, y])
xbig=200
ybig=400
pygame.draw.circle(screen, GREEN, [xbig,ybig], 120)
clock = pygame.time.Clock()
listf=[]
# Loop until the user clicks the close button.
done = False
while not done:

    for event in pygame.event.get():  # User did something
        if event.type == pygame.QUIT:  # If user clicked close
            done = True  # Flag that we are done so we exit this loop
        if event.type==pygame.KEYDOWN:

            if event.key == pygame.K_LEFT:
                update = -3
            elif event.key == pygame.K_RIGHT:
                update = 3
            elif event.key == pygame.K_UP:
                flag=True
        elif event.type == pygame.KEYUP:
                # If it is an arrow key, reset vector back to zero
            if event.key == pygame.K_LEFT or event.key == pygame.K_RIGHT:
                update = 0
            elif event.key == pygame.K_UP or event.key == pygame.K_DOWN:
                flag = False

    # Set the screen background
    screen.fill(BLACK)
    #gun update
    xbig=xbig+update
    pygame.draw.circle(screen, GREEN, [xbig, ybig], 18)

    if(flag==True):
        bullet.append([xbig,ybig])
       # pygame.draw.circle(screen, GREEN, [xbig, ybig], 4)

    # Process each bullet in the list
    for i in range(len(bullet)):
        pygame.draw.circle(screen, GREEN, [bullet[i][0], bullet[i][1]], 4)
        bullet[i][1]=bullet[i][1]-22
        bulletx.append(bullet[i][0])
        bullety.append(bullet[i][1])
        #if (bullet[i][1]<0):
         #    bullet.remove(bullet[i])



    count=0
    # Process each snow flake in the list
    for i in range(len(ball_list)):

        # Draw the snow flake

        pygame.draw.circle(screen, WHITE, ball_list[i], 6)
        xy = ball_list[i]
         
        #print(xy)
        listx = [m for m in range(xy[0] - 10, xy[0] + 10)]
        listy = [m for m in range(xy[1] - 10, xy[1] + 10)]
        for p in range(len(listx)):
            if(listx[p] in bulletx ):
                pygame.draw.circle(screen, BLACK, ball_list[i], 6)
                count=count+1
        #pygame.draw.circle(screen, WHITE, ball_list[i], 10)
    output_string = "score:{}".format(count)
    text = font.render(output_string, True,BLUE)
    screen.blit(text, [270, 350])







    # Go ahead and update the screen with what we've drawn.
    total_seconds = start_time - (frame_count // frame_rate)
    if total_seconds < 0:
        total_seconds = 0
        pygame.quit()


    # Divide by 60 to get total minutes
    minutes = total_seconds // 60

    # Use modulus (remainder) to get seconds
    seconds = total_seconds % 60
    
    if seconds==0:
        pygame.quit()
        quit()


    # Use python string formatting to format in leading zeros
    output_string = "Time left: {0:01}:{1:02}".format(minutes, seconds)

    # Blit to the screen
    text = font.render(output_string, True, BLUE)

    screen.blit(text, [270, 380])

    


    # ALL CODE TO DRAW SHOULD GO ABOVE THIS COMMENT
    frame_count += 1
    pygame.display.flip()
    clock.tick(20)

# Be IDLE friendly. If you forget this line, the program will 'hang'
# on exit.
pygame.quit()

#%%