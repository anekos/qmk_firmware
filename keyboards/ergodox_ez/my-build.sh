#!/bin/bash

# set -euC
# set -x

sudo date

echo 'Ready?'

sudo make TAP_DANCE_ENABLE=yes AUDIO_ENABLE=yes KEYMAP=anekos teensy
# sudo make KEYMAP=default teensy
