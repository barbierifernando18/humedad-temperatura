#include <Wire.h>
#include <Adafruit_HTU21DF.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Configuración de la pantalla OLED 128
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

// Crear objetos para sensor y pantalla
Adafruit_HTU21DF htu = Adafruit_HTU21DF();
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Pines I2C para ESP32 (puedes cambiarlos si es necesario)
#define SDA_PIN 21
#define SCL_PIN 22

void setup() {
  Serial.begin(115200);
  Serial.println("Iniciando sistema de monitoreo HTU21D + OLED");
  
  // Inicializar I2C con pines específicos
  Wire.begin(SDA_PIN, SCL_PIN);
  
  // Inicializar pantalla OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println("Error: No se pudo inicializar la pantalla OLED");
    for(;;); // Bucle infinito si falla
  }
  
  // Configurar pantalla
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.print("Iniciando...");
  display.display();
  delay(2000);
  
  // Inicializar sensor HTU21D
  if (!htu.begin()) {
    Serial.println("Error: No se pudo encontrar el sensor HTU21D");
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("Error HTU21D");
    display.setCursor(0, 16);
    display.print("Verificar");
    display.setCursor(0, 32);
    display.print("conexiones");
    display.display();
    for(;;); // Bucle infinito si falla
  }
  
  Serial.println("Sistema iniciado correctamente");
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Sistema listo!");
  display.display();
  delay(1000);
}

void loop() {
  // Leer temperatura y humedad
  float temperatura = htu.readTemperature();
  float humedad = htu.readHumidity();
  
  // Verificar si las lecturas son válidas
  if (isnan(temperatura) || isnan(humedad)) {
    Serial.println("Error en la lectura del sensor");
    return;
  }
  
  // Mostrar valores en monitor serial
  Serial.println("=== Lecturas del sensor ===");
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");
  Serial.print("Humedad: ");
  Serial.print(humedad);
  Serial.println(" %");
  Serial.println();
  
  // Mostrar en pantalla OLED
  display.clearDisplay();
  
  // Título
  display.setTextSize(1);
  display.setCursor(25, 0);
  display.print("HTU21D Sensor");
  
  // Línea separadora
  display.drawLine(0, 12, 128, 12, WHITE);
  
  // Temperatura
  display.setTextSize(1);
  display.setCursor(0, 20);
  display.print("Temperatura:");
  display.setTextSize(2);
  display.setCursor(10, 32);
  display.print(temperatura, 1);
  display.print(" C");
  
  // Humedad
  display.setTextSize(1);
  display.setCursor(0, 50);
  display.print("Humedad: ");
  display.print(humedad, 1);
  display.print("%");
  
  // Actualizar pantalla
  display.display();
  
  // Esperar 2 segundos antes de la siguiente lectura
  delay(2000);
}

void mostrarError(String mensaje) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("ERROR:");
  display.setCursor(0, 16);
  display.print(mensaje);
  display.display();
}