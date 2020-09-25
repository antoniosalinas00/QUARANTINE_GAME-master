#pragma once
#include "Objeto.h"

class Jugador : public Objeto {
private:
	int vidas;
	Direccion dir;
public:
	Jugador(int);
	void mover(Graphics^);
	void mostrar(Graphics^, Bitmap^);
	void setvidas(int n) {
		vidas = n;
	}
	void setfila(int);
	void setdir(Direccion);
	int getvidas() {
		return vidas;
	}
	Direccion getdir() {
		return dir;
	}
	~Jugador() {

	}
};

Jugador::Jugador(int _vidas) {
	vidas = _vidas;
	x = y = 400;
	dx = dy = 0;
	columna = fila = 0;
}

void Jugador::mover(Graphics^ g){
	if (x + dx >= 0 && x + ancho +dx < g->VisibleClipBounds.Width) x += dx;
	if (y + dy >= 100 && y + alto + dy < g->VisibleClipBounds.Height)y += dy;
}

void Jugador::mostrar(Graphics^ canvas, Bitmap^ sprite) {
	alto = sprite->Height / 4;
	ancho = sprite->Width / 4;
	Rectangle molde = Rectangle(columna*ancho,fila*alto,ancho, alto);
	canvas->DrawImage(sprite, x, y, molde, GraphicsUnit::Pixel);
	columna++;
	if (columna == 4) {
		columna = 0;
	}
}

void Jugador::setfila(int _fila){
	fila = _fila;
}
void Jugador::setdir(Direccion _dir){
	dir = _dir;
}