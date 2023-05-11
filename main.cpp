/*
los pines asociados al modulos brightcontrol
DigitalOut RGBLed[] = {(PB_4), (PA_0), (PD_12)};


en el .h estan
void brightControlInit();
void setDutyCycle( lightSystem_t light, float dutyCycle );

privadas
static void setPeriod( lightSystem_t light, float period );
static void tickerCallbackBrightControl( );

la clase Ticker 
objeto tickerBrightControl;

en lightsysem estan definidas los led rgb
typedef enum {
    RGB_LED_RED,
    RGB_LED_GREEN,
    RGB_LED_BLUE,
} lightSystem_t;
que s ele puede setear el epriodo y dutycicle


en intit de briht cntrol
se establece la interrupcion cada cierto tiempo  tickRateMSBrightControl) / 1000
para que llame a  tickerCallbackBrightControl cada 1ms con tickRateMSBrightControl = 1
    tickerBrightControl.attach( tickerCallbackBrightControl, 
                              ( (float) tickRateMSBrightControl) / 1000.0 );
esto cambia el estado del led correspondiente si pasa su duty cicle

luego setea el periodo y dutycicle para cada led
esto permitirá dar un brillo a este
    setPeriod( RGB_LED_RED, 0.01f );
    setPeriod( RGB_LED_GREEN, 0.01f );
    setPeriod( RGB_LED_BLUE, 0.01f );

    setDutyCycle( RGB_LED_RED, 0.5f );
    setDutyCycle( RGB_LED_GREEN, 0.5f );
    setDutyCycle( RGB_LED_BLUE, 0.5f );
}

setea el epriodo a 0.01s y el dutycicle a 0.5

viendo en el osciloscopio vemos que le preiodo efectivamente es 10ms
pero el tiempo de encendido es 1ms, cuando deberia ser 5ms

*/

//=====[Libraries]=============================================================

#include "smart_home_system.h"

//=====[Main function, the program entry point after power on or reset]========

int main()
{
    smartHomeSystemInit();
    while (true) {
        smartHomeSystemUpdate();
    }
}