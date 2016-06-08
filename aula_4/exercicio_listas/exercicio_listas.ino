/* exercicio_listas.ino
  __  _       _      ___   ___  _  _    __
 / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /  | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \  | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\ |_|\__,_|_.__/ \___/ \___/   |_|   /_/
*/

void ordered_list(int l[], int list_size);
void somaLinhas(int m[][4], int nLinhas);
void somaColunas(int m[][4], int nLinhas);

void setup()
{
	
	Serial.begin(9600);

	int lista[] = {54, 4, 1, 7, 23, 23, 12, 71, 8};
	int comprimentoLista = sizeof(lista)/sizeof(int);

	int matriz[4][4] = {
	                     {3, 4, 2, 6} ,
	                     {7, 5, 3, 5} ,
	                     {3, 6, 2, 12},
	                     {8, 3, 1, 8}
	                    };

	//------------------ ordenando uma lista ------------------//
		
	Serial.println("Ordenando uma lista:");
	Serial.print("Lista original:\n\t { ");
	
	for (int i = 0; i < comprimentoLista; ++i)
	{
		Serial.print(lista[i]);
		Serial.print(", ");
	}
	Serial.println("}");

	Serial.print("Lista Ordenada:\n\t { ");

	ordered_list(lista, comprimentoLista);
	for (int i = 0; i < comprimentoLista; ++i)
	{
		Serial.print(lista[i]);
		Serial.print(", ");
	}

	Serial.print("}");
	Serial.println("\n*********************************************\n");

	//---------------------------------------------------------//
	
	// ------------------ Imprimindo a matriz ----------------//
	Serial.print("Matriz: \n\t{");
	for (int i = 0; i < 4; ++i)
	{
		Serial.print("\n\t { ");
		for (int j = 0; j < 4; ++j)
		{
			Serial.print(matriz[i][j]);	
			Serial.print(",");
		}
		Serial.print(" }");
	}
	Serial.println("\n\t}");

	//---------------------------------------------------------//

	//--------------- calculando a soma das linhas ------------//
	Serial.println("Calculando a soma das linhas");
	somaLinhas(matriz, 4);	
	Serial.println("\n*********************************************\n");

	//---------------------------------------------------------//

	//--------------- calculando a soma das colunas ------------//

	Serial.println("Calculando a soma das colunas");
	somaColunas(matriz, 4);	
	Serial.println("\n*********************************************\n");


}

void loop()
{
	
}


void ordered_list(int l[], int list_size)
{
	int pivot;
	for (int i = 0; i < list_size; ++i)
	{
		for (int j = i; j < list_size; j++)
		{
			if (l[i] > l[j])
			{
				pivot = l[i];
				l[i] = l[j];
				l[j] = pivot;
			}
		}
	}	
}

void somaLinhas(int m[][4], int nLinhas)
{
	int soma;
	for (int i = 0; i < nLinhas; ++i)
	{
		soma = 0;
		Serial.print("Soma da linha ");
		Serial.print(i);
		Serial.print(" = ");
		for (int j = 0; j < 4; ++j)
		{
			soma += m[i][j];
		}
		Serial.println(soma);
		soma = 0;
	}
}

void somaColunas(int m[][4], int nLinhas)
{
	int soma;
	for (int i = 0; i < nLinhas; ++i)
	{
		soma = 0;
		Serial.print("Soma da coluna ");
		Serial.print(i);
		Serial.print(" = ");
		for (int j = 0; j < 4; ++j)
		{
			soma += m[j][i];
		}
		Serial.println(soma);
		soma = 0;
	}
}