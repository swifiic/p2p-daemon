#include "includes.h"
#include "common/wpa_ctrl.h"
#include "utils/common.h"
#include "utils/eloop.h"
#include "utils/edit.h"
#include "utils/list.h"
#include "common/version.h"
#include "common/ieee802_11_defs.h"

static struct wpa_ctrl *ctrl_conn;

static void wpa_cli_msg_cb(char *msg, size_t len)
{
	printf("Callback msg: %s\n", msg);
}

static void eloop_callback(int sock, void *eloop_ctx, void *sock_ctx)
{
    // wpa_cli_recv_pending(ctrl_conn, 0);
}

// static void wpa_cli_recv_pending(struct wpa_ctrl *ctrl, int action_monitor)
// {
	// while (wpa_ctrl_pending(ctrl) > 0) {
	// 	char buf[4096];
	// 	size_t len = sizeof(buf) - 1;
	// 	if (wpa_ctrl_recv(ctrl, buf, &len) == 0) {
	// 		buf[len] = '\0';
	// 		if (action_monitor)
	// 			wpa_cli_action_process(buf);
	// 		else {
	// 			cli_event(buf);
	// 			if (wpa_cli_show_event(buf)) {
	// 				edit_clear_line();
	// 				printf("\r%s\n", buf);
	// 				edit_redraw();
	// 			}
	// 		}
	// 	} else {
	// 		printf("Could not read pending message.\n");
	// 		break;
	// 	}
	// }

	// if (wpa_ctrl_pending(ctrl) < 0) {
	// 	printf("Connection to wpa_supplicant lost - trying to "
	// 	       "reconnect\n");
	// 	wpa_cli_reconnect();
	// }
// }

int main()
{
    ctrl_conn = wpa_ctrl_open("/var/run/wpa_supplicant/p2p-dev-wlp3s0");
    if (ctrl_conn == NULL) {
        printf("%s", "Not able to connect to wpa");
    } else {
        printf("%s", "Good");
    }

    int ret;

    if(eloop_init()) {
        return -1;
    }
    ret = wpa_ctrl_attach(ctrl_conn);
    
    eloop_register_read_sock(wpa_ctrl_get_fd(ctrl_conn), eloop_callback, NULL, NULL);
    
    
    printf("Atteched ctrl%d\n", ret);
    char buf[4096];
    size_t len;
	len = sizeof(buf) - 1;

    ret = wpa_ctrl_request(ctrl_conn, "P2P_FIND", os_strlen("P2P_FIND"), buf, &len, wpa_cli_msg_cb);
    printf("Ret value: %d\n%s", ret, buf);
    return 0;
} 
