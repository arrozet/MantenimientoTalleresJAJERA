-- Crear la base de datos y usarla
-- CREATE DATABASE IF NOT EXISTS TrabajoGI2425;
-- USE TrabajoGI2425;

-- Tabla tPermiso
CREATE TABLE tPermiso (
    rolName VARCHAR(50) NOT NULL,
    pantalla VARCHAR(50) NOT NULL,
    acceso BOOLEAN NOT NULL,
    modificacion BOOLEAN NOT NULL,
    PRIMARY KEY (rolName, pantalla)
);

-- Tabla tPiezas
CREATE TABLE tPiezas (
    ID INT AUTO_INCREMENT NOT NULL,
    NOMBRE VARCHAR(255) NOT NULL,
    FABRICANTE VARCHAR(255) NOT NULL,
    ID_TIPO VARCHAR(4) NOT NULL,
    PRIMARY KEY (ID)
);

-- Tabla tRol
CREATE TABLE tRol (
    rolName VARCHAR(50) NOT NULL,
    rolDes VARCHAR(255),
    admin BOOLEAN NOT NULL,
    PRIMARY KEY (rolName)
);

-- Tabla tTipoPieza
CREATE TABLE tTipoPieza (
    ID_TIPO VARCHAR(4) NOT NULL,
    NOMBRE VARCHAR(80) NOT NULL,
    PRIMARY KEY (ID_TIPO)
);

-- Tabla tUsuario
CREATE TABLE tUsuario (
    nombre VARCHAR(50) NOT NULL,
    password VARCHAR(50) NOT NULL,
    rolName VARCHAR(50) NOT NULL,
    PRIMARY KEY (nombre),
    FOREIGN KEY (rolName) REFERENCES tRol(rolName) ON UPDATE CASCADE ON DELETE CASCADE
);

-- Relaciones entre tablas
ALTER TABLE tPermiso
ADD CONSTRAINT FK_tPermiso_tRol FOREIGN KEY (rolName)
REFERENCES tRol(rolName);

ALTER TABLE tPiezas
ADD CONSTRAINT FK_tPiezas_tTipoPieza FOREIGN KEY (ID_TIPO)
REFERENCES tTipoPieza(ID_TIPO) ON UPDATE CASCADE ON DELETE CASCADE;

-- Insertar datos iniciales
INSERT INTO tRol (rolName, rolDes, admin) VALUES
('administrador', 'administrador', 1),
('usuario', 'usuario', 0),
('invitado', 'invitado', 0);

INSERT INTO tUsuario (nombre, password, rolName) VALUES
('admin', 'admin', 'administrador'),
('user', 'user', 'usuario'),
('inv', 'inv', 'invitado');

INSERT INTO tPermiso (rolName, pantalla, acceso, modificacion) VALUES
('administrador', 'LOGIN', 1, 1),
('administrador', 'TIPOPIEZA', 1, 1),
('administrador', 'PIEZAS', 1, 1),
('usuario', 'LOGIN', 1, 1),
('usuario', 'TIPOPIEZA', 1, 0),
('usuario', 'PIEZAS', 1, 0),
('invitado', 'LOGIN', 1, 1),
('invitado', 'TIPOPIEZA', 0, 0),
('invitado', 'PIEZAS', 0, 0);

INSERT INTO tTipoPieza (ID_TIPO, NOMBRE) VALUES
('A', 'Chapa'),
('B', 'Motor'),
('C', 'Iluminación'),
('D', 'Sensores'),
('E', 'Cristales'),
('F', 'Pintura'),
('G', 'Otros');

INSERT INTO tPiezas (NOMBRE, FABRICANTE, ID_TIPO) VALUES
('PARAGOLPES DELANTERO NEGRO-LISO A IMPRIMAR', 'MAZDA', 'A'),
('PARAGOLPES TRASERO-IMPRIMADO', 'MAZDA', 'A'),
('REJILLA NEGRA', 'MAZDA', 'A'),
('ALETA DELANTERA DCH CON AUJERO PARA PILOTO CX3 16', 'MAZDA', 'A'),
('ALETA DELANTERA IZQ CON AUJERO PARA PILOTO CX3 16', 'MAZDA', 'A'),
('Bombillas luz delantera', 'RENAULT', 'C'),
('Bombillas señalización delantera', 'RENAULT', 'C'),
('Bombillas luz trasera', 'RENAULT', 'C'),
('Bombillas señalización trasera', 'RENAULT', 'C'),
('Estuches de bombillas', 'RENAULT', 'C'),
('Iluminación LED', 'RENAULT', 'C'),
('Bombillas interior', 'RENAULT', 'C'),
('Bombillas Xenon', 'RENAULT', 'C'),
('Juntas y otras piezas del motor', 'FORD', 'B'),
('Alimentación', 'FORD', 'B'),
('Kits de distribución', 'FORD', 'B'),
('Correas', 'FORD', 'B'),
('Poleas', 'FORD', 'B'),
('Kits', 'FORD', 'B'),
('Válvulas EGR', 'FORD', 'B'),
('Herramienta específica', 'FORD', 'B'),
('Turbocompresores', 'FORD', 'B'),
('Sensores electrónicos y medidores de flujo', 'FORD', 'B'),
('Cable de acelerador y starter', 'FORD', 'B');
