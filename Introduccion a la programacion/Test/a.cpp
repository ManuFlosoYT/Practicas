#include <iostream>

using namespace std;

struct Punto
{
    float x, y;
};

struct Cuadrado
{
    Punto pos1, pos2;
    float base, altura;
};

bool EsCuadrado(Cuadrado c)
{
    if(c.base == c.altura)
    {
        return true;
    }
    return false;
}

void LeerCuadrado(Cuadrado &d)
{
    cout << "Pon los valores X e Y de la primera esquina: ";
    cin >> d.pos1.x >> d.pos1.y;
    cout << "Pon los valores X e Y de la segunda esquina: ";
    cin >> d.pos2.x >> d.pos2.y;
    cout << "Pon la base y la altura del cuadrilatero: ";
    cin >> d.base >> d.altura;
}

bool Alineados(Cuadrado a, Cuadrado b)
{
    if((a.pos1.x == b.pos1.x) && (a.pos1.y == b.pos1.y))
    {
        return true;
    }
    return false;
}


int main()
{
    Cuadrado cuadro1, cuadro2;
    bool alineados, esCuadrado1, esCuadrado2;

    LeerCuadrado(cuadro1);
    LeerCuadrado(cuadro2);
    
    alineados = Alineados(cuadro1, cuadro2);

    esCuadrado1 = EsCuadrado(cuadro1);
    esCuadrado2 = EsCuadrado(cuadro2);

    if(alineados)
    {
        cout << "Ambos cuadrilateros estan alineados" << endl;
    }

    if(esCuadrado1)
    {
        cout << "El primer cuadrilatero es un cuadrado, su area es: " << cuadro1.base * cuadro1.altura << endl;
    }
    else
    {
        cout << "El primer cuadrilatero no es un cuadrado, su perimetro es: " << cuadro1.base * 2 + cuadro1.altura * 2;
    }

    if(esCuadrado2)
    {
        cout << "El segundo cuadrilatero es un cuadrado, su area es: " << cuadro2.base * cuadro2.altura;
    }
    else
    {
        cout << "El segundo cuadrilatero no es un cuadrado, su perimetro es: " << cuadro2.base * 2 + cuadro2.altura * 2 << endl;
    }

    return 0;
}
