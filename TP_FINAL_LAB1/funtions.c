#include <stdio.h>
#include <stdlib.h>
#include "funtions.h"
#include <stdbool.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <time.h>

///Funcion que muestra el menu solo para los administradores.
void menuAdministrador()
{
    char DatosEmpleado[]= {"dataEmpleado.bin"};  /// nombre ubicacion de los datos de los empleados
    char DatosCliente[]={"dataCliente.bin"};    /// nombre ubicacion de los datos de los clientes

    char control;
    int opcion = 0;

    do
    {
        system("cls");
        printf("\n               [-- Usted esta en modo de ADMINISTRADOR --]\n\n");

        printf("1.        Agregar un nuevo empleado.\n\n");
        printf("2.         Agregar un nuevo cliente.\n\n");
        printf("3.                Ver mis empleados.\n\n");
        printf("4.                 Ver mis clientes.\n\n");
        printf("5.                  Editar empleado.\n\n");
        printf("6.                   Editar cliente.\n\n");
        printf("7.                Ganancias del mes.\n\n");
        printf("8.                 Empleado del mes.\n\n");
        printf("9.                            Salir.\n\n");

        printf("Que desea realizar?\n");
        fflush(stdin);
        scanf("%d", &opcion);
        system("cls");

        switch(opcion)
        {
            case 1:

                carga_datos_empleado(DatosEmpleado);

                break;
            case 2:

                carga_datos_cliente(DatosCliente);

                break;
            case 3:

                Mostrar_Datos_Empleados(DatosEmpleado);

                break;
            case 4:

                Mostrar_Datos_Clientes(DatosCliente);

                break;
            case 9:

                return 0;

                break;
        }

        printf("Desea ejecutar otra funcion? s/n\n");
        fflush(stdin);
        scanf("%c", &control);
        system("cls");

    }while(control == 's' || control == 'S');
}

///Funcion de login solo para los administradores.
void loginAdmin()
{
    const char username[]={"userAdmin"};
    const char password[]={"passAdmin"};

    char nombre_admin[10];
    char contrasenia_admin[10];

    int i = 0;
    int intentos = 0;
    int flag = 0;
    char contra;

    //bucle para la cantidad de intentos.
    while(intentos < 3 && flag == 0)
    {
        system("cls");

        printf("\n               [-- Usted se esta logeando como ADMINISTRADOR --]\n\n");

        printf("           Nombre de usuario: ");
        fflush(stdin);
        gets(nombre_admin);

        printf("\n                Contrasenia: ");
        fflush(stdin);
        while(contra = getch())
        {
            if( contra == 13)
            {
                contrasenia_admin[i] = '\0';
                break;
            }
            else
            {
             printf("*");
             contrasenia_admin[i] = contra;
             i++;
            }
        }

        if(strcmp(nombre_admin, username) == 0 && strcmp(contrasenia_admin, password) == 0)
        {
            flag = 1;
        }
        else
        {
            printf("\nERROR --------- Datos incorrectos!\n");
            intentos ++;
            getchar();
        }
    }

    if(flag == 1)
    {
        menuAdministrador();
    }else
    {
        printf("\nERROR -------------- Usted a sobrepasado la cantidad de intentos disponibles para loguearse (3)\n\n");
    }
}

///Funcion que carga los datos del empleado.
void carga_datos_empleado (char ArchivoEmple[])
{
    FILE * Archi;
    stEmpleado Empleado;

    int numero=1;
    char control='s';

    Archi=fopen(ArchivoEmple,"ab");
    if(Archi!=NULL)
    {
        while(control=='s')
        {
            printf("\n Cargar Empleados: ");

            puts("\n----------------------------------------------------");
            Empleado.id_empleado = numero;
            printf("\n Id Empleado: %d", Empleado.id_empleado);
            numero = numero + 1;

            printf("\n         Nombre: ");
            fflush(stdin);
            gets(Empleado.nombre_empleado);

            printf("\n       Apellido: ");
            fflush(stdin);
            gets(Empleado.apellido_empleado);

            printf("\n      Domicilio: ");
            fflush(stdin);
            gets(Empleado.domicilio_empleado);

            printf("\n Nro. Domicilio: ");
            fflush(stdin);
            scanf("%d", &Empleado.numero_domicilio_empleado);

            printf("\n        Celular: ");
            fflush(stdin);
            scanf("%d", &Empleado.celular_empleado);

            printf("\n         Correo: ");
            fflush(stdin);
            scanf("%s", Empleado.correo_empleado);

            printf("\n Cargo Empleado: ");             /// a cargo de administrador
            fflush(stdin);
            scanf("%s", Empleado.cargo_empleado);

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
            printf("\n      Nro Domicilio: %d", Empleados.numero_domicilio_empleado);
            printf("\n            Celular: %d", Empleados.celular_empleado);
            printf("\n Correo Electronico: %s", Empleados.correo_empleado);
            printf("\n     Cargo Empleado: %s", Empleados.cargo_empleado);
            puts("\n--------------------------------------------------------------------------------");
        }
        fclose(archi);
    }
}

///Funcion que carga los clientes.
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
        while(control=='s' || control == 'S')
        {
            printf("\n Carga de Clientes: ");

            puts("\n----------------------------------------------------");
            Cliente.id_cliente = numero;
            printf("\n Id Cliente: %d", Cliente.id_cliente);
            numero = numero + 1;
            puts("\n----------------------------------------------------");
            printf("\n         Nombre: ");
            fflush(stdin);
            gets(Cliente.nombre_cliente);

            printf("\n       Apellido: ");
            fflush(stdin);
            gets(Cliente.apellido_cliente);

            printf("\n      Domicilio: ");
            fflush(stdin);
            gets(Cliente.domicilio_cliente);

            printf("\n Nro. Domicilio: ");
            fflush(stdin);
            scanf("%d", &Cliente.numero_domicilio_cliente);

            printf("\n        Celular: ");
            fflush(stdin);
            scanf("%d", &Cliente.celular_cliente);

            printf("\n         Correo: ");
            fflush(stdin);
            scanf("%s", Cliente.correo_cliente);
            puts("\n----------------------------------------------------");

            fwrite(&Cliente, sizeof(stEmpleado),1,Archi);

            printf("\n Desea seguir agregando? (s|n)\n");
            fflush(stdin);
            scanf("%c", &control);
        }
        fclose(Archi);
    }
}

///Funcion que muestra la info de los clientes.
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
            printf("\n      Nro Domicilio: %d", Cliente.numero_domicilio_cliente);
            printf("\n            Celular: %d", Cliente.celular_cliente);
            printf("\n Correo Electronico: %s", Cliente.correo_cliente);
            puts("\n--------------------------------------------------------------------------------");
        }
        fclose(archi);
    }
}

///Funcion que carga los productos.
void carga_datos_productos (char ArchivosProduct[])
{
    FILE * Archi;

    stProducto Producto;

    int numero=1;

    char control='s';

    Archi=fopen(ArchivosProduct,"ab");
    if(Archi!=NULL)
    {
        while(control=='s' || control == 'S')
        {
            printf("\n Carga de Productos");


            puts("\n-------------------------------------------------------");
            Producto.id_producto = numero;
            printf("\n        Id Producto: %d", Producto.id_producto );
            numero = numero + 1;
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
            gets(Producto.nombre_producto);
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

///Funcion que muestra la info de los productos.
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
        fclose(archi);
    }
}

///Funcion que carga los pedidos.
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
        while(control=='s' || control == 'S')
        {
            printf("\n Carga de Pedidos: ");

            puts("\n-------------------------------------------------------");
            pedido.id_pedido = numero;
            printf("\n           Id Pedido: %d", pedido.id_pedido );
            numero = numero + 1;
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
            scanf("%s", pedido.domicilio_entrega_pedido);

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

///Funcion que muestra la info de los pedidos.
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
            printf("\n      Domicilio de Entrega: %s", pedido.domicilio_entrega_pedido);
            printf("\n          Fecha del Pedido: %s", pedido.fecha_pedido);
            puts("\n--------------------------------------------------------------------------------");
        }
        fclose(archi);
    }
}
