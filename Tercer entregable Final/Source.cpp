#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <vector>
#include <string>


using namespace std;
using namespace System;


int Reflexivo(vector<string>RelacionI, vector<string>RelacionD, int cantidad)
{
	int cant_reflexivo = 0;
	int reflexivo = 0;
	for (int i = 0; i < RelacionI.size(); i++)
	{
		if (RelacionI[i] == RelacionD[i])
		{
			cant_reflexivo++;
		}

	}
	if (cant_reflexivo == cantidad) reflexivo = 1;
	return reflexivo;

}

int Irreflexivo(vector<string>RelacionI, vector<string>RelacionD)
{
	int bucle = 0;
	int irreflexivo = 1;
	for (int i = 0; i < RelacionI.size(); i++)
	{
		if (RelacionI[i] == RelacionD[i])
		{
			bucle++;
		}

	}
	if (bucle > 0) irreflexivo = 0;
	return irreflexivo;

}
int Simetrico(vector<string>RelacionI, vector<string>RelacionD)
{
	int cant = 0;
	int simetrico = 0;
	for (int i = 0; i < RelacionI.size(); i++)
	{
		for (int f = 0; f < RelacionI.size(); f++)
		{
			if ((RelacionI[i] == RelacionD[f]) && (RelacionD[i] == RelacionI[f]))
			{
				cant++;
			}

		}

	}
	if (cant == RelacionI.size()) simetrico = 1;
	return simetrico;

}

int Asimetrico(vector<string>RelacionI, vector<string>RelacionD)
{
	int cant = 0;
	int asimetrico = 1;
	for (int i = 0; i < RelacionI.size(); i++)
	{
		for (int f = 0; f < RelacionI.size(); f++)
		{
			if ((RelacionI[i] == RelacionD[f]) && (RelacionD[i] == RelacionI[f]))
			{
				cant++;
			}

		}

	}
	if (cant > 0) asimetrico = 0;
	return asimetrico;

}
int Antisimetrico(vector<string>RelacionI, vector<string>RelacionD)
{
	int cant = 0;
	int antisimetrico = 1;
	for (int i = 0; i < RelacionI.size(); i++)
	{
		for (int f = 0; f < RelacionI.size(); f++)
		{
			if ((RelacionI[i] == RelacionD[f]) && (RelacionD[i] == RelacionI[f]) && (RelacionI[f] != RelacionD[f]))
			{
				cant++;
			}

		}

	}
	if (cant > 0) antisimetrico = 0;
	return antisimetrico;

}
int Transitivo(vector<string> RelacionI, vector<string> RelacionD)
{
	int entro = 0;
	int transitivo = 0;
	int encontrado = 0;
	for (int i = 0; i < RelacionI.size(); i++) {
		for (int j = 0; j < RelacionI.size(); j++) {
			if (RelacionD[i] == RelacionI[j]) {
				entro = 1;
				for (int k = 0; k < RelacionI.size(); k++) {
					if (RelacionI[k] == RelacionI[i] && RelacionD[k] == RelacionD[j]) {
						encontrado = 1;
						break;
					}
				}
				if (encontrado == 0)
				{
					transitivo = 0;
					return transitivo;
				}
				encontrado = 0;
			}

		}
	}
	if (entro == 1) transitivo = 1;
	return transitivo;
}

void conjuntoCociente(vector<string> RelacionI, vector<string> RelacionD, vector<string> ConjuntoA)
{
	vector<vector<string>>conjCociente;
	vector<string>valClase;
	int condicion = 0;

	for (int i = 0; i < ConjuntoA.size(); i++)
	{
		valClase.clear();
		condicion = 0;

		for (int j = 0; j < RelacionD.size(); j++)
		{
			if (RelacionD[j] == ConjuntoA[i])
			{
				valClase.push_back(RelacionI[j]);
			}
		}

		if (conjCociente.size() == 0)
		{
			conjCociente.push_back(valClase);
		}
		else
		{
			for (int a = 0; a < conjCociente.size(); a++)
			{
				for (int b = 0; b < conjCociente[a].size(); b++)
				{
					for (int c = 0; c < valClase.size(); c++)
					{
						if (valClase[c] == conjCociente[a][b])
						{
							condicion = 1;
						}
					}
				}
			}
			if (condicion == 0)
			{
				conjCociente.push_back(valClase);
			}
		}
	}

	cout << endl << "Conjunto cociente del conjunto A con respecto a la relacion R es: " << endl << endl;
	cout << "A|R = { ";

	for (int x = 0; x < conjCociente.size(); x++)
	{
		cout << " {";

		for (int y = 0; y < conjCociente[x].size(); y++)
		{
			if (y == conjCociente[x].size() - 1)
			{
				cout << conjCociente[x][y];
			}
			else
			{
				cout << conjCociente[x][y] << "; ";
			}
		}
		cout << " } ";
	}
	cout << " }";
	
}

void funOrdenParcial(vector<string> RelacionI, vector<string> RelacionD, int cantidad, vector<string> conjuntoA)
{
	

	string** matriz;
	matriz = new string * [cantidad + 3];

	for (int i = 0; i < cantidad + 3; i++)
	{
		matriz[i] = new string[cantidad + 3];
	}

	cout << "\n" << "- Matriz del conjunto parcialmente ordenado:" << endl << endl << endl;


	for (int i = 0; i < cantidad + 3; i++)
	{
		for (int j = 0; j < cantidad + 3; j++)
		{
			if (i == 0 && j == 0 || i == 0 && j == 1 || i == 0 && j == cantidad + 2 || i == 1 && j != 1 && j != cantidad + 2 || i == cantidad + 2 && j != 1 && j != cantidad + 2)
			{
				matriz[i][j] = " ";
			}
			else if (j == 0 && i > 1 && i < cantidad + 2)
			{
				matriz[i][j] = conjuntoA[i - 2];
			}
			else if (i == 0 && j > 1 && j < cantidad + 2)
			{
				matriz[i][j] = conjuntoA[j - 2];
			}
			else if (j == 1 || j == cantidad + 2)
			{
				if (i == 1 && j == 1)
				{
					matriz[i][j] = char(218);
				}
				else if (i == 1 && j == cantidad + 2)
				{
					matriz[i][j] = char(191);
				}
				else if (i == cantidad + 2 && j == cantidad + 2)
				{
					matriz[i][j] = char(217);
				}
				else if (i == cantidad + 2 && j == 1)
				{
					matriz[i][j] = char(192);
				}
				else
				{
					matriz[i][j] = "|";
				}
			}
			else
			{
				matriz[i][j] = "0";
			}


			for (int i = 2; i < cantidad + 2; i++)
			{
				for (int j = 2; j < cantidad + 2; j++)
				{
					for (int k = 0; k < RelacionD.size(); k++)
					{
						if (matriz[i][0] == RelacionI[k] && matriz[0][j] == RelacionD[k])
						{
							matriz[i][j] = "1";
						}
					}
				}
			}

		}
	}

	for (int i = 0; i < cantidad + 3; i++)
	{
		for (int j = 0; j < cantidad + 3; j++)
		{
			cout << matriz[i][j] << "  " << " ";
		}
		cout << "\n" << "\n";
	}
	cout << "Presione cualquier tecla para continuar";
	_getch();
	cout << endl << endl;

	cout << "\n" << "- Matriz (paso 1):" << endl << endl << endl;

	for (int i = 2; i < cantidad + 2; i++)
	{
		for (int j = 2; j < cantidad + 2; j++)
		{
			for (int k = 0; k < RelacionD.size(); k++)
			{
				if (matriz[i][0] == RelacionI[k] && matriz[0][j] == RelacionD[k] && RelacionI[k] == RelacionD[k])
				{
					matriz[i][j] = "0";
				}
			}
		}
	}

	for (int i = 0; i < cantidad + 3; i++)
	{
		for (int j = 0; j < cantidad + 3; j++)
		{
			cout << matriz[i][j] << "  " << " ";
		}
		cout << "\n" << "\n";
	}

	cout << "Presione cualquier tecla para continuar";
	_getch();
	cout << endl << endl;

	cout << "\n" << "- Matriz (paso 2):" << endl << endl << endl;

	string* matrizAux;
	string** matrizProv;
	string** matrizHasse = matriz;
	int condicion = 0;

	matrizProv = new string * [cantidad + 3];

	for (int i = 0; i < cantidad + 3; i++)
	{
		matrizProv[i] = new string[cantidad + 3];
	}

	for (int i = 0; i < cantidad + 3; i++)
	{
		for (int j = 0; j < cantidad + 3; j++)
		{
			if (i == 0 && j == 0 || i == 0 && j == 1 || i == 0 && j == cantidad + 2 || i == 1 && j != 1 && j != cantidad + 2 || i == cantidad + 2 && j != 1 && j != cantidad + 2)
			{
				matrizProv[i][j] = " ";
			}
			else if (j == 0 && i > 1 && i < cantidad + 2)
			{
				matrizProv[i][j] = conjuntoA[i - 2];
			}
			else if (i == 0 && j > 1 && j < cantidad + 2)
			{
				matrizProv[i][j] = conjuntoA[j - 2];
			}
			else if (j == 1 || j == cantidad + 2)
			{
				if (i == 1 && j == 1)
				{
					matrizProv[i][j] = char(218);
				}
				else if (i == 1 && j == cantidad + 2)
				{
					matrizProv[i][j] = char(191);
				}
				else if (i == cantidad + 2 && j == cantidad + 2)
				{
					matrizProv[i][j] = char(217);
				}
				else if (i == cantidad + 2 && j == 1)
				{
					matrizProv[i][j] = char(192);
				}
				else
				{
					matrizProv[i][j] = "|";
				}
			}
			else
			{
				matrizProv[i][j] = "0";
			}
		}
	}

	for (int i = 2; i < cantidad + 2; i++)
	{
		matrizAux = matriz[i];

		for (int a = 2; a < cantidad + 2; a++)
		{
			for (int b = 2; b < cantidad + 2; b++)
			{
				if (matriz[a][b] == "1" && matrizAux[a] == "1")
				{
					matrizProv[i][b] = "1";
				}
			}
		}
	}

	for (int i = 0; i < cantidad + 3; i++)
	{
		for (int j = 0; j < cantidad + 3; j++)
		{
			cout << matrizProv[i][j] << "  " << " ";
		}
		cout << "\n" << "\n";
	}

	cout << "Presione cualquier tecla para continuar";
	_getch();
	cout << endl << endl;

	cout << "\n" << "- Matriz del Diagrama de Hasse (paso 3):" << endl << endl << endl;

	for (int i = 2; i < cantidad + 2; i++)
	{
		for (int j = 2; j < cantidad + 2; j++)
		{
			if (matriz[i][j] == "1" && matrizProv[i][j] == "1")
			{
				matrizHasse[i][j] = "0";
			}
		}
	}

	for (int i = 0; i < cantidad + 3; i++)
	{
		for (int j = 0; j < cantidad + 3; j++)
		{
			cout << matrizHasse[i][j] << "  " << " ";
		}
		cout << "\n" << "\n";
	}

	cout << "Presione cualquier tecla para continuar";
	_getch();
	cout << endl << endl;
	vector<string>Hasse;
	cout << "\n" << "- Explicacion de la Matriz del Diagrama de Hasse:" << endl << endl;

	for (int i = 2; i < cantidad + 2; i++)
	{
		for (int j = 2; j < cantidad + 2; j++)
		{
			if (matriz[i][j] == "1")
			{

				Hasse.push_back(matriz[0][j]);
			}

		}
		if (Hasse.size() > 0)
		{
			cout << "El elemento " << matriz[i][0] << " esta relacionado con: ";
			for (int k = 0; k < Hasse.size(); k++)
			{
				if (k == Hasse.size() - 1)
				{
					cout << Hasse[k];
				}
				else
				{
					cout << Hasse[k] << " ; ";
				}
			}
			cout << endl;
			Hasse = { };
		}
	}
}

int main()
{
	int num = 0;
	int opcion = 0;
	int cantidad = 0;
	char elemento[10];
	char elementoF[10];
	int numero;
	int contador = 0;
	int contadorNeg = 0;
	int reflexivo = -1;
	int irreflexivo = -1;
	int simetrico = -1;
	int asimetrico = -1;
	int antisimetrico = -1;
	int transitivo = -1;
	int equivalencia = 0;
	int orden_parcial = 0;
	string numeros;
	string letras;
	vector<char>conjunto(cantidad);
	vector<string>ConjuntoA;
	vector<string>CartesianoI;
	vector<string>CartesianoD;
	vector<string>RelacionI;
	vector<string>RelacionD;
	vector<string>VerifI;
	vector<string>VerifD;
	vector<int>posici;
	vector<string>IngresoI;
	vector<string>IngresoD;


	//Menú
	do
	{
		system("cls");
		printf("El Equipo 3 presenta:");
		printf("\n\nPROYECTO 2");
		printf("\n\nNumero de elementos para el conjunto A");
		printf("\n(Se aceptan valores entre 4 y 7)");
		printf("\n\nCantidad: ");
		cin >> cantidad;

	} while (cantidad < 4 || cantidad > 7);
	//Validación de datos
	vector<string>repeticion;
	repeticion.push_back("10000");
	
	for (int i = 1; i <= cantidad; i++)
	{
		do
		{
			int a = 0;
			contadorNeg = 0;
			cout << endl << "Ingrese el valor del elemento " << i << ": ";
			cin >> elemento;
			while (a < sizeof(elemento) - 1) {
				if (isdigit(elemento[a])) {
					contador++;
				}
				else {
					numero = int(elemento[a]);
					if (numero > 0 && numero < 255)
					{
						if (numero >= 97 && numero <= 122 || numero >= 65 && numero <= 90)
						{
							contador++;
						}
						else
						{
							contadorNeg++;
						}
					}
				}
				a++;
			}
			
			for (int j = 0; j < repeticion.size(); j++)
			{
				if (elemento == repeticion[j]) contadorNeg++;
				
			}
			repeticion.push_back(elemento);
		} while (contadorNeg != 0);

		cout << endl << "Elemento " << i << " ingresado: " << elemento << endl << endl;
		
		ConjuntoA.push_back(elemento);
		
	}
	cout << endl;
	cout << "Luego de haber ingresado los " << cantidad << " elementos, se le\npresenta a continuacion el conjunto A por extension:";
	cout << endl << endl << "A = { ";
	for (int i = 0; i < ConjuntoA.size(); i++)
	{
		if (i == ConjuntoA.size() - 1)
		{
			cout << ConjuntoA[i];
		}
		else
		{
			cout << ConjuntoA[i] << " ; ";
		}

	}
	cout << " }";
	cout << endl;

	//Producto Cartesiando Izquierda
	for (int i = 0; i < cantidad; i++)
	{
		for (int conteo = 0; conteo <= ConjuntoA.size() - 1; conteo++)
		{
			CartesianoI.push_back(ConjuntoA[i]);

		}

	}
	//Producto Cartesiando Derecha
	for (int conteo = 0; conteo <= ConjuntoA.size() - 1; conteo++)
	{
		for (int i = 0; i < cantidad; i++)
		{
			CartesianoD.push_back(ConjuntoA[i]);
		}
	}
	//Salida del Producto Cartesiaino
	cout << endl << "Producto Cartesiano de A: {";
	for (int i = 0; i < CartesianoI.size(); i++)
	{
		if (i == CartesianoI.size() - 1)
		{
			cout << "(" << CartesianoI[i] << "," << "" << CartesianoD[i] << ")";
		}
		else
		{
			cout << "(" << CartesianoI[i] << "," << "" << CartesianoD[i] << ") ; ";
		}
	}
	cout << " }";
	cout << endl;
	cout << endl;
	do
	{
		printf("Desea ingresar manualmente valores para la relacion R (1:Si, 0:No)?: ");
		cin >> opcion;

		if (opcion == 0) {
			printf("La relacion R se generara de manera aleatoria...");
		}

	} while (opcion != 0 && opcion != 1);
	cout << endl;
	//Generación de Relación R Izquierda y Derecha Aleatoria
	if (opcion == 0) {
		Random a;
		Random r;
		int canti = a.Next(1, pow(cantidad, 2) + 5);
		//canti = 1000;
		// si quieres que la relacion R tenga todos los elementos del producto cartesiano, coloca abajo: canti = 1000000;
		int pos;
		int comprob = 0;
		posici.push_back(100000000000000);
		for (int i = 0; i < canti; i++)
		{
			pos = r.Next(0, CartesianoI.size());
			for (int f = 0; f < posici.size(); f++)
			{
				if (pos == posici[f])
				{
					comprob = 1;
				}
			}
			if (comprob == 0)
			{
				RelacionI.push_back(CartesianoI[pos]);
				RelacionD.push_back(CartesianoD[pos]);
				posici.push_back(pos);
			}
			comprob = 0;

		}
	}
	//Generación de Relación R Izquierda y Derecha Manual
	if (opcion == 1)
	{
		int bloqueado = 0;
		int existe = 0;
		string izquierda;
		string derecha;
		int romper = 0;
		IngresoI.push_back("10000");
		IngresoD.push_back("10000");
		do {
			cout << "Ingrese la cantidad de subcojuntos que ingresara para la Relacion R: ";
			cin >> num;
		} while (num <= 0 || num > pow(cantidad, 2));
		cout << endl;
		for (int i = 0; i < num; i++)
		{

			cout << "Valor izquierdo # " << i + 1 << " de la relacion R: ";
			cin >> izquierda;
			cout << "Valor derecho # " << i + 1 << " de la relacion R: ";
			cin >> derecha;

			for (int j = 0; j < IngresoI.size(); j++)
			{
				if ((izquierda == IngresoI[j]) && (derecha == IngresoD[j])) {

					existe = 0;
					romper = 1;
					break;
				}
			}
			if (romper == 0)
			{
				for (int k = 0; k < CartesianoI.size(); k++)
				{


					if ((izquierda == CartesianoI[k]) && (derecha == CartesianoD[k]))
					{
						RelacionI.push_back(izquierda);
						RelacionD.push_back(derecha);
						IngresoI.push_back(izquierda);
						IngresoD.push_back(derecha);
						existe = 1;

					}


				}
			}
			cout << endl;

			if (existe == 0) i = i - 1;
			existe = 0;
			romper = 0;

		}


	}
	//Salida de la Relación
	cout << endl << "Relacion R generada aleatoriamente: {";
	for (int i = 0; i < RelacionI.size(); i++)
	{
		if (i == RelacionI.size() - 1)
		{
			cout << "(" << RelacionI[i] << "," << "" << RelacionD[i] << ")";
		}
		else
		{
			cout << "(" << RelacionI[i] << "," << "" << RelacionD[i] << ") ; ";
		}
	}
	cout << " }";
	cout << endl;
	//Clasificacion de relacion
	reflexivo = Reflexivo(RelacionI, RelacionD, cantidad);
	irreflexivo = Irreflexivo(RelacionI, RelacionD);
	simetrico = Simetrico(RelacionI, RelacionD);
	asimetrico = Asimetrico(RelacionI, RelacionD);
	antisimetrico = Antisimetrico(RelacionI, RelacionD);
	transitivo = Transitivo(RelacionI, RelacionD);
	if ((reflexivo == 1) && (simetrico == 1) && (transitivo == 1)) equivalencia = 1;
	if ((reflexivo == 1) && (antisimetrico == 1) && (transitivo == 1)) orden_parcial = 1;
	//Salida de la clasificacion
	cout << endl << "La relacion R es:" << endl;
	if (reflexivo == 1) cout << "\t-Reflexiva" << endl;
	if (irreflexivo == 1) cout << "\t-Irreflexiva" << endl;
	if (simetrico == 1) cout << "\t-Simetrica" << endl;
	if (asimetrico == 1) cout << "\t-Asimetrica" << endl;
	if (antisimetrico == 1) cout << "\t-Antisimetrica" << endl;
	if (transitivo == 1) cout << "\t-Transitiva" << endl;
	if (equivalencia == 0 || orden_parcial == 0)
	{
		if (reflexivo == 1 && simetrico == 0 && transitivo == 0)
		{
			cout  << "-La relacion no es de equivalencia porque solo es reflexiva (no es simetrica ni transitiva)" << endl;
			if (antisimetrico == 1) cout  << "-La relacion no es de orden parcial porque solo es reflexiva y antisimetrica (no es transitiva)" << endl;
			else cout  << "-La relación no es de orden parcial porque solo es reflexiva (no es antisimetrica ni transiitva) " << endl;
		}
		if (reflexivo == 1 && simetrico == 0 && transitivo == 1)
		{
			cout << "-La relacion no es de equivalencia porque solo es reflexiva y transitiva (no es simetrica)" << endl;
			if (antisimetrico == 0) cout << "-La relacion no es de orden parcial porque solo es reflexiva y transitiva (no es antisimetrica)" << endl;
		}
		if (reflexivo == 1 && simetrico == 1 && transitivo == 0)
		{
			cout << "-La relacion no es de equivalencia porque solo es reflexiva y simetrica (no es transitiva)" << endl;
			if (antisimetrico == 1) cout << "-La relacion no es de orden parcial porque solo es reflexiva y antisimetrica (no es transitiva)" << endl;
			else cout << "-La relacion no es de orden parcial porque solo es reflexiva (no es antisimetrica ni transitiva)" << endl;
			
		}
		if (reflexivo == 1 && simetrico == 1 && transitivo == 1)
		{
			if (antisimetrico == 0) cout << "-La relacion no es de orden parcial porque solo es reflexiva y transitiva (no es antisimetrica)" << endl;
		}
		if (reflexivo == 0 && simetrico == 1 && transitivo == 0)
		{
			cout << "-La relacion no es de equivalencia porque solo es simetrica (no es reflexiva ni transitiva)" << endl;
			if (antisimetrico == 1) cout << "-La relacion no es de orden parcial porque solo es antisimetrica (no es reflexiva ni transitiva)" << endl;
			else cout << "-La relacion no es de orden parcial porque no es reflexiva ni antisimetrica ni transitiva" << endl;
		}
		if (reflexivo == 0 && simetrico == 1 && transitivo == 1)
		{
			cout << "-La relacion no es de equivalencia porque solo es simetrica y transitiva (no es reflexiva)" << endl;
			if (antisimetrico == 1) cout << "-la relacion no es de orden parcial porque solo es antisimetrica y transitiva (no es reflexiva)" << endl;
			else cout << "-La relacion no es de orden parcial porque solo es transitiva (no es reflexiva ni antisimetrica)" << endl;
		}
		if (reflexivo == 0 && simetrico == 0 && transitivo == 1)
		{
			cout << "-La relacion no es de equivalencia porque solo es transitiva (no es reflexiva ni simetrica)" << endl;
			if (antisimetrico == 1) cout << "-La relacion no es de orden parcial porque solo es antisimetrica y transitiva (no es reflexiva)" << endl;
			else cout << "-La relacion no es de orden parcial porque solo es transitiva (no es ni antisimetrica ni reflexiva) " << endl;
		}
		if (reflexivo == 0 && simetrico == 0 && transitivo == 0)
		{
			cout << "-La relacion no es de equivalencia porque no es reflexiva ni simetrica ni transitiva" << endl;
			if (antisimetrico == 1) cout << "-La relacion no es de orden parcial porque solo es antisimetrica (no es reflexiva ni transitiva)" << endl;
			else cout << "-La relacion no es de orden parcial porque no es reflexiva ni antisimetrica ni transitiva" << endl;
		}
	}
	if ((reflexivo == 0) && (irreflexivo == 0) && (simetrico == 0) && (asimetrico == 0) && (antisimetrico == 0) && (transitivo == 0) && (equivalencia == 0) && (orden_parcial == 0)) cout <<endl<< "*Por ende, La relacion R no entra en ninguna clasificacion" << endl;

	//Resultado de equivalencia o de orden parcial
	if (equivalencia == 1)
	{
		cout << endl << "*Debido a sus clasificaciones anteriores, es una relacion de equivalencia" << endl << endl;
		conjuntoCociente(RelacionI, RelacionD, ConjuntoA);
	}
	cout << endl << endl;

	if (orden_parcial == 1)
	{
		cout << endl << "*Debido a sus clasificaciones anteriores, es una relacion de orden parcial" << endl << endl;
		funOrdenParcial(RelacionI, RelacionD, cantidad, ConjuntoA);
	}

	_getch();
	return 0;

}