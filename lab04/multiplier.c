#include <superkarel.h>

void turn_right();
void double_row();
void double_all_beepers();
void move_up();
bool is_in_corner();
void go_to_corner();
int main(){
    turn_on("multiplier.kw");
    set_step_delay(200);
    go_to_corner();
    while(is_in_corner() == false){
        double_row();
        move_up();
    }
    turn_off();
    return 0;
}

void turn_right(){
    set_step_delay(0);
    turn_left();
    turn_left();
    set_step_delay(200);
    turn_left();
}

void double_row(){
    while(front_is_clear()){
        double_all_beepers();
        step();
    }
    double_all_beepers();
}

void double_all_beepers(){
    if(beepers_present()){
        pick_beeper();
        double_all_beepers();
        put_beeper();
        put_beeper();
    }
}

void move_up(){
    if(facing_east() && left_is_clear()){
        turn_left();
        step();
        turn_left();
    } else if(facing_west() && right_is_clear()){
        turn_right();
        step();
        turn_right();
    }
}

bool is_in_corner(){
    if(facing_east()){
        if(front_is_blocked() && left_is_blocked()){
            return true;
        } else {
            return false;
        }
    } else if(facing_west()){
        if(front_is_blocked() && right_is_blocked()){
            return true;
        } else {
            return false;
        }
    }
    return false;
}

void go_to_corner(){
    while(not_facing_west()){
        turn_left();
    }
    while(front_is_clear()){
        step();
    }
    turn_left();
    while(front_is_clear()){
        step();
    }
    turn_left();
}
