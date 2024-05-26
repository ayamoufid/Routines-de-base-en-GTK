#pragma once
#include "en_commun.h"




//-------------------------------------------------------------------------------
void on_dialog_response(GtkDialog* dialog, gint response_id, gpointer user_data) {
    GtkWidget* window_anc = GTK_WIDGET(user_data);

    if (response_id == GTK_RESPONSE_YES) {
        GtkWidget* window, * image, * button, * box;

        window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_title(GTK_WINDOW(window), "Ma fenetre");
        gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);


        // Créer la boîte qui contiendra l'image et le bouton
        box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
        gtk_container_add(GTK_CONTAINER(window), box);

        // Créer l'image
        image = gtk_image_new_from_file("image.png");
        gtk_box_pack_start(GTK_BOX(box), image, TRUE, TRUE, 0);

        gtk_widget_show_all(window);


        //GdkPixbuf* pixbuf=NULL,*im=NULL;
        //pixbuf = gdk_pixbuf_new_from_file("image.png", NULL);
        //pixbuf = gdk_pixbuf_scale_simple(pixbuf, 200, 200, GDK_INTERP_BILINEAR);
        //
        //im = gtk_image_new_from_pixbuf(pixbuf);

        //GtkWidget* fix = fix = gtk_fixed_new();
        //gtk_container_add(GTK_CONTAINER(window_anc), fix);
        //gtk_fixed_put(GTK_FIXED(fix), im, 0,300);
    }
    else if (response_id == GTK_RESPONSE_NO) {
        // L'utilisateur a cliqué sur le bouton "Non"
        // Mettez ici le code que vous voulez exécuter lorsque l'utilisateur clique sur "Non"
    }
    else if (response_id == GTK_RESPONSE_CANCEL) {
        // L'utilisateur a cliqué sur le bouton "Annuler"
        // Mettez ici le code que vous voulez exécuter lorsque l'utilisateur clique sur "Annuler"
    }

    // Fermer la boîte de dialogue
    gtk_widget_destroy(GTK_WIDGET(dialog));
}














#pragma once
void dialogue_ajouter(GtkWidget* window)
{

    GtkWidget* dialog;
    GtkWidget* content_area;
    GtkWidget* image;
    GtkWidget* hbox; // Nouveau widget GtkBox

    dialog = gtk_message_dialog_new(GTK_WINDOW(window),
        0,
        GTK_MESSAGE_QUESTION,
        GTK_BUTTONS_NONE,
        "");


    gtk_window_move(GTK_WINDOW(dialog), 50, 50);

    gtk_window_set_transient_for(GTK_WINDOW(dialog), GTK_WINDOW(window));

    gtk_dialog_add_button(GTK_DIALOG(dialog), "Oui", GTK_RESPONSE_YES);
    gtk_dialog_add_button(GTK_DIALOG(dialog), "Non", GTK_RESPONSE_NO);
    gtk_dialog_add_button(GTK_DIALOG(dialog), "Annuler", GTK_RESPONSE_CANCEL);


    g_signal_connect(dialog, "response", G_CALLBACK(on_dialog_response), window);

    GtkWidget* label = gtk_label_new("Voulez vous afficher une image");

    GdkPixbuf* pixbuf;
    pixbuf = gdk_pixbuf_new_from_file("war.png", NULL);
    pixbuf = gdk_pixbuf_scale_simple(pixbuf, 60, 60, GDK_INTERP_BILINEAR);
    image = gtk_image_new_from_pixbuf(pixbuf);

    hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE, TRUE, 0);
    // Ajout de la boîte horizontale à la boîte de dialogue
    content_area = gtk_message_dialog_get_message_area(GTK_MESSAGE_DIALOG(dialog));
    gtk_box_pack_start(GTK_BOX(content_area), hbox, FALSE, FALSE, 0);

    //gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER_ON_PARENT);
   /* GtkWidget fix = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window), fix);
    gtk_fixed_put(GTK_FIXED(fix), dialog, 500, 500); */

        gtk_widget_show_all(dialog);
}


void on_button_diag(GtkWidget* widget, gpointer data)
{
    GtkWindow* window = GTK_WINDOW(data);
    dialogue_ajouter(window);
}

