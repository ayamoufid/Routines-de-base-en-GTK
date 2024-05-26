#include <gtk/gtk.h>
#include <stdio.h>
#include "en_commun.h"

//structure de fenetre
typedef struct fenetre
{
    int window_type;
    gboolean decorated; //TRUE or =FALSE, the window decorations will be removed, 
    gboolean resizable; //TRUE the user will be able to resize the window by dragging its edges or corners
    gboolean deletable; //the window will have a close button that the user can click to close the window
    taille taille;
    int border_taille;
    char name[20];
    GtkWindowPosition position;  //position de window
    float x; // en cas de position = GTK_WIN_POS_NONE (x,y)
    float y;
    char icon[20];  //link de image
    char bg_color[20];
    float opacity; // Set the opacity of the window
    int screen; //object to fullscreen mode
    //0 nothing 1 fullscrean 2 unfullscrean
    //3 maxmise 4 unmaximize 5 minimise
    gboolean present; //to bring a GTK window to the front and give it focus. 
    GtkWidget* window;   //the window
    // GtkWidget* parent;
    int scroll;
    char image_background[20];
    int id;
}fenetre;

int id = 0;

//structure de app
typedef struct app
{
    fenetre fenetre;
    struct app* svt;
}application;




fenetre initialiser_valeurs_fenetre()
{
    fenetre var;

    var.window_type = GTK_WINDOW_TOPLEVEL;
    var.decorated = TRUE;
    var.resizable = TRUE;
    var.deletable = TRUE;
    var.taille.width = 600;
    var.taille.height = 600;
    var.position = GTK_WIN_POS_NONE;
    var.opacity = 1;
    var.screen = 0;
    var.present = TRUE;
    strcpy(var.name, "Jeu de dames");
    var.border_taille = 0;
    strcpy(var.icon, "icon.png");
    strcpy(var.bg_color, "white");
    var.scroll = 3;
    var.id = id;
    id++;
    // strcpy(var.image_background, "image.png");
    return var;
}




/*les valeures possible pour window_type
GTK_WINDOW_TOPLEVEL: Creates a top-level window that is not a dialog,
pop-up, or child window. This is the most common type of window used
for main application windows.

GTK_WINDOW_POPUP: Creates a pop-up window that is usually used
for context menus or tooltips. Pop-up windows do not have a title
bar or border by default.
*/

/*les valeures possible pour position
GTK_WIN_POS_NONE - the position is not specified
GTK_WIN_POS_CENTER - the window is centered on the screen
GTK_WIN_POS_MOUSE - the window is positioned at the location of the mouse cursor
GTK_WIN_POS_CENTER_ALWAYS - the window is always centered on the screen
GTK_WIN_POS_CENTER_ON_PARENT - the window is centered on its parent window
*/

/*gtk_window_maximize() is used to maximize the window, which means making the window
occupy the entire screen and hiding the window decorations such as title bar and borders.
gtk_window_unmaximize()  <=> Esc
gtk_window_minimize() hiding the window and displaying its icon on the desktop or taskbar.
*/


//------------------------------------------window-------------------------------------------
/* les valeures possible pour scrollbar
GTK_POLICY_ALWAYS: The scrollbar is always visible, even if it is not needed.
GTK_POLICY_AUTOMATIC: The scrollbar is visible only when it is needed.
GTK_POLICY_NEVER: The scrollbar is never visible.
*/



void ajouter_fenetre(fenetre* var)
{
    //creation de la fenetre 
    //if(var->window_type==0)

    switch (var->window_type)
    {
    case 1: var->window = gtk_window_new(GTK_WINDOW_POPUP);
    default: var->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    }

    //l'utilisateur peut utiliser les fonctions pour les d�corations
    gtk_window_set_decorated(GTK_WINDOW(var->window), var->decorated);
    //l'utilisateur peut modifier la taille de la fen�tre
    gtk_window_set_resizable(GTK_WINDOW(var->window), var->resizable);
    //l'utilisateur peut supprimer la fen�tre
    gtk_window_set_deletable(GTK_WINDOW(var->window), var->deletable);
    //titre de la fenetre
    gtk_window_set_title(GTK_WINDOW(var->window), var->name);
    //position de fenetre
    gtk_window_set_position(GTK_WINDOW(var->window), var->position);

    //la taille de la fenetre
    gtk_window_set_default_size(GTK_WINDOW(var->window), var->taille.width, var->taille.height);
    // si la position nest pas definie
    if (var->position == GTK_WIN_POS_NONE)
        gtk_window_move(GTK_WINDOW(var->window), var->x, var->y);

    // Charge l'image de l'ic�ne � partir d'un fichier et d�finit l'ic�ne de la fen�tre
    gtk_window_set_icon(GTK_WINDOW(var->window), gdk_pixbuf_new_from_file(var->icon, NULL));

    // D�finir l'opacit� de la fen�tre
    gtk_widget_set_opacity(GTK_WINDOW(var->window), var->opacity);

    //le mode d'affichage de la fen�tre
    if (var->screen != 0)
    {
        if (var->screen == 1) gtk_window_fullscreen(GTK_WINDOW(var->window));
        else if (var->screen == 2) gtk_window_unfullscreen(GTK_WINDOW(var->window));
        else if (var->screen == 3) gtk_window_maximize(GTK_WINDOW(var->window));
        else if (var->screen == 4)  gtk_window_unmaximize(GTK_WINDOW(var->window));
        else if (var->screen == 5) gtk_window_minimize(GTK_WINDOW(var->window));
    }

    if (var->present == TRUE)  gtk_window_present(GTK_WINDOW(var->window));
    //ajouter le couleur de fenetre a l'aide de classe dans css

    GtkStyleContext* context = gtk_widget_get_style_context(var->window);
    gtk_style_context_add_class(context, "mon-style_w");


    GtkCssProvider* provider = gtk_css_provider_new();
    char* css_data = g_strdup_printf(".mon-style_w { background: %s; }", var->bg_color);



    gtk_css_provider_load_from_data(provider, css_data, -1, NULL);
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);


    if (var->image_background)
    {
        //image background
        GtkCssProvider* provider2 = gtk_css_provider_new();
        char* css_data2 = g_strdup_printf(".mon-style_w { background-image: url('%s'); }", var->image_background);
        gtk_css_provider_load_from_data(provider2, css_data2, -1, NULL);
        gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(provider2), GTK_STYLE_PROVIDER_PRIORITY_USER);
    }

    gtk_container_set_border_width(GTK_CONTAINER(var->window), var->border_taille);

}



void afficher_fenetre(fenetre* var)
{
    gtk_widget_show_all(var->window);

}


GtkWidget* create_header(fenetre* var, int bol)
{
    GtkWidget* header_bar = gtk_header_bar_new();
    if (bol)
        gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(header_bar), TRUE);

    gtk_window_set_titlebar(GTK_WINDOW(var->window), header_bar);

    return (GtkWidget*)header_bar;

}

void add_to_header_bar(GtkWidget* header_bar, GtkWidget* objet, int x, int y)
{
    GtkWidget* fix = fix = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(header_bar), fix);
    gtk_fixed_put(GTK_FIXED(fix), objet, x, y);
}




GtkWindowPosition get_window_position_from_string(char* str) {
    if (strcmp(str, "NONE") == 0) {
        return GTK_WIN_POS_NONE;
    }
    else if (strcmp(str, "CENTER") == 0) {
        return GTK_WIN_POS_CENTER;
    }
    else if (strcmp(str, "MOUSE") == 0) {
        return GTK_WIN_POS_MOUSE;
    }
    else if (strcmp(str, "CENTER_ALWAYS") == 0) {
        return GTK_WIN_POS_CENTER_ALWAYS;
    }
    else {
        return GTK_WIN_POS_NONE;
    }
}





void set_propriety_fenetre(fenetre* var, cellule_propriete* liste)
{
    while (liste != NULL)
    {
        if (strcmp(liste->attribut, "x") == 0)
        {
            var->x = atoi(liste->valeur);
        }
        else if (strcmp(liste->attribut, "y") == 0)
        {
            var->y = atoi(liste->valeur);
        }
        else if (strcmp(liste->attribut, "width") == 0)
        {
            var->taille.width = atoi(liste->valeur);
        }
        else if (strcmp(liste->attribut, "height") == 0)
        {
            var->taille.height = atoi(liste->valeur);
        }
        else if (strcmp(liste->attribut, "icon") == 0)
        {
            strcpy(var->icon, liste->valeur);
        }
        else if (strcmp(liste->attribut, "background") == 0)
        {
            strcpy(var->bg_color, liste->valeur);
        }
        else if (strcmp(liste->attribut, "border") == 0)
        {
            var->border_taille = atoi(liste->valeur);
        }
        else if (strcmp(liste->attribut, "name") == 0)
        {
            strcpy(var->name, liste->valeur);
        }
        else if (strcmp(liste->attribut, "screen") == 0)
        {
            var->screen = atoi(liste->valeur);
        }
        else if (strcmp(liste->attribut, "opacity") == 0)
        {
            var->opacity = atof(liste->valeur);
        }
        else if (strcmp(liste->attribut, "decorated") == 0)
        {
            if (strcmp(liste->valeur, "true") == 0)
                var->decorated = TRUE;
            else var->decorated = FALSE;
        }
        else if (strcmp(liste->attribut, "resizable") == 0)
        {
            if (strcmp(liste->valeur, "true") == 0)
                var->resizable = TRUE;
            else var->resizable = FALSE;
        }
        else if (strcmp(liste->attribut, "deletable") == 0)
        {
            if (strcmp(liste->valeur, "true") == 0)
                var->deletable = TRUE;
            else var->deletable = FALSE;
        }
        else if (strcmp(liste->attribut, "present") == 0)
        {
            if (strcmp(liste->valeur, "true") == 0)
                var->present = TRUE;
            else var->present = FALSE;
        }
        else if (strcmp(liste->attribut, "position") == 0)
        {
            var->position = get_window_position_from_string(liste->valeur);
        }
        else if (strcmp(liste->attribut, "background_image") == 0)
        {
            strcpy(var->image_background, liste->valeur);
        }
        else if (strcmp(liste->attribut, "type") == 0)
        {

            var->window_type = liste->valeur;
        }

        liste = liste->suivant;
    }
}



void add_onglet(GtkWidget* notebook, GtkWidget* box, GtkWidget* label)
{
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), box, label);
}

void on_button_close_clicked(GtkWidget* widget, gpointer data)
{
    GtkWindow* window = GTK_WINDOW(data);
    gtk_widget_destroy(GTK_WIDGET(window));
}

void close(GtkButton* button, gpointer user_data)
{
    GtkWidget* window = GTK_WIDGET(user_data);
    gtk_widget_destroy(window);
}
void maxwn(GtkButton* button, gpointer user_data)
{
    GtkWidget* window = GTK_WIDGET(user_data);
    gtk_window_maximize(GTK_WINDOW(window));
}
void minwn(GtkButton* button, gpointer user_data)
{
    GtkWidget* window = GTK_WIDGET(user_data);
    gtk_window_unmaximize(GTK_WINDOW(window));
}


void dialog(GtkWidget* window)
{

    GtkWidget* dialog;
    GtkWidget* content_area;
    GtkWidget* button1;
    GtkWidget* button2;
    GtkWidget* button3;
    GtkWidget* image;
    GtkWidget* box; // Nouveau widget GtkBox

    dialog = gtk_message_dialog_new(GTK_WINDOW(window),
        GTK_DIALOG_MODAL,
        GTK_MESSAGE_QUESTION,
        GTK_BUTTONS_NONE,
        "");

    gtk_window_move(GTK_WINDOW(dialog), 630, 620);

    gtk_window_set_transient_for(GTK_WINDOW(dialog), GTK_WINDOW(window));

    gtk_dialog_add_button(GTK_DIALOG(dialog), "Oui", GTK_RESPONSE_YES);
    gtk_dialog_add_button(GTK_DIALOG(dialog), "Non", GTK_RESPONSE_NO);
    gtk_dialog_add_button(GTK_DIALOG(dialog), "Annuler", GTK_BUTTONS_OK); //GTK_RESPONSE_CANCEL

    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5); // Espacement de 5 pixels entre les enfants
    gtk_container_add(GTK_CONTAINER(gtk_dialog_get_content_area(GTK_DIALOG(dialog))), box);

    GtkWidget* fix = fix = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(box), fix);

    // Cr�ation de la bo�te qui contiendra les boutons et l'image

    // Cr�ation des boutons
    GtkWidget* label = gtk_label_new("Voulez vous afficher une image");

    gtk_fixed_put(GTK_FIXED(fix), label, 100, 0);

    // Chargement de l'image
  //  image = gtk_image_new_from_file("image.png");
    GdkPixbuf* pixbuf;
    pixbuf = gdk_pixbuf_new_from_file("war.png", NULL);
    pixbuf = gdk_pixbuf_scale_simple(pixbuf, 60, 60, GDK_INTERP_BILINEAR);
    image = gtk_image_new_from_pixbuf(pixbuf);
    gtk_fixed_put(GTK_FIXED(fix), image, 0, 0);

    // Affichage des boutons et de l'image
    gtk_widget_show_all(dialog);
}