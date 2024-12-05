#include "Pieza.h"
#include <iostream>
#include <stdexcept>

// Variables globales definidas
std::string BDServer = "database-minipim.cdwgeayaeh1v.eu-central-1.rds.amazonaws.com:3306?auth_plugin=mysql_native_password";
std::string User = "grupo07";
std::string Password = "FjLWM6DNk6TJDzfV";
std::string BDName = "grupo07DB";

// Constructor para cargar una pieza existente
Pieza::Pieza(int id) {
    DBContext db(BDServer, User, Password, BDName);
    db.connect();
    auto res = db.select("SELECT * FROM tPiezas WHERE ID = " + std::to_string(id));
    if (res.empty()) {
        throw std::runtime_error("Pieza no encontrada");
    }
    this->id = std::stoi(res[0][0]);
    this->nombre = res[0][1];
    this->fabricante = res[0][2];
    this->idTipo = res[0][3];
}

// Constructor para insertar una nueva pieza
Pieza::Pieza(const std::string& nombre, const std::string& fabricante, const std::string& idTipo) {
    DBContext db(BDServer, User, Password, BDName);
    db.connect();
    db.execute("INSERT INTO tPiezas (NOMBRE, FABRICANTE, ID_TIPO) VALUES ('" + nombre + "', '" + fabricante + "', '" + idTipo + "')");
    auto res = db.select("SELECT LAST_INSERT_ID()");
    this->id = std::stoi(res[0][0]);
    this->nombre = nombre;
    this->fabricante = fabricante;
    this->idTipo = idTipo;
}

// Listar todas las piezas
std::vector<Pieza> Pieza::ListarTodas() {
    DBContext db(BDServer, User, Password, BDName);
    db.connect();
    std::vector<Pieza> piezas;
    auto res = db.select("SELECT ID FROM tPiezas");
    for (const auto& row : res) {
        piezas.emplace_back(std::stoi(row[0]));
    }
    return piezas;
}

// Listar piezas por tipo
std::vector<Pieza> Pieza::ListarPorTipo(const std::string& idTipo) {
    DBContext db(BDServer, User, Password, BDName);
    db.connect();
    std::vector<Pieza> piezas;
    auto res = db.select("SELECT ID FROM tPiezas WHERE ID_TIPO = '" + idTipo + "'");
    for (const auto& row : res) {
        piezas.emplace_back(std::stoi(row[0]));
    }
    return piezas;
}

// Setters con actualización en la base de datos
void Pieza::setNombre(const std::string& nombre) {
    DBContext db(BDServer, User, Password, BDName);
    db.connect();
    db.execute("UPDATE tPiezas SET NOMBRE = '" + nombre + "' WHERE ID = " + std::to_string(this->id));
    this->nombre = nombre;
}

void Pieza::setFabricante(const std::string& fabricante) {
    DBContext db(BDServer, User, Password, BDName);
    db.connect();
    db.execute("UPDATE tPiezas SET FABRICANTE = '" + fabricante + "' WHERE ID = " + std::to_string(this->id));
    this->fabricante = fabricante;
}

void Pieza::setIdTipo(const std::string& idTipo) {
    DBContext db(BDServer, User, Password, BDName);
    db.connect();
    db.execute("UPDATE tPiezas SET ID_TIPO = '" + idTipo + "' WHERE ID = " + std::to_string(this->id));
    this->idTipo = idTipo;
}

// Getters
int Pieza::getId() const {
    return id;
}


std::string Pieza::getNombre() const {
    return nombre;
}

std::string Pieza::getFabricante() const {
    return fabricante;
}


std::string Pieza::getIdTipo() const {
    return idTipo;
}


// Borrar pieza
void Pieza::borrar() {
    DBContext db(BDServer, User, Password, BDName);
    db.execute("DELETE FROM tPiezas WHERE ID = " + std::to_string(this->id));
    this->id = -1;
}

// Representación en cadena
std::string Pieza::toString() const {
    return "Pieza: " + nombre + " (" + fabricante + ")";
}

// Comparación
bool Pieza::operator==(const Pieza& other) const {
    return this->id == other.id;
}
