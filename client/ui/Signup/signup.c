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
GtkWidget	*signInLbl;
GtkWidget	*stack1;
GtkWidget	*viewPort1;
GtkWidget	*textView1;
GtkWidget	*stack2;
GtkWidget	*viewPort2;
GtkWidget	*textView2;
GtkWidget	*stack3;
GtkWidget	*viewPort3;
GtkWidget	*textView3;
GtkWidget	*stack4;
GtkWidget	*viewPort4;
GtkWidget	*textView4;
GtkWidget	*saveBtn;
GtkTextBuffer	*textBuffer1;
GtkTextBuffer	*textBuffer2;
GtkTextBuffer	*textBuffer3;
GtkTextBuffer	*textBuffer4; 

GtkBuilder	*builder;

void	on_changed_text1(GtkTextBuffer *t);
void	on_changed_text2(GtkTextBuffer *t); 
void	on_changed_text3(GtkTextBuffer *t);
void	on_changed_text4(GtkTextBuffer *t); 

int main(int argc, char *argv[]) {
	gtk_init(&argc, &argv);
	
	builder = gtk_builder_new_from_file ("signup.glade");

	window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));

	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	gtk_builder_connect_signals(builder, NULL);

	fixed = GTK_WIDGET(gtk_builder_get_object(builder, "fixed"));

	stack1 = GTK_WIDGET(gtk_builder_get_object(builder, "stack1"));

	viewPort1 = GTK_WIDGET(gtk_builder_get_object(builder, "viewPort1"));

	textView1 = GTK_WIDGET(gtk_builder_get_object(builder, "textView1"));

	stack2 = GTK_WIDGET(gtk_builder_get_object(builder, "stack2"));

	viewPort2 = GTK_WIDGET(gtk_builder_get_object(builder, "viewPort2"));

	textView2 = GTK_WIDGET(gtk_builder_get_object(builder, "textView2"));

	stack3 = GTK_WIDGET(gtk_builder_get_object(builder, "stack3"));

	viewPort3 = GTK_WIDGET(gtk_builder_get_object(builder, "viewPort3"));

	textView3 = GTK_WIDGET(gtk_builder_get_object(builder, "textView3"));

	stack4 = GTK_WIDGET(gtk_builder_get_object(builder, "stack4"));

	viewPort4 = GTK_WIDGET(gtk_builder_get_object(builder, "viewPort4"));

	textView4 = GTK_WIDGET(gtk_builder_get_object(builder, "textView4"));

	saveBtn = GTK_WIDGET(gtk_builder_get_object(builder, "saveBtn"));

	textBuffer1 = gtk_text_view_get_buffer (GTK_TEXT_VIEW(textView1));

	textBuffer2 = gtk_text_view_get_buffer (GTK_TEXT_VIEW(textView2));

	textBuffer3 = gtk_text_view_get_buffer (GTK_TEXT_VIEW(textView3));

	textBuffer4 = gtk_text_view_get_buffer (GTK_TEXT_VIEW(textView4));

	 g_signal_connect(textBuffer1, "changed", G_CALLBACK(on_changed_text1), NULL); 

	g_signal_connect(textBuffer2, "changed", G_CALLBACK(on_changed_text2), NULL); 

	 g_signal_connect(textBuffer3, "changed", G_CALLBACK(on_changed_text3), NULL); 

	g_signal_connect(textBuffer4, "changed", G_CALLBACK(on_changed_text4), NULL); 

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

	gtk_text_buffer_get_iter_at_offset (GTK_TEXT_BUFFER(textBuffer4), &begin, (gint) 0);
	gtk_text_buffer_get_iter_at_offset (GTK_TEXT_BUFFER(textBuffer4), &end, (gint) -1);

	text = gtk_text_buffer_get_text (GTK_TEXT_BUFFER(textBuffer4), &begin, &end, TRUE);
	printf("-------\n%s\n-------\n", text);

	gtk_widget_hide(saveBtn);
}

void on_changed_text1(GtkTextBuffer *t) {
	printf("*** Login changed\n");
	gtk_widget_show(saveBtn);
}

void on_changed_text2(GtkTextBuffer *t) {
	printf("*** Password changed\n");
	gtk_widget_show(saveBtn);
}

void on_changed_text3(GtkTextBuffer *t) {
	printf("*** Name changed\n");
	gtk_widget_show(saveBtn);
}

void on_changed_text4(GtkTextBuffer *t) {
	printf("*** Passport changed\n");
	gtk_widget_show(saveBtn);
}
