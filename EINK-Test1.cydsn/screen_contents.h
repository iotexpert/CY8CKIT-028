/******************************************************************************
* File Name: screen_contents.h
*
* Version: 1.00
*
* Description: This file contains the macros and variable declarations that can
*              be used to access the images and text stored in screen_contents.c            
*
* Related Document: CE218133_EINK_CapSense.pdf
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
/*****************************************************************************
* This file contains the macros and variable declarations that can be used to 
* access the images and text stored in screen_contents.c  
*******************************************************************************/

/* Include Guard */
#ifndef SCREEN_CONTENTS_H
#define SCREEN_CONTENTS_H
    
/* Header file includes */
#include <project.h>
#include "cy_eink_library.h"

/* Number of items in the main menu */
#define NUMBER_OF_MAIN_MENU_ITEMS       (uint8_t) (0x04u)

/* Number of text pages of each text page group, corresponding to a main menu
   item */
#define NUMBER_OF_MCU_FEATURES_PAGES    (uint8_t) (0x08)
#define NUMBER_OF_KIT_FEATURES_PAGES    (uint8_t) (0x07)
#define NUMBER_OF_KIT_DOCUMENT_PAGES    (uint8_t) (0x04)
#define NUMBER_OF_KIT_EXAMPLES_PAGES    (uint8_t) (0x07)

/* Total number of text pages, which is a sum of the text pages in each text 
   page group */
#define TOTAL_TEXT_PAGES                NUMBER_OF_MCU_FEATURES_PAGES + \
                                        NUMBER_OF_KIT_FEATURES_PAGES + \
                                        NUMBER_OF_KIT_DOCUMENT_PAGES + \
                                        NUMBER_OF_KIT_EXAMPLES_PAGES

/* Maximum number of text pages of in a page group */
#define MAX_NUMBER_OF_TEXT_PAGES        (uint8_t) (0x08u)

/* Size of a text page in number of ASCII characters */
#define TEXT_PAGE_CHARACTER_SIZE        (uint16_t)(0x18D)

/* Value returned from the page index array if an invalid page is accessed */
#define INVALID_PAGE_INDEX              (uint8_t) (0xFFu)
    
/* Variable from screen_contents.c that stores the maximum index of each text
   page array */
extern uint8_t const maxTextPageIndexes[NUMBER_OF_MAIN_MENU_ITEMS];

/* Variables from screen_contents.c that store the text page and the associated
   indexes in flash */
extern char    const textPage[TOTAL_TEXT_PAGES]
                             [TEXT_PAGE_CHARACTER_SIZE];
extern uint8_t const textPageIndex[NUMBER_OF_MAIN_MENU_ITEMS]
                                  [MAX_NUMBER_OF_TEXT_PAGES];

/* Variables from screen_contents.c that store images in flash */
extern cy_eink_image_t const logo                [CY_EINK_IMAGE_SIZE];
extern cy_eink_image_t const textPageBackground  [CY_EINK_IMAGE_SIZE];
extern cy_eink_image_t const mainMenuImage       [NUMBER_OF_MAIN_MENU_ITEMS]
                                                 [CY_EINK_IMAGE_SIZE];

#endif
/* [] END OF FILE */
