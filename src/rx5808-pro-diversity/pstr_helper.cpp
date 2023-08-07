#include "pstr_helper.h"
#include <pgmspace.h>
#include "Arduino.h"

char PSTR2_BUFFER[PSTR2_BUFFER_SIZE];

char *PSTRtoBuffer_P(PGM_P str) { 
    uint8_t i = 0;
    
    for (
        uint8_t c = '\0';
        c = pgm_read_byte(str + i) && i < sizeof(PSTR2_BUFFER); 
        i++
    ) {
        PSTR2_BUFFER[i] = pgm_read_byte(str + i);
    }
    
    PSTR2_BUFFER[i] = '\0'; // Loop drops early so add in finishing terminator.
    return PSTR2_BUFFER;
}