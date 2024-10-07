#include <iostream>

int main()
{
	struct fecha
	{
		int dia;
		int mes;
		int ano;
	};

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
			if(f.dia < 28)
			{
				f.dia++;
			}
			else
			{
				f.dia = 1;
				f.mes++;
			}
			break;
			
		case 4: //MESES DE 30
		case 6:
		case 9:
		case 11:
			if(f.dia < 30)
			{
				f.dia++;
			}
			else
			{
				f.dia = 1;
				f.mes++;
			}
			break;
			
		case 1: //MESES DE 31
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
			if(f.dia < 31)
			{
				f.dia++;
			}
			else
			{
				f.dia = 1;
				f.mes++;
			}
			break;
			
		case 12: //DICIEMBRE
			if(f.dia < 31)
			{
				f.dia++;
			}
			else
			{
				f.dia = 1;
				f.mes = 1;
				f.ano++;
			}
			break;
			
		default:
			std::cout << "Formato invalido";
			return -1;
			break;
	}
	
	std::cout << "La fecha del dia siguiente es: " << f.dia << "/" << f.mes << "/" << f.ano;
	
	return 0;
}
