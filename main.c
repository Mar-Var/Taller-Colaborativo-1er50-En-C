#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>


void validarCorreo(char *email);

void contarPalabras(char *str1,char *str2 );

void eliminarRepetidos(char *str1);

void interseccion();

void borrarCaracteres();

void llenarCaracteres();

void cuentaANuevo(const char *hora);

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
                 "9. Validar correo electronico\n"
                 "0. Salir\n\n"
                 "Dijite una opcion\n";
    char opcion;

    char *name[500];
    do{
        printf(menu);
        fflush(stdin);
        opcion = getchar();

        switch(opcion){
            case '1':
                convertiraPropio(); //Laura
                break;
            case '2': buscarCadenaCaracteres();//Laura
                break;
            case '3': contarVocales();//Laura
                break;
            case '4':
                printf("Ingrese la hora actual en formato HH:MM");
                char* horita[50];
                fflush(stdin);
                fgets(horita,50,stdin);
                const char* hora =horita;
                cuentaANuevo(hora);//Marcos
                break;
            case '5': llenarCaracteres();//Yasser
                break;
            case '6': borrarCaracteres();//Yasser
                break;
            case '7': interseccion();//Yasser
                break;

            case '8':
                printf("ingrese la cadena a operar");
                char *str1_[200];
                fflush(stdin);
                fgets(str1_,200,stdin);

                eliminarRepetidos(str1_);//Marcos
                break;

            case '9':
            printf("Ingrese una direccion de correo electronico");
            char* email[300];
            fflush(stdin);
            fgets(email,300,stdin);
            validarCorreo(email);//Marcos
                break;
        }
    } while (opcion!='0');

    return 0;
}

char* obtenerString(int chararacter){

    fflush(stdin);
    char* string;
    string = 0;
    int tamanio = 0;
    do{
        if (chararacter) {
            printf("Por favor ingrese el caracter que desea utilizar:\n");

            string = (char*)realloc(string,tamanio + 1);


            int c = getchar();

            string[tamanio] = (char)c;


            string[tamanio+1] = 0;
        }else {
            printf("Por favor ingrese la cadena de caracteres que desea utilizar:\n");
            fflush(stdout);
            while( 1 ) {

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

void cuentaANuevo(const char* hora) {

    int cantidadMinutosRestantes;
    int cont=0;
    for(int i=0;i<5;i++){
        if(hora[i]==':'){
            cont++;
        }
    }

    if(cont==1){
        int i1, i2;
        if (2 == sscanf(hora,
                        "%d%*[^0123456789]%d",
                        &i1,
                        &i2))
        {

           if(i1>=24 ||i1<0 || i2<0 || i2>=60 ){
                printf("Los valores asignados no son validos");
            }else{
                cantidadMinutosRestantes=1440-((i1*60)+i2);
                printf("la cantidad de minutos restantes es  : %d minutos ",cantidadMinutosRestantes);
            }
        }

    }else{
        printf("El formato ingresado no corresponde");
    }



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

int nCharsRepe(char chain[], char c) {
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

void eliminarRepetidos(char *str1) {
    char c ,aux;
    int k=0;
    char resultado[200]="";
    for (int j = 0; j < strlen(str1); j++ )  {
        str1[j] = tolower( str1[j] );
    }
    for (int i = 0; i < strlen(str1); ++i) {
        if(!strchr(resultado,str1[i]))
            resultado[k++]=str1[i];
    }
    resultado[k]='\0';
    printf("la cadena final sin caracteres repetidos es %s",resultado);

/*    for (int i = 0; i < strlen(str1); ++i) {
        c=str1[i];
        for (int j = i+1; j < strlen(str1); ++j) {
            if(str1[j]==str1[i]){
                str1[j]="";
                printf(str1);
            }
            if(j+1==strlen(str1)) break;
        }
    }*/


}

/*
void contarPalabras(char *str1,char *str2) {
    int len1= strlen(str1);
    int len2 = strlen(str2);
    int j=0;
    int count=0;
    char c = str2[0];
    //convertir Cadena larga a minusculas
    for (int i = 0; i < len1; i++ )  {
        str1[i] = tolower( str1[i] );
    }
    //convertir palabra a minusculas
    for (int k = 0; k < len2; k++ )  {
        str2[k] = tolower( str2[k] );
    }

    while (j<len1){
        if ( str1[j]== c){
            if(strncmp(&str1[j],str2,len2)==0){
                count++;
            }
        }
        j++;
    }

    printf("la cantidad de veces que se repite la palabra ' %s ' es %d vez/veces ",str2,count);

}
*/

void validarCorreo(char *email) {
    int contadorAnterior =0,contadorPosterior=0,contadorPostPunto=0,contadorPostPostPunto=0,contadorArroba=0,contadorPuntos=0;

    int longitud= strlen(email);

    //Fase de Validacion de email
    if(email[longitud-2]=='@'||email[0]=='@'|| email[longitud-2]=='.'||email[0]=='.'){
        printf("Formato de email invalido");
    }else{
        for (int i=0;i<strlen(email);i++){
            if(((email[i]=='@')&&(email[i+1]=='@'))||((email[i]=='@')&&(email[i+1]=='.'))||((email[i]=='.')&&(email[i+1]=='@'))){
                printf("Formato de email invalido");
                break;
            }else{
            }
        }
        for(int i=0;i<strlen(email);i++){
            if(email[i]=='@') contadorArroba++;
        }
        if(contadorArroba==0)printf("Formato de email invalido. Debe conterner minimo una @");
    }

    // Fase de Validacion 2
    int j=0,k;
    for(j=0;j<longitud;j++){
        contadorAnterior++;
        if(email[j]=='@'){
            j=j;
            break;
        }
       // marcosvargas97@gmail.com
    }
    k=j;
    for (k; k < longitud; k++) {
        if(email[k]=='.') contadorPuntos++;
    }
    for(j=j;j<longitud;j++){

        if(email[j]=='.'){
            j=j;
            break;
        }
        contadorPosterior++;
    }
    for(j=j+1;j<longitud;j++){
        contadorPostPunto++;
        if(email[j]=='.'){
            j=j;
            break;
        }
    }
    if(contadorPuntos==2){
        for(j=j;j=='\0';j++){
            contadorPostPostPunto++;
        }
        if(contadorPostPostPunto<0)printf("Debe tener mas de 1 caracteres despues  de el anterior punto que le seguia a la @");

    }
    if (contadorPuntos>2) { printf("El formato del correo es invalido"); }else{
        if(contadorAnterior<3)printf("Debe tener mas de 2 caracteres antes de el @");
        else if(contadorPosterior<2)printf("Debe tener mas de 2 caracteres despues de el @ y antes del siguiente punto");
        else if(contadorPuntos==0)printf("Debe tener minimo 1 punto despues del @");
        else if(contadorPostPunto<3)printf("Debe tener mas de 2 caracteres antes del primer punto despues del @");

        else{
            printf("El correo que ha ingresado es valido");
        }
    }



}