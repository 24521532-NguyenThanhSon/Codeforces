import pygame
import random
pygame.init()
width = 2000
height = 1000
window = pygame.display.set_mode((width, height))
pygame.display.set_caption("Osu made in Vietnamese")
running = True

# colors
# rand
black = (0, 0, 0)
white = (255, 255, 255)
red = (213, 50, 80)
green = (0, 255, 0)
blue = (0, 0, 255)
yellow = (255, 255, 0)
cyan = (0, 255, 255)
magenta = (255, 0, 255)
orange = (255, 165, 0)
purple = (128, 0, 128)
pink = (255, 192, 203)
brown = (139, 69, 19)
gray = (128, 128, 128)
light_gray = (211, 211, 211)
dark_gray = (64, 64, 64)
gold = (255, 215, 0)
lime = (50, 205, 50)
navy = (0, 0, 128)
teal = (0, 128, 128)
maroon = (128, 0, 0)
olive = (128, 128, 0)
clock = pygame.time.Clock()
speed = 4000
Radius = 60
pos_x = width // 2
pos_y = width // 2
amount = 20
Score = 0
Frames = 0
font = pygame.font.Font(None, 100)  # Use a default font with size 36

Lis = dict()
def Random_Color():
    color = (random.randint(0, 255), random.randint(0, 255), random.randint(0, 255))
    return color
class Point:
    def __init__(self, col, radius, x, y):
        self.col = col
        self.radius = radius
        self.x = x
        self.y = y
for i in range(1, 20):
    Lis[i] = Point(Random_Color(), 60, random.randint(0, width), random.randint(0, height))
while running:
    delta_time = clock.tick(100) / 1000
    text = f"Score: {Score}"
    text_surface = font.render(text, True, blue)

    window.fill(black)

    elapsed_time = (pygame.time.get_ticks()) // 1000
    Time = f"Time: {elapsed_time}"  

    Time_surface = font.render(Time, True, green)
    window.blit(text_surface, (800, 10))  # Position the label at (100, 100)
    window.blit(Time_surface, (100, 10))
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
    pygame.draw.circle(window, magenta, (pos_x, pos_y), Radius)
    
    keys = pygame.key.get_pressed()
    if(keys[pygame.K_LEFT]):
        pos_x -= speed * delta_time
    if(keys[pygame.K_RIGHT]):
        pos_x += speed * delta_time
    if(keys[pygame.K_UP]):
        pos_y -= speed * delta_time
    if(keys[pygame.K_DOWN]):
        pos_y += speed * delta_time
    pos_x = max(pos_x, Radius)
    pos_x = min(pos_x, width - Radius)
    pos_y = max(pos_y, Radius)
    pos_y = min(pos_y, height - Radius) 

    if(keys[pygame.K_x] or keys[pygame.K_c]):
        for i in range(1, 20):
            if((pos_x - Lis[i].x) * (pos_x - Lis[i].x) + (pos_y - Lis[i].y) * (pos_y - Lis[i].y) <= Radius * Radius):
                Lis[i] = Point(Random_Color(), 60, random.randint(0, width), random.randint(0, height))
                Score = Score + 1
    for i in range(1, 20):
        pygame.draw.circle(window, Lis[i].col, (Lis[i].x, Lis[i].y), Lis[i].radius)
    pygame.display.update()
    clock.tick(100)
