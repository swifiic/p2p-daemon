cc -c -o wpa_cli.o -MMD -O2 -Wall -g  -I/home/nic/swifiic/p2p-daemon/src -I/home/nic/swifiic/p2p-daemon/src/utils -DCONFIG_BACKEND_FILE -DCONFIG_PEERKEY -DCONFIG_P2P  -DCONFIG_DRIVER_WIRED -DCONFIG_DRIVER_NL80211 -DCONFIG_LIBNL20 -I/usr/include/libnl3  -DCONFIG_DRIVER_WEXT -DCONFIG_WIRELESS_EXTENSION  -DEAP_TLS -DEAP_PEAP -DEAP_TTLS -DEAP_MD5 -DEAP_MSCHAPv2 -DEAP_GTC -DEAP_OTP -DEAP_LEAP -DCONFIG_WPS -DEAP_WSC -DIEEE8021X_EAPOL -DCONFIG_AP -DCONFIG_NO_RADIUS -DCONFIG_NO_ACCOUNTING -DCONFIG_NO_VLAN -DEAP_SERVER -DEAP_SERVER_IDENTITY -DNEED_AP_MLME -DEAP_SERVER_WSC -DCONFIG_NO_RADIUS -DPKCS12_FUNCS -DCONFIG_SMARTCARD -DEAP_TLS_OPENSSL -DCONFIG_SHA256 -DCONFIG_CTRL_IFACE -DCONFIG_CTRL_IFACE_UNIX  -DCONFIG_SME -DCONFIG_GAS -DCONFIG_OFFCHANNEL wpa_cli.c
cc    -o wpa_cli wpa_cli.o ../src/common/wpa_ctrl.o ../src/utils/wpa_debug.o ../src/utils/common.o ../src/utils/os_unix.o ../src/utils/eloop.o ../src/utils/edit_simple.o -lrt
