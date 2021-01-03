#include <stdlib.h>

#include <sys/types.h>

#include <signal.h>

#include <unistd.h>

#include <string.h>

#include <gtk/gtk.h>

#include <gtk/gtkx.h>

#include <math.h>

#include <ctype.h>

// Make them global

GtkWidget *window;
GtkWidget *fixed1;
GtkWidget *transfer;
GtkWidget *manage;
GtkWidget *exchange;
GtkBuilder *builder;
GtkWidget *asideTitle;
GtkWidget *open_window_button;
GtkWidget *usd;
GtkWidget *eur;
GtkWidget *usz;
GtkWidget *actionTitle;
void open_window(GtkWidget *widget, gpointer window);
int main(int argc, char * argv[]) {

  gtk_init( & argc, & argv); // init Gtk

  builder = gtk_builder_new_from_file("actions-page.glade");

  window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));

  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
  open_window_button = GTK_WIDGET(gtk_builder_get_object(builder, "open_window"));
  g_signal_connect(G_OBJECT(open_window_button), "clicked",
                     G_CALLBACK(open_window), G_OBJECT(window));
  gtk_builder_connect_signals(builder, NULL);

  fixed1 = GTK_WIDGET(gtk_builder_get_object(builder, "fixed1"));
  transfer = GTK_WIDGET(gtk_builder_get_object(builder, "transfer"));
  exchange = GTK_WIDGET(gtk_builder_get_object(builder, "exchange"));
  manage = GTK_WIDGET(gtk_builder_get_object(builder, "manage"));
  asideTitle = GTK_WIDGET(gtk_builder_get_object(builder, "asideTitle"));
  usd = GTK_WIDGET(gtk_builder_get_object(builder, "usd"));
  eur = GTK_WIDGET(gtk_builder_get_object(builder, "eur"));
  usz = GTK_WIDGET(gtk_builder_get_object(builder, "usz"));
  actionTitle = GTK_WIDGET(gtk_builder_get_object(builder, "actionTitle"));

  gtk_widget_show(window);

  gtk_main();

  return EXIT_SUCCESS;
}
void open_window(GtkWidget *widget, gpointer window)
{
    GtkBuilder *builder;
    GtkWidget *secondWindow = NULL;

    builder = gtk_builder_new ();
    gtk_builder_add_from_file (builder, "secondWindow.glade", NULL);
    secondWindow = GTK_WIDGET (gtk_builder_get_object (builder, "secondWindow"));
    g_object_unref (G_OBJECT (builder));

    gtk_window_set_modal(GTK_WINDOW(secondWindow), TRUE);
    gtk_widget_show_all(secondWindow);
}
