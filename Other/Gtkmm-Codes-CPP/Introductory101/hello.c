// here we included the gtk
#include <gtk/gtk.h>

// this is the function to print hello
static void
print_hello (GtkWidget *widget,
             gpointer   data)
{
  g_print ("Hello World\n");
}

// this is the function which should be activated when we click on the button
static void
activate (GtkApplication *app,
          gpointer        user_data)
{

  // here we created window object of gtk widget class 
  GtkWidget *window;

  // here we created button object of gtk widget class
  GtkWidget *button;

  // similarly this is the button box
  GtkWidget *button_box;


  // declaring that window is a gtk application
  window = gtk_application_window_new (app);

  // declaring that gtk window is a title
  gtk_window_set_title (GTK_WINDOW (window), "Window");

  // setting up the size of the window
  gtk_window_set_default_size (GTK_WINDOW (window), 1000, 1000);


  // setting the button box
  button_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
  gtk_container_add (GTK_CONTAINER (window), button_box);

  button = gtk_button_new_with_label ("Hello World");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
  
  gtk_container_add (GTK_CONTAINER (button_box), button);

  gtk_widget_show_all (window);
}

int
main (int    argc,
      char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}