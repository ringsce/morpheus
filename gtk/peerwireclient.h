#ifndef PEERWIRECLIENT_H
#define PEERWIRECLIENT_H

#include <glib.h>
#include <gio/gio.h>

G_BEGIN_DECLS

#define PEERWIRE_CLIENT_TYPE             (peerwire_client_get_type ())
G_DECLARE_FINAL_TYPE(PeerWireClient, peerwire_client, PEERWIRE_CLIENT, GSocketClient)

typedef enum {
    PEERWIRE_STATE_CHOKING_PEER = 0x1,
    PEERWIRE_STATE_INTERESTED_IN_PEER = 0x2,
    PEERWIRE_STATE_CHOKED_BY_PEER = 0x4,
    PEERWIRE_STATE_PEER_IS_INTERESTED = 0x8
} PeerWireState;

typedef struct _TorrentBlock {
    gint piece_index;
    gint offset;
    gint length;
} TorrentBlock;

PeerWireClient *peerwire_client_new(const gchar *peer_id);
void peerwire_client_initialize(PeerWireClient *self, const gchar *info_hash, gint piece_count);
void peerwire_client_set_peer(PeerWireClient *self, gpointer peer);
guint peerwire_client_peer_wire_state(PeerWireClient *self);
GByteArray *peerwire_client_available_pieces(PeerWireClient *self);
GSList *peerwire_client_incoming_blocks(PeerWireClient *self);
void peerwire_client_choke_peer(PeerWireClient *self);
void peerwire_client_unchoke_peer(PeerWireClient *self);
void peerwire_client_send_interested(PeerWireClient *self);
void peerwire_client_send_keep_alive(PeerWireClient *self);
void peerwire_client_send_not_interested(PeerWireClient *self);
void peerwire_client_send_piece_notification(PeerWireClient *self, gint piece);
void peerwire_client_send_piece_list(PeerWireClient *self, GByteArray *bit_field);
void peerwire_client_request_block(PeerWireClient *self, gint piece, gint offset, gint length);
void peerwire_client_cancel_request(PeerWireClient *self, gint piece, gint offset, gint length);
void peerwire_client_send_block(PeerWireClient *self, gint piece, gint offset, GByteArray *data);
gint64 peerwire_client_write_to_socket(PeerWireClient *self, gint64 bytes);
gint64 peerwire_client_read_from_socket(PeerWireClient *self, gint64 bytes);
gint64 peerwire_client_download_speed(PeerWireClient *self);
gint64 peerwire_client_upload_speed(PeerWireClient *self);
gboolean peerwire_client_can_transfer_more(PeerWireClient *self);
gint64 peerwire_client_bytes_available(PeerWireClient *self);
gint64 peerwire_client_socket_bytes_available(PeerWireClient *self);
gint64 peerwire_client_socket_bytes_to_write(PeerWireClient *self);
void peerwire_client_set_read_buffer_size(PeerWireClient *self, gint64 size);
void peerwire_client_connect_to_host(PeerWireClient *self, const gchar *address, guint16 port, GSocketConnectable *connectable, GCancellable *cancellable, GAsyncReadyCallback callback, gpointer user_data);
void peerwire_client_disconnect_from_host(PeerWireClient *self);

G_END_DECLS

#endif /* PEERWIRECLIENT_H */
