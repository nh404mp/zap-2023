#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define START 1
#define END 100
#define ATTEMPT 5

int get_guess(int attempt);
int get_secret(const int start, const int end);
void clear_buffer();
int main(){
    srand(time(NULL));
    char answer = 'y';
    do{    
    printf("Pick a number between %d and %d.\n", START, END);
    int secret = get_secret(START, END);
    int attempt = 1;

        do{
            int guess = get_guess(attempt);
            if(guess > secret){
                printf("Hmm... My number is smaller than yours\n");
            } else if(guess < secret){
                printf("Hmm... My number is bigger than yours.\n");
            } else if(guess == secret){
                printf("Congratulations! You found it!\n");
                return 0;
            }
            if(attempt == ATTEMPT){
            printf("Game over. My number was %d.\n", secret);
            }
            attempt++;
        } while(attempt <= ATTEMPT);
        clear_buffer();
        printf("Play again? (y/n)");
        scanf("%c", &answer);
        clear_buffer();
    } while(answer == 'y');     
    return 0;
}

void clear_buffer(){
    while(getchar() != '\n')
        ;
}
int get_guess(int attempt){
    printf("Your %d. guess: ", attempt);
    int guess;
    scanf("%d", &guess);
    return guess;
}

int get_secret(const int start, const int end){
    return (rand() % (end - start + 1)) + start;
}
