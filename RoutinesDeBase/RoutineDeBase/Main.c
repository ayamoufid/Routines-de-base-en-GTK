//#include <gtk/gtk.h>
//#include <stdio.h>
//#include "Fenetre.h"
//#include "Box.h"
//#include "RadioButton.h"
//#include "CheckButton.h"
//#include "SimpleButton.h"
//#include "zonedetexte.h"
//#include "Image.h"
//#include "combobox.h"
//#include "textView.h"
//#include "label.h"
//#include "frame.h"
//#include "prog_bar.h"
////#include "table.h"
//#include "scale.h"
//#include "Menu.h"
//#include "grid.h"
//#include "Fichier.h"
//
//
//
//// Fonction principale de création de l'interface graphique
//int main(int argc, char* argv[]) {
//    // Initialisation de GTK
//    gtk_init(&argc, &argv);
//
//
//
//
//    Menu_Gtk* MenuPrincipale = NULL;
//    Item_menu* itemMenu = NULL, * itemMenu2 = NULL;
//    ButtonItem* button = NULL, * button2 = NULL;
//
//    GtkWidget* scrolled_window = NULL;
//    cellule_window* windows = NULL;
//    fenetre window;
//    window = initialiser_valeurs_fenetre();
//    window.taille.width = 1000;
//    window.taille.height = 1000;
//    ajouter_fenetre(&window);
//    windows = ajouter_window(windows, window);
//    g_signal_connect(window.window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
//    Grid_object* gridd = NULL;
//    gridd = init_grid_default();
//    gridd->nbr_ligne = 20;
//    gridd->nbr_colonne = 20;
//    gridd->homogene = FALSE;
//    gridd->commune.posx = 0;
//    gridd->commune.posy = 0;
//    gridd = create_grid(gridd);
//    ajouter_conteneur(GTK_CONTAINER(window.window), gridd->grid);
//
//    MenuPrincipale = init_menu();
//    MenuPrincipale->direction = 1;
//    MenuPrincipale->position.posx = 0;
//    MenuPrincipale->position.posy = 0;
//    MenuPrincipale = cree_menu(MenuPrincipale);
//    gtk_grid_attach(gridd->grid, MenuPrincipale->Barre_menu, MenuPrincipale->position.posx, MenuPrincipale->position.posy, MenuPrincipale->position.posx+1, MenuPrincipale->position.posy + 1);
//    
//    itemMenu = init_item();
//    //strcpy(itemMenu->label, "File");
//    itemMenu->label = "File";
//    itemMenu = cree_item(itemMenu);
//    MenuPrincipale = add_item(MenuPrincipale, itemMenu);
//    itemMenu2 = init_item();
//    //strcpy(itemMenu2->label, "View");
//    itemMenu2->label = "View";
//    itemMenu2 = cree_item(itemMenu2);
//    MenuPrincipale = add_item(MenuPrincipale, itemMenu2);
//
//    
//    button = init_button();
//    button->positionnement.posx = 1;
//    button->positionnement.posy = 0;
//    button->dimension.width = 20;
//    button->dimension.height = 10;
//    //strcpy(button->label, "New game");
//    button->label= "New game";
//   // strcpy(button->signal, "new_game");
//    gtk_grid_attach(gridd->grid, button->widget, button->positionnement.posx, button->positionnement.posy, button->positionnement.posx+1, button->positionnement.posy + 1);
//    
//    button2 = init_button();
//    button2->positionnement.posx = 3;
//    button2->positionnement.posy = 0;
//    button2->dimension.width = 20;
//    button2->dimension.height = 10;
//    //strcpy(button2->label, "End game");
//    button2->label= "End game";
//    //strcpy(button2->signal, "quitter_jeu");
//    gtk_grid_attach(gridd->grid, button2->widget, button2->positionnement.posx, button2->positionnement.posy, button2->positionnement.posx+1, button2->positionnement.posy + 1);
//
//    label_object* lb = NULL;
//    Format frm = init_format();
//    //initialise le label
//    lb = initLabelObject();
//    lb->lab = frm;
//    lb->size.height = 50;
//    lb->size.width = 50;
//    //lb->text = "Bienvenue dans le jeu de dames !";
//    strcpy(lb->text, "Bienvenue dans le jeu de dames !");
//    lb = createLabelObject(lb);
//    gtk_grid_attach(gridd->grid, lb->label, lb->position.posx, lb ->position.posy, lb->position.posx + 1, lb->position.posy + 1);
//
//    
//    while (windows != NULL)
//    {
//        afficher_fenetre(&windows->var);
//        windows = windows->suivant;
//     }
//
//
//    gtk_main();
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//#include <gtk/gtk.h>
//
//void on_button_clicked(GtkWidget *widget, gpointer data) {
//    // Changer la couleur de fond du bouton
//    GtkStyleContext *context = gtk_widget_get_style_context(widget);
//    gtk_style_context_add_class(context, "selected");
//}
//
//int main(int argc, char *argv[]) {
//    gtk_init(&argc, &argv);
//
//    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
//    gtk_window_set_title(GTK_WINDOW(window), "Exemple de bouton");
//    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
//
//    GtkWidget *button = gtk_button_new_with_label("Cliquez-moi");
//    gtk_widget_set_halign(button, GTK_ALIGN_CENTER);
//    gtk_widget_set_valign(button, GTK_ALIGN_CENTER);
//    gtk_container_add(GTK_CONTAINER(window), button);
//
//    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), NULL);
//
//    // Style CSS pour mettre en évidence la couleur de fond du bouton sélectionné
//    const gchar *css =
//        ".selected {"
//        "   background-color: red;"
//        "   color: white;"
//        "}";
//    GtkCssProvider *provider = gtk_css_provider_new();
//    gtk_css_provider_load_from_data(provider, css, -1);
//    GtkStyleContext *context = gtk_widget_get_style_context(window);
//    gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
//
//    gtk_widget_show_all(window);
//    gtk_main();
//
//    return 0;
//}

#include <gtk/gtk.h>
#include <stdio.h>
#define BOARD_SIZE 8

typedef struct {
    int row;
    int column;
    gboolean isSelected;
    gboolean isHighlighted;
} BoardCell;

BoardCell board[BOARD_SIZE][BOARD_SIZE];

void updateBoard(GtkWidget* widget, gpointer data) {
    BoardCell* cell = (BoardCell*)data;

    // Mettre à jour l'état de la case (sélectionnée ou non)
    cell->isSelected = !cell->isSelected;

    // Mettre à jour l'état des cases voisines (mise en évidence ou non)
    if (cell->isSelected) {
        // Réinitialiser tous les états de mise en évidence
        for (int row = 0; row < BOARD_SIZE; row++) {
            for (int column = 0; column < BOARD_SIZE; column++) {
                board[row][column].isHighlighted = FALSE;
            }
        }

        // Mettre en évidence les cases voisines
        int selectedRow = cell->row;
        int selectedColumn = cell->column;

        // Case diagonale supérieure gauche
        if (selectedRow > 0 && selectedColumn > 0) {
            board[selectedRow - 1][selectedColumn - 1].isHighlighted = TRUE;
        }

        // Case diagonale supérieure droite
        if (selectedRow > 0 && selectedColumn < BOARD_SIZE - 1) {
            board[selectedRow - 1][selectedColumn + 1].isHighlighted = TRUE;
        }
    }

    // Redessiner les cases
    gtk_widget_queue_draw(widget);
}

gboolean drawBoardCell(GtkWidget* widget, cairo_t* cr, gpointer data) {
    BoardCell* cell = (BoardCell*)data;

    // Vérifier si la case est sélectionnée
    if (cell->isSelected) {
        // Modifier le style CSS pour la mise en évidence de la case sélectionnée
        GtkStyleContext* context = gtk_widget_get_style_context(widget);
        gtk_style_context_add_class(context, "selected");
    }
    else if (cell->isHighlighted) {
        // Modifier le style CSS pour la mise en évidence des cases voisines
        GtkStyleContext* context = gtk_widget_get_style_context(widget);
        gtk_style_context_add_class(context, "highlighted");
    }

    // Autres opérations de dessin (par exemple, afficher le pion)

    return FALSE;
}

int main(int argc, char* argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Jeu de Dames");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget* grid = gtk_grid_new();
    gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
    gtk_container_add(GTK_CONTAINER(window), grid);

    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int column = 0; column < BOARD_SIZE; column++) {
            GtkWidget* button = gtk_button_new();
            gtk_widget_set_size_request(button, 50, 50);

            g_signal_connect(button, "clicked", G_CALLBACK(updateBoard), &board[row][column]);
            g_signal_connect(button, "draw", G_CALLBACK(drawBoardCell), &board[row][column]);

            gtk_grid_attach(GTK_GRID(grid), button, column, row, 1, 1);

            board[row][column].row = row;
            board[row][column].column = column;
            board[row][column].isSelected = FALSE;
            board[row][column].isHighlighted = FALSE;
        }
    }

    // Style CSS pour la mise en évidence des cases
    const gchar* css =
        ".selected {"
        "   background-color: blue;"
        "   color: white;"
        "}"
        ".highlighted {"
        "   background-color: green;"
        "   color: white;"
        "}";
    GtkCssProvider* provider = gtk_css_provider_new();
   // gtk_css_provider_load_from_data(provider, css, -1);
    GError* error=NULL;
    gtk_css_provider_load_from_data(provider, css, strlen(css),&error);
    if (error != NULL) {
        // Gérer l'erreur
        g_print("Erreur lors du chargement du style CSS : %s\n", error->message);
        g_error_free(error);
        return 1;
    }
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
