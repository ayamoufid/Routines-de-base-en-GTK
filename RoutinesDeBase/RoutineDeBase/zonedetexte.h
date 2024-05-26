#include "en_commun.h"




typedef struct
{
    GtkWidget* entry; // entr�e.
    commune position;
    taille size;
    gboolean visible; //le texte est visible ou pas.
    char invisible_car; //le caract�re d'un texte invisible.
    gboolean editable;//on peut saisir par clavier.
    char text_to_set[30];//le texte � saisir.
    int max_car; //max des caracteres
    char placeholder_text[50];
    char icon_name[30];
    char* completion_strings[30];
    int num_completion_strings;
}zonetxt_object;




// D�finition de la fonction qui utilise gtk_entry_set_progress_fraction
void update_progress(GtkWidget* widget, gpointer data)
{
    zonetxt_object* zonetxt = (zonetxt_object*)data;
    GtkEntry* entry = GTK_ENTRY(zonetxt->entry);
    gdouble progress = gtk_entry_get_progress_fraction(entry);
    const gchar* text = gtk_entry_get_text(entry);
    gint length = strlen(text);
    gdouble new_progress = (gdouble)length / (gdouble)zonetxt->max_car;
    gtk_entry_set_progress_fraction(entry, new_progress);
}


zonetxt_object* zonetxt_init()
{
    zonetxt_object* zone = NULL;
    //Allocation memoire
    zone = (zonetxt_object*)malloc(sizeof(zonetxt_object));
    if (!zone)
    {
        g_print("l'allocation a echou�e\n");///Message d'erreur
        exit(-1);
    }

    zone->max_car = 10;
    zone->size.height = 10;
    zone->size.width = 30;
    zone->visible = TRUE;
    zone->invisible_car = '*';
    zone->editable = TRUE;
    strcpy(zone->text_to_set, "");
    zone->position.posx = 0;
    zone->position.posy = 0;
    strcpy(zone->icon_name, "");//edit-copy
    strcpy(zone->placeholder_text, "Saisissez votre texte");
    //zone->completion_strings = NULL;
    zone->num_completion_strings = 0;

    return zone; //Retourner l'objet initialiser
}





zonetxt_object* zonetxt_create(zonetxt_object* zone)
{
    zone->entry = gtk_entry_new();

    gtk_entry_set_input_purpose(GTK_ENTRY(zone->entry), GTK_INPUT_PURPOSE_FREE_FORM);
    gtk_entry_set_input_hints(GTK_ENTRY(zone->entry), GTK_INPUT_HINT_SPELLCHECK);

    // D�finition du nombre maximum de caract�res
    gtk_entry_set_max_length(GTK_ENTRY(zone->entry), zone->max_car);

    //La taille minimale de la zone de texte
    gtk_widget_set_size_request(zone->entry, zone->size.width, zone->size.height);

    // D�finition de la largeur de la zone de texte en nombre de caract�res
    int width_chars = (int)(zone->size.height / 8); // 8 pixels par caract�re (taille approximative)
    gtk_entry_set_width_chars(GTK_ENTRY(zone->entry), width_chars);

    // Le texte est visible ou pas.
    gtk_entry_set_visibility(GTK_ENTRY(zone->entry), zone->visible);
    if (!zone->visible)
    {
        gtk_entry_set_invisible_char(GTK_ENTRY(zone->entry), zone->invisible_car);
        g_signal_connect(zone->entry, "changed", G_CALLBACK(update_progress), zone);
    }
    //if (!zone->visible) gtk_entry_set_input_purpose(GTK_ENTRY(zone->entry), GTK_INPUT_PURPOSE_PASSWORD);//des grans points

    // D�finition si le texte est modifiable ou non
    gtk_editable_set_editable(GTK_EDITABLE(zone->entry), zone->editable);

    // D�finition du texte initial
    if (zone->text_to_set) gtk_entry_set_text(GTK_ENTRY(zone->entry), zone->text_to_set);

    // Ajout de la zone de texte au GtkFixed
    gtk_fixed_put(GTK_FIXED(zone->position.container), zone->entry, zone->position.posx, zone->position.posy);

    GtkEntryCompletion* completion;
    GtkListStore* store;
    GtkCellRenderer* renderer;

    gtk_entry_set_placeholder_text(GTK_ENTRY(zone->entry), zone->placeholder_text);

    // Ajout d'une ic�ne
    gtk_entry_set_icon_from_icon_name(GTK_ENTRY(zone->entry), GTK_ENTRY_ICON_PRIMARY, zone->icon_name);
    /*
    "folder-open" : une ic�ne de dossier ouvert
    "folder" : une ic�ne de dossier ferm�
    "document-new" : une ic�ne de document vide ou nouveau
    "document-open" : une ic�ne de document ouvert
    "document-save" : une ic�ne de document sauvegard�
    "edit-cut" : une ic�ne de ciseaux pour couper
    "edit-copy" : une ic�ne de deux feuilles pour copier
    "edit-paste" : une ic�ne de collage
    "search" : une ic�ne de loupe pour la recherche
    "information" : une ic�ne d'information ou d'aide
    "warning" : une ic�ne d'avertissement ou d'alerte
    "error" : une ic�ne d'erreur ou de danger
    "help" : une ic�ne d'aide ou de support
    "preferences" : une ic�ne de pr�f�rences ou de param�tres
    "mail-send" : repr�sente un champ de saisie d'adresse email
    "dialog-password" : repr�sente un champ de saisie de mot de passe
    "dialog-ok" : Pour une ic�ne de validation
    */

    if (zone->num_completion_strings >= 1)
    {
        // Activation de la compl�tion de texte
        completion = gtk_entry_completion_new();
        store = gtk_list_store_new(1, G_TYPE_STRING);
        int i;
        for (i = 0; i < zone->num_completion_strings; i++)
        {
            GtkTreeIter iter;
            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter, 0, zone->completion_strings[i], -1);
        }
        gtk_entry_completion_set_model(completion, GTK_TREE_MODEL(store));
        gtk_entry_completion_set_text_column(completion, 0);
        renderer = gtk_cell_renderer_text_new();
        //gtk_entry_completion_pack_start(completion, renderer);
        gtk_entry_completion_set_inline_completion(completion, TRUE);
        gtk_entry_completion_set_popup_completion(completion, TRUE);
        gtk_entry_set_completion(GTK_ENTRY(zone->entry), completion);
    }

    gtk_widget_show_all(zone->position.container);

    return zone;
}



zonetxt_object* set_proprietyzone(zonetxt_object* cb, cellule_propriete* liste)
{
    int i = 0;
    while (liste != NULL)
    {
        if (strcmp(liste->attribut, "x") == 0) cb->position.posx = atoi(liste->valeur);
        if (strcmp(liste->attribut, "y") == 0) cb->position.posy = atoi(liste->valeur);
        if (strcmp(liste->attribut, "width") == 0) cb->size.width = atoi(liste->valeur);
        if (strcmp(liste->attribut, "height") == 0) cb->size.height = atoi(liste->valeur);
        if (strcmp(liste->attribut, "visible") == 0)
        {
            if (strcmp(liste->valeur, "true") == 0) cb->visible = TRUE;
            else if (strcmp(liste->valeur, "false") == 0) cb->visible = FALSE;
        }
        if (strcmp(liste->attribut, "editable") == 0)
        {
            if (strcmp(liste->valeur, "true") == 0) cb->editable = TRUE;
            else if (strcmp(liste->valeur, "false") == 0) cb->editable = FALSE;
        }
        if (strcmp(liste->attribut, "invisibleCar") == 0) cb->invisible_car = liste->valeur[0];
        if (strcmp(liste->attribut, "maxCar") == 0) cb->max_car = atoi(liste->valeur);
        if (strcmp(liste->attribut, "text") == 0) strcpy(cb->text_to_set, liste->valeur); // copier l'�l�ment dans le tableau
        if (strcmp(liste->attribut, "placeholder") == 0) strcpy(cb->placeholder_text, liste->valeur);
        if (strcmp(liste->attribut, "numcompletion") == 0)  cb->num_completion_strings = atoi(liste->valeur);
        if (strcmp(liste->attribut, "completion") == 0)
        {
            cb->completion_strings[i] = (char*)malloc((strlen(liste->valeur) + 1) * sizeof(char)); // allouer dynamiquement de la m�moire
            strcpy(cb->completion_strings[i], liste->valeur); // copier l'�l�ment dans le tableau
            i++;
        }
        if (strcmp(liste->attribut, "icone") == 0)  strcpy(cb->icon_name, liste->valeur);

        liste = liste->suivant;
    }
    return cb;
}





void show_zonedetexte(GList* group)
{
    for (GSList* zone = group; zone != NULL; zone = g_slist_next(zone))
    {
        zonetxt_object* button_R = (zonetxt_object*)zone->data;
        // V�rifier si le bouton est s�lectionn�
        const gchar* text = gtk_entry_get_text(GTK_ENTRY(button_R->entry));
        const char* text_to_get = text;
        printf("Le texte est : %s\n", text_to_get);
    }
}
void on_button_signal(GtkButton* button, gpointer user_data)
{
    // Appeler la fonction show_checked_buttons()
    GList* button_list = (GList*)user_data;
    show_zonedetexte(button_list);
}





//g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(on_button_clicked_zone), zone);
