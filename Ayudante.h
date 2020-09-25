#pragma once
#include "Objeto.h"
#include "Adversario.h"
#include <vector>
enum estadomovimiento { Perseguir, Rescatar, Escapar };
class Ayudante : public Objeto {
protected:
	Adversario* adversario;
public:
	Ayudante() {
		
	}
	
	~Ayudante() {
	}
	virtual void perseguir(){
	}
};