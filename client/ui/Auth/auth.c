#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <ctype.h>

GtkWidget	*window;
GtkWidget	*fixed;
GtkWidget	*signIn;
GtkWidget	*signUp; 
GtkBuilder	*builder;

int main(int argc, char *argv[]) {
	gtk_init(&argc, &argv);
	
	builder = gtk_builder_new_from_file ("auth.glade");

	window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));

	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	gtk_builder_connect_signals(builder, NULL);

	fixed = GTK_WIDGET(gtk_builder_get_object(builder, "fixed"));

	signIn = GTK_WIDGET(gtk_builder_get_object(builder, "signIn"));

	signUp = GTK_WIDGET(gtk_builder_get_object(builder, "signUp"));

	gtk_widget_show(window);

	gtk_main(); 

	return EXIT_SUCCESS;

}


void	on_signIn_clicked (GtkButton *b) {
	printf("Sign In tapped\n");
}

void	on_signUp_clicked (GtkButton *b) {
	printf("Sign Up tapped\n");
}


