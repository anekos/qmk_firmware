

#define ACTION_RENDANCE_DOUBLE(kc1, kc2) { \
    .fn = { NULL, qk_tap_dance_pair_finished, qk_tap_dance_pair_reset }, \
    .user_data = (void *)&((qk_tap_dance_pair_t) { kc1, kc2 })  \
  }

void rendance_pair_finished (qk_tap_dance_state_t *state, void *user_data) {
  qk_tap_dance_pair_t *pair = (qk_tap_dance_pair_t *)user_data;

  if (state->count == 1) {
    register_code (pair->kc1);
  } else if (state->count == 2) {
    register_code (pair->kc2);
  }
}

void rendance_pair_reset (qk_tap_dance_state_t *state, void *user_data) {
  qk_tap_dance_pair_t *pair = (qk_tap_dance_pair_t *)user_data;

  if (state->count == 1) {
    unregister_code (pair->kc1);
  } else if (state->count == 2) {
    unregister_code (pair->kc2);
  }
}
