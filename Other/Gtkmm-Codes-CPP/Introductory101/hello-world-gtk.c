// headerfile for gtk
#include <gtk/gtk.h>

static void
print_hello (GtkWidget *widget,
             gpointer   data)
{

  // this function will be called when we click on the button ! and this will just print the given string in the terminal ! nothing else! 
  
  g_print ("Hello World\n");
}

static void
activate (GtkApplication *app,
          gpointer        user_data)
{
  // when this function is called, window and button were set upped first.

  // window object is created of class gtk widget 
  GtkWidget *window;

  // button object is created of class gtk widget
  GtkWidget *button;

  // then we say that window is actually a window. Till now window is just a name.
  window = gtk_application_window_new (app);

  // then we set some title to the window created ! With the string passed as a second parameter
  gtk_window_set_title (GTK_WINDOW (window), "Window");

  // then we set the default size of the window created
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);

  // lets deal with the button now

  // new button is created with label hello world
  button = gtk_button_new_with_label ("Hello World");

  // then we set a signal to the button which is not being called yet
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);

  // then we are setting that button is a child of the window object;
  gtk_window_set_child (GTK_WINDOW (window), button);

  // and now we are showing the window with the button that we setup-ed in the last line 
  // with the process which is similar to dom manipulation

  // this will now show the window to the screen
  gtk_window_present (GTK_WINDOW (window));

}


// main function that is running and we will be going through this flow 
int
main (int    argc,
      char **argv)
{
  // a GtkApplication is created with the name *app
  GtkApplication *app;

  // integer status // we don't know its use yet
  int status;

  // app is a new gtk_application where org.gtk.example is the id for the same
  // and the second parameter consist of flags
  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);

  // then comes the gtk signal which is not being called yet ! We are just setting up that what to do if app is executed

  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  
  // then we run the gtk application where we can give the application we want to run
  status = g_application_run (G_APPLICATION (app), argc, argv);

  // this will be executed when we press the close button
  g_object_unref (app);

  return status;
}