#include <AccelStepper.h>

// Definir os pinos de controle do motor de passo
#define STEP_PIN 12
#define DIR_PIN 13

// Criar uma instância do objeto AccelStepper
AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);

void setup() {
  // Definir a velocidade máxima do motor em passos por segundo
  stepper.setMaxSpeed(1000);

  // Definir a aceleração em passos por segundo por segundo
  stepper.setAcceleration(250);
    stepper.setMinPulseWidth(100);

}

void loop() {
  // Mover o motor de passo 1000 passos na direção horária
  stepper.moveTo(2000);
  stepper.runToPosition();
  
  // Esperar 1 segundo antes de mover o motor na direção anti-horária
  delay(1000);
  
  // Mover o motor de passo 500 passos na direção anti-horária
  stepper.moveTo(0);
  stepper.runToPosition();
  
  // Esperar 1 segundo antes de repetir o processo
  delay(1000);
}