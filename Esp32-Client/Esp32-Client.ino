#include <ArduinoWebsockets.h>
#include <WiFi.h>

const char* ssid = "Pizza"; // Ingresa el SSID de tu red Wi-Fi
const char* password = "pollofrito"; // Ingresa la contraseña de tu red Wi-Fi
const char* websockets_server_host = "192.168.50.158"; // Ingresa la dirección IP o el nombre de dominio de tu servidor Phoenix
const uint16_t websockets_server_port = 44216; // Ingresa el puerto del servidor

using namespace websockets;

WebsocketsClient client;

void setup() {
    Serial.begin(115200);
    // Conectarse a la red Wi-Fi
    WiFi.begin(ssid, password);

    // Esperar un tiempo para conectarse a la red Wi-Fi
    for(int i = 0; i < 10 && WiFi.status() != WL_CONNECTED; i++) {
        Serial.print(".");
        delay(1000);
    }

    // Verificar si se conectó a la red Wi-Fi
    if(WiFi.status() != WL_CONNECTED) {
        Serial.println("¡Sin conexión Wi-Fi!");
        return;
    }

    Serial.println("Conectado a la red Wi-Fi, conectándose al servidor.");
    // Intentar conectarse al servidor Websockets
    bool connected = client.connect(websockets_server_host, websockets_server_port, "/socket/websocket");
    if(connected) {
        Serial.println("¡Conectado!");
        // Unirse al canal ws_server:42
        String joinMessage = R"({"topic":"ws_server:42","event":"phx_join","payload":{},"ref":"1"})";
        client.send(joinMessage);
    } else {
        Serial.println("¡No se pudo conectar!");
    }
    
    // Ejecutar la devolución de llamada cuando se reciben mensajes
    client.onMessage([&](WebsocketsMessage message){
        Serial.print("Mensaje recibido: ");
        Serial.println(message.data());
    });
}

void loop() {
    // Permitir que el cliente de websockets compruebe si hay mensajes entrantes
    if(client.available()) {
        client.poll();
    }
    delay(500);
}
