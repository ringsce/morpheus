#ifndef CONNECTION_MANAGER_H
#define CONNECTION_MANAGER_H

#include <glib.h>
#include <glib-object.h>

G_BEGIN_DECLS

#define CONNECTION_MANAGER_TYPE             (connection_manager_get_type ())
G_DECLARE_FINAL_TYPE(ConnectionManager, connection_manager, CONNECTION_MANAGER, GObject)

ConnectionManager *connection_manager_get_instance(void);

gboolean connection_manager_can_add_connection(ConnectionManager *self);
void connection_manager_add_connection(ConnectionManager *self, gpointer connection);
void connection_manager_remove_connection(ConnectionManager *self, gpointer connection);
gint connection_manager_max_connections(ConnectionManager *self);
const gchar *connection_manager_client_id(ConnectionManager *self);

G_END_DECLS

#endif /* CONNECTION_MANAGER_H */
