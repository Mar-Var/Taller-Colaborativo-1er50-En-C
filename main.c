#include <stdio.h>


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
    char *menu = "<<<<<<<<<Taller Colaborativo en C>>>>>>>>\n\n"
                 "1.Convertir cadena a nombre propio\n"
                 "2. Buscar cadena de caracteres\n"
                 "3. Contar vocales\n"
                 "4. Año nuevo\n"
                 "5. Llenar caracteres\n"
                 "6. Borrar caracteres\n"
                 "7. Interseccion\n"
                 "8. Elliminar repetidos\n"
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

void convertiraPropio() {

}

void buscarCadenaCaracteres() {

}

void contarVocales() {

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

