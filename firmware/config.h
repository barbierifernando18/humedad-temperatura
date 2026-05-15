// Configuración del proyecto de humedad y temperatura
// Aquí puedes definir parámetros fáciles de cambiar, como pines I2C,
// intervalos de lectura y otros ajustes generales.

#ifndef CONFIG_H
#define CONFIG_H

// Pines I2C para ESP32
#define SDA_PIN 22
#define SCL_PIN 21

// Dirección I2C del OLED
#define SCREEN_ADDRESS 0x3C

// Intervalo de lectura en milisegundos
#define READ_INTERVAL_MS 2000

#endif // CONFIG_H
