#include <windows.h>
#include <stdio.h>

int sumatorio(int n)
{
    if (n == 1) return 1;
    return n + sumatorio(n - 1);
}

int suma_digitos(int n)
{
    if (n < 10) return n;
    return n % 10 + suma_digitos(n / 10);
}

int longitud(const char* s)
{
    if (*s == '\0') return 0;
    return 1 + longitud(s + 1);
}

void piramide(char* s)
{
    if (*s == '\0') return;
    piramide(s + 1);
    printf("%s\n", s);
}

void piramide_invertida(char * s)
{
    if (*s == '\0') return;
    printf("%s\n", s);
    piramide_invertida(s + 1);
}

int palindromo_aux(char* s, int i, int j)
{
    if (i >= j) return 1;
    if (s[i] != s[j]) return 0;
    return palindromo_aux(s, i+1, j-1);
}

int palindromo(char* s)
{
    return palindromo_aux(s, 0, longitud(s) - 1);
}

char* copia(char* s1, const char* s2) 
{
    if (*s2 == '\0') 
    {
        *s1 = '\0';
        return s1;
    }
    *s1 = *s2;
    copia(s1 + 1, s2 + 1);
    return s1;
}

void sustituye(char* s, char a, char b)
{
    if (*s == '\0') return;
    if (*s == a) *s = b;
    sustituye(s + 1, a, b);
}

int main()
{
    //Activar la consola con caracteres Españoles
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    
    int n;

    printf("Introduce un número entero positivo >= 1: ");
    scanf("%d", &n);
    printf("El sumatorio de %d es %d\n", n, sumatorio(n));

    printf("Introduce un número entero positivo: ");
    printf("La suma de los dígitos de %d es %d\n", n, suma_digitos(n));

    printf("Introduce una cadena de caracteres <=256 caracteres: ");
    char cadena[256];
    scanf("%s", cadena);
    printf("La longitud de la cadena \"%s\" es %d\n", cadena, longitud(cadena));
    piramide(cadena);
    piramide_invertida(cadena);
    printf("La cadena \"%s\" %s un palíndromo\n", cadena, palindromo(cadena) ? "es" : "no es");

    const char cadenaFija[256] = "Hola Mundo";
    char* cadenaCopia = (char*)malloc(sizeof(char) * (longitud(cadenaFija) + 1));
    copia(cadenaCopia, cadenaFija);
    printf("La copia de la cadena fija \"%s\" es \"%s\"\n", cadenaFija, cadenaCopia);
    
    char a, b;
    while (getchar() != '\n'); // Limpiar el buffer de entrada
    printf("Introduce un carácter a sustituir: ");
    scanf("%c", &a);

    while (getchar() != '\n'); // Limpiar el buffer de entrada
    printf("Introduce el carácter por el que sustituir: ");
    scanf("%c", &b);
    
    sustituye(cadena, a, b);
    printf("La cadena \"%s\" después de sustituir '%c' por '%c' es: ", cadena, a, b);

    free(cadenaCopia);
    return 0;
}