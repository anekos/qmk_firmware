#!/bin/bash

set -euC
# set -x


sudo date
sleep 3
echo 'Ready?'
sudo make keymap=anekos TAP_DANCE_ENABLE=yes AUDIO_ENABLE=yes MOUSEKEY_ENABLE=yes dfu
