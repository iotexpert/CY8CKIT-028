
#include "project.h"
#include <project.h>
#include "display.h"

extern cy_eink_image_t const logo                [CY_EINK_IMAGE_SIZE];

int main(void)
{
    /* Enable global interrupts */
    __enable_irq();

    /* Initialize the display, touch detection and low power modules */
    eink_initDisplay();
    eink_displayImage((cy_eink_image_t *)logo);
    CyDelay(1000);
    eink_displayImage(PV_EINK_WHITE_FRAME_ADDRESS);
    CyDelay(1000);
    eink_displayImage(PV_EINK_BLACK_FRAME_ADDRESS);
    CyDelay(1000);
    eink_setText("abc123ABC", 2, 2);
    eink_setText("0123456789",0,0);
    eink_displayTextBuffer();
    eink_clearTextBuffer();
    eink_setText("Alan Hawse",3,3);
    CyDelay(1000);
    eink_setUpdateMode( CY_EINK_FULL_2STAGE);
    eink_displayTextBuffer();
    
    for (;;)
    {
    }
}
