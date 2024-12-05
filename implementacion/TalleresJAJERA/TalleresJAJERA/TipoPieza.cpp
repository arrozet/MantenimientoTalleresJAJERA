#include "TipoPieza.h"
#include <iostream>
#include <stdexcept>

// Habilitamos el uso del namespace std
using namespace std;

// Define el DBContext estático
DBContext TipoPieza::db;

// Constructor para cargar un tipo de pieza existente
TipoPieza::TipoPieza(const string& idTipo) {
    auto res = db.select("SELECT * FROM tTipoPieza WHERE ID_TIPO = '" + idTipo + "'");
    if (res.empty()) {
        throw runtime_error("Tipo de pieza no encontrado");
    }
    this->idTipo = res[0][0];
    this->nombre = res[0][1];
}

// Constructor para insertar un nuevo tipo de pieza
TipoPieza::TipoPieza(const string& idTipo, const string& nombre) {
    db.execute("INSERT INTO tTipoPieza (ID_TIPO, NOMBRE) VALUES ('" + idTipo + "', '" + nombre + "')");
    this->idTipo = idTipo;
    this->nombre = nombre;
}

// Listar todos los tipos de piezas
vector<TipoPieza> TipoPieza::ListarTodos() {
    vector<TipoPieza> tipos;
    auto res = db.select("SELECT ID_TIPO FROM tTipoPieza");
    for (const auto& row : res) {
        tipos.emplace_back(row[0]);
    }
    return tipos;
}

// Getters y Setters
string TipoPieza::getIdTipo() const {
    return idTipo;
}

void TipoPieza::setIdTipo(const string& idTipo) {
    db.execute("UPDATE tTipoPieza SET ID_TIPO = '" + idTipo + "' WHERE ID_TIPO = '" + this->idTipo + "'");
    this->idTipo = idTipo;
}

string TipoPieza::getNombre() const {
    return nombre;
}

void TipoPieza::setNombre(const string& nombre) {
    db.execute("UPDATE tTipoPieza SET NOMBRE = '" + nombre + "' WHERE ID_TIPO = '" + this->idTipo + "'");
    this->nombre = nombre;
}

// Borrar tipo de pieza
void TipoPieza::borrar() {
    db.execute("DELETE FROM tTipoPieza WHERE ID_TIPO = '" + this->idTipo + "'");
    this->idTipo = "";
    this->nombre = "";
}

// Representación en cadena
string TipoPieza::toString() const {
    return "TipoPieza: " + idTipo + " (" + nombre + ")";
}

// Comparación
bool TipoPieza::operator==(const TipoPieza& other) const {
    return this->idTipo == other.idTipo;
}
