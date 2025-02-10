default: all

all: ejemplo-depuracion

ejemplo-depuracion: ejemplo-depuracion.c mips-runtime.c mips-runtime.h keyio.c keyio.h
# Compilado con -static para asegurar que funciona en los laboratorios
	gcc -static -Wall -g -std=c99 -O2 -oejemplo-depuracion ejemplo-depuracion.c mips-runtime.c keyio.c

clean:
	rm -f ejemplo-depuracion 
