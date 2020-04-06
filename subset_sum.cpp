// Image <main.c>
// EE 312 practice maze
// Jaxon Coward
// Jsc3536
// Slip days used: <0>
// Spring 2020

#include <stdlib.h>
#include <stdio.h>

typedef struct _maze {
    int rows;
    int cols;
    int **maze;
} Maze;

int Matrix[10][10] =
        {{0, 0, 9, 0, 0, 0, 0, 9, 9, 0},
        {0, 0, 0, 0, 9, 0, 9, 0, 0, 0,},
        {0, 9, 0, 9, 0, 0, 0, 0, 9, 0,},
        {0, 9, 9, 9, 9, 9, 9, 9, 9, 9,},
        {0, 0, 0, 9, 0, 0, 0, 0, 0, 0,},
        {0, 9, 0, 9, 9, 0, 9, 0, 9, 0,},
        {0, 9, 0, 9, 9, 0, 0, 0, 0, 9,},
        {0, 0, 0, 0, 0, 0, 9, 9, 0, 9,},
        {0, 0, 9, 0, 9, 9, 9, 0, 0, 9,},
        {9, 0, 0, 0, 9, 9, 9, 9, 0, -1}};

Maze* mazeAlloc(int rows, int cols);
void mazeInit(Maze *m);
void mazeFree(Maze *m);

int min(int a, int b) {
    return a < b ? a : b;
}
int max(int a, int b) {
    return a > b ? a : b;
}

/* A. Allocate (and return) an maze on the heap. Also initialize all
* attributes of the allocated maze based on the given arguments.
* You do not have to initialize each space to any specific value. */
Maze* mazeAlloc(int rows, int cols) {
    Maze* m = (Maze*)malloc(sizeof(Maze));
    m->cols = cols;
    m->rows = rows;
    m->maze = (int**)malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; i++){
        m->maze[i] = (int*)malloc(cols * sizeof(int));
    }

    return m;
}

/* B. Initialize the given maze (which is already allocated) to
* random values. Each pixel should have value between 0 and 255
* (inclusive). Do *not* change number of columns and rows. */
void mazeInit(Maze *m) {
    int rows = m->rows;
    int cols = m->cols;

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            m->maze[i][j] = Matrix[i][j];
        }
    }
}

/* C. Free everything related to the given maze (and the maze) from
* the heap. */
void mazeFree(Maze *m) {
    for(int i = 0; i < m->rows; i++){
        free(m->maze[i]);
    }
    free(m->maze);
    free(m);
    m = NULL;
}

void mazePrint(Maze *m) {
    int rows = m->rows;
    int cols = m->cols;
    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if(m->maze[i][j] == 9)
                printf("   ");
            else
                printf("%d  ", m->maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int checkSpot(Maze* m, int r, int c){
    if(r >= 0 && r < m->rows && c >= 0 && c < m->cols) {
        if(m->maze[r][c] == 0 || m->maze[r][c] == -1)
            return 1;
    }
    return 0;
}

int findPath(Maze* m, int r, int c){
    if(r >= 0 && r < m->rows && c >= 0 && c < m->cols){
        if(m->maze[r][c] == -1)
            return 1;

        m->maze[r][c] = 5;

        if(checkSpot(m, r, c+1)) {
            if (findPath(m, r, c+1)){
                m->maze[r][c] = 1;
                return 1;
            }
        }
        if(checkSpot(m, r+1, c)){
            if(findPath(m, r+1, c)) {
                m->maze[r][c] = 1;
                return 1;
            }
        }
        if(checkSpot(m, r, c-1)){
            if(findPath(m, r, c-1)){
                m->maze[r][c] = 1;
                return 1;
            }
        }
        if(checkSpot(m, r-1, c)){
            if(findPath(m, r-1, c)){
                m->maze[r][c] = 1;
                return 1;
            }
        }
    }
    return 0;
}

/* F. Write a program that creates one image, blurs the image, and
* frees allocated space. */
int main(void) {
    Maze* m = mazeAlloc(10, 10);
    mazeInit(m);

    mazePrint(m);
    findPath(m, 0, 0);
    mazePrint(m);

    mazeFree(m);
}
