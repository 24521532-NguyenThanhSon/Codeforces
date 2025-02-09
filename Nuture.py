import pygame

# Initialize Pygame
pygame.init()

# Define game window dimensions

width = 800
height = 800
window = pygame.display.set_mode((width, height))
pygame.display.set_caption("Simple Direction Game")

# Define colors
black = (0, 0, 0)
white = (255, 255, 255)
green = (0, 255, 0)

# Define the rectangle dimensions
rect_width = 50
rect_height = 50

rect_x = width // 2
rect_y = height // 2

speed = 1000
running = True
clock = pygame.time.Clock()
while running:
    window.fill(black)
    pygame.draw.circle(window, green, (rect_x, rect_y), 30)
    delta_time = clock.tick(60) / 1000 
    for event in pygame.event.get():
        if(event.type == pygame.QUIT):
            running = False
    keys = pygame.key.get_pressed()
    if keys[pygame.K_LEFT]:
        rect_x -= speed * delta_time
    if keys[pygame.K_RIGHT]:
        rect_x += speed * delta_time
    if keys[pygame.K_UP]:
        rect_y -= speed * delta_time
    if keys[pygame.K_DOWN]:
        rect_y += speed * delta_time
    rect_x = max(rect_x, 0)
    rect_x = min(rect_x, width - rect_width)
    rect_y = max(rect_y, 0)
    rect_y = min(rect_y, height - rect_height)

    pygame.display.update()
    clock.tick(1000)
