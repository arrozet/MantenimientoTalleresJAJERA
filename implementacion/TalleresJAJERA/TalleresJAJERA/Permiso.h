#ifndef PERMISO_H  // Inicio de la protecci�n del encabezado
#define PERMISO_H

#include <string>
#include <vector>
#include "DBContext.h" // Verifica que este archivo exista y est� en el directorio correcto

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

    // M�todos de listado
    static std::vector<Permiso> ListarTodos();
    static std::vector<Permiso> ListarPorRol(const std::string& rolName);
    static std::vector<Permiso> ListarPorPantalla(const std::string& pantalla);

    // Setters con actualizaci�n en la base de datos
    void setAcceso(bool acceso);
    void setModificacion(bool modificacion);

    // Getters
    std::string getRolName() const;
    std::string getPantalla() const;
    bool getAcceso() const;
    bool getModificacion() const;

    // M�todo para borrar un permiso
    void borrar();

    // Representaci�n en cadena
    std::string toString() const;

    // DBContext est�tico para compartir la conexi�n
    static DBContext db;
};

#endif // Fin de la protecci�n del encabezado
