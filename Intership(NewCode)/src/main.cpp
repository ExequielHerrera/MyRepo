#include <iostream>

#include <bits/stdc++.h>
#include "JsonAnalizer.h"
#include<stdlib.h>
#include<fstream>

//Candidate: Herrera De Rosa, Exequiel.
//Technical questionnaire, GLOBANT Gaming Internship 2022.



//AGREGADOS:

//Debido a que el codigo puede crecer en gran medida, y es complicado hacer el seguimiento de includes (ademas de lo ineficiente que puede ser llegar a hacer reemplazos literales)
//se tiene una alternativa que es el pragma once.


//namespace divide el codigo en estructuras logicas. Uno puede invocar las estructuras/clases definidas all� incluyendo el nombre del namespace donde ellas fueron declaradas.
//Esto con el fin de mejorar la legibilidad y escalaibilidad del c�digo.
//NO SE DEBE ABUSAR DEL NAMESPACE PORQUE PUEDE TRAER CONFLICTOS POR NOMBRES! (Siempre que sea posible, evitar usarlo y utilizar la llamada del tipo namespace_name::).




//P R A G M A    O N C E       V  S      I N C L U D E    G U A R D S    (I N D E F)


//#PRAGMA ONCE permite que el c�digo solamente sea includo una unica vez en la compilaci�n.
//Su ventajas principales ser� que se analizar� una menor cantidad de codigo (por ende, salida mas peque�a).
//Se evitan colisiones de nombres.
//La compilaci�n se realizar mas r�pidamente.



//#IFNDEF NAME_CLASE #DEFINE NAME_CLASS . . .   #ENDIF NAME_CLASS
//Los include guards se utilizan para cuando el compilador no encuentra definida la clase, entonces todo lo que encuentres
//Despues de esto, ser� esa clase. Si la compliaci�n encuentra que esta definido, entonces skipea el codigo entre esas regiones.
//Aun as�, esto no evita que se compile el archivo.


//Es mas conveniente por legibilidad utilizar pragma once, ademas la gran mayoria de compliadores importantes los incluye (ya que no es del estandart)
//)La compilaci�n puede llegar a ser mas rapida, y legible ya que se requiere menos codigo (por ende, menos propenza a errores).


//Compilar actualmente el codigo tarda unos buenos segundos.




//I N C L U D E     V   S     F O W A R D    D E C L A R A T I O N


//Normalmente se declara adelantadamente en el archivo Header y los include en los cpp files cuando vas a usar los miembros de la clase declarada adelantadamente.
//(Esto es lo que hago).


//Una declaraci�n adelantada es mucho mas rapida de compilar que todo un archivo por si misma (ya que incluso puede incluir mas archivos).
//Ademas, si se cambia algo en el archivo del header incluido, todo (inluso los headers que �l mismo incluye) deben ser recompilados.


//Para utilizar foward declarations, se deben utilizar punteros, no instancias de la pila.


//CONSTRUCTORES VACIOS.
//Para constructores vacios, utilizar la definici�n del metodo constructor class_name() = default ;
//De esta forma, el compilador definir� el constructor predeterminado impl�cito incluso si hay otros constructores presentes.


//MEMORY LEAK
//Una fuga de memoria es un error de software que ocurre cuando un bloque de memoria reservada no es liberada en un programa de computaci�n.
//Com�nmente ocurre porque se pierden todas las referencias a esa �rea de memoria antes de haberse liberado


//SMART POINTERS

//Container o wrapper para RAW POINTERS. Los punteros inteligentes librean memoria automaticamente, por lo que no hay que preocuparse por leaks de memoria en el programa.
//Lo primero que hay que hacer es incluir la biblioteca <memory>
//Hay 3 punteros inteligentes en c++.

// --> Unique pointers:
//      --> Los punteros unique se declaran   unique_type<Class_name>pointer_name = make_unique<class_name>(valueAlocated); . Las desreferencias siguen siendo las mismas.
//      --> Los punteros unique NO PUEDEN COMPARTIRSE, SE PUEDE DERIVAR EL OWNERSHIP DE UN PUNTERO CON: move(unique_ptr_name); El due�o anterior ahora es nulo.
//      --> Su Tiempo de utilidad esta ligado al scope que lo contiene.

// --> Los share pointers pueden ser compartidos entre multiple owners.
        //--> Share_ptr<class_name> ptr_name = make_shared<class_name>(value);
        //--> Se puede saber la cantidad de punteros que comparten el dato, name_ptr.use_count()
        //--> Para compartir, share_ptr<class_name> ptr_name2 = ptr_name:
        //--> Cuando no hayan mas owners al dato, se desaloja automaticamente la memoria.
        //--> Cuando vayan terminando cada scope de los punteros que referencian al dato, se va restando un contador al total.

// --> Weaks pointers:
        //--> Los weak pointer son similares a los punteros compartidos, con la diferencia que ellos no aumentan la cantidad de use_counts del dato apuntado.
        //--> Tienen la semantica de observar, pero no de mantener vivo si es que nadie mas lo necesita, a diferencia del share que si lo har�.


//Un puntero sin procesar (RAW POINTER) es un puntero cuya vida �til no est� controlada por un objeto encapsulador, como un puntero inteligente.
//A un puntero sin procesar se le puede asignar la direcci�n de otra variable que no sea un puntero, o se le puede asignar un valor de nullptr


//La palabra inglesa wrapper designa un embalaje o envoltorio.
//En el contexto del software, este t�rmino hace referencia a programas o c�digos que rodean otros componentes de programa.



//La clase List tiene un maximo de tama�o vinculado al momento de crearla, por lo que (a mi entender) son estructuras semi-estaticas.
//Es por ello que didier mensiona que estoy corrompiendo la memoria, por que la lista esta en la STACK.




//ENUMERADOS:

//Tipo definido por el usuario que contiene un conjunto de nombres,
//llamados enumeradores, los cuales son constantes enteras. Su objetivo es agrupar constantes simbolicas
//que dan mas claridad al programa

//Dos tipos
//  --> Enumerados sin ambitos    enum identificador {cteSim1, conteSim2,...};
//      --> Ejemplo: enum estacion {primavera,verano,oto�o,invierno};
//      --> Ejemplo: enum fruta{sandia=3,fresa,naranja,pera=9} --> le da valores iguales al anterior +1 (fresa vale 4).
//      --> Luego, se instancia estacion st= primavera;


//  --> Enumeraci�n con ambito
//      --> enum class identificador {nombre1,nombre2,nombre3,...};
//      --> enum class estacion {primavera,verano,oto�o=1,invierno};
//      --> enum class fruta {sandia,fresa,naranja,pera=9};
// variable estacion st = estacion::primavera;


//VTABLES:

//Las tablas V (o tablas virtuales) son la forma en que la mayor�a de las implementaciones de C ++ hacen polimorfismo.
//Para cada implementaci�n concreta de una clase, hay una tabla de punteros de funci�n para todos los m�todos virtuales.
//Existe un puntero a esta tabla (llamada tabla virtual) como miembro de datos en todos los objetos.
//Cuando uno llama a un m�todo virtual, buscamos en la tabla v del objeto y llamamos al m�todo de clase derivado apropiado.


//VIRTUAL EN DESTRUCTORES:

//En la mayor�a de las implementaciones, la llamada al destructor se resolver� como cualquier c�digo no virtual, lo que significa que se llamar� al destructor de la clase base
//pero no al de la clase derivada, lo que provocar� una fuga de recursos.
//En resumen, siempre haga que los destructores de las clases base sean virtuales cuando est�n destinados a ser manipulados polim�rficamente.
//Si desea evitar la eliminaci�n de una instancia a trav�s de un puntero de clase base, puede hacer que el destructor de clase base est� protegido y no virtual;
//al hacerlo, el compilador no le permitir� llamar a delete en un puntero de clase base.


//Combinando estos topicos anteriores, declarar un constructor virtual sin herencia no tiene sentido, ya que se fuerza la generaci�n de una vtable innecesariamente.



//RETORNAR REFERENCIAS A CONSTANTES
//�C�mo devuelvo una referencia const?
//Cuando se desea devolver una referencia const cuando devuelve una propiedad de un objeto, que no desea que se modifique fuera de �l.
//Por ejemplo: cuando su objeto tiene un nombre, puede hacer el siguiente m�todo const std::string& get_name(){ return name; }; . Cu�l es la forma m�s �ptima.









string readFile();



string readFile(string fileName){
    ifstream originalCode;

    string exitCode;
    string line;

    originalCode.open(fileName,ios::in);

    if(originalCode.fail())
    {
        std::cout<<"An error occurred trying to open the file."<<std::endl;
        exit(1);
    }
    while(getline(originalCode,line)){
        exitCode = exitCode + line;
    }
    originalCode.close();
    exitCode = exitCode + "$"; //we include the End of File ($) character to the code.
    return exitCode;

}





int main()
{


    JsonAnalizer j;

    //we read the file.
    string code = readFile("ValidCode2.txt");

    //we set the code
    j.setJsonCode(code);

    //we get the dictionary

    list<DictionaryData> data = j.getDictionary();












    //showing the results

    if (!data.empty()){
            cout<<"D i c t i o n a r y   -   R e s u l t s"<<'\n'<<endl;
        }
    list<DictionaryData>::const_iterator Yter=data.begin();
    while (Yter!=data.end()){
        Yter->printData();
        Yter++;
    }




  return 0;
}
