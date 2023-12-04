#include <stdio.h>
#include <string.h>
void draw(const int height, const int width, char world[][width+1]);
char change_direction(const int x, const int y, const int finish_x, const int finish_y, const char direction);
char find_cow(const int height, const int width, int *x, int *y, char world[][width+1]);
void find_finish(const int height, const int width, int *finish_x, int *finish_y, char world[][width+1]);
int solve_maze(const int height, const int width, char world[][width+1]);

int main(int argc, char *argv[]){
    if(argc < 2){
        printf("Error: Too few arguments\n");
        return 1;
    }
    char filename[20];

    strcpy(filename, argv[1]);
    FILE *fp = NULL;
    fp = fopen(filename, "r");
    int height, width;
    fscanf(fp, "%d %d ", &width, &height);
    char world[height][width+1];
    for(int i=0; i<height; i++){
        fgets(world[i], width+1, fp);        
        fgetc(fp);
    }
    draw(height, width, world);
    solve_maze(height, width, world);
    draw(height, width, world);
    fclose(fp);
    return 0;
}

void draw(const int height, const int width, char world[][width+1]){
    for(int i=0; i<height; i++){
        printf("%s", world[i]);
        putchar('\n');
    }
}

char find_cow(const int height, const int width, int* x, int* y, char world[][width+1]){
    for(int idx_h=0; idx_h<height; idx_h++){
        for(int idx_w=0; idx_w<width; idx_w++){
            if(world[idx_h][idx_w] == 'W' || world[idx_h][idx_w] == 'E' || world[idx_h][idx_w] == 'S' || world[idx_h][idx_w] == 'N'){
                *x = idx_w;
                *y = idx_h;
                return world[idx_h][idx_w];
            }
        }
    }
    return 'E';
}

void find_finish(const int height, const int width, int* finish_x, int* finish_y, char world[][width+1]){
    for(int idx_h=0; idx_h<height; idx_h++){
        for(int idx_w=0; idx_w<width; idx_w++){
            if(world[idx_h][idx_w] == 'F'){
                *finish_x = idx_w;
                *finish_y = idx_h;
            }
        }
    }
}

char change_direction(const int x, const int y, const int finish_x, const int finish_y, const char direction){
    if(direction == 'N' || direction == 'S'){
        return ((x < finish_x) ? 'E' : 'W'); 
    }
    return ((y < finish_y) ? 'S' : 'N');
}

int solve_maze(const int height, const int width, char world[height][width+1]){
    int x, y, finish_x, finish_y;
    char direction = find_cow(height, width, &x, &y, world);
    find_finish(height, width, &finish_x, &finish_y, world);

    int direction_changes = 0;
    char previous = world[y][x];

    while(world[y][x] != 'F'){
        int next_x = (direction == 'W') ? x-1 : (direction == 'E') ? x+1 : x;
        int next_y = (direction == 'N') ? y-1 : (direction == 'S') ? y+1 : y;

        char next = world[next_y][next_x];
        if(next == 'X'){
            if(previous == 'X'){
                direction_changes -= 1;
                break;
            }
            direction = change_direction(x, y, finish_x, finish_y, direction);
            world[y][x] = (direction == 'N') ? '^' : (direction == 'S') ? 'v' : (direction == 'E') ? '>' : (direction == 'W') ? '<' : ' ';
            direction_changes++;
            previous = 'X';
        } else {
            x = next_x;
            y = next_y;
            previous = ' ';
        }
    }
    return direction_changes;
}
