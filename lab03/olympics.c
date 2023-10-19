#include <superkarel.h>

void jump_over();
void turn_right();
int main(){
    turn_on("olympics5.kw");
    set_step_delay(200);
    while(beepers_present() == false){
        jump_over();
        while(front_is_clear() && no_beepers_present()){
            step();
        }
    }
    turn_off();
    return 0;
}

void jump_over(){
    turn_left();
    while(right_is_blocked()){
        step();
    }
    turn_right();
    step();
    while(right_is_blocked()){
        step();
    }
    turn_right();
    step();
    while(front_is_clear()){
        step();
    }
    turn_left();
}

void turn_right(){
    turn_left();
    turn_left();
    turn_left();
}
