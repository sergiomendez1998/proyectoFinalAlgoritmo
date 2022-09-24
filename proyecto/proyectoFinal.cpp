#include <iostream>
#include <vector>

using namespace std;

class Empresa
{
public:
    int id;
    string nombre;
    string direccion;
    string telefono;
    string nit;
    string fechaInicioPeriodo;
    string fechaFinalPeriodo;
    int dpiEmpleado;
    string nombreEmpleado;
    string sueldoEmpleado;
    string edadEmpleado;
    string estado;
    string estadoSueldo;
    string estadoContracion;
    void agregarEmpresa();
    void agregarEmpleado();
    void buscarEmpresaPorId();
    Empresa(int id, string nombre, string direccion, string telefono, string nit, string fechaInicioPeriodo, string fechaFinalPeriodo, int dpiEmpleado, string nombreEmpleado, string sueldoEmpleado, string edadEmpleado, string estado, string estadoSueldo, string estadoContracion)
    {
        this->id = id;
        this->nombre = nombre;
        this->direccion = direccion;
        this->telefono = telefono;
        this->nit = nit;
        this->fechaInicioPeriodo = fechaInicioPeriodo;
        this->fechaFinalPeriodo = fechaFinalPeriodo;
        this->dpiEmpleado = dpiEmpleado;
        this->nombreEmpleado = nombreEmpleado;
        this->sueldoEmpleado = sueldoEmpleado;
        this->edadEmpleado = edadEmpleado;
        this->estado = estado;
        this->estadoSueldo = estadoSueldo;
        this->estadoContracion = estadoContracion;
    }
};

vector<Empresa> listEmpresas;
void menuReportes()
{
    cout << "+--------- ESCOGE TIPO DE REPORTE -----+" << endl;
    cout << "| 1. Empleados con sueldo mayor a 3 mil|" << endl;
    cout << "| 2. Empleados con sueldo minimo       |" << endl;
    cout << "+--------------------------------------+" << endl;
    cout << "Ingrese una opcion: ";
    cout<<"\n";
}
void menuPrincipal()
{

    int opcion;
    do
    {

        cout << "+-------------------------------------+" << endl;
        cout << "| 1. Cargar Planilla                  |" << endl;
        cout << "| 2. Ver reportes                     |" << endl;
        cout << "| 3. Buscar Empresa por ID            |" << endl;
        cout << "| 4. Salir                            |" << endl;
        cout << "+-------------------------------------+" << endl;
        cout << "Ingrese una opcion: ";

        cin >> opcion;
        switch (opcion)
        {
        case 1:
            // cargarPlanilla();
            break;
        case 2:
            menuReportes();
            cin>>opcion;
            if (opcion == 1)
            {
                // generara el report de html con empleados que ganan mas de 3000
            }
            else if (opcion == 2)
            {
                // generara el report de html con empleados que ganen sueldo minimo
            }
            break;
        case 3:

            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }

    } while (opcion != 4);
};

int main()
{
    menuPrincipal();
    return 0;
}