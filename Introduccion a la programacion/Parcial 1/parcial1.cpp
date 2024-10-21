#include <iostream>
using namespace std;

struct coche
{
	string marca, matricula;
	int anoMatriculacion;
    float tiempoAce;
	char tipoCoche, etiqueta;
};

void CalcAceYDist (coche c, float &ace, float &dist)
{
// La variable c.tiempoAce almacena el tiempo que tarda de 0 a 28m/s entonces usamos 28 como velocidad final en las formulas
	ace = 28 / c.tiempoAce;
	dist = 14 * c.tiempoAce; //28/2 = 14, simplificando el cálculo
}
char EtiquetaTurismo (coche c) //Toma el tipo de turismo y devuelve su etiqueta
{
	switch (c.tipoCoche)
	{
		case 'B':
		case 'H': 
			return '0';
			break;
		case 'E':
		case 'A':
			return 'E';
			break;
	}
	if(c.tipoCoche == 'G')
	{
		if(c.anoMatriculacion < 2006)
		{
			return 'B';
		}
		return 'C';
	}
	if(c.tipoCoche == 'D')
	{
		if(c.anoMatriculacion < 2015)
		{
			return 'B';
		}
		return 'C';
	}
	return 'N'; //Solo se ejecuta si la entrada no está contemplada
}

//Usamos un parámetro de tipo dato-resultado para recibir y devolver la información a través de la misma variable
void LeerCoche(coche &c) 
{
	cout << "Marca del turismo: ";
	cin >> c.marca; //string
	cout << "Matricula del turismo: ";
	cin >> c.matricula; //string
	cout << "Año de matriculación: ";
	cin >> c.anoMatriculacion; //int
	cout << "Tiempo de 0 a 28m/s: ";
	cin >> c.tiempoAce; //float
	cout << "Tipo de turismo (D / G / B / H / E / A): ";
	cin >> c.tipoCoche; //char
// Una vez tomados los datos del turismo, pasa el tipo de turismo a la        función para calcular la etiqueta correspondiente
	c.etiqueta = EtiquetaTurismo( c ); //char
}

int main()
{
	//Léxico
	coche c;
	float ace, dist;
	
	//Algoritmo
	LeerCoche( c );
	CalcAceYDist( c, ace, dist );

	cout << "La marca del turismo es: " << c.marca << endl;
	cout << "La matrícula del turismo es: " << c.matricula << endl;
	cout << "La etiqueta energética del turismo es: " << c.etiqueta << endl;
	cout << "La aceleración del turismo de 0 a 28m/s^2 es: " << ace << endl;
	cout << "La distancia recorrida acelerando es: " << dist << endl;

    return 0;
}
