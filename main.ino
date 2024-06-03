int trigger = 12;  // Pin del trigger del sensor
int echo = 11;      // Pin del echo del sensor
float tiempo_de_espera, distancia; // Variables para tiempo de espera y distancia

void setup() {
  Serial.begin(9600);  // Iniciar comunicación serial
  pinMode(trigger, OUTPUT);  // Configurar pin del trigger como salida
  pinMode(echo, INPUT);  // Configurar pin del echo como entrada
  
  pinMode(2, OUTPUT);  // Configurar pin 2 como salida para LED
  pinMode(3, OUTPUT);  // Configurar pin 3 como salida para LED
  pinMode(4, OUTPUT);  // Configurar pin 4 como salida para LED
  pinMode(5, OUTPUT);  // Configurar pin 5 como salida para LED
  pinMode(6, OUTPUT);  // Configurar pin 6 como salida para LED
  pinMode(7, OUTPUT);  // Configurar pin 7 como salida para LED
  pinMode(8, OUTPUT);  // Configurar pin 8 como salida para LED
  pinMode(9, OUTPUT);  // Configurar pin 9 como salida para LED
  pinMode(10, OUTPUT);  // Configurar pin 10 como salida para LED
}

void loop() {
  digitalWrite(trigger, LOW);  // Establecer trigger en bajo
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH); // Establecer trigger en alto
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);  // Establecer trigger en bajo

  tiempo_de_espera = pulseIn(echo, HIGH);  // Medir duración del pulso
  distancia = (tiempo_de_espera / 2.0) / 29.15;  // Calcular distancia
  int distancia_entera = (int)distancia;  // Convertir distancia a un número entero
  Serial.print(distancia_entera);
  Serial.println("cm");
  delay(1000);

  // Encender LEDs según la representación binaria del número entero de la distancia
  for (int i = 0; i < 9; i++) {
    digitalWrite(2 + i, (distancia_entera >> i) & 0x01);  // Desplazar el bit y establecer el LED correspondiente
  }
}
