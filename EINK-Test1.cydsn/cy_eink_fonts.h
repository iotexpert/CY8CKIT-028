/******************************************************************************
* File Name: cy_eink_fonts.h
*
* Version: 1.00
*
* Description: This file contains macros, structures and constant variable
*              declarations that can be used to access the font information 
*              stored in the cy_eink_fonts.c file.
*
* Related Document: CE220186_RTC_CTS.pdf
*
* Hardware Dependency: CY8CKIT-062-BLE PSoC 6 BLE Pioneer Kit
*                      CY8CKIT-028-EPD E-INK Display Shield
*
******************************************************************************
* Copyright (2017), Cypress Semiconductor Corporation.
******************************************************************************
* This software, including source code, documentation and related materials
* ("Software") is owned by Cypress Semiconductor Corporation (Cypress) and is
* protected by and subject to worldwide patent protection (United States and 
* foreign), United States copyright laws and international treaty provisions. 
* Cypress hereby grants to licensee a personal, non-exclusive, non-transferable
* license to copy, use, modify, create derivative works of, and compile the 
* Cypress source code and derivative works for the sole purpose of creating 
* custom software in support of licensee product, such licensee product to be
* used only in conjunction with Cypress's integrated circuit as specified in the
* applicable agreement. Any reproduction, modification, translation, compilation,
* or representation of this Software except as specified above is prohibited 
* without the express written permission of Cypress.
* 
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND, 
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED 
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* Cypress reserves the right to make changes to the Software without notice. 
* Cypress does not assume any liability arising out of the application or use
* of Software or any product or circuit described in the Software. Cypress does
* not authorize its products for use as critical components in any products 
* where a malfunction or failure may reasonably be expected to result in 
* significant injury or death ("ACTIVE Risk Product"). By including Cypress's 
* product in a ACTIVE Risk Product, the manufacturer of such system or application
* assumes all risk of such use and in doing so indemnifies Cypress against all
* liability. Use of this Software may be limited by and subject to the applicable
* Cypress software license agreement.
*****************************************************************************/
/***************************************************************************
* This file contains macros, structures and constant variable declarations that
* can be used to access the font information stored in the cy_eink_fonts.c file.
* 
* For the details of the E-INK display and library functions, see the code  
* example document of CE218133 - PSoC 6 MCU E-INK Display with CapSense
*******************************************************************************/

/* Include Guard */
#ifndef CY_EINK_FONTS_H
#define CY_EINK_FONTS_H 

/* Header file includes */
#include <project.h>

/* Structure that contains font information */  
typedef struct
{
    /* Pointer to the font pixel data array */
    uint8_t* fontData;
    /* X offset of the font in pixels */
    uint8_t  xOffset;
    /* Y offset of the font in pixels */
    uint8_t  yOffset;
    /* X size of one font data in bytes */
    uint8_t  xSize;
    /* Y size of one font data in bytes */
    uint8_t  ySize;
    /* Number of characters that fit the screen horizontally */
    uint8_t  xSpan;
    /* Number of characters that fit the screen vertically */
    uint8_t  ySpan;
    /* Color of the font : true  = black characters in white background
                           false = white characters in black background */
    bool color;
}   cy_eink_font_t;

/* Two predefined fonts provided by the library */
extern cy_eink_font_t cy_eink_font8By12_blackInWhite;
extern cy_eink_font_t cy_eink_font16By16_blackInWhite; 

#endif  /* CY_EINK_FONTS_H */
/* [] END OF FILE */
