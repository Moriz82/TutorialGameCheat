#include "Modules.hpp"


uintptr_t client_module = (uintptr_t)GetModuleHandle("client.dll");
uintptr_t engine_module = (uintptr_t)GetModuleHandle("engine.dll");

uintptr_t local_player = *(uintptr_t*)(client_module + Offsets::dwLocalPlayer);
Vector3* view_angles = (Vector3*)(*(uintptr_t*)(engine_module + dwClientState) + Offsets::dwClientState_ViewAngles);
DWORD EntityList = *(DWORD*)(client_module + Offsets::dwEntityList);
DWORD glow_object_manager = *(DWORD*)(client_module + Offsets::dwGlowObjectManager);

int* i_shots_fired = (int*)(local_player + m_iShotsFired);
Vector3* aim_punch_angle = (Vector3*)(local_player + Offsets::m_aimPunchAngle);
int local_team = *(int*)(local_player + Offsets::m_iTeamNum);
