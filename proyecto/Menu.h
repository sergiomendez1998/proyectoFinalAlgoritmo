#include <iostream>
#include "FuncionesPrincipales.h"

using namespace std;
namespace Menu
{
    int opcion;
    string idEmpresaTemporal;
    string nombreEmpresaTemporal;
    int numeroPatronalTemporal;
    string codigoPlanillaTemporal;
    string periodoTemporal;

    void limpiarDatosTemporales()
    {
        idEmpresaTemporal = "";
        nombreEmpresaTemporal = "";
        numeroPatronalTemporal = 0;
        codigoPlanillaTemporal = "";
        periodoTemporal = "";
    }

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
            cout << "Ingrese id de la empresa: ";
            cin >> idEmpresaTemporal;
            FuncionesPrincipales::buscarEmpresaPorId(idEmpresaTemporal);
            if (FuncionesPrincipales::existeEmpresa)
            {
                cout << "Ingresa el periodo DD/MM/YYYY - DD/MM/YYYY: ";
                cin >> periodoTemporal;
                FuncionesPrincipales::existePeriodoRegistrado(periodoTemporal, idEmpresaTemporal);
                if (FuncionesPrincipales::existePeriodo)
                {
                    cout << "Ya existe un periodo registrado con ese misma empresa" << endl;
                    limpiarDatosTemporales();
                }
                else
                {
                    string mensaje = FuncionesPrincipales::registrarDatosEmpresaPlanillaCSV(FuncionEmpresa::listEmpresasPlanillaTemporal);
                    cout << mensaje << endl;
                    limpiarDatosTemporales();
                }
            }
            else
            {
                cout << "Aun no existe la empresa en el registro" << endl;
                cout << "Registre la empresa 1. SI 2. NO :";
                cin >> opcion;
                string repuesta = FuncionesPrincipales::escribirEmpresa(opcion, FuncionEmpresa::listEmpresasPlanillaTemporal);
                cout << repuesta << endl;
                limpiarDatosTemporales();
            }

            break;
        case 2:
            cout << "Ingrese numero patronal de la empresa";
            cin >> idEmpresaTemporal;
            FuncionesPrincipales::buscarEmpresaPorNumeroPatronal(numeroPatronalTemporal);
            if (FuncionesPrincipales::existeEmpresa)
            {

                string mensaje = FuncionesPrincipales::registrarDatosEmpresaPlanillaCSV(FuncionEmpresa::listEmpresasPlanillaTemporal);
                cout << mensaje << endl;
                limpiarDatosTemporales();
            }
            else
            {
                cout << "Aun no existe la empresa en el registro" << endl;
                cout << "Registre la empresa 1. SI 2. NO :";
                cin >> opcion;
                string repuesta = FuncionesPrincipales::escribirEmpresa(opcion, FuncionEmpresa::listEmpresasPlanillaTemporal);
                cout << repuesta << endl;
                limpiarDatosTemporales();
            }

            break;
        case 3:
            cout << "Ingrese codigo planilla";
            cin >> codigoPlanillaTemporal;
            FuncionesPrincipales::buscarEmpresaPorCodigoPlanilla(codigoPlanillaTemporal);
            if (FuncionesPrincipales::existeEmpresa)
            {

                string mensaje = FuncionesPrincipales::registrarDatosEmpresaPlanillaCSV(FuncionEmpresa::listEmpresasPlanillaTemporal);
                cout << mensaje << endl;
                limpiarDatosTemporales();
            }
            else
            {
                cout << "Aun no existe la empresa en el registro" << endl;
                cout << "Registre la empresa 1. SI 2. NO :";
                cin >> opcion;
                string repuesta = FuncionesPrincipales::escribirEmpresa(opcion, FuncionEmpresa::listEmpresasPlanillaTemporal);
                cout << repuesta << endl;
                limpiarDatosTemporales();
            }
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
        FuncionesPrincipales::cargarEmpresasExistentes();
        FuncionesPrincipales::registroEmpresaPlanilla();

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
                if (opcion == 1)
                {
                    FuncionesPrincipales::crearHTMLSueldoMayor3000();
                    cout << "reporte generado!";
                    cout << '\n';
                }
                else if (opcion == 2)
                {

                    FuncionesPrincipales::crearHTMLSueldoMinimo();
                    cout << "reporte generado!";
                    cout << '\n';
                }

                break;
            case 3:
                cout << "Ingrese el numero de empresa: ";
                cin >> idEmpresaTemporal;
                FuncionesPrincipales::buscarEmpresaPorNumeroEmpresa(idEmpresaTemporal);
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
}