#include <iostream>
#include <vector>
using namespace std;
namespace FuncionEmpresa
{
  class Empresa
  {
  public:
    string id;
    string codigoPlanilla;
    string nombre;
    string direccion;
    string telefono;
    int numeroPatronal;
    string fechaPeriodo;
    int idEmpleado;
    int dpiEmpleado;
    string nombreEmpleado;
    int sueldoEmpleado;
    int edadEmpleado;
    string estado;             // alta-suspendido-baja-normal
    string estadoSueldo;       // con sueldo-sin sueldo
    string estadoContratacion; // suspendido por el iggs....etc
    Empresa(string id, string codigoPlanilla, string nombre, string direccion, string telefono, int numeroPatronal, string fechaPeriodo, int idEmpleado, int dpiEmpleado, string nombreEmpleado, int sueldoEmpleado, int edadEmpleado, string estado, string estadoSueldo, string estadoContratacion)
    {
      this->id = id;
      this->codigoPlanilla = codigoPlanilla;
      this->nombre = nombre;
      this->direccion = direccion;
      this->telefono = telefono;
      this->numeroPatronal = numeroPatronal;
      this->fechaPeriodo = fechaPeriodo;
      this->idEmpleado = idEmpleado;
      this->dpiEmpleado = dpiEmpleado;
      this->nombreEmpleado = nombreEmpleado;
      this->sueldoEmpleado = sueldoEmpleado;
      this->edadEmpleado = edadEmpleado;
      this->estado = estado;
      this->estadoSueldo = estadoSueldo;
      this->estadoContratacion = estadoContratacion;
    }
    Empresa(string id, string nombre, string dirreccion, string telefono, int numeroPatronal)
    {
      this->id = id;
      this->nombre = nombre;
      this->direccion = direccion;
      this->telefono = telefono;
      this->numeroPatronal = numeroPatronal;
    }
    Empresa(int idEmpleado, int dpiEmpleado, string nombreEmpleado, int edad)
    {
      this->idEmpleado = idEmpleado;
      this->dpiEmpleado = dpiEmpleado;
      this->nombreEmpleado = nombreEmpleado;
      this->edadEmpleado = edad;
    }
  };

  vector<Empresa> listEmpresasRegistradas;
  vector<Empresa> listEmpresasPlanillaRegistradas;
  vector<Empresa> listEmpresasPlanillaTemporal;
  vector<Empresa> listEmpleadosRegistradas;
  vector<Empresa> listEmpleadosTemporal;

}