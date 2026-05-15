# Monitoreo de Humedad y Temperatura con ESP32

Este proyecto lee temperatura y humedad con un sensor HTU21D y muestra los valores en una pantalla OLED 128x64 usando un ESP32.

Proyecto desarrollado en el marco de la **Red Maker Misiones** — Nodo [COMPLETAR].

## Materiales

| Componente | Cantidad | Notas |
|---|---|---|
| ESP32 (o placa compatible) | 1 | Con conexión I2C |
| Sensor HTU21D | 1 | Temperatura y humedad |
| Pantalla OLED 128x64 I2C | 1 | SSD1306 |
| Cables de conexión | 1 | Dupont macho-macho |
| Fuente de alimentación USB | 1 | 5V |

## Requisitos de software

- Arduino IDE 2.x o superior
- Librerías:
  - Adafruit HTU21DF
  - Adafruit SSD1306
  - Adafruit GFX

## Cómo usar

1. Abrir `firmware/humedad-temperatura.ino` en Arduino IDE.
2. Instalar las librerías necesarias desde el Gestor de Librerías.
3. Seleccionar la placa ESP32 correcta y el puerto USB.
4. Cargar el sketch en el ESP32.
5. Conectar los cables I2C:
   - SDA -> GPIO 22
   - SCL -> GPIO 21
6. Abrir el Monitor Serial a 115200 para ver las lecturas.

## Fotos

> 📸 Agregar fotos del proyecto terminado en `docs/fotos/`
>
> ![Foto del proyecto](docs/fotos/foto_01.jpg)

## Estructura del proyecto

```
humedad-temperatura/
├── firmware/
│   ├── humedad-temperatura.ino
│   └── config.h
├── docs/
│   └── fotos/
│       └── .gitkeep
├── LICENSE
├── README.md
└── .gitignore
```

## Autor

**@barbierifernando18** — Nodo [COMPLETAR], Red Maker Misiones  
GitHub: [@barbierifernando18](https://github.com/barbierifernando18)

## Licencia

MIT — Libre para usar, modificar y distribuir citando al autor. Ver [LICENSE](LICENSE).
