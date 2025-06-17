#include <cstdio>
#include "motion.h"

// this file contains functions for writing each character
// the robot will be starting each character at the bottom left most
// and will be ending each character at the bottom right most



// offset from character to character
void offset() {
    turn_right(85);
    move_forward(0.5);
    turn_left(83);
}



// letters A-Z

void writeA() {
    turn_right(41.5);
    move_forward(1.0);
    move_backward(0.5);
    turn_right(41.5);
    move_forward(0.5);
    turn_left(83);
    move_forward(0.5);
    move_backward(1.0);
    turn_right(41.5);
    offset();
}

void writeB() {
    move_forward(1.0);
    turn_right(83);
    move_forward(0.5);
    turn_right(83);
    move_forward(0.5);
    turn_right(83);
    move_forward(0.5);
    move_backward(0.5);
    turn_left(83);
    move_forward(0.5);
    turn_right(83);
    move_forward(0.5);
    move_backward(0.5);
    turn_right(83);
    offset();
}

void writeC() {
    move_forward(1.0);
    turn_right(83);
    move_forward(0.5);
    move_backward(0.5);
    turn_left(83);
    move_backward(1.0);
    turn_right(83);
    move_forward(0.5);
    turn_left(83);
    offset();
}

void writeD() {
    move_forward(1.0);
    turn_right(83);
    turn_right(41.5);
    move_forward(0.25);
    turn_right(41.5);
    move_forward(0.78);
    turn_right(41.5);
    move_forward(0.25);
    turn_right(41.5);
    turn_right(83);
    turn_right(83);
    move_forward(0.75);
    turn_left(83);

    offset();
    
}

void writeE() {
    move_forward(1.0);
    turn_right(85);
    move_forward(0.5);
    move_backward(0.5);
    turn_left(83);
    move_backward(0.5);
    turn_right(85);
    move_forward(0.4);
    move_backward(0.4);
    turn_left(83);
    move_backward(0.5);
    turn_right(85);
    move_forward(0.5);
    turn_left(83);
    offset();
}

void writeF() {
    move_forward(1.0);
    turn_right(83);
    move_forward(0.5);
    move_backward(0.5);
    turn_left(83);
    move_backward(0.15);
    turn_right(83);
    move_forward(0.4);
    move_backward(0.4);
    turn_left(83);
    move_backward(0.35);
    turn_right(83);
    move_forward(0.5);
    turn_left(83);
    offset();
}

void writeG() {
    move_forward(1.0);
    turn_right(83);
    move_forward(0.5);
    move_backward(0.5);
    turn_left(83);
    move_backward(1.0);
    turn_right(83);
    move_forward(0.5);
    turn_left(83);
    move_forward(0.3);
    turn_left(83);
    move_forward(0.15);
    move_backward(0.15);
    turn_left(83);
    move_forward(0.3);
    turn_left(83);
    turn_left(83);
    offset();
}

void writeH() {
    move_forward(1.0);
    move_backward(0.5);
    turn_right(85);
    move_forward(0.5);
    turn_left(83);
    move_forward(0.5);
    move_backward(1.0);
    offset();

}

void writeI() {
    move_forward(1.0);
    turn_right(83);
    move_forward(0.2);
    move_backward(0.4);
    move_forward(0.2);
    turn_left(83);
    move_backward(1.0);
    turn_right(83);
    move_backward(0.2);
    move_forward(0.4);
    turn_left(83);
    offset();
}

void writeJ() {
    move_forward(0.15);
    move_backward(0.15);
    turn_right(83);
    move_forward(0.5);
    turn_left(83);
    move_forward(1.0);
    turn_right(83);
    move_forward(0.25);
    move_backward(0.5);
    move_forward(0.25);
    turn_left(83);
    move_backward(1.0);
    offset();
}

void writeK() {
    move_forward(1.0);
    move_backward(0.5);
    turn_right(41.5);
    move_forward(0.5);
    move_backward(0.5);
    turn_right(83);
    move_forward(0.5);
    move_backward(0.5);
    turn_left(41.5);
    turn_left(83);
    move_backward(0.5);
    turn_right(83);
    move_forward(0.5);
    turn_left(83);
    offset();
}

void writeL() {
    move_forward(1.0);
    move_backward(1.0);
    turn_right(0.43);
    move_forward(0.5);
    turn_left(0.43);
    offset();
}

void writeM() {
    move_forward(1.0);
    turn_right(83);
    turn_right(41.5);
    move_forward(0.5);
    turn_left(83);
    move_forward(0.5);
    turn_right(41.5);
    turn_right(83);
    move_forward(1.0);
    turn_right(1.0);
    offset();
}

void writeN() {
    move_forward(1.0);
    turn_right(83);
    turn_right(41.5);
    move_forward(1.2);
    turn_left(41.5);
    turn_left(83);
    move_forward(1.0);
    move_backward(1.0);
    offset();
}

void writeO() {
    move_forward(1.0);
    turn_right(83);
    move_forward(1.0);
    turn_right(83);
    move_forward(1.0);
    turn_right(83);
    move_forward(1.0);
    move_backward(1.0);
    turn_right(83);

    offset();
}

void writeP() {
    move_forward(1.0);
    turn_right(83);
    move_forward(0.5);
    turn_right(83);
    move_forward(0.5);
    turn_right(83);
    move_forward(0.5);
    turn_right(83);
    move_backward(0.5);
    turn_right(83);
    move_forward(0.5);
    turn_left(83);
    offset();
}

void writeQ() {
    writeO();
    turn_left(83);
    move_forward(0.7);
    turn_left(83);
    turn_left(41.5);
    move_forward(0.25);
    move_backward(0.25);
    turn_left(41.5);
    move_forward(0.7);
    turn_left(83);
    offset();
}

void writeR() {
    move_forward(1.0);
    turn_right(83);
    move_forward(0.5);
    turn_right(83);
    move_forward(0.5);
    turn_right(83);
    move_forward(0.5);
    turn_left(83);
    turn_left(41.5);
    move_forward(0.6);
    turn_left(41.5);
    turn_left(83);
    offset();
}

void writeS() {
    turn_right(83);
    move_forward(0.5);
    turn_left(83);
    move_forward(0.5);
    turn_left(83);
    move_forward(0.5);
    turn_right(83);
    move_forward(0.5);
    turn_right(83);
    move_forward(0.5);
    move_backward(0.5);
    turn_left(83);
    move_backward(0.5);
    turn_left(83);
    move_backward(0.5);
    turn_right(83);
    move_backward(0.5);
    offset();
}

void writeT() {
    turn_right(83);
    move_forward(0.5);
    turn_left(83);
    move_forward(1.0);
    turn_right(83);
    move_forward(0.25);
    move_backward(0.5);
    move_forward(0.25);
    turn_left(83);
    move_backward(1.0);
    turn_right(83);
    move_forward(0.5);
    turn_left(83);
    offset();
}

void writeU() {
    move_forward(1.0);
    move_backward(1.0);
    turn_right(83);
    move_forward(0.5);
    turn_left(83);
    move_forward(1.0);
    move_backward(1.0);
    offset();
}

void writeV() {
    turn_right(83);
    move_forward(0.5);
    turn_left(83);

    turn_right(35);
    move_forward(0.7);
    move_backward(0.7);
    turn_left(35);
    turn_left(35);
    move_forward(0.7);
    move_backward(0.7);
    turn_right(35);
    
    turn_right(83);
    move_forward(0.5);
    turn_left(83);

    offset();
}

void writeW() {
    move_forward(1.0);
    move_backward(1.0);
    turn_right(41.5);
    move_forward(0.5);
    turn_right(83);
    move_forward(0.5);
    turn_left(41.5);
    turn_left(83);
    move_forward(1.0);
    move_backward(1.0);
    offset();
}

void writeX() {
    turn_right(41.5);
    move_forward(1.0);
    move_backward(0.5);
    turn_left(83);
    move_forward(0.5);
    move_backward(1.0);
    turn_right(41.5);
    offset();
}

void writeY() {
    turn_right(83);
    move_forward(0.5);
    turn_left(83);
    move_forward(0.5);
    turn_right(41.5);
    move_forward(0.5);
    move_backward(0.5);
    turn_left(83);
    move_forward(0.5);
    move_backward(0.5);
    turn_right(41.5);
    move_backward(0.5);
    turn_right(83);
    move_forward(0.5);
    turn_left(83);
    offset();
}

void writeZ() {
    turn_right(41.5);
    move_forward(1.0);
    turn_right(41.5);
    move_backward(0.5);
    move_forward(0.5);
    turn_left(41.5);
    move_backward(1.0);
    turn_right(41.5);
    move_forward(0.5);
    turn_left(83);
    offset();
}



// numbers 0-9

void write0() {
    move_forward(1.0);
    turn_right(83);
    move_forward(1.0);
    turn_right(83);
    move_forward(1.0);
    turn_right(83);
    move_forward(1.0);
    turn_right(83);
    offset();
}

void write1() {
    turn_right(83);
    move_forward(1.0);
    move_backward(1.0);
    move_forward(1.0);
    turn_left(83);
    offset();
}

void write2() {
    move_forward(1.0);
    turn_right(83);
    move_forward(1.0);
    turn_right(83);
    move_forward(1.0);
    turn_left(83);
    move_forward(1.0);
    turn_left(83);
    move_forward(1.0);
    offset();
}

void write3() {
    move_forward(1.0);
    turn_right(83);
    move_forward(1.0);
    turn_right(41.5);
    move_forward(1.0);
    move_backward(1.0);
    turn_left(41.5);
    move_backward(1.0);
    turn_left(41.5);
    move_forward(1.0);
    offset();
}

void write4() {
    turn_right(83);
    move_forward(1.0);
    move_backward(0.5);
    turn_left(83);
    move_forward(1.0);
    turn_right(83);
    move_forward(1.0);
    offset();
}

void write5() {
    move_forward(1.0);
    turn_left(83);
    move_forward(1.0);
    turn_left(83);
    move_forward(1.0);
    turn_right(83);
    move_forward(1.0);
    turn_right(83);
    move_forward(1.0);
    offset();
}

void write6() {
    move_forward(1.0);
    turn_right(83);
    move_forward(1.0);
    turn_right(83);
    move_forward(1.0);
    turn_right(83);
    move_forward(1.0);
    turn_right(83);
    move_forward(0.5);
    offset();
}

void write7() {
    move_forward(1.0);
    turn_right(41.5);
    move_forward(1.0);
    turn_left(41.5);
    move_forward(1.0);
    offset();
}

void write8() {
    move_forward(1.0);
    turn_right(83);
    move_forward(1.0);
    turn_right(83);
    move_forward(1.0);
    turn_right(83);
    move_forward(1.0);
    turn_right(83);
    move_forward(0.5);
    turn_right(83);
    move_forward(1.0);
    turn_right(83);
    move_forward(0.5);
    offset();
}

void write9() {
    move_forward(1.0);
    turn_right(83);
    move_forward(1.0);
    turn_right(83);
    move_forward(1.0);
    turn_right(83);
    move_forward(1.0);
    turn_right(83);
    move_forward(1.0);
    offset();
}
