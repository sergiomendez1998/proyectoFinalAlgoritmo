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
    string registrarDatosEmpresaPlanillaCSV(Fuvector<FuncionEmpresa::Empresa> listaEmpresaTemporal)
    {
        ofstream archivoEmpresas;
        archivoEmpresas.open("registroEmpresaPlanilla.csv");

        for (int i = 0; i < listaEmpresaTemporal.size(); i++)
        {
            archivoEmpresas << listaEmpresaTemporal[i].id << "," << listaEmpresaTemporal[i].nombre << "," << listaEmpresaTemporal[i].direccion << "," << listaEmpresaTemporal[i].telefono << "," << listaEmpresaTemporal[i].numeroPatronal << "," << listaEmpresaTemporal[i].fechaPeriodo << "," << listaEmpresaTemporal[i].codigoPlanilla << "," << listaEmpresaTemporal[i].estado << "," << listaEmpresaTemporal[i].estadoSueldo << "," << listaEmpresaTemporal[i].estadoContracion << endl;
        }
        archivoEmpresas.close();
        return "Datos Registrados!"
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
            int id;
            string nombre;
            string direccion;
            string telefono;
            string numeroPatronal;
            string tempString;

            stringstream archivo(linea);
            getline(archivo, tempString, ',');
            id = stoi(tempString);
            getline(archivo, nombre, ',');
            getline(archivo, direccion, ',');
            getline(archivo, telefono, ',');
            getline(archivo, numeroPatronal, ',');
            FuncionEmpresa::Empresa empresa(id, nombre, direccion, telefono, numeroPatronal);
            FuncionEmpresa::listEmpresasRegistradas.push_back(empresa);
        }
        archivo.close();
    };
    //-crear un archivo csv con nombre registrosEmpresaPlanilla.csv
    //-crear un metodo en FuncionesPrincipales que carga los datos al arreglo listEmpresas
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
            int id;
            string nombre;
            string direccion;
            string telefono;
            string numeroPatronal;
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

            getline(archivo, temporal, ',');
            id = stoi(temporal);
            getline(archivo, nombre, ',');
            getline(archivo, direccion, ',');
            getline(archivo, telefono, ',');
            getline(archivo, numeroPatronal, ',');
            getline(archivo,fechaPeriodo,',');
            getline(archivo,temporal,',');
            idEmpleado = stoi(temporal);
            getline(archivo, temporal, ',');
            dpiEmpleado = stoi(temporal);
            getline(archivo, nombreEmpleado,',');
            getline(archivo,temporal,',');
            sueldoEmpleado = stoi(temporal);
            getline(archivo, temporal,',');
            edadEmpleado = stoi(temporal);
            getline(archivo, estado,',');
            getline(archivo, estadoContratacion, ',');

            FuncionEmpresa::Empresa empresa(id,nombre, direccion, telefono, numeroPatronal, fechaPeriodo, idEmpleado, dpiEmpleado, nombreEmpleado,sueldoEmpleado, edadEmpleado,estado,estadoSueldo,estadoContratacion);
            FuncionEmpresa::listEmpresasRegistradas.push_back(empresa);
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
    void buscarEmpresaPorNumeroEmpresa(int numeroEmpresa)
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

    void buscarEmpresaPorId(int idEmpresa)
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

    void cargarEmpresasExistentes()
    {
        obtenerEmpresasExistesDesdeCSVFile();
    }

}
