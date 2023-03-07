#include "resources.h"

void Time::setDay(int day) {
    if (m_day != 30){
        m_day+= day;
    }else{
        m_day=0;
        m_month+=1;
    }
}
