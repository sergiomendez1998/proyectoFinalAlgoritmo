#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "FuncionEmpresa.h"

using namespace std;
namespace FuncionesPrincipales
{
    bool existeEmpresa = false;
    bool existePeriodo = false;
    bool existePlanilla = false;
    bool seRepiteEmpleado = false;
    bool sinSueldo = false;

    void revisarEmpleadoSuspendido(vector<FuncionEmpresa::Empresa> listaTemporal)
    {
        for (FuncionEmpresa::Empresa e : listaTemporal)
        {
            if (e.estado == "Suspendido")
            {
                if (e.sueldoEmpleado == 0 && e.estadoSueldo == "Sin sueldo")
                {
                    sinSueldo = true;
                    break;
                }
                else
                {
                    sinSueldo = false;
                    break;
                }
            }
        }
    }

    void buscarEmpleadoRepetido(vector<FuncionEmpresa::Empresa> listaTemporal)
    {
        for (FuncionEmpresa::Empresa e : listaTemporal)
        {
            for (FuncionEmpresa::Empresa e1 : listaTemporal)
            {
                if (e.dpiEmpleado == e1.dpiEmpleado)
                {
                    seRepiteEmpleado = true;
                    break;
                }
            }
        }
    }

    string registrarDatosEmpresaPlanillaCSV(vector<FuncionEmpresa::Empresa> listaEmpresaTemporal)
    {
        ofstream archivoEmpresas;
        archivoEmpresas.open("registroEmpresaPlanilla.csv");

        for (int i = 0; i < listaEmpresaTemporal.size(); i++)
        {
            archivoEmpresas << listaEmpresaTemporal[i].id << "," << listaEmpresaTemporal[i].nombre << "," << listaEmpresaTemporal[i].direccion << "," << listaEmpresaTemporal[i].telefono << "," << listaEmpresaTemporal[i].numeroPatronal << "," << listaEmpresaTemporal[i].fechaPeriodo << "," << listaEmpresaTemporal[i].codigoPlanilla << "," << listaEmpresaTemporal[i].estado << "," << listaEmpresaTemporal[i].estadoSueldo << "," << listaEmpresaTemporal[i].estadoContracion << endl;
        }
        archivoEmpresas.close();
        return "Datos Registrados!";
    }
    string escribirEmpresa(int opcion, vector<FuncionEmpresa::Empresa> listadoEmpresas)
    {
        if (opcion == 1)
        {
            ofstream archivoEmpresas;
            archivoEmpresas.open("empresasRegistradas.csv");
            for (int i = 0; i < listadoEmpresas.size(); i++)
            {
                archivoEmpresas << listadoEmpresas[0].id << "," << listadoEmpresas[0].nombre << "," << listadoEmpresas[0].direccion << "," << listadoEmpresas[0].telefono << "," << listadoEmpresas[0].numeroPatronal << endl;
            }
            archivoEmpresas.close();
            string mensaje = registrarDatosEmpresaPlanillaCSV(listadoEmpresas);

            return "Empresa Registrada, " + mensaje;
        }
        else
        {
            return "Empresa no se inscribio";
        }
    };
    void obtenerEmpresasExistesDesdeCSVFile()
    {
        ifstream archivo;
        archivo.open("empresasRegistradas.csv");
        string linea = "";
        getline(archivo, linea);
        linea = "";
        while (getline(archivo, linea))
        {
            string id;
            string nombre;
            string direccion;
            string telefono;
            int numeroPatronal;
            string tempString;

            stringstream archivo(linea);
            getline(archivo, id, ',');
            getline(archivo, nombre, ',');
            getline(archivo, direccion, ',');
            getline(archivo, telefono, ',');
            getline(archivo, tempString, ',');
            numeroPatronal = stoi(tempString);
            FuncionEmpresa::Empresa empresa(id, nombre, direccion, telefono, numeroPatronal);
            FuncionEmpresa::listEmpresasRegistradas.push_back(empresa);
        }
        archivo.close();
    };

    // crear metodo para cargar empresas desde el archivo al arreglo de listaEmpresas
    void registroEmpresaPlanilla()
    {
        ifstream archivo;
        archivo.open("registrosEmpresaPlanilla.csv");
        string linea = "";
        getline(archivo, linea);
        linea = "";
        while (getline(archivo, linea))
        {
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
            string estado;
            string estadoSueldo;
            string estadoContratacion;
            string temporal;

            stringstream archivo(linea);

            getline(archivo, id, ',');
            getline(archivo, codigoPlanilla, ',');
            getline(archivo, nombre, ',');
            getline(archivo, direccion, ',');
            getline(archivo, telefono, ',');
            getline(archivo, temporal, ',');
            numeroPatronal = stoi(temporal);
            getline(archivo, fechaPeriodo, ',');
            getline(archivo, temporal, ',');
            idEmpleado = stoi(temporal);
            getline(archivo, temporal, ',');
            dpiEmpleado = stoi(temporal);
            getline(archivo, nombreEmpleado, ',');
            getline(archivo, temporal, ',');
            sueldoEmpleado = stoi(temporal);
            getline(archivo, temporal, ',');
            edadEmpleado = stoi(temporal);
            getline(archivo, estado, ',');
            getline(archivo, estadoSueldo, ',');
            getline(archivo, estadoContratacion, ',');

            FuncionEmpresa::Empresa empresa(id, codigoPlanilla, nombre, direccion, telefono, numeroPatronal, fechaPeriodo, idEmpleado, dpiEmpleado, nombreEmpleado, sueldoEmpleado, edadEmpleado, estado, estadoSueldo, estadoContratacion);
            FuncionEmpresa::listEmpresasPlanillaRegistradas.push_back(empresa);
        }
        archivo.close();
    };

    void buscarPorNombreEmpresa(string nombreEmpresa)
    {
        for (FuncionEmpresa::Empresa e : FuncionEmpresa::listEmpresasRegistradas)
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
    void buscarEmpresaPorNumeroEmpresa(string numeroEmpresa)
    {
        try
        {
            for (FuncionEmpresa::Empresa e : FuncionEmpresa::listEmpresasRegistradas)
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

    void buscarEmpresaPorId(string idEmpresa)
    {
        try
        {
            for (FuncionEmpresa::Empresa e : FuncionEmpresa::listEmpresasRegistradas)
            {
                if (e.id == idEmpresa)
                {
                    existeEmpresa = true;
                }
                else
                {
                    existeEmpresa = false;
                }
            }
        }
        catch (exception e)
        {
            cout << "Lista vacia" << endl;
        }
    };
    void showEmpresasExistentes()
    {
        for (FuncionEmpresa::Empresa e : FuncionEmpresa::listEmpresasRegistradas)
        {
            cout << "ID: " << e.id << endl;
            cout << "Nombre: " << e.nombre << endl;
            cout << "Direccion: " << e.direccion << endl;
            cout << "Telefono: " << e.telefono << endl;
            cout << "Numero Patronal: " << e.numeroPatronal << endl;
        }
    }

    void existePeriodoRegistrado(string periodo, string idEmpresa)
    {

        for (FuncionEmpresa::Empresa e : FuncionEmpresa::listEmpresasPlanillaRegistradas)
        {
            if (e.fechaPeriodo == periodo && e.id == idEmpresa)
            {
                existePeriodo = true;
            }
            else
            {
                existePeriodo = false;
            }
        }
    }
    void buscarEmpresaPorNumeroPatronal(int numeroPatronal)
    {
        for (FuncionEmpresa::Empresa e : FuncionEmpresa::listEmpresasRegistradas)
        {
            if (e.numeroPatronal == numeroPatronal)
            {
                existeEmpresa = true;
            }
            else
            {
                existeEmpresa = false;
            }
        }
    }
    void buscarEmpresaPorCodigoPlanilla(string codigoPlanilla)
    {
        for (FuncionEmpresa::Empresa e : FuncionEmpresa::listEmpresasPlanillaRegistradas)
        {
            if (e.codigoPlanilla == codigoPlanilla)
            {
                existeEmpresa = true;
            }
            else
            {
                existeEmpresa = false;
            }
        }
    }

    void cargarEmpresasExistentes()
    {
        obtenerEmpresasExistesDesdeCSVFile();
    }

}
