typedef struct{
    int id_cliente;
    char nombre_cliente[50];
    char apellido_cliente[50];
    char domicilio_cliente[50];
    int celular_cliente;
    char correo_cliente[100];
    bool baja_cliente;
}cliente;

typedef struct{
    int id_empleado;
    char nombre_empleado[50];
    char apellido_empleado[50];
    char domicilio_empleado[50];
    int celular_empleado;
    char correo_empleado[100];
    char cargo_empleado[20];
    bool baja_empleado;
}empleado;

typedef struct{
    int id_cliente;
    int id_producto;
    int id_pedido;
    int costo_pedido;
    char descripcion_pedido[100];
    char fecha_pedido[20];
    bool baja_pedido;
}pedido;

typedef struct{
    int id_producto;
    int precio_unitario_producto;
    int precio_mayorista_producto;
    int stock_producto;
    char nombre_producto[100];
}producto;
