// ECE 4180 Final Project - Writing Robot
// Authors: Marwan Hassan and Yashad Garude
// APIs used: mbed.h, Motor.h, Servo.h, ICM20948.h

#include "mbed.h"
#include "Motor.h"
#include "characters.h"
#include "Servo.h"
#include "ICM20948.h"


// serial connections
UnbufferedSerial pc(USBTX, USBRX, 9600);    // usb serial to computer
UnbufferedSerial dev(p28, p27, 9600);       // serial for bluetooth module

// motor and servo setup
Motor rightMotor(p23, p18, p17);
Motor leftMotor(p22, p20, p19);
Servo penServo(p21);
DigitalOut motorStdBy(p16);                 // standby pin for enable/disable motor driver

// imu
ICM20948 imu(p9, p10);

// rgb status leds
PwmOut blue(p26);
PwmOut green(p25);
PwmOut red(p24);

/* LED Status:
   - System OFF: no LED
   - System ON: white LED
   - Awaiting input: blinking green
   - Writing: solid red
*/

volatile bool word_ready = false;   // true when full input is received
volatile bool awake = false;        // true when robot is powered on
volatile bool writing = false;      // true when robot is actively writing

char word_buffer[64];               // stores incoming word
char character;                     // current character to write
int word_index = 0;                 // index for word_buffer


// basic motion control for forward/backward
// different speeds were tested with our robot's weight and balance, and the surface we used; settled on 0.5
void move_backward(float seconds) {
    leftMotor.speed(-0.5);
    rightMotor.speed(-0.5);
    wait_us(seconds * 1e6);
    leftMotor.speed(0);
    rightMotor.speed(0);
    wait_us(500000);
}

void move_forward(float seconds) {
    leftMotor.speed(0.5);
    rightMotor.speed(0.5);
    wait_us(seconds * 1e6);
    leftMotor.speed(0);
    rightMotor.speed(0);
    wait_us(500000);
}


// gyroscope based turns
void turn_right(float degrees) {
    float total_angle = 0.0f;
    float dt = 0.01f;            // 10 ms

    leftMotor.speed(0.3);
    rightMotor.speed(-0.3);

    while (total_angle < degrees) {
        imu.getAccGyro();               // update gyro readings
        float gz = imu.getGZ();         // get angular velocity around z-axis
        total_angle += fabs(gz) * dt;   // integrate angular velocity
        wait_us((int)(dt * 1000000));
    }

    leftMotor.speed(0);
    rightMotor.speed(0);
}

void turn_left(float degrees) {
    float total_angle = 0.0f;
    float dt = 0.01f;

    leftMotor.speed(-0.3);
    rightMotor.speed(0.3);

    while (total_angle < degrees) {
        imu.getAccGyro();
        float gz = imu.getGZ();
        total_angle += fabs(gz) * dt;
        wait_us((int)(dt * 1000000));
    }

    leftMotor.speed(0);
    rightMotor.speed(0);
}


// functions for pen control
void raise_pen() {
    for(int i=0; i<95; i++) {
        penServo = i/100.0;
        wait_us(10000);
    }
    wait_us(100000);
}

void lower_pen() {
    for(int i=95; i>0; i--) {
        penServo = i/100.0;
        wait_us(10000);
    }
    wait_us(100000);
}


// bluetooth receiver interrupt handler
void dev_recv() {
    char c;
    static char bnum = '2';
    static char state = 0;

    if (dev.read(&c, 1) == 1) { // read input from bluetooth

        // these if loops check if a '1' (on) or '2' (off) is pressed on the bluetooth controller
        if (c == '!') {
            if (dev.read(&c, 1) == 1 && c == 'B') {
                if (dev.read(&bnum, 1) == 1 && dev.read(&state, 1) == 1) {
                    if ((bnum == '1' || bnum == '2') && state == '1') {

                        if (bnum == '1') {  // robot on
                            awake = true;
                            word_index = 0;     // clear any partial input
                            motorStdBy = 1;     // enable motor driver


                            // fade in white LED
                            for (float b = 0.0f; b <= 1.0f; b += 0.01f) {
                                blue.write(b);
                                green.write(b);
                                red.write(b);
                                wait_us(10000);
                            }


                            wait_us(3000000);   // 3s pause to visually "boot"
                            blue = green = red = 0;     // disable all leds to get ready for next state

                            raise_pen();

                        } else if (bnum == '2') {   // robot off
                            awake = false;
                            word_ready = false;
                            writing = false;


                            blue = green = red = 0;     // disable all leds
                            motorStdBy = 0;     // disable motor driver


                            raise_pen();

                            // reset word for next use
                            word_index = 0;     // clear any partial input
                            memset(word_buffer, 0, sizeof(word_buffer)); // clear the entire word_buffer
                        }
                    }
                }
                return;
            }
        }

        // build up word buffer is robot is awake
        if (awake) {
            if ((c == '\n' || c == '\r') && word_index > 0) { // if char is newline or return and of length > 0
                word_buffer[word_index] = '\0';  // null-terminate to become valid string
                word_ready = true;
                word_index = 0;
            } else if (word_index < sizeof(word_buffer) - 1) {
                word_buffer[word_index++] = c; // add char to word buffer
            }
        }
    }
}


// write each character in the word buffer
void handle_word(char buffer[64]) {
    for (int i = 0; i < 64 && buffer[i] != '\0'; ++i) {
        character = buffer[i];
        pc.write(&character, 1); // print to putty for debugging

        if (character >= 'A' && character <= 'Z') {
            character = character + ('a' - 'A');  // convert to lowercase to minimize number of cases to check 
        }

        switch(character) {
            // letters A-Z
            case 'a': writeA(); break;
            case 'b': writeB(); break;
            case 'c': writeC(); break;
            case 'd': writeD(); break;
            case 'e': writeE(); break;
            case 'f': writeF(); break;
            case 'g': writeG(); break;
            case 'h': writeH(); break;
            case 'i': writeI(); break;
            case 'j': writeJ(); break;
            case 'k': writeK(); break;
            case 'l': writeL(); break;
            case 'm': writeM(); break;
            case 'n': writeN(); break;
            case 'o': writeO(); break;
            case 'p': writeP(); break;
            case 'q': writeQ(); break;
            case 'r': writeR(); break;
            case 's': writeS(); break;
            case 't': writeT(); break;
            case 'u': writeU(); break;
            case 'v': writeV(); break;
            case 'w': writeW(); break;
            case 'x': writeX(); break;
            case 'y': writeY(); break;
            case 'z': writeZ(); break;

            // numbers 0-9
            case '0': write0(); break;
            case '1': write1(); break;
            case '2': write2(); break;
            case '3': write3(); break;
            case '4': write4(); break;
            case '5': write5(); break;
            case '6': write6(); break;
            case '7': write7(); break;
            case '8': write8(); break;
            case '9': write9(); break;

            default: break; // ignore unsupported characters
        }
    }
    writing = false;
}


int main() {
    dev.attach(&dev_recv, SerialBase::RxIrq); // interrupt when a character is received via bluetooth
    imu.powerOn();
    imu.init(0x10, 0x00, 0x10, 0x00);
    imu.gyroCalib();

    while (1) {
        if (!awake) {
            blue = green = red = 0;
            sleep();
            continue;
        }

        if (writing) { 
            red = 1; // solid red during writing
            green = 0;
        } else if (word_ready) {
            word_ready = false;
            writing = true;
            green = 0;
            red = 1;
            handle_word(word_buffer);
            red = 0;  // red will be turned off after writing finishes
            writing = false;
            word_index = 0;
        } else { // blinking green to signal ready for input
            green = 1;
            wait_us(300000);
            green = 0;
            wait_us(300000);
        }

        sleep();
    }
}