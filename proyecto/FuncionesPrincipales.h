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
    bool existeEmpleado = false;

    vector<FuncionEmpresa::Empresa> listaSueldoEmpleadosM3000;
    vector<FuncionEmpresa::Empresa> listaSueldoMinimoEmpleados;

    void revisarEmpleadoSuspendido(vector<FuncionEmpresa::Empresa> listaTemporal)
    {
        for (FuncionEmpresa::Empresa e : listaTemporal)
        {
            if (e.estado == "Suspendido")
            {
                if (e.sueldoEmpleado == 0 && e.estadoSueldo == "Sin sueldo")
                {
                    sinSueldo = true;
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

    void encontrarEmpleadoDuplicado(int dpiEmpleado, int sueldo, string nombreEmpresa)
    {
        for (FuncionEmpresa::Empresa e : listaSueldoEmpleadosM3000)
        {
            if (e.dpiEmpleado == dpiEmpleado && sueldo > 3000 && nombreEmpresa == e.nombre)
            {
                existeEmpleado = true;
                break;
            }
            else
            {
                existeEmpleado = false;
            }
        }
    }

    void generarReporteSueldoEmpleadosM3000()
    {
        for (FuncionEmpresa::Empresa e : FuncionEmpresa::listEmpresasPlanillaRegistradas)
        {
            if (e.sueldoEmpleado > 3000)
            {
                encontrarEmpleadoDuplicado(e.dpiEmpleado, e.sueldoEmpleado, e.nombre);
                if (existeEmpleado == false)
                {
                    listaSueldoEmpleadosM3000.push_back(e);
                }
            }
        }
    }

    void existeEmpleadoDuplicadoSueldoMinimo(int dpiEmpleado, int sueldo, string nombreEmpresa)
    {
        for (FuncionEmpresa::Empresa e : listaSueldoEmpleadosM3000)
        {
            if (e.dpiEmpleado == dpiEmpleado && sueldo == 2800 && nombreEmpresa == e.nombre)
            {
                existeEmpleado = true;
                break;
            }
            else
            {
                existeEmpleado = false;
            }
        }
    };

    void generarReporteSueldoMinimoEmpleados()
    {
        for (FuncionEmpresa::Empresa e : FuncionEmpresa::listEmpresasPlanillaRegistradas)
        {
            if (e.sueldoEmpleado == 2800)
            {
                existeEmpleadoDuplicadoSueldoMinimo(e.dpiEmpleado, e.sueldoEmpleado, e.nombre);
                if (existeEmpleado == false)
                {
                    listaSueldoMinimoEmpleados.push_back(e);
                }
            }
        }
    }

    void crearHTMLSueldoMinimo()
    {
        crearHTMLSueldoMinimo();
        ofstream archivo;
        archivo.open("sueldoMinimo.html");
        archivo << "<!DOCTYPE html>"<<endl;
        archivo << "<html>" <<endl;
        archivo << "<head>"<<endl;
        archivo << "<title>Reporte de sueldos minimos</title>"<<endl;
        archivo << "</head>"<< endl;
        archivo << "<body>"<<endl;
        archivo << "<h1>Reporte de sueldo Minimo</h1>" << endl;
        archivo << "<table border='1'>"<<endl;
        archivo << "<tr>" <<endl;
        archivo << "<th>nombre</th>"<<endl;
        archivo << "<th>DPI</th>"<<endl;
        archivo << "<th>Sueldo</th>"<<endl;
        archivo << "<th>Nombre Empresa</th>"<<endl;
        archivo << "</tr>"<<endl;
        for(FuncionEmpresa::Empresa e : listaSueldoMinimoEmpleados){
            archivo <<"<tr>"<<endl;
            archivo << "<td> "<< e.nombreEmpleado << "</td>"<<endl;
            archivo << "<td>" << e.dpiEmpleado << "</td>" << endl;
            archivo << "<td>" << e.sueldoEmpleado << "</td>"<< endl;
            archivo << "<td>"<< e.nombre << "/td"<<endl;
            archivo << "</tr>" <<endl;
        }
        archivo << "</table>" << endl;
        archivo << "</body>" << endl;
        archivo << "</html>" << endl;
        archivo.close();
    }
    void crearHTMLSueldoMayor3000()
    {
        generarReporteSueldoEmpleadosM3000();
        ofstream archivo;
        archivo.open("sueldoMayor3000.html");
        archivo << "<!DOCTYPE html>" << endl;
        archivo << "<html>" << endl;
        archivo << "<head>" << endl;
        archivo << "<title>Reporte de Sueldo de Empleados Mayor a 3000</title>" << endl;
        archivo << "</head>" << endl;
        archivo << "<body>" << endl;
        archivo << "<h1>Reporte de Sueldo de Empleados Mayor a 3000</h1>" << endl;
        archivo << "<table border='1'>" << endl;
        archivo << "<tr>" << endl;
        archivo << "<th>Nombre</th>" << endl;
        archivo << "<th>DPI</th>" << endl;
        archivo << "<th>Sueldo</th>" << endl;
        archivo << "<th>Nombre Empresa</th>" << endl;
        archivo << "</tr>" << endl;
        for (FuncionEmpresa::Empresa e : listaSueldoEmpleadosM3000)
        {
            archivo << "<tr>" << endl;
            archivo << "<td>" << e.nombre << "</td>" << endl;
            archivo << "<td>" << e.dpiEmpleado << "</td>" << endl;
            archivo << "<td>" << e.sueldoEmpleado << "</td>" << endl;
            archivo << "<td>" << e.nombre << "</td>" << endl;
            archivo << "</tr>" << endl;
        };
    }

}
