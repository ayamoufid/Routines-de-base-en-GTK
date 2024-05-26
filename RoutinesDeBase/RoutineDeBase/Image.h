#include <gtk/gtk.h>
#include <stdio.h>
#include "en_commun.h"


typedef struct image
{
    taille taille;
    char url[20];
    GtkWidget* image;
    commune commune;
}image;



image* initialiser_valeurs_image()
{
    image* im = (image*)malloc(sizeof(image));
    if (!im) g_print("erreur");
    im->commune.container = NULL;
    im->image = NULL;
    im->taille.width = 100;
    im->taille.height = 100;
    strcpy(im->url, "im.jpg");
    im->commune.posx = 20;
    im->commune.posy = 100;
    return (image*)im;
}





void add_image(image* im, GtkWidget* conteneur)
{
    GdkPixbuf* pixbuf;
    pixbuf = gdk_pixbuf_new_from_file(im->url, NULL);
    pixbuf = gdk_pixbuf_scale_simple(pixbuf, im->taille.width, im->taille.height, GDK_INTERP_BILINEAR);
    im->image = gtk_image_new_from_pixbuf(pixbuf);

    GtkWidget* fix = fix = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(conteneur), fix);
    gtk_fixed_put(GTK_FIXED(fix), im->image, im->commune.posx, im->commune.posy);
}









image* set_propriety_image(image* var, cellule_propriete* liste)
{
    while (liste != NULL)
    {
        if (strcmp(liste->attribut, "x") == 0)
        {
            var->commune.posx = atoi(liste->valeur);
        }
        else if (strcmp(liste->attribut, "y") == 0)
        {
            var->commune.posy = atoi(liste->valeur);
        }
        else if (strcmp(liste->attribut, "width") == 0)
        {
            var->taille.width = atoi(liste->valeur);
        }
        else if (strcmp(liste->attribut, "height") == 0)
        {
            var->taille.height = atoi(liste->valeur);
        }
        else if (strcmp(liste->attribut, "url") == 0)
        {
            strcpy(var->url, liste->valeur);
        }
        liste = liste->suivant;
    }
    return var;
}