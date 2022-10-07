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
    int contadorEstadoAlta = 0;
    int contadorEstadoNormal = 0;

    vector<FuncionEmpresa::Empresa> listaSueldoEmpleadosM3000;
    vector<FuncionEmpresa::Empresa> listaSueldoMinimoEmpleados;
    void buscarEmpleadoPorDPI(int dpiEmpleado)
    {
        for (FuncionEmpresa::Empresa e : FuncionEmpresa::listEmpleadosRegistradas)
        {
            if (e.dpiEmpleado == dpiEmpleado)
            {
                existeEmpleado = true;

                break;
            }
        }
    }
    void buscarEmpresaPorId(string idEmpresa)
    {
        try
        {
            for (FuncionEmpresa::Empresa e : FuncionEmpresa::listEmpresasRegistradas)
            {
                if (e.id == idEmpresa)
                {
                    existeEmpresa = true;
                    break;
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
    }
    void obtenerEmpleadosExistesDesdeCSVFile()
    {

        ifstream archivo;
        archivo.open("./csvFile/empleadosRegistrados.csv");
        string linea = "";
        getline(archivo, linea);
        linea = "";
        while (getline(archivo, linea))
        {
            int idEmpleado;
            int dpiEmpleado;
            string nombre;
            int edad;
            string tempString;

            stringstream archivo(linea);
            getline(archivo, tempString, ',');
            idEmpleado = stoi(tempString);
            getline(archivo, tempString, ',');
            dpiEmpleado = stoi(tempString);
            getline(archivo, nombre, ',');
            getline(archivo, tempString, ',');
            edad = stoi(tempString);
            FuncionEmpresa::Empresa empresa(idEmpleado, dpiEmpleado, nombre, edad);
            FuncionEmpresa::listEmpleadosRegistradas.push_back(empresa);
        }
        archivo.close();
    }
    void registrarEmpleadosNuevos()
    {
        ofstream archivoEmpleados;
        archivoEmpleados.open("./csvFile/empleadosRegistrados.csv", ios::app);
        cout << "lista empleados temporal" << FuncionEmpresa::listEmpleadosTemporal.size() << endl;
        for (FuncionEmpresa::Empresa empresa : FuncionEmpresa::listEmpleadosTemporal)
        {

            archivoEmpleados << empresa.idEmpleado
                             << "," << empresa.dpiEmpleado
                             << "," << empresa.nombreEmpleado
                             << "," << empresa.edadEmpleado << endl;
        }
        // idEmpleado, dpiEmpleado,nombre,dirreccion,telefono,edad
        archivoEmpleados.close();
    }
    void cargarNuevaPlanillaEmpresa(string nombreArchivo)
    {
        ifstream archivo;
        archivo.open("./csvFile/" + nombreArchivo);
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
            string tempString;

            stringstream archivo(linea);

            getline(archivo, id, ',');
            getline(archivo, codigoPlanilla, ',');
            getline(archivo, nombre, ',');
            getline(archivo, direccion, ',');
            getline(archivo, telefono, ',');
            getline(archivo, tempString, ',');
            numeroPatronal = stoi(tempString);
            getline(archivo, fechaPeriodo, ',');
            getline(archivo, tempString, ',');
            idEmpleado = stoi(tempString);
            getline(archivo, tempString, ',');
            dpiEmpleado = stoi(tempString);
            getline(archivo, nombreEmpleado, ',');
            getline(archivo, tempString, ',');
            sueldoEmpleado = stoi(tempString);
            getline(archivo, tempString, ',');
            edadEmpleado = stoi(tempString);
            getline(archivo, estado, ',');
            getline(archivo, estadoSueldo, ',');
            getline(archivo, estadoContratacion, ',');

            FuncionEmpresa::Empresa empresa(id, codigoPlanilla, nombre, direccion, telefono, numeroPatronal, fechaPeriodo, idEmpleado, dpiEmpleado, nombreEmpleado, sueldoEmpleado, edadEmpleado, estado, estadoSueldo, estadoContratacion);
            FuncionEmpresa::listEmpresasPlanillaTemporal.push_back(empresa);
        }
        archivo.close();
    }

    void revisarEstadoNormal(vector<FuncionEmpresa::Empresa> listaTemporal)
    {

        for (FuncionEmpresa::Empresa e : listaTemporal)
        {
            if (e.estado == "Normal")
            {
                contadorEstadoNormal++;
                for (FuncionEmpresa::Empresa e2 : FuncionEmpresa::listEmpresasPlanillaRegistradas)
                {
                    if (e2.idEmpleado == e.idEmpleado && e2.estado == "Alta")
                    {
                        contadorEstadoAlta++;
                        break;
                    }
                }
            }
        };
    }
    void revisarEstadodeAlta(vector<FuncionEmpresa::Empresa> listaTemporal)
    {
        for (FuncionEmpresa::Empresa e : listaTemporal)
        {

            if (e.estado == "Alta")
            {

                for (FuncionEmpresa::Empresa e2 : FuncionEmpresa::listEmpresasPlanillaRegistradas)
                {

                    if (e.dpiEmpleado != e2.dpiEmpleado)
                    {

                        FuncionEmpresa::Empresa empleado(e.idEmpleado, e.dpiEmpleado, e.nombreEmpleado, e.edadEmpleado);

                        buscarEmpleadoPorDPI(empleado.dpiEmpleado);

                        if (existeEmpleado == false)
                        {
                            FuncionEmpresa::listEmpleadosTemporal.push_back(empleado);
                            cout << "Empleado que no se encontraba inscrito y tiene estado de alta" << endl;
                            cout << "Fue inscrito exitosamente!" << endl;
                            cout << "\n";
                        }
                    }
                }
            }
        }
        cout << "\n";
    }

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
                if (e.dpiEmpleado == e1.dpiEmpleado && e.sueldoEmpleado != e1.sueldoEmpleado && e.estado != e1.estado)
                {
                    seRepiteEmpleado = true;
                    break;
                }
                {
                    seRepiteEmpleado = false;
                    break;
                }
            }
        }
    }

    string registrarDatosEmpresaPlanillaCSV(vector<FuncionEmpresa::Empresa> listaEmpresaTemporal)
    {
        ofstream archivoEmpresas;

        archivoEmpresas.open("./csvFile/registrosEmpresaPlanilla.csv", ios::app);

        for (int i = 0; i < listaEmpresaTemporal.size(); i++)
        {
            cout << listaEmpresaTemporal[i].codigoPlanilla << endl;
            archivoEmpresas
                << listaEmpresaTemporal[i].id
                << "," << listaEmpresaTemporal[i].codigoPlanilla
                << "," << listaEmpresaTemporal[i].nombre
                << "," << listaEmpresaTemporal[i].direccion
                << "," << listaEmpresaTemporal[i].telefono
                << "," << listaEmpresaTemporal[i].numeroPatronal
                << "," << listaEmpresaTemporal[i].fechaPeriodo
                << "," << listaEmpresaTemporal[i].idEmpleado
                << "," << listaEmpresaTemporal[i].dpiEmpleado
                << "," << listaEmpresaTemporal[i].nombreEmpleado
                << "," << listaEmpresaTemporal[i].sueldoEmpleado
                << "," << listaEmpresaTemporal[i].edadEmpleado
                << "," << listaEmpresaTemporal[i].estado
                << "," << listaEmpresaTemporal[i].estadoSueldo
                << "," << listaEmpresaTemporal[i].estadoContratacion << endl;
        }

        archivoEmpresas.close();
        return "Datos Registrados!";
    }

    string escribirEmpresa(int opcion, vector<FuncionEmpresa::Empresa> listadoEmpresas)
    {
        if (opcion == 1)
        {
            ofstream archivoEmpresas;
            archivoEmpresas.open("./csvFile/empresasRegistradas.csv", ios::app);

            // doesn't delete the header of empresasRegistradas.csv
            int size = FuncionEmpresa::listEmpresasRegistradas.size() + 2;
            buscarEmpresaPorId(listadoEmpresas[1].id);
            if (!existeEmpresa)
            {
                archivoEmpresas
                    << listadoEmpresas[1].id
                    << "," << listadoEmpresas[1].nombre
                    << "," << listadoEmpresas[1].direccion
                    << "," << listadoEmpresas[1].telefono
                    << "," << listadoEmpresas[1].numeroPatronal << endl;
                archivoEmpresas.close();
            }

            return "Empresa Registrada!";
        }
        else
        {
            return "No se pudo registrar la empresa!";
        }
    }

    void obtenerEmpresasExistesDesdeCSVFile()
    {
        ifstream archivo;
        archivo.open("./csvFile/empresasRegistradas.csv");
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
    }

    void registroEmpresaPlanilla()
    {
        ifstream archivo;
        archivo.open("./csvFile/registrosEmpresaPlanilla.csv");
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
            string tempString;

            stringstream archivo(linea);

            getline(archivo, id, ',');
            getline(archivo, codigoPlanilla, ',');
            getline(archivo, nombre, ',');
            getline(archivo, direccion, ',');
            getline(archivo, telefono, ',');
            getline(archivo, tempString, ',');
            numeroPatronal = stoi(tempString);
            getline(archivo, fechaPeriodo, ',');
            getline(archivo, tempString, ',');
            idEmpleado = stoi(tempString);
            getline(archivo, tempString, ',');
            dpiEmpleado = stoi(tempString);
            getline(archivo, nombreEmpleado, ',');
            getline(archivo, tempString, ',');
            sueldoEmpleado = stoi(tempString);
            getline(archivo, tempString, ',');
            edadEmpleado = stoi(tempString);
            getline(archivo, estado, ',');
            getline(archivo, estadoSueldo, ',');
            getline(archivo, estadoContratacion, ',');

            FuncionEmpresa::Empresa empresa(id, codigoPlanilla, nombre, direccion, telefono, numeroPatronal, fechaPeriodo, idEmpleado, dpiEmpleado, nombreEmpleado, sueldoEmpleado, edadEmpleado, estado, estadoSueldo, estadoContratacion);
            FuncionEmpresa::listEmpresasPlanillaRegistradas.push_back(empresa);
        }
        archivo.close();
    }

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
                    cout << "Nombre Empresa : " << e.nombre << endl;
                }
                else
                {
                    cout << "Empresa no encontrado" << endl;
                }
            }
            cout << "\n";
        }
        catch (exception e)
        {
            cout << "Lista vacia" << endl;
        }
    }

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
                break;
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
        generarReporteSueldoMinimoEmpleados();
        ofstream archivo;
        archivo.open("./reportes/sueldoMinimo.html");
        archivo << "<!DOCTYPE html>" << endl;
        archivo << "<html lang ='en'>" << endl;
        archivo << "<head>" << endl;
        archivo << "<meta charset='UTF-8'>" << endl;
        archivo << "<meta http-equiv='X-UA-Compatible' content='IE=edge'>" << endl;
        archivo << "<meta name='viewport' content='width=device-width, initial-scale=1.0'>" << endl;
        archivo << "<link rel='stylesheet' href='./css/style.css'>" << endl;
        archivo << "<link rel='stylesheet' href='./css/nav.css'>" << endl;
        archivo << "<title>Reporte-sueldos</title>" << endl;
        archivo << "</head>" << endl;
        archivo << "<body>" << endl;

        archivo << "<div class='navbar'>" << endl;
        archivo << "<div class='container'>" << endl;
        archivo << "<div class='nav-header'>" << endl;

        archivo << "<a href='#' class='navbar-brand'>Seccion de Reportes de Sueldos</a>" << endl;
        archivo << "</div>" << endl;

        archivo << "<ul class='nav navcollaps'>" << endl;
        archivo << "<li>" << endl;
        archivo << "<a href='sueldoMayor3000.html'>Sueldos mayor 3000</a>" << endl;
        archivo << "</li>" << endl;
        archivo << "<li>" << endl;
        archivo << "<a href='sueldoMinimo.html'>Sueldo Minimo</a>" << endl;
        archivo << "</li>" << endl;
        archivo << "</ul>" << endl;
        archivo << "</div>" << endl;
        archivo << "</div>" << endl;

        archivo << "<br>" << endl;
        archivo << "<br>" << endl;
        archivo << "<br>" << endl;
        archivo << "<br>" << endl;

        archivo << "<div class='table-wrapper'>" << endl;
        archivo << "<table class='fl-table'>" << endl;
        archivo << "<thead>" << endl;
        archivo << "<tr>" << endl;
        archivo << "<th>Nombre</th>" << endl;
        archivo << "<th>DPI</th>" << endl;
        archivo << "<th>Sueldo</th>" << endl;
        archivo << "<th>Nombre Empresa</th>" << endl;
        archivo << "</tr>" << endl;
        archivo << "</thead>" << endl;
        archivo << "<tbody>" << endl;
        for (FuncionEmpresa::Empresa e : listaSueldoMinimoEmpleados)
        {
            archivo << "<tr>" << endl;
            archivo << "<td> " << e.nombreEmpleado << "</td>" << endl;
            archivo << "<td>" << e.dpiEmpleado << "</td>" << endl;
            archivo << "<td>" << e.sueldoEmpleado << "</td>" << endl;
            archivo << "<td>" << e.nombre << "</td>" << endl;
            archivo << "</tr>" << endl;
        }
        archivo << "</tbody>" << endl;
        archivo << "</table>" << endl;
        archivo << "</div>" << endl;
        archivo << "</body>" << endl;
        archivo << "</html>" << endl;

        archivo.close();
    }
    void crearHTMLSueldoMayor3000()
    {
        generarReporteSueldoEmpleadosM3000();
        ofstream archivo;
        archivo.open("./reportes/sueldoMayor3000.html");
        // create html 5
        archivo << "<!DOCTYPE html>" << endl;
        archivo << "<html lang ='en'>" << endl;
        archivo << "<head>" << endl;
        archivo << "<meta charset='UTF-8'>" << endl;
        archivo << "<meta http-equiv='X-UA-Compatible' content='IE=edge'>" << endl;
        archivo << "<meta name='viewport' content='width=device-width, initial-scale=1.0'>" << endl;
        archivo << "<link rel='stylesheet' href='./css/style.css'>" << endl;
        archivo << "<link rel='stylesheet' href='./css/nav.css'>" << endl;
        archivo << "<title>Reporte-sueldos</title>" << endl;
        archivo << "</head>" << endl;
        archivo << "<body>" << endl;

        archivo << "<div class='navbar'>" << endl;
        archivo << "<div class='container'>" << endl;
        archivo << "<div class='nav-header'>" << endl;

        archivo << "<a href='#' class='navbar-brand'>Seccion de Reportes de Sueldos</a>" << endl;
        archivo << "</div>" << endl;

        archivo << "<ul class='nav navcollaps'>" << endl;
        archivo << "<li>" << endl;
        archivo << "<a href='sueldoMayor3000.html'>Sueldos mayor 3000</a>" << endl;
        archivo << "</li>" << endl;
        archivo << "<li>" << endl;
        archivo << "<a href='sueldoMinimo.html'>Sueldo Minimo</a>" << endl;
        archivo << "</li>" << endl;
        archivo << "</ul>" << endl;
        archivo << "</div>" << endl;
        archivo << "</div>" << endl;

        archivo << "<br>" << endl;
        archivo << "<br>" << endl;
        archivo << "<br>" << endl;
        archivo << "<br>" << endl;

        archivo << "<div class='table-wrapper'>" << endl;
        archivo << "<table class='fl-table'>" << endl;
        archivo << "<thead>" << endl;
        archivo << "<tr>" << endl;
        archivo << "<th>Nombre</th>" << endl;
        archivo << "<th>DPI</th>" << endl;
        archivo << "<th>Sueldo</th>" << endl;
        archivo << "<th>Nombre Empresa</th>" << endl;
        archivo << "</tr>" << endl;
        archivo << "</thead>" << endl;
        archivo << "<tbody>" << endl;
        for (FuncionEmpresa::Empresa e : listaSueldoEmpleadosM3000)
        {
            archivo << "<tr>" << endl;
            archivo << "<td>" << e.nombreEmpleado << "</td>" << endl;
            archivo << "<td>" << e.dpiEmpleado << "</td>" << endl;
            archivo << "<td>" << e.sueldoEmpleado << "</td>" << endl;
            archivo << "<td>" << e.nombre << "</td>" << endl;
            archivo << "</tr>" << endl;
        }
        archivo << "</tbody>" << endl;
        archivo << "</table>" << endl;
        archivo << "</div>" << endl;

        archivo << "</body>" << endl;
        archivo << "</html>" << endl;

        archivo.close();
    }
}
