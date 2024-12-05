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

    // Métodos estáticos
    static vector<TipoPieza> ListarTodos();

    // Getters y Setters
    string getIdTipo() const;
    void setIdTipo(const string& idTipo);

    string getNombre() const;
    void setNombre(const string& nombre);

    // Métodos de instancia
    void borrar();
    string toString() const;

    // Sobrecarga de operadores
    bool operator==(const TipoPieza& other) const;

    // DBContext estático para compartir la conexión
    static DBContext db;
};
