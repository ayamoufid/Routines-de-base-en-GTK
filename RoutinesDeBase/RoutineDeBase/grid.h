#ifndef NEW_GRID_H
#define NEW_GRID_H
#include <stdio.h>
#include <gtk/gtk.h>
#include <string.h>
#include "en_commun.h"

typedef struct
{
    GtkWidget* container;
    GtkWidget* grid; // la grille
    int nbr_ligne; // nombre des lignes
    int nbr_colonne; // nombre des colonnes
    gboolean homogene; // true : pour une grille homogène, sinon false ;
    commune commune;
} Grid_object;

Grid_object* init_grid_default()
{
    Grid_object* grid = g_new(Grid_object, 1);
    grid->nbr_ligne = 3;
    grid->nbr_colonne = 3;
    grid->homogene = TRUE;
    grid->commune.posx = 0;
    grid->commune.posy = 0;
    if (!grid)
    {
        printf("\nErreur d'allocation memoire");
        exit(1);
    }
    return grid;
}

Grid_object* create_grid(Grid_object* grid)
{
    grid->grid = gtk_grid_new();
    gtk_grid_set_row_homogeneous(GTK_GRID(grid->grid), grid->homogene);
    gtk_grid_set_column_homogeneous(GTK_GRID(grid->grid), grid->homogene);
    return grid;
}

void add_widget_to_grid(Grid_object* grid, GtkWidget* widget, gint left, gint right, gint top, gint bottom)
{
    gtk_grid_attach(GTK_GRID(grid->grid), widget, left, top, right - left + 1, bottom - top + 1);
}

Grid_object* set_propriety_grid(Grid_object* grid, cellule_propriete* liste)
{
    while (liste != NULL)
    {
        if (strcmp(liste->attribut, "x") == 0)
            grid->commune.posx = atoi(liste->valeur);
        if (strcmp(liste->attribut, "y") == 0)
            grid->commune.posy = atoi(liste->valeur);
        if (strcmp(liste->attribut, "nbr_ligne") == 0)
            grid->nbr_ligne = atoi(liste->valeur);
        if (strcmp(liste->attribut, "nbr_colonne") == 0)
            grid->nbr_colonne = atoi(liste->valeur);
        liste = liste->suivant;
    }
    return grid;
}

#endif //NEW_GRID_H

void ajouter_conteneur(GtkWidget* c1, GtkWidget*c2)
{
    gtk_container_add(GTK_CONTAINER(c1), c2);
}




