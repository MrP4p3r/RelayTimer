/*
 * Функции загрузки и сохранения конфигурации
 */

#include <EEPROM.h>

#ifndef MYCONF_H
#define MYCONF_H

#define CONFIG_VERSION 1000
#define CONFIG_ADDRESS 128

typedef struct Time
{
  uint8_t hour;
  uint8_t minute;
};

typedef struct Config
{
  int version;
  Time T1;
  Time T2;
};

Config defaultConfig = {
  CONFIG_VERSION,
  {  8, 30 },
  { 20, 00 }
};

Config loadConfig()
{
  Config st;
  EEPROM.get(CONFIG_ADDRESS, st);
  if (st.version != CONFIG_VERSION)
  {
    EEPROM.put(CONFIG_ADDRESS, defaultConfig);
    EEPROM.get(CONFIG_ADDRESS, st);
  }
  return st;
}

void saveConfig(const Config &st)
{
  if (st.version == CONFIG_VERSION)
  {
    EEPROM.put(CONFIG_ADDRESS, st);
  }
}

#endif
