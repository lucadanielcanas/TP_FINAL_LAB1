#include <stdio.h>
#include <stdlib.h>
#include "funtions.h"
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <time.h>

int main()
{
    char DatosCliente[]={"dataCliente.bin"};    /// nombre ubicacion de los datos de los clientes
    char DatosPedido[]={"dataPedido.bin"};      /// nombre ubicacion de los datos de los pedidos
    char DatosProducto[]={"dataProducto.bin"};  /// nombre ubicacion de los datos de los productos


/// FUNCIONES...

    /*///EMPLEADOS
    carga_datos_empleado(DatosEmpleado);
    Mostrar_Datos_Empleados (DatosEmpleado);

    ///CLIENTES
    carga_datos_cliente (DatosCliente);
    Mostrar_Datos_Clientes(DatosCliente);

    ///PEDIDOS
    carga_datos_pedidos(DatosPedido);
    Mostrar_Datos_Pedidos(DatosPedido);

    ///PRODUCTOS
    carga_datos_productos(DatosProducto);
    Mostrar_Datos_Productos(DatosProducto);
*/

    loginAdmin();

    return 0;
}
