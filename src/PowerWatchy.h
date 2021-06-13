#ifndef POWER_WATCHY_H
#define POWER_WATCHY_H

#include <Watchy.h>
#include "Px437_IBM_BIOS5pt7b.h"

class PowerWatchy : public Watchy{
    public:
        PowerWatchy();
        void drawWatchFace();
};

#endif