#define JOINTS 6
#define OFF 4096
#define shoulder_rot 0 //Shoulder Rotate: back to front : 110 to 410
#define shoulder_ex 1  //Shoulder Extend: up to down : 75 to 375
#define elbow 2        //Elbow Bend: bent to strait : 100 to 350
#define wrist_b 3      //Wrist Bend: out to in : 100 to 405
#define wrist_t 4      //Wrist Twist: in to out : 110 to 415
#define grip 5         //Hand Gripper: open to closed : 125 to 280
//setPWM(channel, on, off)

// Servo Definitions
//{shoulder_rot, shoulder_ex, elbow, wrist_b, wrist_t, grip}
const uint8_t pins[6] = {0, 1, 2, 3, 4, 5};
const uint16_t smin[6] = {110,  85, 100, 100, 110, 125}; //Right arm minimums
const uint16_t smax[6] = {410, 350, 350, 405, 415, 280}; //Right arm maximums
//const uint16_t smin[6] = {110,  85, 100, 100, 110, 125}; //Left arm minimums
//const uint16_t smax[6] = {410, 350, 350, 405, 415, 280}; //Left arm maximums
