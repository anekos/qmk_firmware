#!/bin/bash

set -euC
# set -x


sudo date
sleep 3
echo 'Ready?'
sudo make keymap=anekos API_SYSEX_ENABLE=no TAP_DANCE_ENABLE=yes AUDIO_ENABLE=yes MOUSEKEY_ENABLE=yes dfu

# API_SYSEX_ENABLE は、https://github.com/jackhumbert/qmk_firmware/issues/922 のために必要
