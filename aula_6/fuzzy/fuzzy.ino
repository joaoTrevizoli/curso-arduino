/*fuzzy.ino
  __  _       _      ___   ___  _  _    __
 / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /  | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \  | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\ |_|\__,_|_.__/ \___/ \___/   |_|   /_/


Vamos considerar t < 25 C como frio e t > 30 C como quente
portanto a faixa de incerteza de quente para frio e o intervalo
30 C e 25 C e o intervalo de incerteza de frio para quente é
o intervalo de 25 e 30 graus
*/

float funcaoPertinencia(float val, float limInferior, float limSuperior);
void representacaoGrafica(float limInferior, float limSuperior);
void representacaoGraficaInterseccao(float limInferior, float limSuperior);
void regiaoIncerteza(float temperatura, int &corQuente, int &corFria, \
  float limInferior, float limSuperior);
float lm35dzTempReading(int lm35dzSensorPin);


const int pinoVermelho = 9;
const int pinoVerde = 10;
const int pinoAzul = 11;
const int lm35dzPin = A2;

float lm35dzTemp;

int corVermelha;
int corAzul;

void setup()
{
  Serial.begin(9600);
  pinMode(pinoVermelho, OUTPUT);
	pinMode(pinoVerde, OUTPUT);
	pinMode(pinoAzul, OUTPUT);

  Serial.println( "-----------Funcao Temperatura Baixa--------");
  representacaoGrafica(30, 25);
  Serial.println( "-------------------------------------------");
  Serial.println( "-----------Funcao Temperatura Alta---------");
  representacaoGrafica(25, 30);
  Serial.println( "-------------------------------------------");
  Serial.println( "-----------Conjunto da Uniao---------------");
  representacaoGraficaInterseccao(25, 30);
  Serial.println( "-------------------------------------------");

}

void loop()
{
  lm35dzTemp = lm35dzTempReading(lm35dzPin);
  regiaoIncerteza(lm35dzTemp, corAzul, corVermelha, 30, 25);
  analogWrite(pinoVermelho, corVermelha);
  analogWrite(pinoAzul, corAzul);
  delay(500);
}

float funcaoPertinencia(float val, float limInferior, float limSuperior)
{
  float resultado;
  if (limInferior >= limSuperior)
  {
    resultado = (val - limSuperior) / (limInferior - limSuperior);
  }
  else
  {
    resultado = -((limSuperior - val) / (limInferior - limSuperior));
  }

  if (resultado >= 1)
    return 1;
  else if (resultado <= 0)
    return 0;
  return resultado;
}

void regiaoIncerteza(float temperatura, int &corQuente, int &corFria, \
  float limInferior, float limSuperior)
{
  float fuzzyQuente = funcaoPertinencia(temperatura, limInferior, limSuperior);
  float fuzzyFrio = funcaoPertinencia(temperatura, limSuperior, limInferior);
  corFria = 255  * fuzzyQuente;
  corQuente =  255 * fuzzyFrio;

  Serial.print(temperatura);
  Serial.print(" Esta frio com pertinencia: ");
  Serial.print(fuzzyFrio);
  Serial.print(", Esta calor com pertinencia: ");
  Serial.println(fuzzyQuente);
}


void representacaoGrafica(float limInferior, float limSuperior)
{
  Serial.println("   C |");
  unsigned int grafVal;

  for (size_t i = 0; i < 35; i++)
  {
    grafVal = 10 * funcaoPertinencia(i, limInferior, limSuperior);
    Serial.print("   ");
    Serial.print(i);
    if (i < 10)
    {
      Serial.print(" |");
    }
    else
    {
      Serial.print( "|");
    }
    for (size_t j = 0; j < grafVal; j++)
    {
        Serial.print( " ");
    }
    Serial.println( "*");
  }

}
void representacaoGraficaInterseccao(float limInferior, float limSuperior)
{
  Serial.println("   C |");
  unsigned int conjunto1;
  unsigned int conjunto2;
  unsigned int min;
  for (size_t i = 0; i < 35; i++)
  {
    // Interseccao
    conjunto1 = 10 * funcaoPertinencia(i, limInferior, limSuperior);
    conjunto2 = 10 * funcaoPertinencia(i, limSuperior, limInferior);

    min = conjunto1;
    if (conjunto2 < min)
      min = conjunto2;

      Serial.print("   ");
      Serial.print(i);

      if (i < 10)
      {
        Serial.print( " |");
      }
      else
      {
        Serial.print("|");
      }
      for (size_t i = 0; i <= min; i++)
      {
          Serial.print(" ");
      }
      Serial.println("*");
  }

}
float lm35dzTempReading(int lm35dzSensorPin)
{
	/*
	O arduino fornece 5v em seu pino de potencia e possui uma resolucao de 10bits,
	ou seja 1024 pontos, para saber o valor da temperatura devemos calcular o intervalo
	de voltagem que o arduino e capaz de ler e converter cada 10 milivolts para 1 C
	*/

	float temperature = (static_cast<float>(analogRead(lm35dzSensorPin))*5/(1023))/0.01;
	return temperature;
}
