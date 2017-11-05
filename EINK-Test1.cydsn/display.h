
/* Include Guard */
#ifndef DISPLAY_H
#define DISPLAY_H

/* Header file includes */
#include <project.h>
#include "cy_eink_library.h"
    
   
/* Function that initializes and clears the display */

void    eink_initDisplay(void);

/* Function that displays an image on the EINK display */
void    eink_displayImage( cy_eink_image_t *imagePointer);

/* Function that displays a string of text with a background image */
void    eink_displayImageAndText(char* text,  cy_eink_image_t *backgroundImage);

void eink_setUpdateMode(cy_eink_update_t mode);

void eink_setText(const char *txt, unsigned int x, unsigned int y);
void eink_clearTextBuffer();
void eink_displayTextBuffer();
#endif
/* [] END OF FILE */
