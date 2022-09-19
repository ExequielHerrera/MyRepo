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


//namespace divide el codigo en estructuras logicas. Uno puede invocar las estructuras/clases definidas allí incluyendo el nombre del namespace donde ellas fueron declaradas.
//Esto con el fin de mejorar la legibilidad y escalaibilidad del código.
//NO SE DEBE ABUSAR DEL NAMESPACE PORQUE PUEDE TRAER CONFLICTOS POR NOMBRES! (Siempre que sea posible, evitar usarlo y utilizar la llamada del tipo namespace_name::).




//P R A G M A    O N C E       V  S      I N C L U D E    G U A R D S    (I N D E F)


//#PRAGMA ONCE permite que el código solamente sea includo una unica vez en la compilación.
//Su ventajas principales será que se analizará una menor cantidad de codigo (por ende, salida mas pequeña).
//Se evitan colisiones de nombres.
//La compilación se realizar mas rápidamente.



//#IFNDEF NAME_CLASE #DEFINE NAME_CLASS . . .   #ENDIF NAME_CLASS
//Los include guards se utilizan para cuando el compilador no encuentra definida la clase, entonces todo lo que encuentres
//Despues de esto, será esa clase. Si la compliación encuentra que esta definido, entonces skipea el codigo entre esas regiones.
//Aun así, esto no evita que se compile el archivo.


//Es mas conveniente por legibilidad utilizar pragma once, ademas la gran mayoria de compliadores importantes los incluye (ya que no es del estandart)
//)La compilación puede llegar a ser mas rapida, y legible ya que se requiere menos codigo (por ende, menos propenza a errores).


//Compilar actualmente el codigo tarda unos buenos segundos.




//I N C L U D E     V   S     F O W A R D    D E C L A R A T I O N


//Normalmente se declara adelantadamente en el archivo Header y los include en los cpp files cuando vas a usar los miembros de la clase declarada adelantadamente.
//(Esto es lo que hago).


//Una declaración adelantada es mucho mas rapida de compilar que todo un archivo por si misma (ya que incluso puede incluir mas archivos).
//Ademas, si se cambia algo en el archivo del header incluido, todo (inluso los headers que él mismo incluye) deben ser recompilados.


//Para utilizar foward declarations, se deben utilizar punteros, no instancias de la pila.


//CONSTRUCTORES VACIOS.
//Para constructores vacios, utilizar la definición del metodo constructor class_name() = default ;
//De esta forma, el compilador definirá el constructor predeterminado implícito incluso si hay otros constructores presentes.


//MEMORY LEAK
//Una fuga de memoria es un error de software que ocurre cuando un bloque de memoria reservada no es liberada en un programa de computación.
//Comúnmente ocurre porque se pierden todas las referencias a esa área de memoria antes de haberse liberado


//SMART POINTERS

//Container o wrapper para RAW POINTERS. Los punteros inteligentes librean memoria automaticamente, por lo que no hay que preocuparse por leaks de memoria en el programa.
//Lo primero que hay que hacer es incluir la biblioteca <memory>
//Hay 3 punteros inteligentes en c++.

// --> Unique pointers:
//      --> Los punteros unique se declaran   unique_type<Class_name>pointer_name = make_unique<class_name>(valueAlocated); . Las desreferencias siguen siendo las mismas.
//      --> Los punteros unique NO PUEDEN COMPARTIRSE, SE PUEDE DERIVAR EL OWNERSHIP DE UN PUNTERO CON: move(unique_ptr_name); El dueño anterior ahora es nulo.
//      --> Su Tiempo de utilidad esta ligado al scope que lo contiene.

// --> Los share pointers pueden ser compartidos entre multiple owners.
        //--> Share_ptr<class_name> ptr_name = make_shared<class_name>(value);
        //--> Se puede saber la cantidad de punteros que comparten el dato, name_ptr.use_count()
        //--> Para compartir, share_ptr<class_name> ptr_name2 = ptr_name:
        //--> Cuando no hayan mas owners al dato, se desaloja automaticamente la memoria.
        //--> Cuando vayan terminando cada scope de los punteros que referencian al dato, se va restando un contador al total.

// --> Weaks pointers:
        //--> Los weak pointer son similares a los punteros compartidos, con la diferencia que ellos no aumentan la cantidad de use_counts del dato apuntado.
        //--> Tienen la semantica de observar, pero no de mantener vivo si es que nadie mas lo necesita, a diferencia del share que si lo hará.


//Un puntero sin procesar (RAW POINTER) es un puntero cuya vida útil no está controlada por un objeto encapsulador, como un puntero inteligente.
//A un puntero sin procesar se le puede asignar la dirección de otra variable que no sea un puntero, o se le puede asignar un valor de nullptr


//La palabra inglesa wrapper designa un embalaje o envoltorio.
//En el contexto del software, este término hace referencia a programas o códigos que rodean otros componentes de programa.



//La clase List tiene un maximo de tamaño vinculado al momento de crearla, por lo que (a mi entender) son estructuras semi-estaticas.
//Es por ello que didier mensiona que estoy corrompiendo la memoria, por que la lista esta en la STACK.




//ENUMERADOS:

//Tipo definido por el usuario que contiene un conjunto de nombres,
//llamados enumeradores, los cuales son constantes enteras. Su objetivo es agrupar constantes simbolicas
//que dan mas claridad al programa

//Dos tipos
//  --> Enumerados sin ambitos    enum identificador {cteSim1, conteSim2,...};
//      --> Ejemplo: enum estacion {primavera,verano,otoño,invierno};
//      --> Ejemplo: enum fruta{sandia=3,fresa,naranja,pera=9} --> le da valores iguales al anterior +1 (fresa vale 4).
//      --> Luego, se instancia estacion st= primavera;


//  --> Enumeración con ambito
//      --> enum class identificador {nombre1,nombre2,nombre3,...};
//      --> enum class estacion {primavera,verano,otoño=1,invierno};
//      --> enum class fruta {sandia,fresa,naranja,pera=9};
// variable estacion st = estacion::primavera;


//VTABLES:

//Las tablas V (o tablas virtuales) son la forma en que la mayoría de las implementaciones de C ++ hacen polimorfismo.
//Para cada implementación concreta de una clase, hay una tabla de punteros de función para todos los métodos virtuales.
//Existe un puntero a esta tabla (llamada tabla virtual) como miembro de datos en todos los objetos.
//Cuando uno llama a un método virtual, buscamos en la tabla v del objeto y llamamos al método de clase derivado apropiado.


//VIRTUAL EN DESTRUCTORES:

//En la mayoría de las implementaciones, la llamada al destructor se resolverá como cualquier código no virtual, lo que significa que se llamará al destructor de la clase base
//pero no al de la clase derivada, lo que provocará una fuga de recursos.
//En resumen, siempre haga que los destructores de las clases base sean virtuales cuando estén destinados a ser manipulados polimórficamente.
//Si desea evitar la eliminación de una instancia a través de un puntero de clase base, puede hacer que el destructor de clase base esté protegido y no virtual;
//al hacerlo, el compilador no le permitirá llamar a delete en un puntero de clase base.


//Combinando estos topicos anteriores, declarar un constructor virtual sin herencia no tiene sentido, ya que se fuerza la generación de una vtable innecesariamente.



//RETORNAR REFERENCIAS A CONSTANTES
//¿Cómo devuelvo una referencia const?
//Cuando se desea devolver una referencia const cuando devuelve una propiedad de un objeto, que no desea que se modifique fuera de él.
//Por ejemplo: cuando su objeto tiene un nombre, puede hacer el siguiente método const std::string& get_name(){ return name; }; . Cuál es la forma más óptima.









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
