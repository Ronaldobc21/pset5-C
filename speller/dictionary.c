
// Implements a dictionary's functionality


#include <stdbool.h>
#include "dictionary.h"
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>


//#define hashtable
//#define  LENGTH 45 // Revisar aqui PORCC. Ya esta declarado en dictionary.h

typedef struct node // Asi es como se declara un nodo  para comenzar.
{
    char word [ LENGTH + 1 ];
    struct node *next;
}
node; // Aqui termina.

const unsigned  int valor  = 10000; // Aqui va la constante.

unsigned int table_val;

unsigned int word_add;

node *sign [valor];

unsigned int table(const char *word);


// Returns true if word is in dictionary else false.
bool check(const char *word)
{


    table_val = table(word);

    node *direction = sign[table_val];


    while (direction != NULL) // Revisa la lista enlazada.
    {
        if (strcasecmp(word, direction -> word) == 0)
        {
            return true;
        }

        direction = direction -> next;  // Este cursor es para que se mueva al siguiente nodo.
    }

    return false;

}


// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{

// TODO
    // El programa venga y lea todos loo del diccionario todos los archivos.
    // Aqui si estan bien escritas las palabras.
    // Si estan bien o malas las palabras.
    // FILE *file fopen(dictionary.h 'r') Aqui es el fichero.

    FILE *file = fopen(dictionary, "r");

    if (file == NULL)
    {
        return false;
    }

    char word [LENGTH +  1];

    while (fscanf(file, "%s", word) != EOF)
    {


        node *new_point = malloc(sizeof(node));


        if (new_point == NULL)
        {
            return false;

        }

        strcpy(new_point -> word, word);

        table_val = table(word);

        new_point -> next = sign[table_val];

        sign [table_val] = new_point;

        word_add++;
    }

    fclose(file);
    return true;


    // TODO
    // Aqui va cargar el diccionario en memoria, aqui carga el diccionario en la memoria cuanto tarde en cargar todo el diccionario por completo
    // El pset es de tiempo

}


unsigned int table(const char *word)
{

    unsigned long table = 5381;

    int paper;

    while ((paper = toupper(*word ++)))
    {

        table = ((table << 5) + table) + paper;   //  Este es el desplazamiento hacia la izquierda es de 5 bits


    }
    return table % valor;


}


// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    // Determina el numero de letras que tiene el diccionario
    // Cuantas palabras tiene de todos los textos osea cada palabra del texto completo
    // Aqui se puede obetener nada mas un incremento  solamente con el return

    if (word_add > 0)
    {
        return word_add; // Retornar el numero de Palabras.
    }

    return 0;
}


// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    // Ver si todo  el proceso es valido.
    for (int count = 0; count < valor; count++)
    {

        node *direction = sign [count];

        while (direction)
        {
            node *temporary = direction;
            direction = direction -> next;
            free(temporary);
        }
        if (count == valor - 1 && direction == NULL)
        {
            return true;
        }

    }

    return false;
}
