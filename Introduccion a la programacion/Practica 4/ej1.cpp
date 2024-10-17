#include <iostream>

int main()
{
	struct fecha
	{
		int dia;
		int mes;
		int ano;
	};

	int largoMes;

	fecha f = {1, 1, 1};
	
	std::cout << "Inserta una fecha en formato (DD MM AAAA): ";
	std::cin >> f.dia >> f.mes >> f.ano;
	
	if(f.dia > 31 || f.dia <= 0)
	{
		std::cout << "Formato invalido";
		return -1;
	}
	if(f.mes > 12 || f.mes <= 0)
	{
		std::cout << "Formato invalido";
		return -1;
	}
	if(f.ano < 1)
	{
		std::cout << "Formato invalido";
		return -1;
	}

	switch(f.mes)
	{
		case 2: //FEBRERO
			largoMes = 28;
			break;
			
		case 4: //MESES DE 30
		case 6:
		case 9:
		case 11:
			largoMes = 30;
			break;
			
		case 1: //MESES DE 31
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			largoMes = 31;
			break;

		default:
			std::cout << "Formato invalido";
			return -1;
			break;
	}

	if(f.dia < largoMes)
	{
		f.dia++;
	}
	else
	{
		f.dia = 1;
		f.mes++;

		if(f.mes > 12)
		{
			f.dia = 1;
			f.mes = 1;
			f.ano++;
		}
	}
	
	std::cout << "La fecha del dia siguiente es: " << f.dia << "/" << f.mes << "/" << f.ano;
	
	return 0;
}
