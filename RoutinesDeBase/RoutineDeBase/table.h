#ifndef NEW_TABLE_H
#define NEW_TABLE_H
#include <stdio.h>
#include <gtk/gtk.h>
#include <string.h>
#include "en_commun.h"

typedef struct {
    GtkWidget* container;
    GtkWidget* table;//la table
    int nbr_ligne; //nombre des lignes
    int nbr_colonne; //nombre des colonnes
    gboolean homogene; // true:pour un table homogène, sinon false ;
    commune commune;
}Table_object;



Table_object* init_table_default()
{
    Table_object* table = g_new(Table_object, 1);
    table->nbr_ligne = 3;
    table->nbr_colonne = 3;
    table->homogene = TRUE;
    table->commune.posx = 0;
    table->commune.posy = 0;
    if (!table)
    {
        printf("\nErreur d'allocation memoire");
        exit(1);
    }
    return table;
}
Table_object* create_table(Table_object* table)
{
    table->table = gtk_table_new(table->nbr_ligne, table->nbr_colonne, table->homogene);
    //table->table = gtk_grid_new(table->nbr_ligne, table->nbr_colonne, table->homogene);
    return table;
}
void add_widget_to_table(Table_object* table, GtkWidget* widget, gint left, gint right, gint top, gint bottom)
{
    gtk_table_attach_defaults(GTK_TABLE(table->table), widget, left, right, top, bottom);
    //gtk_grid_attach(GTK_GRID(table->table), widget, left, right, top, bottom);
}
Table_object* set_propriety_table(Table_object* table, cellule_propriete* liste)
{
    while (liste != NULL)
    {
        if (strcmp(liste->attribut, "x") == 0)
            table->commune.posx = atoi(liste->valeur);
        if (strcmp(liste->attribut, "y") == 0)
            table->commune.posy = atoi(liste->valeur);
        if (strcmp(liste->attribut, "nbr_ligne") == 0)
            table->nbr_ligne = atoi(liste->valeur);
        if (strcmp(liste->attribut, "nbr_colonne") == 0)
            table->nbr_colonne = atoi(liste->valeur);
        liste = liste->suivant;
    }
    return table;
}

#endif //NEW_TABLE_H



