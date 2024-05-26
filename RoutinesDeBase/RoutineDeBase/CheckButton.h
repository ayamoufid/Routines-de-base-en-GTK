#pragma once
#include<stdio.h>
#include <gtk/gtk.h>
#include "en_commun.h"
//typedef struct {
//    GtkWidget* widget;
//    char* label;
//    GtkWidget* conteneur;
//    gboolean active;
//    gboolean sensitive;
//    gint x;
//    gint y;
//} CheckButtonItem;
ToogleButton* init_Button_checkBox()
{
    ToogleButton* check_button = g_new(ToogleButton, 1);
    check_button->widget = NULL;
    check_button->label = "CheckBox button";
    check_button->positionnement.container = NULL;
    check_button->active = FALSE;
    check_button->sensitive = TRUE;
    check_button->positionnement.posx = 0;
    check_button->positionnement.posy = 0;
    return (ToogleButton*)check_button;
}

ToogleButton* create_Button_checkBox(ToogleButton* Data)
{
    Data->widget = gtk_check_button_new();
    GtkWidget* label_widget = gtk_label_new(Data->label);
    gtk_label_set_mnemonic_widget(GTK_LABEL(label_widget), Data->widget);
    gtk_label_set_use_underline(GTK_LABEL(label_widget), TRUE);
    gtk_container_add(GTK_CONTAINER(Data->widget), label_widget);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(Data->widget), Data->active);
    gtk_widget_set_sensitive(GTK_TOGGLE_BUTTON(Data->widget), Data->sensitive);

    return (ToogleButton*)Data;
}

/*
* Prototype : ToogleButton* set_propriety(ToogleButton* Checkbutton, cellule_propriete* liste);
* Description : La fonction set_propriety prend en entr�e un objet ToogleButton et une liste cha�n�e de propri�t�s de cellule.
                Elle parcourt la liste de propri�t�s de cellule et modifie les attributs de l'objet ToogleButton en fonction des propri�t�s sp�cifi�es dans la liste.
                Les attributs modifiables sont "x", "y", "label", "active" et "sensitive". La fonction renvoie un pointeur vers l'objet ToogleButton modifi�.

  Entr�es :     Checkbutton : un pointeur vers un objet ToogleButton � modifier. L'objet doit �tre pr�alablement initialis� et allou� en m�moire.
                liste : un pointeur vers une liste cha�n�e de propri�t�s de cellule. Cette liste doit contenir les propri�t�s � affecter � l'objet ToogleButton.

  Sortie :      La fonction renvoie un pointeur vers l'objet ToogleButton modifi� selon les propri�t�s sp�cifi�es dans la liste liste.

*/

ToogleButton* set_propriety(ToogleButton* Checkbutton, cellule_propriete* liste)
{
    // Boucle while pour parcourir tous les �l�ments de la liste de propri�t�s de cellule
    while (liste != NULL)
    {
        // Si l'attribut est "x", on affecte la valeur enti�re correspondante � l'attribut "x" de l'objet ToogleButton
        if (strcmp(liste->attribut, "x") == 0)
        {
            Checkbutton->positionnement.posx = atoi(liste->valeur);
        }
        // Si l'attribut est "y", on affecte la valeur enti�re correspondante � l'attribut "y" de l'objet ToogleButton
        if (strcmp(liste->attribut, "y") == 0)
        {
            Checkbutton->positionnement.posy = atoi(liste->valeur);
        }
        // Si l'attribut est "label", on affecte la cha�ne de caract�res correspondante � l'attribut "label" de l'objet ToogleButton
        if (strcmp(liste->attribut, "label") == 0)
        {
            Checkbutton->label = liste->valeur;
        }
        // Si l'attribut est "active", on affecte la valeur bool�enne correspondante � l'attribut "active" de l'objet ToogleButton
        if (strcmp(liste->attribut, "active") == 0)
        {
            if (strcmp(liste->valeur, "TRUE") == 0)
            {
                Checkbutton->active = TRUE;
            }
            if (strcmp(liste->valeur, "FALSE") == 0)
            {
                Checkbutton->active = FALSE;
            }
        }
        // Si l'attribut est "sensitive", on affecte la valeur bool�enne correspondante � l'attribut "sensitive" de l'objet ToogleButton
        if (strcmp(liste->attribut, "sensitive") == 0)
        {
            if (strcmp(liste->valeur, "TRUE") == 0)
            {
                Checkbutton->sensitive = TRUE;
            }
            if (strcmp(liste->valeur, "FALSE") == 0)
            {
                Checkbutton->sensitive = FALSE;
            }
        }
        liste = liste->suivant;
    }
    return Checkbutton;
}



void show_checked_buttons(GList* group) {

    for (GSList* button = group; button != NULL; button = g_slist_next(button)) {

        ToogleButton* button_R = (ToogleButton*)button->data;
        // V�rifier si le bouton est s�lectionn�
        printf("Check_button->Vous avez coche : \n");
        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(button_R->widget))) {

            printf("%s\t", button_R->label);

        }
    }
}

void on_button_clicked3(GtkButton* button, gpointer user_data)
{
    // Appeler la fonction show_checked_buttons()
    GList* button_list = (GList*)user_data;
    show_checked_buttons(button_list);
}