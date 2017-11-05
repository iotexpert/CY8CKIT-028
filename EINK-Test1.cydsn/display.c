
/* Header file includes */
#include "display.h"

static unsigned int eink_textCols;
static unsigned int eink_textRows;

cy_eink_update_t eink_updateMode;

#define screenX 33u
#define screenY 22u

static void eink_initializeTextDisplay();


const uint8_t allScreen[] = {0,0,screenX, screenY };

#define TEXT_PAGE_CHARACTER_SIZE        (16*11)
char myTextPage [TEXT_PAGE_CHARACTER_SIZE];

/* Definition of ambient temperature at 25 degree C */
#define AMBIENT_TEMPERATURE_DEFAULT         (25)

/* Macros used to control the red and blue LEDs */
#define LED_ON                      (0x00u)
#define LED_OFF                     (0x01u)

#define NUMBER_OF_FRAME_BUFFERS     (2)

static cy_eink_frame_t eink_frameBuffer[NUMBER_OF_FRAME_BUFFERS][CY_EINK_FRAME_SIZE];

static int eink_currentFrame = 0;


void eink_initDisplay(void)
{
    eink_updateMode = CY_EINK_FULL_4STAGE;
    eink_initializeTextDisplay();
    
    /* Initialize the E-INK display hardware with the given ambient temperature */
    Cy_EINK_Start(AMBIENT_TEMPERATURE_DEFAULT);
    
    /* Power on the display and check if the operation is successful */
    if (Cy_EINK_Power(CY_EINK_ON)== CY_EINK_OPERATION_SUCCESS)
    {
        /* Clear the display to white background */
        Cy_EINK_Clear(CY_EINK_WHITE_BACKGROUND, CY_EINK_POWER_MANUAL);
        Cy_EINK_Power(CY_EINK_OFF);
    }
    /* If the power on operation has failed */
    else
    {
        /* Turn the red LED on to indicate that the E-INK display is not 
           detected. Check the connection between the E-INK shield and the 
           Pioneer Baseboard if this happens, and then reset the PSoC 6 BLE */
        Cy_GPIO_Write(LED_Red_PORT, LED_Red_NUM, LED_ON);
        
        /* Halt the CPU */
        CY_ASSERT(0u != 0u);
    }
    eink_currentFrame = 0;
}

void eink_initializeFrameBuffers(cy_eink_image_t *imagePointer)
{
    for(int i=0 ; i < NUMBER_OF_FRAME_BUFFERS;i++)
    {
        Cy_EINK_ImageToFrameBuffer(eink_frameBuffer[i], imagePointer,(uint8_t *)allScreen);
        Cy_EINK_ImageToFrameBuffer(eink_frameBuffer[i], imagePointer,(uint8_t *)allScreen);
    }                        
}

void eink_displayImage( cy_eink_image_t *imagePointer)
{
    /* Turn on the yellow LED to indicate a display update in progress */
    Cy_GPIO_Write(LED_Orange_PORT, LED_Orange_NUM, LED_ON);
    
    Cy_EINK_ShowFrame(eink_frameBuffer[eink_currentFrame], imagePointer, eink_updateMode,
                          CY_EINK_POWER_AUTO);

    eink_currentFrame = (eink_currentFrame + 1) % NUMBER_OF_FRAME_BUFFERS;

    Cy_GPIO_Write(LED_Orange_PORT, LED_Orange_NUM, LED_OFF);
}

void eink_displayImageAndText(char* text, cy_eink_image_t* backgroundImage)
{
    const uint8_t   textOrigin[] = {0,0 };
    
    Cy_GPIO_Write(LED_Orange_PORT, LED_Orange_NUM, LED_ON);
    
    int previousBuffer = eink_currentFrame;
    eink_currentFrame = (eink_currentFrame + 1) % NUMBER_OF_FRAME_BUFFERS;

    //Cy_EINK_ImageToFrameBuffer(frameBuffer[currentFrameBuffer], backgroundImage,allScreen);
    
    // ARH this needs to be improved... why doesnt the blank screen work?
    for(int i =0; i<(int)sizeof(eink_frameBuffer[eink_currentFrame]); i++)
    {
        eink_frameBuffer[eink_currentFrame][i] = 0xFF;
    }
    
    /* Load the frame buffer with the current text Page content */
    //Cy_EINK_TextToFrameBuffer(frameBuffer[currentFrameBuffer], text, CY_EINK_FONT_8X12BLACK, textOrigin);
    
    Cy_EINK_TextToFrameBuffer(eink_frameBuffer[eink_currentFrame], text, 
        CY_EINK_FONT_16X16BLACK, (uint8_t *)textOrigin);
    
    /* Perform a full update to avoid ghosting as the text pages differ
       significantly from one another and also from the main menu images */
    Cy_EINK_ShowFrame(eink_frameBuffer[previousBuffer], eink_frameBuffer[eink_currentFrame],
                      eink_updateMode, CY_EINK_POWER_AUTO);
    
    
    /* Turn off the yellow LED to indicate that display update is finished */
    Cy_GPIO_Write(LED_Orange_PORT, LED_Orange_NUM, LED_OFF);
}



void eink_initializeTextDisplay()
{
    eink_textCols = 16;  
    eink_textRows = 11;
    eink_clearTextBuffer();
}

void eink_setText(const char *txt, unsigned int x, unsigned int y)
{
    CY_ASSERT(x < eink_textCols); 
    CY_ASSERT(y < eink_textRows);
    int position = x + y*eink_textCols;
    CY_ASSERT(position + strlen(txt) < TEXT_PAGE_CHARACTER_SIZE );
    memcpy(&myTextPage[position],txt,strlen(txt));
}

void eink_clearTextBuffer()
{
    for(int i=0;i<TEXT_PAGE_CHARACTER_SIZE;i++)
    {
        myTextPage[i] = ' ';
    }
}

void eink_displayTextBuffer()
{
    eink_displayImageAndText(myTextPage,PV_EINK_WHITE_FRAME_ADDRESS);
}

//     CY_EINK_PARTIAL, CY_EINK_FULL_4STAGE, CY_EINK_FULL_2STAGE
void eink_setUpdateMode(cy_eink_update_t mode)
{
    eink_updateMode = mode;
}
