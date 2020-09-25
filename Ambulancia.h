#pragma once
#include "Ayudante.h"

class Ambulancia : public Ayudante {
private:
	bool rescatar;
	bool eliminaradversario;
	bool escapar;
public:
	Ambulancia();
	~Ambulancia();
	void mostrar(Graphics^ canvas, Bitmap^ sprite);
	void perseguir(vector<Adversario*>*, estadomovimiento);
	void mover(Direccion dir);
	
	void seteliminaradversario();
	void setrescatar();
	void setescapar();
	bool getrescatar();
	bool geteliminaradversario();
	bool getescapar();

	Adversario* getadversario();
	void setadversario(Adversario*);
};

Ambulancia::Ambulancia(){
	x = 400;
	y = 720;
	dx = dy = 10;
	columna = fila = 0;
	rescatar = false;
	escapar = false;
	eliminaradversario = false;
}
void Ambulancia::mover(Direccion dir) {
	switch (dir)
	{
	case Arriba:
		y -= dy;
		fila = 3;
		break;
	case Abajo:
		y += dy;
		fila = 2;
		break;
	case Izquierda:
		x -= dx;
		fila = 1;
		break;
	case Derecha:
		x += dx;
		fila = 0;
		break;
	}

}
void Ambulancia::perseguir(vector <Adversario*>* _adversarios,estadomovimiento estado) {
	for (int i = 0; i < _adversarios->size(); i++) {
		if (_adversarios->at(i)->getestadogolpe()) {
			adversario = _adversarios->at(i);
			break;
		}
	}

	switch (estado) {
	case Perseguir:
		if (adversario->gety() < y) {
			if (y - adversario->gety() > 4) mover(Arriba);
		}
		else if (adversario->gety() > y) {
			if (adversario->gety() - y > 4) mover(Abajo);
		}

		if (adversario->getx() < x) {
			if (x - adversario->getx() > 4) mover(Izquierda);
		}
		else if (adversario->getx() > x) {
			if (adversario->getx() - x > 4) mover(Derecha);
		}
		break;
	case Rescatar:
		if (adversario->getx() - 6 <= x && adversario->getx() + 6 >= x) {
			if (adversario->gety() - 6 <= y && adversario->gety() + 6 >= y) {
				eliminaradversario = true;
			}
		}
		break;
	case Escapar:
		if (x - dx > 400) {
			mover(Izquierda);
			mover(Izquierda);
			mover(Izquierda);
		}
		else if (x + dx < 400) {
			mover(Derecha);
			mover(Derecha);
			mover(Derecha);
		}
		else if ((x - dx <= 400 || x + dx >= 400) && y + dy < 680) {
			mover(Abajo);
			mover(Abajo);
			if (y + dy >= 680) escapar = false;
		}
		break;
	}
}
void Ambulancia::mostrar(Graphics^ canvas, Bitmap^ sprite) {
	alto = sprite->Height / 4;
	ancho = sprite->Width;
	Rectangle molde = Rectangle(columna*ancho, fila*alto, ancho, alto);
	canvas->DrawImage(sprite, x, y, molde, GraphicsUnit::Pixel);
}

void Ambulancia::setadversario(Adversario* newadversary) {
	adversario = newadversary;
}
void Ambulancia::seteliminaradversario() {
	eliminaradversario = !eliminaradversario;
}
void Ambulancia::setrescatar() {
	rescatar = true;
}
void Ambulancia::setescapar() {
	escapar = true;
	rescatar = false;
	eliminaradversario = false;
}
bool  Ambulancia::getrescatar() {
	return rescatar;
}
bool  Ambulancia::geteliminaradversario() {
	return eliminaradversario;
}
bool  Ambulancia::getescapar() {
	return escapar;
}
Adversario*  Ambulancia::getadversario() {
	return adversario;
}

Ambulancia::~Ambulancia() {

}