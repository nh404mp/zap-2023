#include <karel.h>

void turn_right();
void climb_stair();
bool right_is_clear();
bool right_is_blocked();
bool left_is_clear();
bool left_is_blocked();
int main(){
    turn_on("stairs3.kw");
    set_step_delay(100);
    step();
    while(front_is_clear() == false){
        climb_stair();
    }
    while(beepers_in_bag()){
        put_beeper();
    } 
    turn_off();
    return 0;
}

void turn_right(){
    turn_left();
    turn_left();
    turn_left();
}

void climb_stair(){
    turn_left();
    while(right_is_blocked()){
        step();
    }
    turn_right();
    step();
    while(beepers_present()){
        pick_beeper();
    }
}

bool right_is_clear(){
    turn_right();
    if(front_is_clear()){
        turn_left();
        return true;
    }
    turn_left();
    return false;
}

bool right_is_blocked(){
    if(right_is_clear()){
        return false;
    }
    return true;
}

bool left_is_clear(){
    turn_left();
    if(front_is_clear()){
        turn_right();
        return true;
    }
    turn_right();
    return false;
}

bool left_is_blocked(){
    if(left_is_clear()){
        return false;
    }
    return true;
}
