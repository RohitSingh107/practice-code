
import pygame
import random

# Set up the screen
WIDTH = 800
HEIGHT = 400
BAR_WIDTH = 10
BAR_GAP = 2
FPS = 60

# Colors
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
RED = (255, 0, 0)

# Initialize Pygame
pygame.init()
screen = pygame.display.set_mode((WIDTH, HEIGHT))
clock = pygame.time.Clock()

# Generate a random list of numbers
numbers = [random.randint(1, HEIGHT) for _ in range(WIDTH // (BAR_WIDTH + BAR_GAP))]

# Bubble Sort algorithm
def bubble_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        for j in range(n - 1 - i):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                draw_bars()
                pygame.display.update()
                pygame.time.delay(10)

# Draw the bars on the screen
def draw_bars():
    screen.fill(BLACK)
    for i, num in enumerate(numbers):
        pygame.draw.rect(screen, WHITE, (i * (BAR_WIDTH + BAR_GAP), HEIGHT - num, BAR_WIDTH, num))

# Main game loop
running = True
while running:
    clock.tick(FPS)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Perform Bubble Sort
    bubble_sort(numbers)

    # Draw the bars after sorting is done
    draw_bars()
    pygame.display.update()

pygame.quit()
