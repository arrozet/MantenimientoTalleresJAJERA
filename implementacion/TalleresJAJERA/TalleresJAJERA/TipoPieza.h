#pragma once
#include <string>
#include <vector>
#include "DBContext.h"

// Habilitamos el uso del namespace std
using namespace std;

class TipoPieza {
private:
    string idTipo;     // ID del tipo de pieza
    string nombre;     // Nombre del tipo de pieza

public:
    // Constructores
    TipoPieza(const string& idTipo); // Carga un tipo existente
    TipoPieza(const string& idTipo, const string& nombre); // Inserta un nuevo tipo

    // M�todos est�ticos
    static vector<TipoPieza> ListarTodos();

    // Getters y Setters
    string getIdTipo() const;
    void setIdTipo(const string& idTipo);

    string getNombre() const;
    void setNombre(const string& nombre);

    // M�todos de instancia
    void borrar();
    string toString() const;

    // Sobrecarga de operadores
    bool operator==(const TipoPieza& other) const;

    // DBContext est�tico para compartir la conexi�n
    static DBContext db;
};
