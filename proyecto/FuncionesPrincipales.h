#include <iostream>
#include "FuncionEmpresa.h"
using namespace std;
namespace FuncionesPrincipales
{
    bool existeEmpresa = false;
    bool existePeriodo = false;
    bool existePlanilla = false;
    string escribirEmpresa(int opcion, vector<FuncionEmpresa::Empresa> listadoEmpresas)
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

    void cargarEmpresasExistentes()
    {
    }
}
