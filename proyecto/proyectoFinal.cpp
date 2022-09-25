#include <iostream>
#include <vector>

using namespace std;
int opcion, idEmpresaTemporal;
string nombreEmpresaTemporal;
string numeroPatronalTemporal;
string codigoPlanillaTemporal;
string periodoTemporal;
bool existeEmpresa = false;
bool existePeriodo = false;
bool existePlanilla = false;

class Empresa
{
public:
    int id;
    string codigoPlanilla;
    string nombre;
    string direccion;
    string telefono;
    string numeroPatronal;
    string fechaInicioPeriodo;
    int idEmpleado;
    int dpiEmpleado;
    string nombreEmpleado;
    int sueldoEmpleado;
    int edadEmpleado;
    string estado;           // alta-suspendido-baja-normal
    string estadoSueldo;     // con sueldo-sin sueldo
    string estadoContracion; // suspendido por el iggs....etc

    void agregarEmpresa();
    void agregarEmpleado();
    void buscarEmpresaPorId();
    Empresa(int id, string codigoPlanilla, string nombre, string direccion, string telefono, string numeroPatronal, string fechaInicioPeriodo, int idEmpleado, int dpiEmpleado, string nombreEmpleado, int sueldoEmpleado, int edadEmpleado, string estado, string estadoSueldo, string estadoContracion)
    {
        this->id = id;
        this->nombre = nombre;
        this->direccion = direccion;
        this->telefono = telefono;
        this->numeroPatronal = numeroPatronal;
        this->fechaInicioPeriodo = fechaInicioPeriodo;
        this->idEmpleado = idEmpleado;
        this->dpiEmpleado = dpiEmpleado;
        this->nombreEmpleado = nombreEmpleado;
        this->sueldoEmpleado = sueldoEmpleado;
        this->edadEmpleado = edadEmpleado;
        this->estado = estado;
        this->estadoSueldo = estadoSueldo;
        this->estadoContracion = estadoContracion;
    }
};

vector<Empresa> listEmpresasRegistradas;
vector<Empresa> listEmpresas;
string escribirEmpresa(int opcion, vector<Empresa> listaEmpresas)
{
    if (opcion == 1)
    {
        return "Empresa Registrada";
    }
    else
    {
        return "Empresa no se inscribio";
    }
};
void leerArchivoCsv(){

};
void buscarPorNombreEmpresa(string nombreEmpresa)
{
    for (Empresa e : listEmpresasRegistradas)
    {
        if (e.nombre == nombreEmpresa)
        {
            existeEmpresa = true;
        }
        else
        {
            existeEmpresa = false;
        }
    }
}
void buscarEmpresaPorNumeroEmpresa(int numeroEmpresa)
{
    try
    {
        for (Empresa e : listEmpresasRegistradas)
        {
            if (e.id == numeroEmpresa)
            {
                cout << "Empresa " << e.nombre << endl;
            }
            else
            {
                cout << "Nombre Empresa no encontrado" << endl;
            }
        }
    }
    catch (exception e)
    {
        cout << "Lista vacia" << endl;
    }
};
void menuCargarArchivos()
{
    cout << "+-------      BIENVENIDO          -----+" << endl;
    cout << "| 1. Cargar Por Periodo                |" << endl;
    cout << "| 2. Cargar Por Numero Patronal        |" << endl;
    cout << "| 2. Cargar Por Planilla               |" << endl;
    cout << "+--------------------------------------+" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    switch (opcion)
    {
    case 1:
        cout << "Ingrese Nombre Empresa: ";
        cin >> nombreEmpresaTemporal;
        buscarPorNombreEmpresa(nombreEmpresaTemporal);
        if (existeEmpresa)
        {
            cout << "Ingresa el periodo DD/MM/YYYY - DD/MM/YYYY: ";
            cin >> periodoTemporal;
        }
        else
        {
            cout << "Aun no existe la empresa en el registro" << endl;
            cout << "Registre la empresa 1. SI 2. NO :";
            cin >> opcion;
            string repuesta = escribirEmpresa(opcion, listEmpresas);
            cout << repuesta << endl;
            // metodo
        }

        break;
    case 2:
        cout << "Ingrese Nombre Empresa";
        cin >> nombreEmpresaTemporal;
        break;
    case 3:
        cout << "Ingrese Nombre Empresa";
        cin >> nombreEmpresaTemporal;
        break;
    default:
        cout << "Opcion no valida";
        break;
    }
}

void menuReportes()
{
    cout << "+-------  ESCOGE TIPO DE REPORTE  -----+" << endl;
    cout << "| 1. Empleados con sueldo mayor a 3 mil|" << endl;
    cout << "| 2. Empleados con sueldo minimo       |" << endl;
    cout << "+--------------------------------------+" << endl;
    cout << "Ingrese una opcion: ";
    cout << "\n";
}
void menuPrincipal()
{

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
            menuCargarArchivos();
            break;
        case 2:
            menuReportes();
            cin >> opcion;

            break;
        case 3:
            cout << "Ingrese el numero de empresa: ";
            cin >> idEmpresaTemporal;
            buscarEmpresaPorNumeroEmpresa(idEmpresaTemporal);
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
void cargarEmpresasExistentes()
{
}

int main()
{
    cargarEmpresasExistentes();
    menuPrincipal();
    return 0;
}