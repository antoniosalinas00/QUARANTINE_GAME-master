#pragma once
#include "Objeto.h"

class Mensaje : public Objeto {
private:
	Direccion dir;
	int tipo;
public:
	Mensaje(int, int, Direccion _dir);
	Mensaje(Direccion, int, int);
	~Mensaje();
	void mostrar(Graphics^ canvas, Bitmap^ sprite);
	void mover(Graphics^ canvas);
	
};
Mensaje::Mensaje(int _x, int _y, Direccion _dir) {
	dir = _dir;
	x = _x;
	y = _y;
	dx = dy = 16;
	columna = fila = 0;
	tipo = 1;
}
Mensaje::Mensaje(Direccion _dir, int _x, int _y) {
	dir = _dir;
	x = _x;
	y = _y;
	dx = dy = 16;
	columna = fila = 0;
	tipo = 2;
}

Mensaje::~Mensaje() {

}

void Mensaje::mostrar(Graphics^ canvas, Bitmap^ sprite) {
	if (tipo == 1) {
		alto = sprite->Height / 2;
		ancho = sprite->Width;
	}
	if (tipo == 2) {
		alto = sprite->Height / 4;
		ancho = sprite->Width;
	}
	Rectangle molde = Rectangle(columna*ancho, fila*alto, ancho, alto);
	canvas->DrawImage(sprite, x, y, molde, GraphicsUnit::Pixel);
	if (tipo == 2) {
		fila++;
		if (fila == 4)fila = 0;
	}
}
void Mensaje::mover(Graphics^ canvas) {
	if (tipo == 1) {
		switch (dir)
		{
		case Arriba:
			y -= dy;
			fila = 1;
			break;
		case Abajo:
			y += dy;
			fila = 1;
			break;
		case Izquierda:
			x -= dx;
			fila = 0;
			break;
		case Derecha:
			x += dx;
			fila = 0;
			break;
		}
	} else if (tipo == 2) {
		switch (dir)
		{
		case Arriba:
			y -= dy;
			break;
		case Abajo:
			y += dy;
			break;
		case Izquierda:
			x -= dx;
			break;
		case Derecha:
			x += dx;
			break;
		}
	}
}
