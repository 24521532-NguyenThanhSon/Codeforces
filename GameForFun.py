import pygame

# Initialize Pygame
pygame.init()

# Define game window dimensions
width = 800
height = 600
window = pygame.display.set_mode((width, height))

# Set window title
pygame.display.set_caption("Simple Keyboard Interaction Game")

# Define colors
black = (0, 0, 0)
white = (255, 255, 255)
green = (0, 255, 0)

# Define the rectangle dimensions
rect_width = 50
rect_height = 50

# Starting position of the rectangle
rect_x = width // 2
rect_y = height // 2

# Define the speed at which the rectangle moves (adjustable)
speed = 2000  # Pixels per second (adjust as needed)

# Clock object to control the frame rate
clock = pygame.time.Clock()

# Main game loop
running = True
while running:
    # Get the time passed since the last frame (delta time)
    delta_time = clock.tick(60) / 1000  # in seconds

    # Fill the screen with black
    window.fill(black)

    # Draw the rectangle on the screen
    pygame.draw.rect(window, green, (rect_x, rect_y, rect_width, rect_height))

    # Check for events (keyboard input, window close)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Check for key presses to move the rectangle
    keys = pygame.key.get_pressed()
    
    if keys[pygame.K_LEFT]:
        rect_x -= speed * delta_time  # Move left
    if keys[pygame.K_RIGHT]:
        rect_x += speed * delta_time  # Move right
    if keys[pygame.K_UP]:
        rect_y -= speed * delta_time  # Move up
    if keys[pygame.K_DOWN]:
        rect_y += speed * delta_time  # Move down

    # Prevent the rectangle from going off-screen
    if rect_x < 0:
        rect_x = 0
    if rect_x > width - rect_width:
        rect_x = width - rect_width
    if rect_y < 0:
        rect_y = 0
    if rect_y > height - rect_height:
        rect_y = height - rect_height

    # Update the display
    pygame.display.update()

    # Set the frame rate to 60 frames per second
    clock.tick(1000)  # Keep this at 60 FPS

# Quit Pygame when the game loop ends
pygame.quit()
