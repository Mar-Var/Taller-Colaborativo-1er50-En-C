#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


void validarCorreo();

void contarPalabras();

void eliminarRepetidos();

void interseccion();

void borrarCaracteres();

void llenarCaracteres();

void cuentaANuevo();

void contarVocales();

void buscarCadenaCaracteres();

void convertiraPropio();

int main() {
    char *menu = "\n<<<<<<<<<Taller Colaborativo en C>>>>>>>>\n\n"
                 "1.Convertir cadena a nombre propio\n"
                 "2. Buscar cadena de caracteres\n"
                 "3. Contar vocales\n"
                 "4. Anio nuevo\n"
                 "5. Llenar caracteres\n"
                 "6. Borrar caracteres\n"
                 "7. Interseccion\n"
                 "8. Eliminar repetidos\n"
                 "9. Contar palabras\n"
                 "x. Validar correo electronico\n"
                 "0. Salir\n\n"
                 "Dijite una opcion\n";
    char opcion;
    do{
        printf(menu);
        fflush(stdin);
        opcion = getchar();

        switch(opcion){
            case '1': convertiraPropio(); //Laura
                break;
            case '2': buscarCadenaCaracteres();//Laura
                break;
            case '3': contarVocales();//Laura
                break;
            case '4': cuentaANuevo();//Marcos
                break;
            case '5': llenarCaracteres();//Yasser
                break;
            case '6': borrarCaracteres();//Yasser
                break;
            case '7': interseccion();//Yasser
                break;
            case '8': eliminarRepetidos();//Marcos
                break;
            case '9': contarPalabras();//Marcos
                break;
            case 'x': validarCorreo();//Marcos
                break;
        }
    } while (opcion!='0');

    return 0;
}

char* obtenerString(int chararacter){
    /*
     muchas operaciones se hacen con lso punteros char* asi que en vez de sufrir casteando
     esta funcion lo va haciendo por nosotros letra por letra
     el codigo lo encontre en
     https://es.stackoverflow.com/questions/31601/guardar-cadena-de-caracteres-en-c
     creditos a quien corresponda ;)
     */

    fflush(stdin);
    char* string;
    string = 0;
    int tamanio = 0;
    do{
        if (chararacter) {// 1 = true, significa que se busca unicamente 1 caracter
            printf("Por favor ingrese el caracter que desea utilizar:\n");
            /*realloc retorna un nuevo array con el contenido existente en el array que se
              envio en el 1 parametro y del tamaño que se le envio en el 2 parametro
            */
            string = (char*)realloc(string,tamanio + 1);

            //obtenemos el codigo ascii del caracter ingresado
            int c = getchar();

            /*transformamos el codigo ascii a su respectivo caracter y se ingresa en la posicion
            correspondiente*/
            string[tamanio] = (char)c;

            /*los array para poder ser inpresons mediante el printf deben de tener en su
             ultima casilla un \0 el cual conseguimos al designarle el 0 a la casilla, esto
             lo interpreta el computador como que se finalizo exitosamente la impresion del
             array*/
            string[tamanio+1] = 0;
        }else {// 0 = false, significa que busca una cadena de caracteres
            printf("Por favor ingrese la cadena de caracteres que desea utilizar:\n");
            fflush(stdout);
            while( 1 ) {
                /*aqui repetiremos el proceso anterior las veces necesarias para que el array
                 contenga todos los caracteres inscritos, la funcion realloc estara
                 constanmente retornando un nuevo array con el contenido que ya se tenia y
                 una casilal adicional en blanco la que sera rellenada con el caracter que se
                 esta procesando
                 */
                string = (char*)realloc(string,tamanio + 1);
                int c = getchar();
                if( c == 10 ){
                    string[tamanio] = 0;
                    break;
                }
                string[tamanio] = (char)c;
                tamanio++;
            }
        }
        /*Dado que no se puede procesar el espacio como un caracter la primera casilla queda
         con el valor 0, por ende al presentarse este valor en esta casilla sabemos que el
         array se encuentra "vacio"
         */
        if ((int)(string[0])==0) {
            printf("Lo lamento pero no podemos procesar un espacio en blanco como una cadena\n");
            printf("Presiona enter para ingresar una cadena\n");
            fflush(stdin);
            getchar();
            system("cls");
        }
    }while((int)(string[0])==0);

    return string;
}

void convertiraPropio() {

    char* string = obtenerString(0);
    int numCharacters = strlen(string);

    if(string[0] != ' ' && string[1] != ' ' && strlen(string) > 1){
        if(string[0] >= 'a' && string[0]<='z'){
            string[0] = (char)(('A'-'a') + string[0] );
        }
    }

    else if (string[0] >= 'A' && string[0] <= 'Z'){
        string[0] = (char)(string[0] + ('a' - 'A'));
    }

    for(int i=1; i<numCharacters; i++){

        if((string[i-1] != ' ') || (string[i-1] == ' ' && string[i+1] == ' ' ) || (string[i+1] == '\0')){
            if (string[i] >= 'A' && string[i] <= 'Z'){
                string[i] = (char)(string[i] + ('a' - 'A'));
            }
        }
        else if (string[i] >= 'a' && string[i] <= 'z'){
            string[i] = (char)(('A'-'a') + string[i] );
        }
    }

    printf("La cadena de caracteres ingresada\nconvertida en nombre propio es:\n %s\n", string);
}

void funcionCadena(){
    fflush(stdin);

}


void buscarCadenaCaracteres() {
    printf("%s\n", "*Cadena Uno");
    char* string = obtenerString(0);
    printf("%s\n", "*Palabra a buscar");
    char* palabra = obtenerString(0);

    int tamanioString = strlen(string);
    int tamanioPalabra= strlen(palabra);

    //convertir string a minusculas
    for (int i = 0; i < tamanioString; i++ )  {
        string[i] = tolower( string[i] );
    }
    //convertir palabra a minusculas
    for (int i = 0; i < tamanioPalabra; i++ )  {
        palabra[i] = tolower( palabra[i] );
    }

    int j = 0;
    int iguales = 0;
    int palabrasEncontradas = 0;

    for(int i = 0 ; i < tamanioString ; i++){
        if (string[i] == palabra[j]){
            iguales+=1;
            j+=1;
        }else{
            iguales = 0;
            j = 0;
        }

        if(iguales == tamanioPalabra){
            palabrasEncontradas+=1;
            j = 0;
            iguales = 0;
        }
    }

    printf("\nNumero de palabras encontradas: %d\n", palabrasEncontradas);
}

void contarVocales() {
    printf("%s\n", "*Cadena Uno");
    char* string = obtenerString(0);

    int tamanioString = strlen(string);

    //convertir string a minusculas
    for (int i = 0; i < tamanioString; i++ )  {
        string[i] = tolower( string[i] );
    }

    int vocales[6];
    for (int i = 0; i < 6; i++ )  {
        vocales[i] = 0;
    }

    for(int i = 0 ; i < tamanioString ; i++){
        if(string[i]=='a'){
            vocales[0]++;
        }else if(string[i]=='e'){
            vocales[1]++;
        }else if(string[i]=='i'){
            vocales[2]++;
        }else if(string[i]=='o'){
            vocales[3]++;
        }else if(string[i]=='u'){
            vocales[4]++;
        }
    }

    for (int i = 0; i < 5; i++ )  {
        vocales[5] += vocales[i];
    }

    printf("La cadena ingresada tiene un total de %d vocales\n", vocales[5]);
    printf("a: %d\n", vocales[0]);
    printf("e: %d\n", vocales[1]);
    printf("i: %d\n", vocales[2]);
    printf("o: %d\n", vocales[3]);
    printf("u: %d\n", vocales[4]);

}

void cuentaANuevo() {

}

void llenarCaracteres() {

}

void borrarCaracteres() {

}

void interseccion() {

}

void eliminarRepetidos() {

}

void contarPalabras() {

}

void validarCorreo() {

}