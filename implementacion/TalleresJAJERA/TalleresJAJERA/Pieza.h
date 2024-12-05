#pragma once
#include <string>
#include <vector>
#include "DBContext.h"

// Habilitamos el uso del namespace std
using namespace std;

class Pieza {
private:
    int id;
    string nombre;
    string fabricante;
    string idTipo;

public:
    // Constructores
    Pieza(int id);
    Pieza(const string& nombre, const string& fabricante, const string& idTipo);

    // M�todos est�ticos
    static vector<Pieza> ListarTodas();
    static vector<Pieza> ListarPorTipo(const string& idTipo);

    // Getters y Setters
    int getId() const;

    string getNombre() const;
    void setNombre(const string& nombre);

    string getFabricante() const;
    void setFabricante(const string& fabricante);

    string getIdTipo() const;
    void setIdTipo(const string& idTipo);

    // M�todos de instancia
    void borrar();
    string toString() const;

    // Sobrecarga de operadores
    bool operator==(const Pieza& other) const;

    // DBContext est�tico para compartir la conexi�n
    static DBContext db;
};
