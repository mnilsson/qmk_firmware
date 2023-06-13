// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "planck.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
#include "audio.h"
#endif
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4
#define _PLOVER 5
#define _DATA_ENTRY 6
#define _ADJUST 16

enum planck_keycodes
{
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  PLOVER,
  LOWER,
  RAISE,
  BACKLIT,
  EXT_PLV,
  DATAENT
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
 * ,------------------------------------------------------------------------------------.
 * | Esc   |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |-------+------+------+------+------+-------------+------+------+------+------+------|
 * |Tab/ctl|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |-------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Shift|
 * |-------+------+------+------+------+------+------+------+------+------+------+------|
 * | Hyper | Ctrl | Alt  | GUI  |Lower | Space| Enter|Raise | Left | Down |  Up  |Right |
 * `------------------------------------------------------------------------------------'
 */
    [_QWERTY] = {
        {KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC},
        {CTL_T(KC_TAB), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT},
        {KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT},
        {KC_HYPR, KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_ENT, RAISE, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT}},

    /* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Hyper| Ctrl | Alt  | GUI  |Lower | Space| Enter|Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
    [_COLEMAK] = {
        {KC_ESC, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSPC},
        {CTL_T(KC_TAB), KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, KC_QUOT},
        {KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT},
        {KC_HYPR, KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_ENT, RAISE, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT}},

    /* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | pgdn | pgup |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
    [_RAISE] = {
        {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSPC},
        {KC_DEL, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, _______, _______, _______, _______, _______},
        {_______, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PGDN, KC_PGUP, _______, _______, _______},
        {_______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
    },

    /*
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  !   |  @   |  #   |  $   |   %  |  ^  |   &  |   *   |   (  |   )  |  _   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  ~   |  `   |  +   |  =   |  |   |  \   |  [   |  ]   |   {  |   }  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
    [_LOWER] = {{_______, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS},
        {KC_DEL, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS},
        {_______, KC_TILD, KC_GRV, KC_PLUS, KC_EQL, KC_PIPE, KC_BSLS, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, _______},
        {_______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}},:

    /* Data entry layer
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |TogOut|   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

    [_DATA_ENTRY] = {
        {_______, _______, _______, _______, _______,  KC_BSPC, KC_P7, KC_P8, KC_P9, KC_PSLS, KC_A, KC_B},
        {_______, _______, _______, _______, _______,  _______, KC_P4, KC_P5, KC_P6, KC_PAST, KC_C, KC_D},
        {_______, _______, _______, _______, _______,  _______, KC_P1, KC_P2, KC_P3, KC_PMNS, KC_E, KC_F},
        {LOWER, _______, _______, _______, _______,  _______, KC_P0, KC_PDOT, KC_PENT, KC_PPLS, _______, RAISE}
    },

    /* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
    [_ADJUST] = {
        {_______, RESET, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL},
        {_______, _______, _______, AU_ON, AU_OFF, AG_NORM, AG_SWAP, QWERTY, COLEMAK, DVORAK, PLOVER, DATAENT},
        {_______, MUV_DE, MUV_IN, MU_ON, MU_OFF, MI_ON, MI_OFF, _______, _______, _______, _______, _______},
        {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
    }

};

#ifdef AUDIO_ENABLE

float tone_startup[][2] = SONG(STARTUP_SOUND);
float tone_qwerty[][2] = SONG(QWERTY_SOUND);
float tone_dvorak[][2] = SONG(DVORAK_SOUND);
float tone_colemak[][2] = SONG(COLEMAK_SOUND);
float music_scale[][2] = SONG(MUSIC_SCALE_SOUND);

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
#endif

void persistant_default_layer_set(uint16_t default_layer)
{
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode)
  {
  case QWERTY:
    if (record->event.pressed)
    {
#ifdef AUDIO_ENABLE
      PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
#endif
      persistant_default_layer_set(1UL << _QWERTY);
    }
    return false;
    break;

  case COLEMAK:
    if (record->event.pressed)
    {
#ifdef AUDIO_ENABLE
      PLAY_NOTE_ARRAY(tone_colemak, false, 0);
#endif
      persistant_default_layer_set(1UL << _COLEMAK);
    }
    return false;
    break;
  case LOWER:
    if (record->event.pressed)
    {
      layer_on(_LOWER);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    }
    else
    {
      layer_off(_LOWER);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    }
    return false;
    break;
  case RAISE:
    if (record->event.pressed)
    {
      layer_on(_RAISE);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    }
    else
    {
      layer_off(_RAISE);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    }
    return false;
    break;

  case DATAENT:
    if (record->event.pressed)
    {
      persistant_default_layer_set(1UL << _DATA_ENTRY);
    }
    return false;
    break;
  }
  return true;
}

void matrix_init_user(void)
{
#ifdef AUDIO_ENABLE
  startup_user();
#endif
}

#ifdef AUDIO_ENABLE

void startup_user()
{
  _delay_ms(20); // gets rid of tick
  PLAY_NOTE_ARRAY(tone_startup, false, 0);
}

void shutdown_user()
{
  PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
  _delay_ms(150);
  stop_all_notes();
}

void music_on_user(void)
{
  music_scale_user();
}

void music_scale_user(void)
{
  PLAY_NOTE_ARRAY(music_scale, false, 0);
}

#endif
