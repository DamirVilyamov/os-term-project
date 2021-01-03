#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <ctype.h>

GtkWidget	*window,*SignUpWindow,*SignInWindow,*newSignInWindow;
GtkWidget	*fixed,*fixed1;
GtkWidget	*signIn;
GtkWidget	*signUp; 
GtkWidget	*SignUpFixed,*SignUpTitle,*SignUpLogin,*SignUpPassword,*SignUpName,*SignUpSerialNumber,*SignUpBtn;
GtkWidget	*SignInFixed,*SignInTitle,*SignInLogin,*SignInPassword,*SignInBtn;
GtkWidget	*stack1;
GtkWidget	*viewPort1;
GtkWidget	*textView1;
GtkWidget	*stack2;
GtkWidget	*viewPort2;
GtkWidget	*textView2;
GtkWidget	*saveBtn;
GtkTextBuffer	*textBuffer1;
GtkTextBuffer	*textBuffer2; 
GtkBuilder	*builder;
void	on_changed_text1(GtkTextBuffer *t);
void	on_changed_text2(GtkTextBuffer *t); 
int main(int argc, char *argv[]) {
	gtk_init(&argc, &argv);
	
	builder = gtk_builder_new_from_file ("auth.glade");
	window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
        SignUpWindow = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpWindow"));
	SignInWindow = GTK_WIDGET(gtk_builder_get_object(builder, "SignInWindow"));
	newSignInWindow = GTK_WIDGET(gtk_builder_get_object(builder, "newSignInWindow"));

	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	

	gtk_builder_connect_signals(builder, NULL);
	
	SignUpFixed = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpFixed"));
	SignUpTitle = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpTitle"));
	SignUpLogin = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpLogin"));
	SignUpPassword = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpPassword"));
	SignUpName = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpName"));
	SignUpSerialNumber = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpSerialNumber"));
	SignUpBtn = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpBtn"));

	SignInFixed = GTK_WIDGET(gtk_builder_get_object(builder, "SignInFixed"));
	SignInTitle = GTK_WIDGET(gtk_builder_get_object(builder, "SignInTitle"));
	SignInLogin = GTK_WIDGET(gtk_builder_get_object(builder, "SignInLogin"));
	SignInPassword = GTK_WIDGET(gtk_builder_get_object(builder, "SignInPassword"));
	SignInBtn = GTK_WIDGET(gtk_builder_get_object(builder, "SignInBtn"));
	

	fixed = GTK_WIDGET(gtk_builder_get_object(builder, "fixed"));
	
	signIn = GTK_WIDGET(gtk_builder_get_object(builder, "signIn"));
        signUp = GTK_WIDGET(gtk_builder_get_object(builder, "signUp"));
        stack1 = GTK_WIDGET(gtk_builder_get_object(builder, "stack1"));

	viewPort1 = GTK_WIDGET(gtk_builder_get_object(builder, "viewPort1"));

	textView1 = GTK_WIDGET(gtk_builder_get_object(builder, "textView1"));

	stack2 = GTK_WIDGET(gtk_builder_get_object(builder, "stack2"));

	viewPort2 = GTK_WIDGET(gtk_builder_get_object(builder, "viewPort2"));

	textView2 = GTK_WIDGET(gtk_builder_get_object(builder, "textView2"));

	saveBtn = GTK_WIDGET(gtk_builder_get_object(builder, "saveBtn"));

	textBuffer1 = gtk_text_view_get_buffer (GTK_TEXT_VIEW(textView1));

	textBuffer2 = gtk_text_view_get_buffer (GTK_TEXT_VIEW(textView2));

	g_signal_connect(textBuffer1, "changed", G_CALLBACK(on_changed_text1), NULL); 

	g_signal_connect(textBuffer2, "changed", G_CALLBACK(on_changed_text2), NULL); 

	gtk_widget_hide(saveBtn);
	gtk_widget_show(window);
	

	gtk_main(); 

	return EXIT_SUCCESS;

}


void	on_signIn_clicked (GtkButton *b) {
	printf("Sign In tapped\n");
	gtk_widget_hide(window);
	gtk_widget_show(newSignInWindow);
}

void	on_signUp_clicked (GtkButton *b) {
	printf("Sign Up tapped\n");
	gtk_widget_hide(window);
	gtk_widget_show(SignUpWindow);
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




