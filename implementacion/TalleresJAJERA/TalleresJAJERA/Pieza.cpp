#include "Pieza.h"
#include <iostream>
#include <stdexcept>

// Habilitamos el uso del namespace std
using namespace std;

// Define el DBContext estático
DBContext Pieza::db;

// Constructor para cargar una pieza existente
Pieza::Pieza(int id) {
    auto res = db.select("SELECT * FROM tPiezas WHERE ID = " + to_string(id));
    if (res.empty()) {
        throw runtime_error("Pieza no encontrada");
    }
    this->id = stoi(res[0][0]);
    this->nombre = res[0][1];
    this->fabricante = res[0][2];
    this->idTipo = res[0][3];
}

// Constructor para insertar una nueva pieza
Pieza::Pieza(const string& nombre, const string& fabricante, const string& idTipo) {
    db.execute("INSERT INTO tPiezas (NOMBRE, FABRICANTE, ID_TIPO) VALUES ('" + nombre + "', '" + fabricante + "', '" + idTipo + "')");
    auto res = db.select("SELECT LAST_INSERT_ID()");
    if (res.empty()) {
        throw runtime_error("No se pudo obtener el ID de la nueva pieza");
    }
    this->id = stoi(res[0][0]);
    this->nombre = nombre;
    this->fabricante = fabricante;
    this->idTipo = idTipo;
}

// Listar todas las piezas
vector<Pieza> Pieza::ListarTodas() {
    vector<Pieza> piezas;
    auto res = db.select("SELECT ID FROM tPiezas");
    for (const auto& row : res) {
        piezas.emplace_back(stoi(row[0]));
    }
    return piezas;
}

// Listar piezas por tipo
vector<Pieza> Pieza::ListarPorTipo(const string& idTipo) {
    vector<Pieza> piezas;
    auto res = db.select("SELECT ID FROM tPiezas WHERE ID_TIPO = '" + idTipo + "'");
    for (const auto& row : res) {
        piezas.emplace_back(stoi(row[0]));
    }
    return piezas;
}

// Setters con actualización en la base de datos
void Pieza::setNombre(const string& nombre) {
    db.execute("UPDATE tPiezas SET NOMBRE = '" + nombre + "' WHERE ID = " + to_string(this->id));
    this->nombre = nombre;
}

void Pieza::setFabricante(const string& fabricante) {
    db.execute("UPDATE tPiezas SET FABRICANTE = '" + fabricante + "' WHERE ID = " + to_string(this->id));
    this->fabricante = fabricante;
}

void Pieza::setIdTipo(const string& idTipo) {
    db.execute("UPDATE tPiezas SET ID_TIPO = '" + idTipo + "' WHERE ID = " + to_string(this->id));
    this->idTipo = idTipo;
}

// Getters
int Pieza::getId() const {
    return id;
}

string Pieza::getNombre() const {
    return nombre;
}

string Pieza::getFabricante() const {
    return fabricante;
}

string Pieza::getIdTipo() const {
    return idTipo;
}

// Borrar pieza
void Pieza::borrar() {
    db.execute("DELETE FROM tPiezas WHERE ID = " + to_string(this->id));
    this->id = -1;
}

// Representación en cadena
string Pieza::toString() const {
    return "Pieza: " + nombre + " (" + fabricante + ")";
}

// Comparación
bool Pieza::operator==(const Pieza& other) const {
    return this->id == other.id;
}
