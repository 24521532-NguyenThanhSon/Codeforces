import tkinter as tk
import random

class SnakeGame:
    def __init__(self, root):
        self.root = root
        self.root.title("Snake Game")
        self.root.resizable(False, False)
        self.canvas = tk.Canvas(self.root, width=400, height=400, bg="black")
        self.canvas.pack()

        self.snake = [(20, 20), (40, 20), (60, 20)]
        self.snake_size = 20
        self.food = None
        self.food_size = 20
        self.direction = "Right"
        self.running = True

        self.create_objects()
        self.root.bind("<KeyPress>", self.change_direction)
        self.move_snake()

    def create_objects(self):
        self.snake_rects = []
        for segment in self.snake:
            rect = self.canvas.create_rectangle(
                segment[0], segment[1],
                segment[0] + self.snake_size, segment[1] + self.snake_size,
                fill="green"
            )
            self.snake_rects.append(rect)
        self.create_food()

    def create_food(self):
        x = random.randint(0, (400 // self.food_size) - 1) * self.food_size
        y = random.randint(0, (400 // self.food_size) - 1) * self.food_size
        self.food = (x, y)
        self.food_rect = self.canvas.create_oval(
            x, y, x + self.food_size, y + self.food_size, fill="red"
        )

    def move_snake(self):
        if not self.running:
            return

        head_x, head_y = self.snake[-1]
        if self.direction == "Right":
            head_x += self.snake_size
        elif self.direction == "Left":
            head_x -= self.snake_size
        elif self.direction == "Up":
            head_y -= self.snake_size
        elif self.direction == "Down":
            head_y += self.snake_size

        new_head = (head_x, head_y)

        # Check for collisions with walls
        if head_x < 0 or head_y < 0 or head_x >= 400 or head_y >= 400:
            self.end_game()
            return

        # Check for collisions with self
        if new_head in self.snake:
            self.end_game()
            return

        # Add new head
        self.snake.append(new_head)
        rect = self.canvas.create_rectangle(
            head_x, head_y,
            head_x + self.snake_size, head_y + self.snake_size,
            fill="green"
        )
        self.snake_rects.append(rect)

        # Check if snake eats food
        if new_head == self.food:
            self.canvas.delete(self.food_rect)
            self.create_food()
        else:
            # Remove tail
            tail = self.snake.pop(0)
            self.canvas.delete(self.snake_rects.pop(0))

        self.root.after(100, self.move_snake)

    def change_direction(self, event):
        new_direction = event.keysym
        if (
            (new_direction == "Right" and self.direction != "Left") or
            (new_direction == "Left" and self.direction != "Right") or
            (new_direction == "Up" and self.direction != "Down") or
            (new_direction == "Down" and self.direction != "Up")
        ):
            self.direction = new_direction

    def end_game(self):
        self.running = False
        self.canvas.create_text(
            200, 200, text="Game Over", fill="white", font=("Arial", 24)
        )

if __name__ == "__main__":
    root = tk.Tk()
    game = SnakeGame(root)
    root.mainloop()
