#include "includes.h"
#include "common/wpa_ctrl.h"
#include "utils/common.h"
#include "utils/eloop.h"
#include "utils/edit.h"
#include "utils/list.h"
#include "common/version.h"
#include "common/ieee802_11_defs.h"

int main()
{
    static struct wpa_ctrl *ctrl_conn;
    ctrl_conn = wpa_ctrl_open("/var/run/wpa_supplicant/p2p-wlp3s0-0");
    if (ctrl_conn == NULL) {
        printf("%s", "Not able to connect to wpa");
    } else {
        printf("%s", "Good");
    }
    return 0;
} 
