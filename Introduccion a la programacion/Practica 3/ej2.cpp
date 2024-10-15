#include <iostream>

using namespace std;

float calcInteres(float cantidad, int plazo, float porcentajeInteres)
{
	return cantidad * plazo * porcentajeInteres;
}

float calcRecargo(float cantidad, float interes, bool riesgo)
{
	return (cantidad + interes) * 0.01 * riesgo; 
}

float calcTotal(float cantidad, float interes, float recargo, bool riesgo)
{
	if(riesgo)
	{
		return cantidad + interes + recargo;
	}
	return cantidad + interes;
}

int main()
{
	//Entradas
	int plazo;
	float cantidad, porcentajeInteres;
	bool riesgo;
	char _riesgo;
	
	//Calculos
	float interesCalculado, recargo, total, mensualidad;
	
	//Entrada de datos
	cout << "Introduzca cantidad prestada: ";
	cin >> cantidad;
	cout << "Introduzca el plazo del prestamo en meses: ";
	cin >> plazo;
	cout << "Introduzca el porcentaje de interes: ";
	cin >> porcentajeInteres;
	cout << "Introduzca si es cliente de riesgo (s/n): ";
	cin >> _riesgo;
	
	//Entrada de riesgo
	switch(_riesgo)
	{
		case 's':
		case 'S':
			riesgo = true;
			break;
		case 'n':
		case 'N':
			riesgo = false;
			break;
		default:
			cout << "Entrada incorrecta, usando falso por defecto" << endl;
			riesgo = false;
			break;
	}
	
	//Validar interes
	if(porcentajeInteres >= 1)
	{
		porcentajeInteres = porcentajeInteres / 100;
	}
	
	//Calculos
	interesCalculado = calcInteres(cantidad, plazo, porcentajeInteres);
	recargo = calcRecargo(cantidad, interesCalculado, riesgo);
	total = calcTotal(cantidad, interesCalculado, recargo, riesgo);
	mensualidad = total / plazo;
	
	//Salida de datos
	cout << endl;
	cout << "El total a pagar es: " << "\033[" << 32 << "m" << total << "\033[0m" << " euros" << endl;
	cout << "El interes calculado es: " << "\033[" << 32 << "m" << interesCalculado << "\033[0m" << " euros" << endl;
	cout << "El recargo calculado es: " << "\033[" << 32 << "m" << recargo << "\033[0m" << " euros" << endl;
	cout << "Debe ser ingresado en " << "\033[" << 32 << "m" << plazo << "\033[0m" << " plazos de " << "\033[" << 32 << "m" << mensualidad << "\033[0m" << " euros cada una" << endl; 
	
	return 0;
}
