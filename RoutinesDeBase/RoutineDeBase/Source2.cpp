//
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include "Fonction_computer.h"
//
//// Définir la fonction de rappel pour le clic sur le bouton "Commencer"
//void on_start_button_clicked(GtkWidget* button, gpointer data)
//{
//    // Masquer la fenêtre d'accueil
//    GtkWidget* window2 = GTK_WIDGET(data);
//    gtk_widget_hide(window2);
//
//
//    cellule_window* windows = NULL;
//    //fenetre window;
//    window = initialiser_valeurs_fenetre();
//    window.taille.width = 1000;
//    window.taille.height = 1000;
//    ajouter_fenetre(&window);
//    windows = ajouter_window(windows, window);
//    g_signal_connect(window.window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
//    //g_signal_connect(window.window, "key-press-event", G_CALLBACK(joueur_j), NULL);
//    g_signal_connect(window.window, "key-press-event", G_CALLBACK(joueur_ordi), NULL);
//    //g_signal_connect(window.window, "key-press-event", G_CALLBACK(ordin), NULL);
//    //g_signal_connect(window.window, "key-press-event", G_CALLBACK(on_key_press), NULL);
//    gridd = init_grid_default();
//    gridd = create_grid(gridd);
//    ajouter_conteneur(GTK_CONTAINER(window.window), gridd->grid);
//    //Board_Jeu New_game;
//    init_Jeu(&New_game);
//    print_board(&New_game);
//    vider_grid(gridd->grid);
//    init_Jeu2(gridd->grid, New_game);
//
//
//    //afficher_fenetre(&windows->var);
//    //init_Joueur(&New_game);
//    Noeud* bestMove = NULL;
//    while (windows != NULL)
//    {
//        afficher_fenetre(&windows->var);
//        windows = windows->suivant;
//    }
//    // Code pour afficher le plateau du jeu ici
//}
//
//int main(int argc, char* argv[])
//{
//    // Initialiser GTK
//    gtk_init(&argc, &argv);
//
//    // Créer la fenêtre principale
//    /*GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
//    gtk_window_set_title(GTK_WINDOW(window), "Jeu de Dames");
//    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
//    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
//    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
//    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);*/
//    cellule_window* windows = NULL;
//    fenetre window1;
//    ButtonItem* button = NULL, * button2 = NULL;
//    window1 = initialiser_valeurs_fenetre();
//    window1.taille.width = 1000;
//    window1.taille.height = 1000;
//    ajouter_fenetre(&window1);
//    windows = ajouter_window(windows, window1);
//    g_signal_connect(window1.window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
//
//    // Créer une boîte verticale pour organiser les widgets
//    /*GtkWidget* vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
//    gtk_container_add(GTK_CONTAINER(window1.window), vbox);*/
//
//    gridd = init_grid_default();
//    gridd->nbr_ligne = 2;
//    gridd->nbr_colonne = 2;
//    gridd->homogene = FALSE;
//    gridd->commune.posx = 0;
//    gridd->commune.posy = 0;
//    gridd = create_grid(gridd);
//    ajouter_conteneur(GTK_CONTAINER(window1.window), gridd->grid);
//
//    // Créer un label de bienvenue
//    /*GtkWidget* welcome_label = gtk_label_new("Bienvenue dans le jeu de dames !");
//    gtk_label_set_justify(GTK_LABEL(welcome_label), GTK_JUSTIFY_CENTER);
//    gtk_box_pack_start(GTK_BOX(vbox), welcome_label, TRUE, TRUE, 0);*/
//    label_object* lb = NULL;
//    Format frm = init_format();
//    //initialise le label
//    lb = initLabelObject();
//    lb->lab = frm;
//    lb->position.posx = 0;
//    lb->position.posy = 0;
//    lb->size.height = 50;
//    lb->size.width = 50;
//    //lb->text = "Bienvenue dans le jeu de dames !";
//    strcpy(lb->text, "Bienvenue dans le jeu de dames !");
//    lb = createLabelObject(lb);
//    gtk_grid_attach(gridd->grid, lb->label, lb->position.posx, lb->position.posy, lb->position.posx + 1, lb->position.posy + 1);
//
//
//
//    // Créer un bouton "Commencer"
//    /*GtkWidget* start_button = gtk_button_new_with_label("Commencer");
//    gtk_widget_set_hexpand(start_button, TRUE);
//    gtk_widget_set_vexpand(start_button, TRUE);
//    gtk_box_pack_start(GTK_BOX(vbox), start_button, TRUE, TRUE, 0);*/
//
//
//    button = init_button();
//    button->positionnement.posx = 1;
//    button->positionnement.posy = 0;
//    button->dimension.width = 20;
//    button->dimension.height = 10;
//    button->label = "New game";
//   
//    gtk_grid_attach(gridd->grid, button->widget, button->positionnement.posx, button->positionnement.posy, button->positionnement.posx + 1, button->positionnement.posy + 1);
//
//    button2 = init_button();
//    button2->positionnement.posx = 1;
//    button2->positionnement.posy = 1;
//    button2->dimension.width = 20;
//    button2->dimension.height = 10;
//    //strcpy(button2->label, "End game");
//    button2->label = "End game";
//    //strcpy(button2->signal, "quitter_jeu");
//    gtk_grid_attach(gridd->grid, button2->widget, button2->positionnement.posx, button2->positionnement.posy, button2->positionnement.posx + 1, button2->positionnement.posy + 1);
//
//    // Définir la fonction de rappel pour le clic sur le bouton "Commencer"
//    g_signal_connect(button->widget, "clicked", G_CALLBACK(on_start_button_clicked), window1.window);
//    g_signal_connect(button2->widget, "destroy", G_CALLBACK(gtk_main_quit), NULL);
//
//    // Afficher tous les widgets
//   // gtk_widget_show_all(window);
//    while (windows != NULL)
//    {
//        afficher_fenetre(&windows->var);
//        windows = windows->suivant;
//    }
//
//    // Lancer la boucle principale GTK
//    gtk_main();
//
//    return 0;
//}
////int main(int argc, char* argv[])
////{
////	// Initialisation de GTK
////	gtk_init(&argc, &argv);
////	GtkWidget* scrolled_window = NULL;
////	cellule_window* windows = NULL;
////	//fenetre window;
////	window = initialiser_valeurs_fenetre();
////	window.taille.width = 1000;
////	window.taille.height = 1000;
////	ajouter_fenetre(&window);
////	windows = ajouter_window(windows, window);
////	g_signal_connect(window.window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
////	//g_signal_connect(window.window, "key-press-event", G_CALLBACK(joueur_j), NULL);
////	g_signal_connect(window.window, "key-press-event", G_CALLBACK(joueur_ordi), NULL);
////	//g_signal_connect(window.window, "key-press-event", G_CALLBACK(ordin), NULL);
////	//g_signal_connect(window.window, "key-press-event", G_CALLBACK(on_key_press), NULL);
////	gridd = init_grid_default();
////	gridd = create_grid(gridd);
////	ajouter_conteneur(GTK_CONTAINER(window.window), gridd->grid);
////	//Board_Jeu New_game;
////	init_Jeu(&New_game);
////	print_board(&New_game);
////	init_Jeu2(gridd->grid, New_game);
////	
////
////	afficher_fenetre(&windows->var);
////	//init_Joueur(&New_game);
////	Noeud* bestMove = NULL;
////	while (windows != NULL)
////	{
////		afficher_fenetre(&windows->var);
////		windows = windows->suivant;
////	}
////
////
////	gtk_main();
////	return 0;
////}
//
////main()
////{
////	Board_Jeu New_game;
////	init_Jeu(&New_game);
////	printf("\n------------------------------------------------------------------------------------------------------------------\n");
////	printf("Joueur 1:  %s                                                                        Joueur 2:  %s                  \n", New_game.Players[0]->nom, New_game.Players[0]->nom);
////	printf("score  1:  %d                                                                           score 2:  %d                  \n", New_game.Players[1]->score, New_game.Players[1]->score);
////	printf("------------------------------------------------------------------------------------------------------------------\n");
////	int x, y, new_x, new_y;
////	int is_capturing;
////	int compteur = 0;
////	init_Joueur(&New_game);
////	Noeud* bestMove = NULL;
////	while (1)
////	{
////		printf("\n%d\n\n", New_game.tour_Joueur);
////		print_board(&New_game);
////		printf("\n liste des pions player 1 \n ");
////		afficher_liste(New_game.Players[0]->Mes_pieces);
////		printf("\n liste des pions player 2 \n ");
////		afficher_liste(New_game.Players[1]->Mes_pieces);
////		if (New_game.tour_Joueur == 0)
////		{
////			printf("\n C'est au joueur %d de jouer.\n", New_game.tour_Joueur ? 1 : 2);
////			printf("Entrez les coordonnees de la piece a deplacer (x,y): ");
////			scanf("%d,%d", &x, &y);
////			Liste_piece* tmp = chercher_pion(New_game.Players[New_game.tour_Joueur]->Mes_pieces, x, y);
////			//printf(" \n est dames %d \n",tmp->is_dame);
////			//printf(" \n donnee %d %d  dans %d \n",x,y,New_game.board[x][y]);
////			printf("Entrez les nouvelles coordonnées (x,y): ");
////			scanf("%d,%d", &new_x, &new_y);
////			//printf(" \n new donnee %d %d  dans %d \n",x,y,New_game.board[new_x][new_y]);
////
////			printf("\n\n %d %d -> %d %d", x, y, new_x, new_y);
////			is_capturing = is_capturing_move(x, y, new_x, new_y, New_game);
////
////			printf("\ncapt %d \n", is_capturing);
////
////			printf("\n\n valide %d\n", is_valid_input(x, y, new_x, new_y, is_capturing, New_game));
////
////			if (is_valid_input(x, y, new_x, new_y, is_capturing, New_game) == 0)
////			{
////				printf("Entrée invalide. Veuillez réessayer case 1.\n");
////				continue;
////			}
////			else
////			{
////				make_move(x, y, new_x, new_y, &New_game);
////				printf("\nfaire mpuvement\n");
////				if (is_capturing == 0)
////				{
////					if (tester_gain(New_game))
////					{
////						printf(" \n you did not move the right one \n");
////						New_game.Players[0]->Mes_pieces = supprimer_val(New_game.Players[0]->Mes_pieces, x, y);
////						//exit(0);	
////					}
////				}
////
////				New_game.tour_Joueur = 1;
////			}
////			//exit(1);
////		}
////
////		else if (New_game.tour_Joueur == 1)
////		{
////			tableau tab;
////			init_tab(&tab);
////			Noeud* racine = NULL;
////			List_Pions* Mouvements = NULL;
////			//checkCaptureDame(int row,int col,piece_t board[8][8],tableau * tab,List_Pions * Mouvements);
////			int valeur = 0;
////			//Mouvements = checkCapture(5,4,New_game.board,&tab,New_game.tour_Joueur,Mouvements,&valeur);
////			//Mouvements = checkCapture(5,0,New_game.board,&tab,New_game.tour_Joueur,Mouvements,&valeur);
////			//Mouvements = checkCaptureDame(5,2,New_game.board,&tab,Mouvements,&valeur);
////			Noeud* Arbre = NULL;
////
////			List_Pions* liste1 = NULL;
////			liste1 = ajouter_liste(0, 0, 0, 0, liste1);
////			Arbre = remplir_arbre(liste1, Arbre);
////
////			Arbre = genererMov(New_game, Arbre);
////
////			Arbre = simulation(Arbre, New_game);
////
////			int valeur5 = minimax(Arbre, 1);
////
////			initialiserValeurs(Arbre, 0);
////			Noeud* Move = NULL;
////			int score_best;
////			Move = findBestMove(Arbre, &score_best);
////			//	printf("\n\n\n\n mov \n : ");
////		//	affichage_pions(Move->contenu);
////
//////			printf("avant mouv\n");
//////			print_board(&New_game);
//////			printf("apres mouv\n");
////			appliquer_Mouvement(&New_game, Move->contenu);
////			//print_board(&New_game);
////
////			New_game.tour_Joueur = 0;
////			//	exit(0);
////		}
////	}
////}
//
