//#include <gtk/gtk.h>
//
//// Définir la fonction de rappel pour le clic sur le bouton "Commencer"
//void on_start_button_clicked(GtkWidget* button, gpointer data)
//{
//    // Masquer la fenêtre d'accueil
//    GtkWidget* window = GTK_WIDGET(data);
//    gtk_widget_hide(window);
//
//    // Afficher la fenêtre du jeu de dames
//    // Code pour afficher le plateau du jeu ici
//}
//
//int main(int argc, char* argv[])
//{
//    // Initialiser GTK
//    gtk_init(&argc, &argv);
//
//    // Créer la fenêtre principale
//    GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
//    gtk_window_set_title(GTK_WINDOW(window), "Jeu de Dames");
//    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
//    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
//    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
//    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
//
//    // Créer une boîte verticale pour organiser les widgets
//    GtkWidget* vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
//    gtk_container_add(GTK_CONTAINER(window), vbox);
//
//    // Créer un label de bienvenue
//    GtkWidget* welcome_label = gtk_label_new("Bienvenue dans le jeu de dames !");
//    gtk_label_set_justify(GTK_LABEL(welcome_label), GTK_JUSTIFY_CENTER);
//    gtk_box_pack_start(GTK_BOX(vbox), welcome_label, TRUE, TRUE, 0);
//
//    // Créer un bouton "Commencer"
//    GtkWidget* start_button = gtk_button_new_with_label("Commencer");
//    gtk_widget_set_hexpand(start_button, TRUE);
//    gtk_widget_set_vexpand(start_button, TRUE);
//    gtk_box_pack_start(GTK_BOX(vbox), start_button, TRUE, TRUE, 0);
//
//    // Définir la fonction de rappel pour le clic sur le bouton "Commencer"
//    g_signal_connect(start_button, "clicked", G_CALLBACK(on_start_button_clicked), window);
//
//    // Afficher tous les widgets
//    gtk_widget_show_all(window);
//
//    // Lancer la boucle principale GTK
//    gtk_main();
//
//    return 0;
//}
