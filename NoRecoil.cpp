#include "Includes.h"

void StartNoRecoil() {
    Vector3 o_punch{ 0,0,0 };
	while (true) {
        Vector3 punch_angle = *aim_punch_angle * 2;
        if (*i_shots_fired > 1) {
            Vector3 new_angle = *view_angles + o_punch - punch_angle;
            new_angle.Normalize();
            *view_angles = new_angle;
        }
        o_punch = punch_angle;
	}
}