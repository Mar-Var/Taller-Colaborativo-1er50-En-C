#include <stdio.h>
#include <string.h>
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
    char input[100], charc;
    int n, dir;

    printf("Digite una cadena \n");
    gets(input);
    gets(input);
    printf("Digite el caracter \n");
    scanf("%c", &charc);
    printf("Digite el numero de veces que se repite el caracter \n");
    scanf("%i", &n);

    char chars[n-1];
    for (int i = 0; i < n; i++) {
        chars[i] = charc;
    }

    printf("Selecion direccion: \n"
           "[0] Derecaha \n"
           "[1] Izquierda \n");
    scanf("%i", &dir);
    switch ( dir ) {
        case 0:
            strcat(&input, &chars);
            printf("%s \n", input);
            break;
        case 1:
            strcat(&chars, &input);
            printf("%s \n", chars);
            break;
        default:
            printf("Digito invalido \nIntente de nuevo \n");
            llenarCaracteres();
            break;
    }


}

void borrarCaracteres() {
    char input[100], charc, aux[100];

    printf("Digite cadena \n");
    gets(input);
    gets(input);

    printf("Digite caracter a borrar de la cadena \n");
    scanf("%c", &charc);

    int index = 0;
    for (int i = 0; i < strlen(input); i++) {
        if ( (tolower((unsigned char) input[i]) != tolower((unsigned char) charc)) && (input[i] != '\0' && charc !='\0') ){
            aux[index] = input[i];
            index++;
        } else {}
    }

    printf("Cadena final: ");
    for (int i = 0; i < strlen(aux); i++) {
        if ( aux[i] != '\0' ){
            printf("%c", aux[i]);
        }
    }
    printf("\n");

}

int nCharsRepe(char chain[], char c) {//Devuelve el numero de veces que existe un caracter en la cadena.
    int cont = 0;
    for (int i = 0; i < strlen(chain); ++i) {
        if ( c == chain[i] ) {
            cont++;
        }
    }

    return cont;
}

void interseccion() {
    char chain_1[100], chain_2[100], aux[100];
    printf("Digite la 1ra cadena\n");
    gets(chain_1);
    gets(chain_1);
    printf("Digite la 2da cadena\n");
    gets(chain_2);

    printf("Cadena 1: %s | Cadena 2: %s \n", chain_1, chain_2);

    int index = 0;
    for (int i = 0; i < strlen(chain_1); i++) {
        for (int j = 0; j < strlen(chain_2); j++) {
            if ( tolower((unsigned char) chain_1[i]) == tolower((unsigned char) chain_2[j]) ) {
                //printf("coincide => %c = %c \n", chain_1[i], chain_2[j]);
                char rep = chain_1[i];

                if ( nCharsRepe(aux, rep) == 0 ) {
                    aux[index] = rep;
                    index++;
                }

            } else {
            }
        }
    }

    printf("Interseccion: %s \n", aux);

}

void eliminarRepetidos() {

}

void contarPalabras() {

}

void validarCorreo() {

}

