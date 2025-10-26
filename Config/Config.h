#ifndef CONFIG_H
#define CONFIG_H

// Board supportate
#define ARDUINO_UNO 1
#define NUCLEO_F030R8 2
#define ARDUINO_NANO 3
#define NUCLEO_F401RE 4
#define ARDUINO_MEGA 4

#define BOARD ARDUINO_UNO
// #define BOARD NUCLEO_F030R8
// #define BOARD ARDUINO_NANO
// #define BOARD NUCLEO_F401RE
// #define BOARD ARDUINO_MEGA

// Active debug
#define DEBUG 0

#if DEBUG
#define DEBUG_PRINT(x) Serial.print(x)
#define DEBUG_PRINTLN(x) Serial.println(x)
#define DEBUG_PRINT_FUNC()                                                       \
  do                                                                             \
  {                                                                              \
    Serial.print("[DEBUG] ");                                                    \
    String fullSig = __PRETTY_FUNCTION__;                                        \
    int start = fullSig.indexOf(' ') + 1;                                        \
    int sep = fullSig.indexOf("::", start);                                      \
    String className = (sep > 0) ? fullSig.substring(start, sep) : "(no class)"; \
    Serial.print(className);                                                     \
    Serial.print("::");                                                          \
    Serial.print(__FUNCTION__);                                                  \
    Serial.print(" (linea ");                                                    \
    Serial.print(__LINE__);                                                      \
    Serial.print(")  --->  ");                                                   \
  } while (0)
#else
#define DEBUG_PRINT(x)
#define DEBUG_PRINTLN(x)
#define DEBUG_PRINT_FUNC()
#endif

#endif
