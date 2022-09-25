#include <iostream>
#include <vector>
using namespace std;
namespace FuncionEmpresa
{
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

}