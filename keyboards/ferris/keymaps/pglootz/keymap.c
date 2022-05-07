#include QMK_KEYBOARD_H
#include "layout.h"

#include "features/casemodes.h"

enum layers {
	BASE,
	NAV,
	SYM,
	NUM,
	FUN,
	EMOJI_1,
	EMOJI_2,
};

enum custom_keycodes {
	CAPSWORD = SAFE_RANGE,
	SNAKECASE,
};

enum unicode_names {
    SEEDLING,
    FERN,
    INCUBATOR,
	EVERGREEN,
	INBOX,
	NOTE,
	MOC,
	ARTICLE,
	THOUGHT,
	TWEET,
	PAPER,
	PODCAST,
	PEOPLE,
	SQR_RED,
	SQR_ORANGE,
	SQR_YELLOW,
	SQR_GREEN,
	PIN,
	GEAR,
	BOOK,
	RAISE_HANDS,
	HUNDRED,
	TADA,
	FIRE,
	SPARKLES,
	JOY_TEARS,
	THUMBS_UP,
	THUMBS_DOWN,
	STAR_EYES,
	CRYING,
	ROFL,
	CRCL_RED,
	CRCL_ORANGE,
	CRCL_YELLOW,
	CRCL_GREEN,
	HEART,
	KISS,
	WINK,
	HEART_FACE,
	CHART_UP,
	CHART_DOWN,
	CHECK_MARK,
	FOLDED_HANDS,
};

const uint32_t PROGMEM unicode_map[] = {
	// Emoji 1 Layer
    [SEEDLING]  = 0x1F331,  // 🌱
    [FERN] = 0x1F33F,  // 🌿
    [INCUBATOR] = 0x1F31E, // 🌞️
	[EVERGREEN] = 0x1F332, // 🌲
	[INBOX] = 0x1F4E5, // 📥
	[PAPER] = 0x1F4DC, // 📜️
	[TWEET] = 0x1F426, // 🐦️
	[THOUGHT] = 0x1F4AD, // 💭️
	[ARTICLE] = 0x1F4F0, // 📰️
	[PODCAST] = 0x1F3A7, // 🎧️
	[MOC] = 0x1F5FA, // 🗺️
	[NOTE] = 0x1F4DD, // 📝️
	[PEOPLE] = 0x1F464, // 👤️
	[SQR_RED] = 0x1F7E5, // 🟥️ 
	[SQR_ORANGE] = 0x1F7E7, // 🟧️️
	[SQR_YELLOW] = 0x1F7E8, // 🟨️
	[SQR_GREEN] = 0x1F7E9, // 🟩️️
	[PIN] = 0x1F4CC, // 📌
	[GEAR] = 0x2699, // ⚙️
	[BOOK] = 0x1F4D6, // 📖
	[SPARKLES] = 0x2728, // ✨
	[CHART_UP] = 0x1F4C8, // 📈
	[CHART_DOWN] = 0x1F4C9, // 📉
	[FOLDED_HANDS] = 0x1F64F, // 🙏
	// Emoji 2 Layer
	[RAISE_HANDS] = 0x1F64C, // 🙌
	[HUNDRED] = 0x1F4AF, // 💯
	[TADA] = 0x1F389, // 🎉
	[FIRE] = 0x1F525, // 🔥
	[JOY_TEARS] = 0x1F602, // 😂
	[THUMBS_UP] = 0x1F44D, // 👍
	[THUMBS_DOWN] = 0x1F44E, // 👎
	[STAR_EYES] = 0x1F929, // 🤩
	[CRYING] = 0x1F62D, // 😭
	[ROFL] = 0x1F923, // 🤣
	[CRCL_RED] = 0x1F534, // 🔴
	[CRCL_ORANGE] = 0x1F7E0, // 🟠
	[CRCL_YELLOW] = 0x1F7E1, //🟡
	[CRCL_GREEN] = 0x1F7E2, // 🟢
	[HEART] = 0x2764, // ♥️
	[KISS] = 0x1F618, // 😘
	[WINK] = 0x1F609, // 😉
	[HEART_FACE] = 0x1F970, // 🥰 
	[CHECK_MARK] = 0x2705, // ✅ 
};

// Home row mods
//
//             Left hand                          Right hand
// +-------+-------+-------+-------+   +-------+-------+-------+-------+
// |  Ctrl |  Gui  |  Alt  | Shift |   | Shift |  Alt  |  Gui  |  Ctrl |
// +-------+-------+-------+-------+   +-------+-------+-------+-------+
// |       |                                                   |       |
// +-------+                                                   +-------+

// Alphamods
#define HOME_R LCTL_T(KC_R)
#define HOME_S LGUI_T(KC_S)
#define HOME_N LALT_T(KC_N) 
#define HOME_D LSFT_T(KC_D)
#define HOME_A RSFT_T(KC_A)
#define HOME_I RGUI_T(KC_I)
#define HOME_E RALT_T(KC_E)
#define HOME_H RCTL_T(KC_H)
#define SYM_T LT(SYM, KC_T)

//Nav layer home row mods
#define HOME_VOLU LSFT_T(KC_VOLU)
#define HOME_VOLD LALT_T(KC_VOLD)
#define HOME_MUTE LGUI_T(KC_MUTE)

// More custom keys
#define EURO LALT(LSFT(KC_2))
#define SCREEN1 C(G(S(KC_4)))
#define SCREEN2 C(G(S(KC_3)))
#define SCREEN3 C(S(KC_4))

// Layer tap keys
#define TAB_NAV LT(NAV, KC_TAB)
#define ENT_FUN LT(FUN, KC_ENTER)
#define NUM_SPC LT(NUM, KC_SPACE)
#define EMJ_1 OSL(EMOJI_1)
#define EMJ_2 OSL(EMOJI_2)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BASE] = LAYOUT_LR(
		KC_J    , KC_G   , KC_M     , KC_P   , KC_V     ,
		HOME_R  , HOME_S , HOME_N   , HOME_D , KC_W     ,
		KC_X    , KC_F   , KC_L     , KC_C   , KC_B     ,
		                                                  SYM_T   , TAB_NAV , 
		
	                       KC_UNDS  , KC_DOT , KC_SLASH , KC_DQT , KC_QUOTE ,
						   KC_COMMA , HOME_A , HOME_E   , HOME_I , HOME_H   ,
						   KC_MINUS , KC_U   , KC_O     , KC_Y   , KC_K     ,
		ENT_FUN , NUM_SPC 
	),

	[NAV] = LAYOUT_LR(
		_______ , _______ , _______ , _______ , _______ ,
		CAPSWORD  , HOME_MUTE , HOME_VOLD , HOME_VOLU , KC_MPLY ,
		SCREEN1   , SCREEN2   , KC_MPRV , KC_MNXT , _______ ,
														  _______ , _______ ,

							KC_INS  , KC_HOME , KC_PGDN , KC_PGUP , KC_END  ,
							_______ , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT ,
							_______ , _______ , _______ , _______ , _______ ,
		KC_DEL  , _______
	),

	[SYM] = LAYOUT_LR(
		_______ , KC_CIRC , KC_HASH  , KC_AT     , _______ , 
		_______ , KC_LT   , KC_GT    , KC_PERC   , A(KC_S) ,
		A(KC_E) , KC_GRV  , A(KC_U)  , A(KC_C)   , _______ , 
							    							   _______   , _______ ,
							KC_EQUAL , KC_DLR    , KC_LCBR   , KC_RCBR   , KC_EXLM ,
							KC_GRV   , KC_BSLS   , KC_LPRN   , KC_RPRN   , KC_PIPE ,
							_______  , KC_TILD   , KC_LBRC   , KC_RBRC   , _______ ,									
		_______ , _______
	),

	[NUM] = LAYOUT_LR(
		_______ , _______ , _______ , EURO      , _______ ,
		KC_LCTL , KC_LGUI , KC_LALT  , KC_LSFT   , _______ ,
		_______ , _______ , _______ , A(KC_C)   , _______ ,
															   _______ , _______ ,
							
							KC_EQL   , KC_P7      , KC_P8      , KC_P9       , KC_P0     ,
							KC_COMMA , KC_P4      , KC_P5      , KC_P6       , KC_P0     ,
							KC_DOT   , KC_P1      , KC_P2      , KC_P3       , KC_P0     ,
		_______ , _______ 
	),

	[FUN] = LAYOUT_LR(
		_______ , _______ , _______ , _______ , _______ ,
		KC_LCTL , KC_LGUI , KC_RALT , KC_LSFT   , _______ ,
		_______ , _______ , _______ , _______ , _______ ,
															   _______ , _______ ,

							_______ , KC_F7     , KC_F8     , KC_F9      , KC_F12   ,
							EMJ_2   , KC_F4     , KC_F5     , KC_F6      , KC_F11   ,
							EMJ_1   , KC_F1     , KC_F2     , KC_F3      , KC_F10   ,
		_______ , _______ 
	),

	[EMOJI_1] = LAYOUT_LR(
		X(INBOX)    , X(PODCAST) ,  X(PIN)     , X(BOOK)      , X(SPARKLES)  , 
		X(NOTE)     , X(THOUGHT)  , X(ARTICLE) , X(PEOPLE)    , X(PAPER)     ,
		X(MOC)      , X(SEEDLING) , X(FERN)    , X(INCUBATOR) , X(EVERGREEN) ,
													       _______ , _______ ,
							_______ , X(GEAR)     ,  X(CHECK_MARK) , X(CHART_UP)    , X(CHART_DOWN) ,
							_______ , X(CRCL_RED) , X(CRCL_ORANGE) , X(CRCL_YELLOW) , X(CRCL_GREEN) ,
							_______ , X(SQR_RED)  , X(SQR_ORANGE)  , X(SQR_YELLOW)  , X(SQR_GREEN)  ,									
		_______ , _______
	),

	[EMOJI_2] = LAYOUT_LR(
		X(ROFL)      , X(CRYING)      , X(HEART)     , X(KISS)      , X(HEART_FACE)   , 
		X(THUMBS_UP) , X(THUMBS_DOWN) , X(JOY_TEARS) , X(STAR_EYES) , X(WINK)         ,
		X(HUNDRED)   , X(RAISE_HANDS) , X(TADA)      , X(FIRE)      , X(FOLDED_HANDS) ,
													       _______ , _______ ,
							_______  , _______ , _______ , _______ , _______ ,
							_______  , _______ , _______ , _______ , _______ ,
							_______ , _______ , _______ , _______ , _______ ,									
		_______ , _______
	),
};

const key_override_t custom_shift_minus_to_plus = ko_make_basic(MOD_MASK_SHIFT, KC_MINUS, KC_PLUS);
const key_override_t custom_shift_comma_to_colon = ko_make_basic(MOD_MASK_SHIFT, KC_COMMA, KC_COLON);
const key_override_t custom_shift_under_to_semi = ko_make_basic(MOD_MASK_SHIFT, KC_UNDS, KC_SCLN);
const key_override_t custom_shift_dot_to_amper = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_AMPERSAND);
const key_override_t custom_shift_fslash_to_star = ko_make_basic(MOD_MASK_SHIFT, KC_SLASH, KC_ASTR);
const key_override_t custom_shift_dqt_to_question = ko_make_basic(MOD_MASK_SHIFT, KC_DQT, KC_QUESTION);
const key_override_t custom_shift_squote_to_exclamation = ko_make_basic(MOD_MASK_SHIFT, KC_QUOTE, KC_EXCLAIM);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &custom_shift_minus_to_plus,
    &custom_shift_comma_to_colon,
    &custom_shift_under_to_semi,
	&custom_shift_dot_to_amper,
	&custom_shift_fslash_to_star,
	&custom_shift_dqt_to_question,
	&custom_shift_squote_to_exclamation,
    NULL // Null terminate the array of overrides!
};

const uint16_t PROGMEM bsp_combo[] = {KC_O, KC_K, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {KC_X, KC_F, COMBO_END};
const uint16_t PROGMEM z_combo[] = {KC_J, KC_G, COMBO_END};
const uint16_t PROGMEM q_combo[] = {KC_U, KC_K, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
	COMBO(bsp_combo, KC_BACKSPACE),
	COMBO(esc_combo, KC_ESCAPE),
	COMBO(z_combo, KC_Z),
	COMBO(q_combo, KC_Q)
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	// Process case modes
	if (!process_case_modes(keycode, record)) {
		return false;
	}

	// Regular user keycode case statement
	switch (keycode) {
		case CAPSWORD:
			if (record->event.pressed) {
				enable_caps_word();
			}
			return false;
		case SNAKECASE:
			if (record->event.pressed) {
				enable_xcase_with(KC_UNDS);
			}
			return false;
		default:
			return true;
	}	
};