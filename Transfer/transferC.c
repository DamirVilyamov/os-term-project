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
GtkWidget	*transferLbl;
GtkWidget	*fromLbl;
GtkWidget	*chooseLbl;
GtkWidget	*toLbl;
GtkWidget	*accountNumLbl;
GtkWidget	*transferBtn;
GtkWidget	*radio1;
GtkWidget	*radio2;
GtkWidget	*radio3;
GtkWidget	*stack;
GtkWidget	*viewPort;
GtkWidget	*textView;
GtkTextBuffer	*textBuffer; 
GtkBuilder	*builder;

char	tmp[20];
void	on_changed_text(GtkTextBuffer *t); 

int main(int argc, char *argv[]) {
	gtk_init(&argc, &argv);
	
	builder = gtk_builder_new_from_file ("transferScr.glade");

	window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));

	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	gtk_builder_connect_signals(builder, NULL);

	fixed = GTK_WIDGET(gtk_builder_get_object(builder, "fixed"));

	transferLbl = GTK_WIDGET(gtk_builder_get_object(builder, "transferLbl"));

	fromLbl = GTK_WIDGET(gtk_builder_get_object(builder, "fromLbl"));

	chooseLbl = GTK_WIDGET(gtk_builder_get_object(builder, "chooseLbl"));

	accountNumLbl = GTK_WIDGET(gtk_builder_get_object(builder, "accountNumLbl"));

	transferBtn = GTK_WIDGET(gtk_builder_get_object(builder, "transferBtn"));

	radio1 = GTK_WIDGET(gtk_builder_get_object(builder, "radio1"));

	radio2 = GTK_WIDGET(gtk_builder_get_object(builder, "radio2"));

	radio3 = GTK_WIDGET(gtk_builder_get_object(builder, "radio3"));

	textView = GTK_WIDGET(gtk_builder_get_object(builder, "textView"));

	stack = GTK_WIDGET(gtk_builder_get_object(builder, "stack"));

	viewPort = GTK_WIDGET(gtk_builder_get_object(builder, "viewPort"));

	textBuffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW(textView));

	 g_signal_connect(textBuffer, "changed", G_CALLBACK(on_changed_text), NULL); 
	strcpy(tmp, "8600 0000 0000 0000");
	
	gtk_text_buffer_set_text (textBuffer, (const gchar *) tmp, (gint) -1);

	gtk_widget_show(window);

	gtk_main(); 

	return EXIT_SUCCESS;
}

void	on_transferBtn_clicked (GtkButton *b) {
	printf("Button tapped\n");
}

void on_radio1_toggled(GtkRadioButton *b) {
	gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));
	if (T) printf("Radio 1 active\n");
	else printf("Radio 1 inactive\n");
}

void on_radio2_toggled(GtkRadioButton *b) {
	 gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));
	if (T) printf("Radio 2 active\n");
	else printf("Radio 2 inactive\n");
}
  
void on_radio3_toggled(GtkRadioButton *b) {
	 gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));
	if (T) printf("Radio 3 active\n");
	else printf("Radio 3 inactive\n");
 }

void on_changed_text(GtkTextBuffer *t) {
	printf("*** text changed\n");
}
