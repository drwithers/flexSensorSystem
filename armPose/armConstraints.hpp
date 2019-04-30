#define JOINTS 6
#define OFF 4096
//setPWM(channel, on, off)

// Servo Definitions
//{shoulder_rot, shoulder_ex, elbow, wrist_b, wrist_t, grip} // 
const uint8_t pins[6] = {0, 1, 2, 3, 4, 5};
//const uint16_t smin[6] = {115, 100, 160, 130, 115, 150}; //Right arm minimums
//const uint16_t smax[6] = {435, 350, 400, 410, 250, 275}; //Right arm maximums
const uint16_t smin[6] = {85,  85, 250, 60, 175, 375}; //Left arm minimums
const uint16_t smax[6] = {455, 460, 490, 410, 480, 485}; //Left arm maximums
