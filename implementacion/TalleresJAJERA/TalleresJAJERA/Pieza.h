#pragma once
#include <string>
#include <vector>
#include "DBContext.h"

class Pieza {
private:
    int id;
    std::string nombre;
    std::string fabricante;
    std::string idTipo;

public:
    // Constructores
    Pieza(int id);
    Pieza(const std::string& nombre, const std::string& fabricante, const std::string& idTipo);

    // M�todos est�ticos
    static std::vector<Pieza> ListarTodas();
    static std::vector<Pieza> ListarPorTipo(const std::string& idTipo);

    // Getters y Setters
    int getId() const;

    std::string getNombre() const;
    void setNombre(const std::string& nombre);

    std::string getFabricante() const;
    void setFabricante(const std::string& fabricante);

    std::string getIdTipo() const;
    void setIdTipo(const std::string& idTipo);

    // M�todos de instancia
    void borrar();
    std::string toString() const;

    // Sobrecarga de operadores
    bool operator==(const Pieza& other) const;

    // DBContext est�tico para compartir la conexi�n
    static DBContext db;
};
