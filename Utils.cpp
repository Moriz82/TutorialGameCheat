#include "Includes.h"

void Utils::display_message_box(LPCSTR title, LPCSTR message) {
    MessageBox(
        NULL,
        title,
        message,
        MB_ICONEXCLAMATION | MB_OK
    );
}

