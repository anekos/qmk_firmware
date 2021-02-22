MOUSEKEY_ENABLE = yes       # Mouse keys(+4700)
EXTRAKEY_ENABLE = yes       # Audio control and System control(+450)
RGBLIGHT_ENABLE = no        # Enable WS2812 RGB underlight.  Do not enable this with audio at the same time.
TAP_DANCE_ENABLE  = yes

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif
