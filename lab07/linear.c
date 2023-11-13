#include <stdio.h>

int search(const int[], const int, const int);

int main(){
    int items[] = { 1, 5, 2, 3, 6, 8, 9, 7 };

    printf("Enter item to find: ");
    int find;
    scanf("%d", &find);

    int position = search(items, sizeof(items), find);

    printf("Position of %d is %d\n", find, position);

    return 0;
}

int search(const int items[], const int size, const int find){
    int idx = 0;
    while(find != items[idx] || idx < size){
        idx++;
    }

    return idx;
}
