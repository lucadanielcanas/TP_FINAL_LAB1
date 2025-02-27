#include <stdio.h>
#include <stdlib.h>

//DEFINIENDO ESTRUCTURAS.
typedef struct{
    int id_cliente;
    char nombre_cliente[50];
    char apellido_cliente[50];
    char domicilio_cliente[70];
    int numero_domicilio_cliente;
    int celular_cliente;
    char correo_cliente[100];
    int baja_cliente;
}stCliente;

typedef struct{
    int id_empleado;
    char nombre_empleado[50];
    char apellido_empleado[50];
    char domicilio_empleado[50];
    int numero_domicilio_empleado;
    int celular_empleado;
    char correo_empleado[100];
    char cargo_empleado[20];
    int baja_empleado;
}stEmpleado;

typedef struct{
    int id_producto;
    int precio_unitario_producto;
    int precio_mayorista_producto;
    int stock_producto;
    char nombre_producto[100];
}stProducto;

typedef struct{
    int id_cliente;
    int id_producto;
    int id_pedido;
    int costo_pedido;
    char domicilio_entrega_pedido[70];
    char descripcion_pedido[100];
    char fecha_pedido[20];
    int baja_pedido;
}stPedido;


///PROTOTIPADO DE LAS FUNCIONES.
void carga_datos_empleado (char ArchivoEmple[]);    /// CARGA DE DATPS DE LOS EMPLEADOS
void Mostrar_Datos_Empleados (char ArchivoEmple[]); /// MOSTRAR DATOS DE LOS EMPLEADOS

void carga_datos_cliente (char ArchivoClient[]);      /// CARGA DE DATOS DE LOS CLIENTES
void Mostrar_Datos_Clientes (char ArchivoClient[]);  /// MOSTRAR DATOS DEL CLIENTE FN

void carga_datos_productos (char ArchivosProduct[]);     /// CARGA DE DATOS DE LOS PRODUCTOS
void Mostrar_Datos_Productos(char ArchivoProduct[]); /// MOSTRAR DATOS DE LOS PRODUCTOS

void carga_datos_pedidos (char ArchivosPedidos[]);   /// CARGA DATOS CLIENTES
void Mostrar_Datos_Pedidos(char ArchivosPedido[]);  /// MOSTRAR DATOS DEL CLIENTES

//MENU Y LOGIN PARA ADMIN/CLIENTE/EMPLE
void menuAdministrador();
void loginAdmin();
