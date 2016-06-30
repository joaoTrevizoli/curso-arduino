/*fuzzy.ino
  __  _       _      ___   ___  _  _    __
 / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /  | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \  | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\ |_|\__,_|_.__/ \___/ \___/   |_|   /_/

*/

inline float funcaoPertinencia(float val, float limInferior, float limSuperior);
void regiaoIncerteza(float temperatura, int &corQunte, int &corFria);
void representacaoGrafica(int typeQF);
void representacaoGraficaInterseccao();
float lm35dzTempReading(int lm35dzSensorPin);

const int pinoVermelho = 9;
const int pinoVerde = 10;
const int pinAzul = 11;
const int lm35dzPin = A2;

float lm35dzTemp;

int vermelho;
int azul;

void setup()
{
  Serial.begin(9600);
  pinMode(pinoVermelho, OUTPUT);
	pinMode(pinoVerde, OUTPUT);
	pinMode(pinAzul, OUTPUT);

  Serial.println( "-----------Conjunto da Temperatura Baixa--------");
  representacaoGrafica('f');
  Serial.println( "-----------Conjunto da Temperatura Alta---------");
  representacaoGrafica('q');
  Serial.println( "-----------Conjunto da Uniao--------------------");
  representacaoGraficaInterseccao();
}

void loop()
{
  lm35dzTemp = lm35dzTempReading(lm35dzPin);
  regiaoIncerteza(lm35dzTemp, vermelho, azul);
  Serial.println(lm35dzTemp);
  delay(1500);

}

inline float funcaoPertinencia(float val, float limInferior, float limSuperior)
{
  float resultado;
  if (limInferior >= limSuperior)
    resultado = (val - limSuperior) / (limInferior - limSuperior);
  else
    resultado = -((limSuperior - val)/ (limInferior - limSuperior));
  if (resultado >= 1)
    return 1;
  if (resultado <= 0)
    return 0;
  return resultado;

}

void regiaoIncerteza(float temperatura, int &corQuente, int &corFria)
{
  corQuente = 255 * funcaoPertinencia(temperatura, 25.0, 30.0);
  corFria =  255 * funcaoPertinencia(temperatura, 30.0, 25.0);

}
void representacaoGrafica(int typeQF)
{
  Serial.println("   C |");
  unsigned int grafVal;

  for (size_t i = 0; i < 35; i++)
  {
    if (typeQF == 'q' || typeQF == 'Q')
      grafVal = 10 * funcaoPertinencia(i, 30.0, 25.0);
    else
      grafVal = 10 * funcaoPertinencia(i, 25.0, 30.0);
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


void representacaoGraficaInterseccao()
{
  Serial.println("   C |");
  unsigned int quente;
  unsigned int frio;
  unsigned int min;
  for (size_t i = 0; i < 35; i++)
  {
    quente = 10 * funcaoPertinencia(i, 30.0, 25.0);
    frio = 10 * funcaoPertinencia(i, 25.0, 30.0);
    min = quente;
    if (frio < min)
      min = frio;

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
