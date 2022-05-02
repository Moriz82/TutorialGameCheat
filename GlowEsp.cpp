#include "Includes.h"

void StartGlowEsp() {
	while (true) {

		for (int i = 1; i < 32; i++) {
			DWORD entity = *(DWORD*)((client_module + Offsets::dwEntityList) + i * 0x10);

			if (entity == NULL) { continue; }

			int glow_index = *(int*)(entity + Offsets::m_iGlowIndex);
			int entity_team = *(int*)(entity + Offsets::m_iTeamNum);

			if (entity_team == local_team) {
				*(float*)((glow_object_manager + glow_index * 0x38 + 0x4)) = 0.f; //r
				*(float*)((glow_object_manager + glow_index * 0x38 + 0x8)) = 0.f; //g
				*(float*)((glow_object_manager + glow_index * 0x38 + 0xC)) = 1.f; //b
				*(float*)((glow_object_manager + glow_index * 0x38 + 0x10)) = 1.f; //a
			}
			else {
				*(float*)((glow_object_manager + glow_index * 0x38 + 0x4)) = 1.f; //r
				*(float*)((glow_object_manager + glow_index * 0x38 + 0x8)) = 0.f; //g
				*(float*)((glow_object_manager + glow_index * 0x38 + 0xC)) = 0.f; //b
				*(float*)((glow_object_manager + glow_index * 0x38 + 0x10)) = 1.f; //a
			}
			*(bool*)((glow_object_manager + glow_index * 0x38 + 0x24)) = true;
			*(bool*)((glow_object_manager + glow_index * 0x38 + 0x25)) = false;

		}
		Sleep(10000);
	}
}