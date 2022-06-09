/*
C++
Carrinho que se mantém entre a faixa preta.
Bruno Moreira - 30/03/2022.
v1.0
*/


#define MOTOR1 10
#define MOTOR2 11
#define POTENCIOMETRO A0
#define SENSOR1 4
#define SENSOR2 7

int memopot;    // variavel
int velocidade; // variavel

void setup() // inicializa as entradas
{
    pinMode(MOTOR1, OUTPUT); // motor saida
    pinMode(MOTOR2, OUTPUT);
    pinMode(SENSOR1, INPUT); // sensor entrada
    pinMode(SENSOR2, INPUT);
}

void loop() // execução continua
{
    memopot = analogRead(POTENCIOMETRO); // li o valor da potencia
                                         // val = map(val, 0, 1023, 0, 255);

    velocidade = map(memopot, 0, 1023, 0, 255);

    if (digitalRead(SENSOR1) == LOW) // if = se
    {
        analogWrite(MOTOR1, velocidade); // liguei o motor
    }

    else // else = se nao
    {
        analogWrite(MOTOR1, 0); // desliga o motor
    }

    if (digitalRead(SENSOR2) == LOW) // if = se
    {
        analogWrite(MOTOR2, velocidade); // liguei o motor
    }

    else // else = se nao
    {
        analogWrite(MOTOR2, 0); // desliga o motor
    }
}