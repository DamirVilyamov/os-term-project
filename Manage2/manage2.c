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
GtkWidget	*accLbl;
GtkWidget	*nameLbl;
GtkWidget	*numLbl;
GtkWidget	*expLabel;
GtkWidget	*nameTxtView;
GtkWidget	*numTxtView;
GtkWidget	*expTxtView;
GtkWidget	*saveBtn;
GtkTextBuffer	*textBuffer1;
GtkTextBuffer	*textBuffer2;
GtkTextBuffer	*textBuffer3; 
GtkBuilder	*builder;

void	on_changed_text1(GtkTextBuffer *t);
void	on_changed_text2(GtkTextBuffer *t); 
void	on_changed_text3(GtkTextBuffer *t);

int main(int argc, char *argv[]) {
	gtk_init(&argc, &argv);
	
	builder = gtk_builder_new_from_file ("manage2.glade");

	window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));

	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	gtk_builder_connect_signals(builder, NULL);

	fixed = GTK_WIDGET(gtk_builder_get_object(builder, "fixed"));

	titleLbl = GTK_WIDGET(gtk_builder_get_object(builder, "titleLbl"));

	accLbl = GTK_WIDGET(gtk_builder_get_object(builder, "accLbl"));

	nameLbl = GTK_WIDGET(gtk_builder_get_object(builder, "nameLbl"));

	numLbl = GTK_WIDGET(gtk_builder_get_object(builder, "numLbl"));

	expLabel = GTK_WIDGET(gtk_builder_get_object(builder, "expLabel"));

	nameTxtView = GTK_WIDGET(gtk_builder_get_object(builder, "nameTxtView"));

	numTxtView = GTK_WIDGET(gtk_builder_get_object(builder, "numTxtView"));

	expTxtView = GTK_WIDGET(gtk_builder_get_object(builder, "expTxtView"));

	saveBtn = GTK_WIDGET(gtk_builder_get_object(builder, "saveBtn"));

	textBuffer1 = gtk_text_view_get_buffer (GTK_TEXT_VIEW(nameTxtView));

	textBuffer2 = gtk_text_view_get_buffer (GTK_TEXT_VIEW(numTxtView));

	textBuffer3 = gtk_text_view_get_buffer (GTK_TEXT_VIEW(expTxtView));

	 g_signal_connect(textBuffer1, "changed", G_CALLBACK(on_changed_text1), NULL); 

	g_signal_connect(textBuffer2, "changed", G_CALLBACK(on_changed_text2), NULL); 

	g_signal_connect(textBuffer3, "changed", G_CALLBACK(on_changed_text3), NULL); 
	//strcpy(tmp, "8600 0000 0000 0000");
	
	//gtk_text_buffer_set_text (textBuffer, (const gchar *) tmp, (gint) -1);

	gtk_widget_hide(saveBtn);

	gtk_widget_show(window);

	gtk_main(); 

	return EXIT_SUCCESS;
}

void	on_saveBtn_clicked (GtkButton *b) {
	printf("Button clicked\n");

	GtkTextIter begin, end;
	gchar * text;

	gtk_text_buffer_get_iter_at_offset (GTK_TEXT_BUFFER(textBuffer1), &begin, (gint) 0);
	gtk_text_buffer_get_iter_at_offset (GTK_TEXT_BUFFER(textBuffer1), &end, (gint) -1);

	text = gtk_text_buffer_get_text (GTK_TEXT_BUFFER(textBuffer1), &begin, &end, TRUE);
	printf("-------\n%s\n-------\n", text);

	gtk_text_buffer_get_iter_at_offset (GTK_TEXT_BUFFER(textBuffer2), &begin, (gint) 0);
	gtk_text_buffer_get_iter_at_offset (GTK_TEXT_BUFFER(textBuffer2), &end, (gint) -1);

	text = gtk_text_buffer_get_text (GTK_TEXT_BUFFER(textBuffer2), &begin, &end, TRUE);
	printf("-------\n%s\n-------\n", text);

	gtk_text_buffer_get_iter_at_offset (GTK_TEXT_BUFFER(textBuffer3), &begin, (gint) 0);
	gtk_text_buffer_get_iter_at_offset (GTK_TEXT_BUFFER(textBuffer3), &end, (gint) -1);

	text = gtk_text_buffer_get_text (GTK_TEXT_BUFFER(textBuffer3), &begin, &end, TRUE);
	printf("-------\n%s\n-------\n", text);

	gtk_widget_hide(saveBtn);
}

void on_changed_text1(GtkTextBuffer *t) {
	printf("*** Name changed\n");
	gtk_widget_show(saveBtn);
}

void on_changed_text2(GtkTextBuffer *t) {
	printf("*** Num changed\n");
	gtk_widget_show(saveBtn);
}

void on_changed_text3(GtkTextBuffer *t) {
	printf("*** Expiration date changed\n");
	gtk_widget_show(saveBtn);
}
