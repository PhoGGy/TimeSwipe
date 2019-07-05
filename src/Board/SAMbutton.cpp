#include "SAMbutton.h"
#include "sam.h"

SAMButton::SAMButton(CButtonEvent &sink) : m_sink(sink)
{
    PORT->Group[0].PINCFG[16].bit.INEN=1;
}
bool SAMButton::get_signal(void){

#ifdef EMU
        return is_key_pressed();
#else
     return ( (PORT->Group[0].IN.reg) & (1L<<16) ) ? false:true; //this is the right one for the PandaBoard! 24.04.2019
#endif

}

void SAMButton::send_event(typeButtonState nState)
{

     m_sink.OnButtonState(nState);

     //14.06.2019:
     nlohmann::json v=typeButtonState::pressed==nState ? true:false;
     Fire_on_event("Button", v);
}