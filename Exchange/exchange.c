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
GtkWidget	*titleLbl;
GtkWidget	*rateLbl;
GtkWidget	*fromLbl;
GtkWidget	*toLbl;
GtkWidget	*choose1Lbl;
GtkWidget	*choose2Lbl;
GtkWidget	*radioF1;
GtkWidget	*radioF2;
GtkWidget	*radioF3;
GtkWidget	*radioT1;
GtkWidget	*radioT2;
GtkWidget	*radioT3;
GtkWidget	*exchangeBtn;
GtkBuilder	*builder;

int main(int argc, char *argv[]) {
	gtk_init(&argc, &argv);
	
	builder = gtk_builder_new_from_file ("Exchange.glade");

	window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));

	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	gtk_builder_connect_signals(builder, NULL);

	fixed = GTK_WIDGET(gtk_builder_get_object(builder, "fixed"));

	titleLbl = GTK_WIDGET(gtk_builder_get_object(builder, "titleLbl"));

	rateLbl = GTK_WIDGET(gtk_builder_get_object(builder, "rateLbl"));

	fromLbl = GTK_WIDGET(gtk_builder_get_object(builder, "fromLbl"));

	toLbl = GTK_WIDGET(gtk_builder_get_object(builder, "toLbl"));

	choose1Lbl = GTK_WIDGET(gtk_builder_get_object(builder, "choose1Lbl"));

	choose2Lbl = GTK_WIDGET(gtk_builder_get_object(builder, "choose2Lbl"));

	radioF1 = GTK_WIDGET(gtk_builder_get_object(builder, "radioF1"));

	radioF2 = GTK_WIDGET(gtk_builder_get_object(builder, "radioF2"));

	radioF3 = GTK_WIDGET(gtk_builder_get_object(builder, "radioF3"));

	radioT1 = GTK_WIDGET(gtk_builder_get_object(builder, "radioT1"));

	radioT2 = GTK_WIDGET(gtk_builder_get_object(builder, "radioT2"));

	radioT3 = GTK_WIDGET(gtk_builder_get_object(builder, "radioT3"));

	exchangeBtn = GTK_WIDGET(gtk_builder_get_object(builder, "exchangeBtn"));

	gtk_widget_show(window);

	gtk_main(); 

	return EXIT_SUCCESS;
}

void	on_exchangeBtn_clicked (GtkButton *b) {
	printf("Button tapped\n");
}

void on_radioF1_toggled(GtkRadioButton *b) {
	gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));
	if (T) printf("Radio F1 active\n");
	else printf("Radio F1 inactive\n");
}

void on_radioF2_toggled(GtkRadioButton *b) {
	gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));
	if (T) printf("Radio F2 active\n");
	else printf("Radio F2 inactive\n");
}
  
void on_radioF3_toggled(GtkRadioButton *b) {
	gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));
	if (T) printf("Radio F3 active\n");
	else printf("Radio F3 inactive\n");
 }

void on_radioT1_toggled(GtkRadioButton *b) {
	gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));
	if (T) printf("Radio T1 active\n");
	else printf("Radio T1 inactive\n");
}

void on_radioT2_toggled(GtkRadioButton *b) {
	gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));
	if (T) printf("Radio T2 active\n");
	else printf("Radio T2 inactive\n");
}
  
void on_radioT3_toggled(GtkRadioButton *b) {
	gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));
	if (T) printf("Radio T3 active\n");
	else printf("Radio T3 inactive\n");
 }
