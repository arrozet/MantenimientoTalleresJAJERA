#ifndef PERMISO_H  // Inicio de la protección del encabezado
#define PERMISO_H

#include <string>
#include <vector>
#include "DBContext.h" // Verifica que este archivo exista y esté en el directorio correcto

class Permiso {
private:
    std::string rolName;
    std::string pantalla;
    bool acceso;
    bool modificacion;

public:
    // Constructor para cargar un permiso existente
    Permiso(const std::string& rolName, const std::string& pantalla);

    // Constructor para insertar un nuevo permiso
    Permiso(const std::string& rolName, const std::string& pantalla, bool acceso, bool modificacion);

    // Métodos de listado
    static std::vector<Permiso> ListarTodos();
    static std::vector<Permiso> ListarPorRol(const std::string& rolName);
    static std::vector<Permiso> ListarPorPantalla(const std::string& pantalla);

    // Setters con actualización en la base de datos
    void setAcceso(bool acceso);
    void setModificacion(bool modificacion);

    // Getters
    std::string getRolName() const;
    std::string getPantalla() const;
    bool getAcceso() const;
    bool getModificacion() const;

    // Método para borrar un permiso
    void borrar();

    // Representación en cadena
    std::string toString() const;

    // DBContext estático para compartir la conexión
    static DBContext db;
};

#endif // Fin de la protección del encabezado
