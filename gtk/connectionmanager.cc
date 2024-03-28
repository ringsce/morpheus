#include "connectionmanager.h"
#include "peerwireclient.h" // Assuming you have this header file

#include <glib.h>

#define MAX_CONNECTIONS 250

static ConnectionManager *connection_manager_instance = NULL;

struct _ConnectionManager {
    GSet *connections;
    gchar *id;
};

static void connection_manager_init_id(ConnectionManager *self);

ConnectionManager *connection_manager_get_instance(void) {
    if (!connection_manager_instance) {
        connection_manager_instance = g_object_new(CONNECTION_MANAGER_TYPE, NULL);
        connection_manager_init_id(connection_manager_instance);
    }
    return connection_manager_instance;
}

gboolean connection_manager_can_add_connection(ConnectionManager *self) {
    g_return_val_if_fail(self != NULL, FALSE);
    return g_set_size(self->connections) < MAX_CONNECTIONS;
}

void connection_manager_add_connection(ConnectionManager *self, gpointer connection) {
    g_return_if_fail(self != NULL);
    g_return_if_fail(connection != NULL);
    g_set_add(self->connections, connection);
}

void connection_manager_remove_connection(ConnectionManager *self, gpointer connection) {
    g_return_if_fail(self != NULL);
    g_return_if_fail(connection != NULL);
    g_set_remove(self->connections, connection);
}

gint connection_manager_max_connections(ConnectionManager *self) {
    g_return_val_if_fail(self != NULL, -1);
    return MAX_CONNECTIONS;
}

const gchar *connection_manager_client_id(ConnectionManager *self) {
    g_return_val_if_fail(self != NULL, NULL);
    return self->id;
}

static void connection_manager_init_id(ConnectionManager *self) {
    if (!self->id) {
        // Generate peer id
        gchar *version_str = g_strdup_printf("-GTK%04x-", GTK_MAJOR_VERSION);
        gchar *startup_time_str = g_strdup_printf("%ld", g_get_real_time() / 1000000);
        
        self->id = g_strconcat(version_str, startup_time_str, "-", NULL);
        
        g_free(version_str);
        g_free(startup_time_str);
    }
}
