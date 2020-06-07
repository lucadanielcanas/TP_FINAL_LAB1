#include <stdio.h>
#include <stdlib.h>
#include "funtions.h"
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <time.h>

void carga_datos_empleado (char ArchivoEmple[])
{
    FILE * Archi;
    stEmpleado Empleado;

    int numero=1;
    Empleado.id_empleado=numero;
    char control='s';

    Archi=fopen(ArchivoEmple,"ab");
    if(Archi!=NULL)
    {
        while(control=='s')
        {
            printf("\n Cargar Empleados: ");

            puts("\n----------------------------------------------------");
            printf("\n Id Empleado: %d", Empleado.id_empleado);

            printf("\n         Nombre: ");
            fflush(stdin);
            scanf("%s", Empleado.nombre_empleado);

            printf("\n       Apellido: ");
            fflush(stdin);
            scanf("%s", Empleado.apellido_empleado);

            printf("\n      Domicilio: ");
            fflush(stdin);
            scanf("%s", Empleado.domicilio_empleado);

            printf("\n Nro. Domicilio: ");
            fflush(stdin);
            scanf("%d", &Empleado.Numero_calle_empleado);

            printf("\n        Celular: ");
            fflush(stdin);
            scanf("%d", &Empleado.celular_empleado);

            printf("\n         Correo: ");
            fflush(stdin);
            scanf("%s", Empleado.correo_empleado);

            printf("\n Cargo Empleado: ");             /// a cargo de administrador
            fflush(stdin);
            scanf("%s", Empleado.cargo_empleado);

            numero++;

            fwrite(&Empleado, sizeof(stEmpleado),1,Archi);

            printf("\n Desea seguir agregando? (s|n)\n");
            fflush(stdin);
            scanf("%c", &control);


        }
        fclose(Archi);
    }
}

void Mostrar_Datos_Empleados (char ArchivoEmple[])
{
    FILE * archi;
    stEmpleado Empleados;
    archi=fopen(ArchivoEmple, "rb");
    int i=0;

    if(archi!=NULL)
    {
        while (fread(&Empleados, sizeof(stEmpleado),1,archi)>0)
        {
            printf("\n Registro numero %d", i++);
            puts("\n--------------------------------------------------------------------------------");
            printf("\n                Id : %d", Empleados.id_empleado);
            printf("\n             Nombre: %s", Empleados.nombre_empleado);
            printf("\n           Apellido: %s", Empleados.apellido_empleado);
            printf("\n          Domicilio: %s", Empleados.domicilio_empleado);
            printf("\n            Celular: %d", Empleados.celular_empleado);
            printf("\n Correo Electronico: %s", Empleados.correo_empleado);
            printf("\n     Cargo Empleado: %s", Empleados.cargo_empleado);
            puts("\n--------------------------------------------------------------------------------");
        }
    }
}

void carga_datos_cliente (char ArchivoClient[])   /// mostrar datos de clientes
{
    FILE * Archi;
    stCliente Cliente;

    int numero=1;

    Cliente.id_cliente=numero;
    char control='s';

    Archi=fopen(ArchivoClient,"ab");
    if(Archi!=NULL)
    {
        while(control=='s')
        {
            printf("\n Carga de Clientes: ");

            puts("\n----------------------------------------------------");
            printf("\n Id Cliente: %d", Cliente.id_cliente);
            puts("\n----------------------------------------------------");
            printf("\n         Nombre: ");
            fflush(stdin);
            scanf("%s", Cliente.nombre_cliente);

            printf("\n       Apellido: ");
            fflush(stdin);
            scanf("%s", Cliente.apellido_cliente);

            printf("\n      Domicilio: ");
            fflush(stdin);
            scanf("%s", Cliente.domicilio_cliente);

            printf("\n Nro. Domicilio: ");
            fflush(stdin);
            scanf("%d", &Cliente.numero_calle_cliente);

            printf("\n        Celular: ");
            fflush(stdin);
            scanf("%d", &Cliente.celular_cliente);

            printf("\n         Correo: ");
            fflush(stdin);
            scanf("%s", Cliente.correo_cliente);
            puts("\n----------------------------------------------------");

            numero++;

            fwrite(&Cliente, sizeof(stEmpleado),1,Archi);

            printf("\n Desea seguir agregando? (s|n)\n");
            fflush(stdin);
            scanf("%c", &control);


        }
        fclose(Archi);
    }
}

void Mostrar_Datos_Clientes (char ArchivoClient[])  /// MOSTRAR DATOS DEL CLIENTE FN
{
    FILE * archi;
    stCliente Cliente;
    archi=fopen(ArchivoClient, "rb");
    int i=0;

    if(archi!=NULL)
    {
        while (fread(&Cliente, sizeof(stCliente),1,archi)>0)
        {
            puts("\n---------------------------------------------------------------------------------");
            printf("\n Registro Cliente %d", i++);
            puts("\n--------------------------------------------------------------------------------");
            printf("\n                 Id: %d", Cliente.id_cliente);
            printf("\n             Nombre: %s", Cliente.nombre_cliente);
            printf("\n           Apellido: %s", Cliente.apellido_cliente);
            printf("\n          Domicilio: %s", Cliente.domicilio_cliente);
            printf("\n      Nro Domicilio: %d", Cliente.numero_calle_cliente);
            printf("\n            Celular: %d", Cliente.celular_cliente);
            printf("\n Correo Electronico: %s", Cliente.correo_cliente);
            puts("\n--------------------------------------------------------------------------------");
        }
    }
}


void carga_datos_productos (char ArchivosProduct[])
{
    FILE * Archi;

    stProducto Producto;

    int numero=1;

    Producto.id_producto=numero;

    char control='s';

    Archi=fopen(ArchivosProduct,"ab");
    if(Archi!=NULL)
    {
        while(control=='s')
        {
            printf("\n Carga de Productos");


            puts("\n-------------------------------------------------------");
            printf("\n        Id Producto: %d", Producto.id_producto );
            puts("\n--------------------------------------------------------");
            printf("\n    Precio Unitario: ");
            fflush(stdin);
            scanf("%d", &Producto.precio_unitario_producto);

            printf("\n    Precio Mayorista: ");
            fflush(stdin);
            scanf("%d", &Producto.precio_mayorista_producto);

            printf("\n   Stok del Producto: ");
            fflush(stdin);
            scanf("%d", &Producto.stock_producto);

            printf("\n     Nombre Producto: ");
            fflush(stdin);
            scanf("%s", Producto.nombre_producto);
            puts("\n--------------------------------------------------------");
            numero++;

            fwrite(&Producto, sizeof(stProducto),1,Archi);

            printf("\n Desea seguir agregando productos? (s|n)\n");
            fflush(stdin);
            scanf("%c", &control);


        }
        fclose(Archi);
    }
}

void Mostrar_Datos_Productos(char ArchivoProduct[])  /// MOSTRAR DATOS DEL CLIENTE FN
{
    FILE * archi;
    stProducto Producto;
    archi=fopen(ArchivoProduct, "rb");
    int i=0;

    if(archi!=NULL)
    {
        while (fread(&Producto, sizeof(stProducto),1,archi)>0)
        {
            puts("\n---------------------------------------------------------------------------------");
            printf("\n Registro Producto %d", i++);
            puts("\n--------------------------------------------------------------------------------");
            printf("\n                 Id: %d", Producto.id_producto);
            printf("\n             Nombre: %s", Producto.nombre_producto);
            printf("\n    Precio Unitario: %d", Producto.precio_unitario_producto);
            printf("\n   Precio Mayorista: %d", Producto.precio_mayorista_producto);
            printf("\n              Stock: %d", Producto.stock_producto);
            puts("\n--------------------------------------------------------------------------------");
        }
    }
}

void carga_datos_pedidos (char ArchivosPedidos[])
{
    FILE * Archi;

    stPedido pedido;

    int numero=1;

    pedido.id_pedido=numero;

    char control='s';

    Archi=fopen(ArchivosPedidos,"ab");
    if(Archi!=NULL)
    {
        while(control=='s')
        {
            printf("\n Carga de Pedidos: ");

            puts("\n-------------------------------------------------------");
            printf("\n           Id Pedido: %d", pedido.id_pedido );
            puts("\n--------------------------------------------------------");

            printf("\n          Id CLiente: ");
            fflush(stdin);
            scanf("%d", &pedido.id_cliente);

            printf("\n         Id Producto: ");
            fflush(stdin);
            scanf("%d", &pedido.id_producto);


            printf("\n         Descripcion: ");
            fflush(stdin);
            scanf("%s", pedido.descripcion_pedido);

            printf("\n               Costo: ");
            fflush(stdin);
            scanf("%d", &pedido.costo_pedido);

            printf("\n   Domicilio Entrega: ");
            fflush(stdin);
            scanf("%s", pedido.domicilio_entre_pedido);

            printf("\n        Fecha Pedido: ");
            fflush(stdin);
            scanf("%s", pedido.fecha_pedido);
            puts("\n--------------------------------------------------------");
            numero++;

            fwrite(&pedido, sizeof(stPedido),1,Archi);

            printf("\n Desea seguir agregando pedidos? (s|n)\n");
            fflush(stdin);
            scanf("%c", &control);


        }
        fclose(Archi);
    }
}

void Mostrar_Datos_Pedidos(char ArchivosPedido[])  /// MOSTRAR DATOS DEL CLIENTE FN
{
    FILE * archi;
    stPedido pedido;
    archi=fopen(ArchivosPedido, "rb");
    int i=0;

    if(archi!=NULL)
    {
        while (fread(&pedido, sizeof(stPedido),1,archi)>0)
        {
            puts("\n---------------------------------------------------------------------------------");
            printf("\n Registro Pedido %d", i++);
            puts("\n--------------------------------------------------------------------------------");
            printf("\n                        Id: %d", pedido.id_pedido);
            printf("\n                Id Cliente: %d", pedido.id_cliente);
            printf("\n               Id Producto: %d", pedido.id_producto);
            printf("\n               Descripcion: %s", pedido.descripcion_pedido);
            printf("\n                     Costo: %d", pedido.costo_pedido);
            printf("\n      Domicilio de Entrega: %s", pedido.domicilio_entre_pedido);
            printf("\n          Fecha del Pedido: %s", pedido.fecha_pedido);
            puts("\n--------------------------------------------------------------------------------");
        }
    }
}
