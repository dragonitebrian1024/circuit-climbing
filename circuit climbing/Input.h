#pragma once
#include <GLFW/glfw3.h>
#include <vector>

static std::vector<bool> TheKeys(48, false);

#define key_a 0
#define key_d 1
#define key_w 2
#define key_s 3
#define key_left 4
#define key_right 5
#define key_up 6
#define key_down 7
#define key_space 8
#define key_q 9
#define key_e 10
#define key_z 11
#define key_x 12
#define key_c 13
#define key_r 14
#define key_f 15
#define key_v 16
#define key_t 17
#define key_g 18
#define key_b 19
#define key_y 20
#define key_h 21
#define key_n 22
#define key_u 23
#define key_j 24
#define key_m 25
#define key_i 26
#define key_k 27
#define key_o 28
#define key_l 29
#define key_p 30
#define key_tab 31
#define key_enter 32
#define key_lshift 33
#define key_rshift 34
#define key_escape 35
#define key_0 36
#define key_1 37
#define key_2 38
#define key_3 39
#define key_4 40
#define key_5 41
#define key_6 42
#define key_7 43
#define key_8 44
#define key_9 47
#define key_lctrl 45
#define key_rctrl 46

//put this in your key_callback function
void key_update(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_A && action == GLFW_PRESS) {
        TheKeys.at(0) = true;
    }
    if (key == GLFW_KEY_D && action == GLFW_PRESS) {
        TheKeys.at(1) = true;
    }
    if (key == GLFW_KEY_A && action == GLFW_RELEASE) {
        TheKeys.at(0) = false;
    }
    if (key == GLFW_KEY_D && action == GLFW_RELEASE) {
        TheKeys.at(1) = false;
    }

    if (key == GLFW_KEY_W && action == GLFW_PRESS) {
        TheKeys.at(2) = true;
    }
    if (key == GLFW_KEY_S && action == GLFW_PRESS) {
        TheKeys.at(3) = true;
    }
    if (key == GLFW_KEY_W && action == GLFW_RELEASE) {
        TheKeys.at(2) = false;
    }
    if (key == GLFW_KEY_S && action == GLFW_RELEASE) {
        TheKeys.at(3) = false;
    }

    if (key == GLFW_KEY_LEFT && action == GLFW_PRESS) {
        TheKeys.at(4) = true;
    }

    if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS) {
        TheKeys.at(5) = true;
    }

    if (key == GLFW_KEY_LEFT && action == GLFW_RELEASE) {
        TheKeys.at(4) = false;
    }

    if (key == GLFW_KEY_RIGHT && action == GLFW_RELEASE) {
        TheKeys.at(5) = false;
    }

    if (key == GLFW_KEY_UP && action == GLFW_PRESS) {
        TheKeys.at(6) = true;
    }

    if (key == GLFW_KEY_DOWN && action == GLFW_PRESS) {
        TheKeys.at(7) = true;
    }

    if (key == GLFW_KEY_UP && action == GLFW_RELEASE) {
        TheKeys.at(6) = false;
    }

    if (key == GLFW_KEY_DOWN && action == GLFW_RELEASE) {
        TheKeys.at(7) = false;
    }
    if (key == GLFW_KEY_SPACE && action == GLFW_RELEASE) {
        TheKeys.at(8) = false;
    }
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
        TheKeys.at(8) = true;
    }
    if (key == GLFW_KEY_Q && action == GLFW_RELEASE) {
        TheKeys.at(9) = false;
    }
    if (key == GLFW_KEY_Q && action == GLFW_PRESS) {
        TheKeys.at(9) = true;
    }
    if (key == GLFW_KEY_E && action == GLFW_RELEASE) {
        TheKeys.at(10) = false;
    }
    if (key == GLFW_KEY_E && action == GLFW_PRESS) {
        TheKeys.at(10) = true;
    }
    if (key == GLFW_KEY_Z && action == GLFW_RELEASE) {
        TheKeys.at(11) = false;
    }
    if (key == GLFW_KEY_Z && action == GLFW_PRESS) {
        TheKeys.at(11) = true;
    }
    if (key == GLFW_KEY_X && action == GLFW_RELEASE) {
        TheKeys.at(12) = false;
    }
    if (key == GLFW_KEY_X && action == GLFW_PRESS) {
        TheKeys.at(12) = true;
    }
    if (key == GLFW_KEY_C && action == GLFW_RELEASE) {
        TheKeys.at(13) = false;
    }
    if (key == GLFW_KEY_C && action == GLFW_PRESS) {
        TheKeys.at(13) = true;
    }
    if (key == GLFW_KEY_R && action == GLFW_RELEASE) {
        TheKeys.at(14) = false;
    }
    if (key == GLFW_KEY_R && action == GLFW_PRESS) {
        TheKeys.at(14) = true;
    }
    if (key == GLFW_KEY_F && action == GLFW_RELEASE) {
        TheKeys.at(15) = false;
    }
    if (key == GLFW_KEY_F && action == GLFW_PRESS) {
        TheKeys.at(15) = true;
    }
    if (key == GLFW_KEY_V && action == GLFW_RELEASE) {
        TheKeys.at(16) = false;
    }
    if (key == GLFW_KEY_V && action == GLFW_PRESS) {
        TheKeys.at(16) = true;
    }
    if (key == GLFW_KEY_T && action == GLFW_RELEASE) {
        TheKeys.at(17) = false;
    }
    if (key == GLFW_KEY_T && action == GLFW_PRESS) {
        TheKeys.at(17) = true;
    }
    if (key == GLFW_KEY_G && action == GLFW_RELEASE) {
        TheKeys.at(18) = false;
    }
    if (key == GLFW_KEY_G && action == GLFW_PRESS) {
        TheKeys.at(18) = true;
    }
    if (key == GLFW_KEY_B && action == GLFW_RELEASE) {
        TheKeys.at(19) = false;
    }
    if (key == GLFW_KEY_B && action == GLFW_PRESS) {
        TheKeys.at(19) = true;
    }
    if (key == GLFW_KEY_Y && action == GLFW_RELEASE) {
        TheKeys.at(20) = false;
    }
    if (key == GLFW_KEY_Y && action == GLFW_PRESS) {
        TheKeys.at(20) = true;
    }
    if (key == GLFW_KEY_H && action == GLFW_RELEASE) {
        TheKeys.at(21) = false;
    }
    if (key == GLFW_KEY_H && action == GLFW_PRESS) {
        TheKeys.at(21) = true;
    }
    if (key == GLFW_KEY_N && action == GLFW_RELEASE) {
        TheKeys.at(22) = false;
    }
    if (key == GLFW_KEY_N && action == GLFW_PRESS) {
        TheKeys.at(22) = true;
    }
    if (key == GLFW_KEY_U && action == GLFW_RELEASE) {
        TheKeys.at(23) = false;
    }
    if (key == GLFW_KEY_U && action == GLFW_PRESS) {
        TheKeys.at(23) = true;
    }
    if (key == GLFW_KEY_J && action == GLFW_RELEASE) {
        TheKeys.at(24) = false;
    }
    if (key == GLFW_KEY_J && action == GLFW_PRESS) {
        TheKeys.at(24) = true;
    }
    if (key == GLFW_KEY_M && action == GLFW_RELEASE) {
        TheKeys.at(25) = false;
    }
    if (key == GLFW_KEY_M && action == GLFW_PRESS) {
        TheKeys.at(25) = true;
    }
    if (key == GLFW_KEY_I && action == GLFW_RELEASE) {
        TheKeys.at(26) = false;
    }
    if (key == GLFW_KEY_I && action == GLFW_PRESS) {
        TheKeys.at(26) = true;
    }
    if (key == GLFW_KEY_K && action == GLFW_RELEASE) {
        TheKeys.at(27) = false;
    }
    if (key == GLFW_KEY_K && action == GLFW_PRESS) {
        TheKeys.at(27) = true;
    }
    if (key == GLFW_KEY_O && action == GLFW_RELEASE) {
        TheKeys.at(28) = false;
    }
    if (key == GLFW_KEY_O && action == GLFW_PRESS) {
        TheKeys.at(28) = true;
    }
    if (key == GLFW_KEY_L && action == GLFW_RELEASE) {
        TheKeys.at(29) = false;
    }
    if (key == GLFW_KEY_L && action == GLFW_PRESS) {
        TheKeys.at(29) = true;
    }
    if (key == GLFW_KEY_P && action == GLFW_RELEASE) {
        TheKeys.at(30) = false;
    }
    if (key == GLFW_KEY_P && action == GLFW_PRESS) {
        TheKeys.at(30) = true;
    }
    if (key == GLFW_KEY_TAB && action == GLFW_RELEASE) {
        TheKeys.at(31) = false;
    }
    if (key == GLFW_KEY_TAB && action == GLFW_PRESS) {
        TheKeys.at(31) = true;
    }
    if (key == GLFW_KEY_ENTER && action == GLFW_RELEASE) {
        TheKeys.at(32) = false;
    }
    if (key == GLFW_KEY_ENTER && action == GLFW_PRESS) {
        TheKeys.at(32) = true;
    }
    if (key == GLFW_KEY_LEFT_SHIFT && action == GLFW_RELEASE) {
        TheKeys.at(33) = false;
    }
    if (key == GLFW_KEY_LEFT_SHIFT && action == GLFW_PRESS) {
        TheKeys.at(33) = true;
    }
    if (key == GLFW_KEY_RIGHT_SHIFT && action == GLFW_RELEASE) {
        TheKeys.at(34) = false;
    }
    if (key == GLFW_KEY_RIGHT_SHIFT && action == GLFW_PRESS) {
        TheKeys.at(34) = true;
    }
    if (key == GLFW_KEY_ESCAPE && action == GLFW_RELEASE) {
        TheKeys.at(35) = false;
    }
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        TheKeys.at(35) = true;
    }
    if (key == GLFW_KEY_0 && action == GLFW_RELEASE) {
        TheKeys.at(36) = false;
    }
    if (key == GLFW_KEY_0 && action == GLFW_PRESS) {
        TheKeys.at(36) = true;
    }
    if (key == GLFW_KEY_1 && action == GLFW_RELEASE) {
        TheKeys.at(37) = false;
    }
    if (key == GLFW_KEY_1 && action == GLFW_PRESS) {
        TheKeys.at(37) = true;
    }
    if (key == GLFW_KEY_2 && action == GLFW_RELEASE) {
        TheKeys.at(38) = false;
    }
    if (key == GLFW_KEY_2 && action == GLFW_PRESS) {
        TheKeys.at(38) = true;
    }
    if (key == GLFW_KEY_3 && action == GLFW_RELEASE) {
        TheKeys.at(39) = false;
    }
    if (key == GLFW_KEY_3 && action == GLFW_PRESS) {
        TheKeys.at(39) = true;
    }
    if (key == GLFW_KEY_4 && action == GLFW_RELEASE) {
        TheKeys.at(40) = false;
    }
    if (key == GLFW_KEY_4 && action == GLFW_PRESS) {
        TheKeys.at(40) = true;
    }
    if (key == GLFW_KEY_5 && action == GLFW_RELEASE) {
        TheKeys.at(41) = false;
    }
    if (key == GLFW_KEY_5 && action == GLFW_PRESS) {
        TheKeys.at(41) = true;
    }
    if (key == GLFW_KEY_6 && action == GLFW_RELEASE) {
        TheKeys.at(42) = false;
    }
    if (key == GLFW_KEY_6 && action == GLFW_PRESS) {
        TheKeys.at(42) = true;
    }
    if (key == GLFW_KEY_7 && action == GLFW_RELEASE) {
        TheKeys.at(43) = false;
    }
    if (key == GLFW_KEY_7 && action == GLFW_PRESS) {
        TheKeys.at(43) = true;
    }
    if (key == GLFW_KEY_8 && action == GLFW_RELEASE) {
        TheKeys.at(44) = false;
    }
    if (key == GLFW_KEY_8 && action == GLFW_PRESS) {
        TheKeys.at(44) = true;
    }
    if (key == GLFW_KEY_LEFT_CONTROL && action == GLFW_RELEASE) {
        TheKeys.at(45) = false;
    }
    if (key == GLFW_KEY_LEFT_CONTROL && action == GLFW_PRESS) {
        TheKeys.at(45) = true;
    }
    if (key == GLFW_KEY_RIGHT_CONTROL && action == GLFW_RELEASE) {
        TheKeys.at(46) = false;
    }
    if (key == GLFW_KEY_RIGHT_CONTROL && action == GLFW_PRESS) {
        TheKeys.at(46) = true;
    }
    if (key == GLFW_KEY_9 && action == GLFW_RELEASE) {
        TheKeys.at(47) = false;
    }
    if (key == GLFW_KEY_9 && action == GLFW_PRESS) {
        TheKeys.at(47) = true;
    }
}