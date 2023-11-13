#include <stdio.h>
void draw(const int size, char field[][size]);
int add_cross(const int size, char field[][size], const int x, const int y, const char player);
int is_solved(const int size, char field[][size]);
int main(){

    char player = B;
    int size = 0;
    do {
        printf("Enter the size of field: ");
        scanf("%d", &size);
    } while(size < 4 || size > 9);
    char field[size][size];
    for(int y = 0; y < size; y++){
        for(int x = 0; x < size; x++){
            field[y][x] =  ;
        }
    }
    draw(size, field);
    do {
        player = (player == B) ? A : B;
        printf("Player %c: ", player);
        int x, y;
        scanf("%d %d", &x, &y);
        add_cross(size, field, x, y, player);
        draw(size, field);
    } while(is_solved(size, field) == 0);
    printf("Player %c wins!\n", player);
    return 0;
}

void draw(const int size, char field[][size]){
    for(int y = 0; y < size; y++){
        printf("  ");
        for(int i = 0; i < size; i++){
            printf("+-");
        }
        printf("+\n");
        printf("%d ", size-y);
        for(int i = 0; i < size; i++){
            printf("|%c", field[y][i]);
        }
        printf("|\n");
    }
    printf("  ");
    for(int i = 0; i < size; i++){
        printf("+-");
    }
    printf("+\n");
    printf("  ");
    for(int i = 0; i < size; i++){
        printf(" %d", i+1);
    }
    printf(" \n");
}

int add_cross(const int size, char field[][size], const int x, const int y, const char player){
    if(x < 1 || x > size || y < 1 || y > size){
        printf("Wrong position!\n");
        return -1;
    }
    if(field[size-y][x-1] == X || field[size-y][x-1] == O){
        return 0;
    }
    field[size-y][x-1] = (player == B) ? O : X;
    return 1;
}

int is_solved(const int size, char field[][size]){
    for(int y = 0; y < size - 2; y++){
        for(int x = 0; x < size - 2; x++){
            char tmp = field[y][x];
            if(tmp !=  ){
                if(field[y][x+1] == tmp && field[y][x+2] == tmp){
                    return 1;
                }
                if(field[y+1][x] == tmp && field[y+2][x] == tmp){
                    return 1;
                }
                if(field[y+1][x+1] == tmp && field[y+2][x+2] == tmp){
                    return 1;
                }
            }
        }
    }
    for(int y = 0; y < size - 2; y++){
        for(int x = 2; x < size; x++){
            char tmp = field[y][x];
            if(tmp !=   && field[y+1][x-1] == tmp && field[y+2][x-2] == tmp){
                    return 1;
            }
        }
    }
    return 0;
}
