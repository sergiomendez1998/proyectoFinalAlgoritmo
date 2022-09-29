#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "FuncionEmpresa.h"

using namespace std;

namespace GeneraReportes
{

    vector<FuncionEmpresa::Empresa> listaSueldoEmpleadosM3000;
    vector<FuncionEmpresa::Empresa> listaSueldoMinimoEmpleados;

    bool existeEmpleado = false;

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