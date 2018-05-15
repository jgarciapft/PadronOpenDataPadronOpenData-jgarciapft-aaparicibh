//============================================================================
// Name        : UI.cpp
// Author      : Profesores de la asignatura EDI
// Version     : Curso 17/18
// Copyright   :
// Description : Interfaz de usuario
//============================================================================

#include "ui.h"

using namespace std;

UI::UI() {
	ejecutar();
}

void UI::ejecutar() {
	double t_start, t_end;				//Almacena la diferencia de tiempo entre dos intervalos. Mide los tiempos de ejecución de los algoritmos
	int opcion;							//Opción del menú elegida por el usuario
	string nombreBarrio;				//Nombre del barrio a utilizar por los algoritmos 2 y 8
	string nombreProvincia;				//Nombre de la provincia a utilizar por el algoritmo 10 y 12
	string nombreVia;					//Nombre de la vía a utilizar por el algoritmo 11
	string raizVia;						//Raíz de la vía a utilizar por el algoritmo 12
	int limInf;							//Límite inferior del rango de edad a utilizar por el algoritmo 7
	int limSup;							//Límite superior del rango de edad a utilizar por el algoritmo 7

	bool salir = false;					//Bandera que indica que si el usuario ha decidido cerrar el programa
	bool datosCargados = false;			//Bandera para prevenir la ejecución de algoritmo sin haber cargado los datos y para prevenir la múltiple carga de datos

	do {
		opcion = menu();				//Obtiene la opción indicada por el usuario
		switch (opcion) {				//En base a la opción elegida pregunta datos adicionales y/o ejecuta el algoritmo seleccionado
		case 1:
			if(!datosCargados){			//Maneja la múltiple carga de datos
				t_start = Time::getTime();
				cout << "Cargando datos ... " << endl;
				p.cargarBarrios();
				p.cargarVias();
				p.cargarDatosDemograficos();
				cout << "Carga finalizada ... " << endl;
				t_end= Time::getTime();
				cout << "Tiempo: " << t_end - t_start << "  seg." << endl;
				datosCargados = true;	//Actualización de la bandera para indicar que los datos ya están cargados
			}else{						//Si los datos ya han sido cargados se indica al usuario por consola
				cout << "YA HAN SIDO CARGADOS LOS DATOS DEL PADRÓN \n Puede ejecutar los algoritmos con norlmalidad" << endl;
				pausa();
			}
			break;
		case 2:
			if(datosCargados){			//Comprueba que los datos del padrón hayan sido cargados
				cout << "Introduzca el nombre del BARRIO :" << endl;
				cin >> nombreBarrio;
				t_start = Time::getTime();
				p.alg2(nombreBarrio);
				t_end= Time::getTime();
				cout << "Tiempo: " << t_end - t_start << "  seg." << endl;
			}else{						//Sino se indica al usuario por consola
				cout << "ERROR : No se han cargados los datos del Padrón\n Utilice la OPCIÓN 1 y vuelva a intentarlo" << endl;
			}
			pausa();					//Pausa la ejecución hasta que el usuario pulse una tecla para dar tiempo a visualizar los resultados de los algoritmos
			break;
		case 3:
			if(datosCargados){			//Comprueba que los datos del padrón hayan sido cargados
				t_start = Time::getTime();
				p.alg3();
				t_end= Time::getTime();
				cout << "Tiempo: " << t_end - t_start << "  seg." << endl;
			}else{						//Sino se indica al usuario por consola
				cout << "ERROR : No se han cargados los datos del Padrón\n Utilice la OPCIÓN 1 y vuelva a intentarlo" << endl;
			}
			pausa();
			break;
		case 4:
			if(datosCargados){
				t_start = Time::getTime();
				p.alg4();
				t_end= Time::getTime();
				cout << "Tiempo: " << t_end - t_start << "  seg." << endl;
			}else{
				cout << "ERROR : No se han cargados los datos del Padrón\n Utilice la OPCIÓN 1 y vuelva a intentarlo" << endl;
			}
			pausa();
			break;
		case 5:
			if(datosCargados){
				t_start = Time::getTime();
				p.alg5();
				t_end= Time::getTime();
				cout << "Tiempo: " << t_end - t_start << "  seg." << endl;
			}else{
				cout << "ERROR : No se han cargados los datos del Padrón\n Utilice la OPCIÓN 1 y vuelva a intentarlo" << endl;
			}
			pausa();
			break;
		case 6:
			if(datosCargados){
				t_start = Time::getTime();
				p.alg6();
				t_end= Time::getTime();
				cout << "Tiempo: " << t_end - t_start << "  seg." << endl;
			}else{
				cout << "ERROR : No se han cargados los datos del Padrón\n Utilice la OPCIÓN 1 y vuelva a intentarlo" << endl;
			}
			pausa();
			break;
		case 7:
			if(datosCargados){
				cout << "Introduzca el LÍMITE INFERIOR del intervalo : " << endl;
				cin >> limInf;
				cout << "Introduzca el LÍMITE SUPERIOR del intervalo : " << endl;
				cin >> limSup;
				t_start = Time::getTime();
				p.alg7(limInf, limSup);
				t_end= Time::getTime();
				cout << "Tiempo: " << t_end - t_start << "  seg." << endl;
			}else{
				cout << "ERROR : No se han cargados los datos del Padrón\n Utilice la OPCIÓN 1 y vuelva a intentarlo" << endl;
			}
			pausa();
			break;
		case 8:
			if(datosCargados){
				cout << "Introduzca el nombre del BARRIO :" << endl;
				cin >> nombreBarrio;
				t_start = Time::getTime();
				p.alg8(nombreBarrio);
				t_end= Time::getTime();
				cout << "Tiempo: " << t_end - t_start << "  seg." << endl;
			}else{
				cout << "ERROR : No se han cargados los datos del Padrón\n Utilice la OPCIÓN 1 y vuelva a intentarlo" << endl;
			}
			pausa();
			break;
		case 9:
			if(datosCargados){
				t_start = Time::getTime();
				p.alg9();
				t_end= Time::getTime();
				cout << "Tiempo: " << t_end - t_start << "  seg." << endl;
			}else{
				cout << "ERROR : No se han cargados los datos del Padrón\n Utilice la OPCIÓN 1 y vuelva a intentarlo" << endl;
			}
			pausa();
			break;
		case 10:
			if(datosCargados){
				cout << "Introduzca el nombre la PROVINCIA :" << endl;
				cin >> nombreProvincia;
				t_start = Time::getTime();
				p.alg10(nombreProvincia);
				t_end= Time::getTime();
				cout << "Tiempo: " << t_end - t_start << "  seg." << endl;
			}else{
				cout << "ERROR : No se han cargados los datos del Padrón\n Utilice la OPCIÓN 1 y vuelva a intentarlo" << endl;
			}
			pausa();
			break;
		case 11:
			if(datosCargados){
				cout << "Introduzca el nombre de la VÍA :" << endl;
				cin >> nombreVia;
				t_start = Time::getTime();
			 	p.alg11_EDNL(nombreVia);
				t_end= Time::getTime();
				cout << "Tiempo: " << t_end - t_start << "  seg." << endl;
			}else{
				cout << "ERROR : No se han cargados los datos del Padrón\n Utilice la OPCIÓN 1 y vuelva a intentarlo" << endl;
			}
			pausa();
			break;
		case 12:
			if(datosCargados){
				cout << "Introduzca la RÁIZ de la VÍA :" << endl;
				cin >> raizVia;
				cout << "Introduzca la PROVINCIA :" << endl;
				cin >> nombreProvincia;
				t_start = Time::getTime();
				p.alg12_EDNL(raizVia, nombreProvincia);
				t_end= Time::getTime();
				cout << "Tiempo: " << t_end - t_start << "  seg." << endl;
			}else{
				cout << "ERROR : No se han cargados los datos del Padrón\n Utilice la OPCIÓN 1 y vuelva a intentarlo" << endl;
			}
			pausa();
			break;
		case 0:							//Se ha seleccionado terminar el programa
			salir = true;
			break;
		default:						//Si la opción no es válida vuelve a preguntar al usuario
			cout << "ERROR en la opcion de menu" << endl;
			break;
		}
	} while (!salir);
}

int UI::menu() {
	int opcion;

	do {
		cout << endl;
		cout << "_________________________________ MENU PRINCIPAL __________________________________"<< endl << endl;

		cout << "   1. Carga de datos                                                               "<< endl;
		cout << "   2. Mostrar vías de un barrio                                                    "<< endl;
		cout << "   3. Mostrar las vías que pertenecen a varios barrios                             "<< endl;
		cout << "   4. Mostrar el número de habitantes de Cáceres agrupados por rango de edad       "<< endl;
		cout << "   5. Listado por nacionalidades                                                   "<< endl;
		cout << "   6. Número de habitantes por provincia de nacimiento                             "<< endl;
		cout << "   7. Barrio con mayor número de habitantes para un rango de edad                  "<< endl;
		cout << "   8. Fichero por nivel de estudios de todos los ciudadanos de un barrio           "<< endl;
		cout << "   9. Barrio con mayor porcentaje de hombres/mujeres.                              "<< endl;
		cout << "  10. Fichero con los habitantes nacidos en los pueblos de una provincia           "<< endl;
		cout << "  11. Fichero por lugar de nacimiento de una determinada vía (Alg. crítico)        "<< endl;
		cout << "  12. Listado nº de personas nacidas en una provincia de las vias que comiencen por...(Alg.crítico)"<< endl;

		cout << endl;
		cout << "   0. Finalizar. " << endl;
		cout << " Opcion:  ";
		cin >> opcion;
		cin.ignore();

	} while ((opcion < 0) || (opcion > 13));

	return opcion;
}

void UI::pausa() {
	string tecla;						//Almacena la tecla pulsada (y cualquier tipo de cadena que el usuario haya podido meter descuidadamente. Se evita llenar el buffer de escritura)

	do{									//Permite al usuario elegir cuando quiere volver al menú
		cout << "\nPresione la tecla (" << TECLA_MENU << ") para volver al menú . . ." << endl;
		cin >> tecla;
	}while(tecla[0] != TECLA_MENU);
}

UI::~UI() {
	cout << "Finalizado....";
}

int main() {
	UI ui;

	return 0;
}

