#ifndef RESOURCES_H
#define RESOURCES_H

#include "string"

using namespace std;

class Time{
    int m_day;
    int m_month;
public:
    Time(int day, int month) : m_day(day), m_month(month) {}
    int getDay() const { return m_day; }
    int getMonth() const { return m_month; }
    void setDay(int day);
    void setMonth(int month) { m_month = month; }
};

#endif