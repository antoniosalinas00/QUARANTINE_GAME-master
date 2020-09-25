#pragma once
#include "Objeto.h"

class Pantalla {
	int x, y, ancho, alto, columna, fila;
public:
	Pantalla() {
		x = y = 0;
		columna = fila = 0;
	}
	;
	void mostrar(Graphics^ c, Bitmap^ sprite, int nivel) {
		alto = sprite->Height /3;
		ancho = sprite->Width/5;
		if (nivel == 1) fila = 0;
		if (nivel == 2) fila = 1;
		if (nivel == 3) fila = 2;
		Rectangle molde = Rectangle(columna*ancho, fila*alto, ancho, alto);
		c->DrawImage(sprite, x, y, molde, GraphicsUnit::Pixel);
		columna++;
		if (columna == 5) {
			columna = 0;
		}
	};
};