//#include <gtk/gtk.h>
//#include <glib.h>
//
//typedef struct 
//{
//    int row;
//    int column;
//} ButtonCoordinates;
//
//void on_button_clicked(GtkButton* button, gpointer user_data) 
//{
//    ButtonCoordinates* coordinates = g_object_get_data(G_OBJECT(button), "coordinates");
//    int row = coordinates->row;
//    int column = coordinates->column;
//    g_print("Bouton clique a la position : (%d, %d)\n", row, column);
//    g_free(coordinates);
//}
//
//GtkWidget* create_button_with_coordinates(int row, int column) 
//{
//    GtkWidget* button = gtk_button_new();
//    ButtonCoordinates* coordinates = g_new(ButtonCoordinates, 1);
//    coordinates->row = row;
//    coordinates->column = column;
//    g_object_set_data(G_OBJECT(button), "coordinates", coordinates);
//    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(on_button_clicked), NULL);
//    return button;
//}
//
//void print_board() 
//{
//    GtkWidget* window;
//    GtkWidget* grid;
//
//    gtk_init(NULL, NULL);
//
//    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
//    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
//
//    grid = gtk_grid_new();
//    gtk_container_add(GTK_CONTAINER(window), grid);
//
//    int i, j;
//    int checkers[8][8] = {
//        {0, 1, 0, 1, 0, 1, 0, 1},
//        {1, 0, 1, 0, 1, 0, 1, 0},
//        {0, 1, 0, 1, 0, 1, 0, 1},
//        {0, 0, 0, 0, 0, 0, 0, 0},
//        {0, 0, 0, 0, 0, 0, 0, 0},
//        {2, 0, 2, 0, 2, 0, 2, 0},
//        {0, 2, 0, 2, 0, 2, 0, 2},
//        {2, 0, 2, 0, 2, 0, 2, 0}
//    };
//
//    for (i = 0; i < 8; i++) {
//        for (j = 0; j < 8; j++) {
//            GtkWidget* button = create_button_with_coordinates(i, j);
//            gtk_grid_attach(GTK_GRID(grid), button, j, i, 1, 1);
//
//            if ((i + j) % 2 == 1) {
//               // GtkWidget* label = gtk_label_new(NULL);
//                int piece = checkers[i][j];
//                switch (piece) {
//                case 0:
//                    //gtk_label_set_text(GTK_LABEL(label), "  "); // Case vide
//                {
//                    GtkWidget* label = gtk_label_new(" ");
//                    char* label_text = g_strdup(" ");
//                    gtk_button_set_label(GTK_BUTTON(button), label_text);
//                    g_free(label_text);
//                    break;
//                }
//                   
//                case 1:
//                {
//                    GtkWidget* label = gtk_label_new("O");
//                    char* label_text = g_strdup("O");
//                    gtk_button_set_label(GTK_BUTTON(button), label_text);
//                    g_free(label_text);
//                    break;
//                }
//                case 2:
//                {
//                    GtkWidget* label = gtk_label_new("X");
//                    char* label_text = g_strdup("X");
//                    gtk_button_set_label(GTK_BUTTON(button), label_text);
//                    g_free(label_text);
//                    break;
//                }
//                }
//            }
//        }
//    }
//
//    gtk_widget_show_all(window);
//
//    gtk_main();
//}
//
//
//int main(int argc, char* argv[]) {
//    print_board();
//    return 0;
//}
//

