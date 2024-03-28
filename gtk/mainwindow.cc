#include <gtk/gtk.h>

// Callback functions for menu items
void on_login_clicked(GtkMenuItem *menuitem, gpointer user_data) {
    g_print("Login clicked\n");
}

void on_register_clicked(GtkMenuItem *menuitem, gpointer user_data) {
    g_print("Register clicked\n");
}

void on_exit_clicked(GtkMenuItem *menuitem, gpointer user_data) {
    g_print("Exit clicked\n");
    gtk_main_quit();
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Create the main window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "GTK Window with Menu");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Create a box to hold the main components
    GtkWidget *main_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 6);
    gtk_container_add(GTK_CONTAINER(window), main_box);

    // Create a header bar with an icon tab
    GtkWidget *header_bar = gtk_header_bar_new();
    gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(header_bar), TRUE);
    gtk_header_bar_set_title(GTK_HEADER_BAR(header_bar), "My App");
    gtk_window_set_titlebar(GTK_WINDOW(window), header_bar);

    // Create a stack to hold different pages
    GtkWidget *stack = gtk_stack_new();
    gtk_stack_set_transition_type(GTK_STACK(stack), GTK_STACK_TRANSITION_TYPE_SLIDE_LEFT_RIGHT);
    gtk_stack_set_transition_duration(GTK_STACK(stack), 1000);
    gtk_box_pack_start(GTK_BOX(main_box), stack, TRUE, TRUE, 0);

    // Create and add pages to the stack
    GtkWidget *page1 = gtk_label_new("Welcome to Page 1!");
    gtk_widget_set_halign(page1, GTK_ALIGN_CENTER);
    gtk_stack_add_named(GTK_STACK(stack), page1, "page1");

    // Create and add a menu
    GtkWidget *menu_bar = gtk_menu_bar_new();
    gtk_box_pack_start(GTK_BOX(main_box), menu_bar, FALSE, FALSE, 0);

    // Create the main menu items
    const gchar *menu_names[] = {"File", "Edit", "View", "Help"};
    for (int i = 0; i < G_N_ELEMENTS(menu_names); i++) {
        GtkWidget *menu_item = gtk_menu_item_new_with_label(menu_names[i]);
        gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), menu_item);
        GtkWidget *submenu = gtk_menu_new();
        gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item), submenu);

        // If the name is "File", add a submenu for login/registration and exit
        if (g_strcmp0(menu_names[i], "File") == 0) {
            GtkWidget *login_item = gtk_menu_item_new_with_label("Login/Registration");
            gtk_menu_shell_append(GTK_MENU_SHELL(submenu), login_item);
            GtkWidget *login_submenu = gtk_menu_new();
            gtk_menu_item_set_submenu(GTK_MENU_ITEM(login_item), login_submenu);

            GtkWidget *login_option = gtk_menu_item_new_with_label("Login");
            gtk_menu_shell_append(GTK_MENU_SHELL(login_submenu), login_option);
            g_signal_connect(login_option, "activate", G_CALLBACK(on_login_clicked), NULL);

            GtkWidget *register_option = gtk_menu_item_new_with_label("Register");
            gtk_menu_shell_append(GTK_MENU_SHELL(login_submenu), register_option);
            g_signal_connect(register_option, "activate", G_CALLBACK(on_register_clicked), NULL);

            GtkWidget *exit_option = gtk_menu_item_new_with_label("Exit");
            gtk_menu_shell_append(GTK_MENU_SHELL(submenu), exit_option);
            g_signal_connect(exit_option, "activate", G_CALLBACK(on_exit_clicked), NULL);
        }
    }

    // Show all components
    gtk_widget_show_all(window);

    gtk_main();
    return 0;
}
