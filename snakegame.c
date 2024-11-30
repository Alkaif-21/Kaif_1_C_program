#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define WIDTH 20
#define HEIGHT 20

// Directions
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

// Game variables
int snakeX[100], snakeY[100];  // Snake body
int snakeLength = 1;
int foodX, foodY;              // Food position
int direction = RIGHT;         // Initial direction
int gameOver = 0;

// Function prototypes
void initializeGame();
void drawGame();
void moveSnake();
void spawnFood();
void checkCollision();
void updateDirection();

int main() {
    initializeGame();
    while (!gameOver) {
        drawGame();
        updateDirection();
        moveSnake();
        checkCollision();
        _sleep(100);  // Slow down the game
    }
    printf("Game Over! Your score: %d\n", snakeLength - 1);
    return 0;
}

// Initialize the game
void initializeGame() {
    snakeX[0] = WIDTH / 2;  // Start in the middle
    snakeY[0] = HEIGHT / 2;
    spawnFood();
}

// Draw the game field
void drawGame() {
    system("cls");
    for (int i = 0; i < WIDTH + 2; i++) printf("#");  // Top border
    printf("\n");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j == 0) printf("#");  // Left border
            int isSnake = 0;
            for (int k = 0; k < snakeLength; k++) {
                if (snakeX[k] == j && snakeY[k] == i) {
                    printf("O");  // Snake body
                    isSnake = 1;
                    break;
                }
            }
            if (foodX == j && foodY == i)
                printf("F");  // Food
            else if (!isSnake)
                printf(" ");
            if (j == WIDTH - 1) printf("#");  // Right border
        }
        printf("\n");
    }
    for (int i = 0; i < WIDTH + 2; i++) printf("#");  // Bottom border
    printf("\n");
    printf("Score: %d\n", snakeLength - 1);
}

// Move the snake
void moveSnake() {
    // Move the body
    for (int i = snakeLength - 1; i > 0; i--) {
        snakeX[i] = snakeX[i - 1];
        snakeY[i] = snakeY[i - 1];
    }
    // Move the head
    switch (direction) {
        case UP: snakeY[0]--; break;
        case DOWN: snakeY[0]++; break;
        case LEFT: snakeX[0]--; break;
        case RIGHT: snakeX[0]++; break;
    }
}

// Spawn food at a random position
void spawnFood() {
    foodX = rand() % WIDTH;
    foodY = rand() % HEIGHT;
}

// Check for collisions
void checkCollision() {
    // Check if the snake eats the food
    if (snakeX[0] == foodX && snakeY[0] == foodY) {
        snakeLength++;
        spawnFood();
    }

    // Check if the snake collides with walls
    if (snakeX[0] < 0 || snakeX[0] >= WIDTH || snakeY[0] < 0 || snakeY[0] >= HEIGHT) {
        gameOver = 1;
    }

    // Check if the snake collides with itself
    for (int i = 1; i < snakeLength; i++) {
        if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i]) {
            gameOver = 1;
        }
    }
}

// Update direction based on user input
void updateDirection() {
    if (_kbhit()) {  // Check if a key is pressed
        switch (_getch()) {
            case 'w': if (direction != DOWN) direction = UP; break;
            case 's': if (direction != UP) direction = DOWN; break;
            case 'a': if (direction != RIGHT) direction = LEFT; break;
            case 'd': if (direction != LEFT) direction = RIGHT; break;
        }
    }
}