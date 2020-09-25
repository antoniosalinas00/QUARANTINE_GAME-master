#pragma once
#include <iostream>

using namespace System;
using namespace std;
using namespace System::Drawing;

enum Direccion {Arriba, Abajo, Izquierda, Derecha} ;

class Objeto {
protected:
	int x, y, dx, dy, ancho, alto, columna, fila;
public:
	Objeto();
	int getx(), gety(), getdx(), getdy(), getancho(), getalto();
	void setx(int), sety(int), setdx(int), setdy(int), setancho(int), setalto(int);
	virtual void mover(Graphics^ canvas, Direccion direccion);
	virtual void mostrar(Graphics^ canvas, Bitmap^ sprite);
	Rectangle getarea() {
		return Rectangle(x,y,ancho,alto);
	}
};

Objeto::Objeto() {
	System::Threading::Thread::Sleep(20);
}

int Objeto::getx() {
	return x;
}
int Objeto::gety() {
	return y;
}
int Objeto::getdx() {
	return dx;
}
int Objeto::getdy() {
	return dy;
}
int Objeto::getancho() {
	return ancho;
}
int Objeto::getalto() {
	return alto;
}

void Objeto::setx(int x) {
	this->x = x;
}
void Objeto::sety(int y) {
	this->y = y;
}
void Objeto::setdx(int dx) {
	this->dx = dx;
}
void Objeto::setdy(int dy) {
	this->dy = dy;
}
void Objeto::setancho(int ancho) {
	this->ancho = ancho;
}
void Objeto::setalto(int alto) {
	this->alto = alto;
}
void Objeto::mover(Graphics^ canvas, Direccion direccion){

}
void Objeto::mostrar(Graphics^ canvas, Bitmap^ sprite) {

}
