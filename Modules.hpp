#pragma once
#include "Includes.h"
#ifndef Modules
#define Modules

extern uintptr_t client_module;
extern uintptr_t engine_module;

extern uintptr_t local_player;
extern Vector3* view_angles;
extern DWORD EntityList;
extern DWORD glow_object_manager;

extern int* i_shots_fired;
extern Vector3* aim_punch_angle;
extern int local_team;
#endif