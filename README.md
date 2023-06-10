# Código de Cliente de PHX Channel Websockets para Arduino

Este es un ejemplo de código para un cliente de Websockets alojados y/o generados con Channel de Phonix Framework en Arduino. El cliente se conecta a un servidor Websockets y envía y recibe mensajes.

## Requisitos

- Arduino IDE instalado
- Librería ArduinoWebsockets instalada

## Configuración

Antes de ejecutar el código, asegúrate de realizar la siguiente configuración:

1. Ingresa el SSID de tu red Wi-Fi en la variable `ssid`.
2. Ingresa la contraseña de tu red Wi-Fi en la variable `password`.
3. Ingresa la dirección IP o el nombre de dominio de tu servidor Phoenix en la variable `websockets_server_host`.
4. Ingresa el puerto del servidor en la variable `websockets_server_port`.
