// -*- mode: c++ -*-
// Copyright 2016 Keyboardio, inc. <jesse@keyboard.io>
// See "LICENSE" for license details

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif


/**
 * These #include directives pull in the Kaleidoscope firmware core,
 * as well as the Kaleidoscope plugins we use in the Model 01's firmware
 */


// The Kaleidoscope core
#include "Kaleidoscope.h"

// Support for keys that move the mouse
#include "Kaleidoscope-MouseKeys.h"

// Support for macros
#include "Kaleidoscope-Macros.h"

// Support for controlling the keyboard's LEDs
#include "Kaleidoscope-LEDControl.h"

// Support for "Numpad" mode, which is mostly just the Numpad specific LED mode
#include "Kaleidoscope-NumPad.h"

// Support for an "LED off mode"
#include "LED-Off.h"

// Support for the "Boot greeting" effect, which pulses the 'LED' button for 10s
// when the keyboard is connected to a computer (or that computer is powered on)
// #include "Kaleidoscope-LEDEffect-BootGreeting.h"

// Support for LED modes that set all LEDs to a single color
#include "Kaleidoscope-LEDEffect-SolidColor.h"

// Support for an LED mode that makes all the LEDs 'breathe'
#include "Kaleidoscope-LEDEffect-Breathe.h"

// Support for an LED mode that makes a red pixel chase a blue pixel across the keyboard
#include "Kaleidoscope-LEDEffect-Chase.h"

// Support for LED modes that pulse the keyboard's LED in a rainbow pattern
#include "Kaleidoscope-LEDEffect-Rainbow.h"

// Support for an LED mode that lights up the keys as you press them
#include "Kaleidoscope-LED-Stalker.h"

// Support for an LED mode that prints the keys you press in letters 4px high
#include "Kaleidoscope-LED-AlphaSquare.h"

// Support for Keyboardio's internal keyboard testing mode
#include "Kaleidoscope-Model01-TestMode.h"

// Support for host power management (suspend & wakeup)
#include "Kaleidoscope-HostPowerManagement.h"

// Needed for the Unicode plugin
#include <Kaleidoscope-HostOS.h>
#include <Kaleidoscope/HostOS-select.h>

// Support for entering unicode characters
#include <Kaleidoscope-Unicode.h>

// Custom key definitions
#include "key_defs_custom.h"


/** This 'enum' is a list of all the macros used by the Model 01's firmware
  * The names aren't particularly important. What is important is that each
  * is unique.
  *
  * These are the names of your macros. They'll be used in two places.
  * The first is in your keymap definitions. There, you'll use the syntax
  * `M(MACRO_NAME)` to mark a specific keymap position as triggering `MACRO_NAME`
  *
  * The second usage is in the 'switch' statement in the `macroAction` function.
  * That switch statement actually runs the code associated with a macro when
  * a macro key is pressed.
  */

enum { MACRO_VERSION_INFO,
       MACRO_ANY,
       MACRO_ENDASH,
       MACRO_EMDASH
     };



/** The Model 01's key layouts are defined as 'keymaps'. By default, there are three
  * keymaps: The standard QWERTY keymap, the "Function layer" keymap and the "Numpad"
  * keymap.
  *
  * Each keymap is defined as a list using the 'KEYMAP_STACKED' macro, built
  * of first the left hand's layout, followed by the right hand's layout.
  *
  * Keymaps typically consist mostly of `Key_` definitions. There are many, many keys
  * defined as part of the USB HID Keyboard specification. You can find the names
  * (if not yet the explanations) for all the standard `Key_` defintions offered by
  * Kaleidoscope in these files:
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_keyboard.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_consumerctl.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_sysctl.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_keymaps.h
  *
  * Additional things that should be documented here include
  *   using ___ to let keypresses fall through to the previously active layer
  *   using XXX to mark a keyswitch as 'blocked' on this layer
  *   using ShiftToLayer() and LockLayer() keys to change the active keymap.
  *   the special nature of the PROG key
  *   keeping NUM and FN consistent and accessible on all layers
  *
  *
  * The "keymaps" data structure is a list of the keymaps compiled into the firmware.
  * The order of keymaps in the list is important, as the ShiftToLayer(#) and LockLayer(#)
  * macros switch to key layers based on this list.
  *
  *

  * A key defined as 'ShiftToLayer(FUNCTION)' will switch to FUNCTION while held.
  * Similarly, a key defined as 'LockLayer(NUMPAD)' will switch to NUMPAD when tapped.
  */

/**
  * Layers are "0-indexed" -- That is the first one is layer 0. The second one is layer 1.
  * The third one is layer 2.
  * This 'enum' lets us use names like QWERTY, FUNCTION, and NUMPAD in place of
  * the numbers 0, 1 and 2.
  *
  */

enum {
  ANISHTRO,
  SHIFT,
  SYMBOL,
  SHIFT_SYMBOL,
  SPECIAL,
  SHIFT_SPECIAL,
  QWERTY,
  NUMPAD,
  FUNCTION
};

/* This comment temporarily turns off astyle's indent enforcement
 *   so we can make the keymaps actually resemble the physical key layout better
 */
// *INDENT-OFF*

const Key keymaps[][ROWS][COLS] PROGMEM = {

  [ANISHTRO] = KEYMAP_STACKED
  (Key_LeftShift, Key_EAcute, Key_LeftAlt, Key_LeftControl, ShiftToLayer(SHIFT), Key_LeftGui, Key_PageUp,
   Key_RightDoubleQuoteMark, Key_Q, Key_L, Key_U, Key_C, Key_J, Key_PageDown,
   Key_Tab, Key_A, Key_N, Key_I, Key_S, Key_V,
   Key_ADiaeresis, Key_Slash, Key_Question, Key_Y, Key_G, Key_X, Key_DownArrow,
   Key_RightArrow, Key_E, ShiftToLayer(SYMBOL), Key_Backspace,
   // ShiftToLayer(SPECIAL),
   XXX,

   Key_ScrollLock, Key_RightGui, ShiftToLayer(SHIFT), Key_RightControl, Key_LeftAlt, Key_ARing, Key_PcApplication,
   Key_Delete, Key_K, Key_P, Key_M, Key_W, Key_Minus, Key_RightSingleQuoteMark,
   /* none */ Key_B, Key_H, Key_T, Key_R, Key_O, Key_Escape,
   Key_UpArrow, Key_Z, Key_F, Key_D, Key_Period, Key_Comma, Key_ODiaeresis,
   Key_Enter, ShiftToLayer(SYMBOL), Key_Spacebar, Key_LeftArrow,
   // ShiftToLayer(SPECIAL)),
   XXX),

  [SHIFT] = KEYMAP_STACKED
  (Key_RightShift, LSHIFT(Key_EAcute), ___, ___, ___, ___, LSHIFT(Key_PageUp),
   Key_LeftDoubleQuoteMark, LSHIFT(Key_Q), LSHIFT(Key_L), LSHIFT(Key_U), LSHIFT(Key_C), LSHIFT(Key_J), LSHIFT(Key_PageDown),
   LSHIFT(Key_Tab), LSHIFT(Key_A), LSHIFT(Key_N), LSHIFT(Key_I), LSHIFT(Key_S), LSHIFT(Key_V),
   LSHIFT(Key_ADiaeresis), Key_Backslash, Key_Exclamation, LSHIFT(Key_Y), LSHIFT(Key_G), LSHIFT(Key_X), LSHIFT(Key_DownArrow),
   LSHIFT(Key_RightArrow), LSHIFT(Key_E), ShiftToLayer(SHIFT_SYMBOL), LSHIFT(Key_Backspace),
   // ShiftToLayer(SHIFT_SPECIAL),
   XXX,

   LSHIFT(Key_ScrollLock), ___, ___, ___, ___, LSHIFT(Key_ARing), LSHIFT(Key_PcApplication),
   LSHIFT(Key_Delete), LSHIFT(Key_K), LSHIFT(Key_P), LSHIFT(Key_M), LSHIFT(Key_W), LSHIFT(Key_Minus), Key_LeftSingleQuoteMark,
   /* none */ LSHIFT(Key_B), LSHIFT(Key_H), LSHIFT(Key_T), LSHIFT(Key_R), LSHIFT(Key_O), LSHIFT(Key_Escape),
   LSHIFT(Key_UpArrow), LSHIFT(Key_Z), LSHIFT(Key_F), LSHIFT(Key_D), Key_Colon, Key_Semicolon, LSHIFT(Key_ODiaeresis),
   LSHIFT(Key_Enter), ShiftToLayer(SHIFT_SYMBOL), LSHIFT(Key_Spacebar), LSHIFT(Key_LeftArrow),
   // ShiftToLayer(SHIFT_SPECIAL)),
   XXX),

  [SYMBOL] =  KEYMAP_STACKED
  (LockLayer(QWERTY), ___, ___, ___, ShiftToLayer(SHIFT_SYMBOL), ___, Key_LEDEffectNext,
   ___, Key_LessThan, Key_GreaterThan, Key_LeftCurlyBracket, Key_RightCurlyBracket, Key_Asterisk, Key_Insert,
   Key_Ampersand, Key_LeftBracket, Key_RightBracket, Key_LeftParen, Key_RightParen, Key_At,
   ___, Key_Tilde, Key_Backtick, Key_Quote, Key_DoubleQuote, M(MACRO_EMDASH), Key_PageDown,
   Key_End, Key_Dollar, ___, ___,
   XXX,

   M(MACRO_ANY), ___, ShiftToLayer(SHIFT_SYMBOL), ___, ___, ___, LockLayer(NUMPAD),
   Key_PrintScreen, Key_Pound, Key_7, Key_8, Key_9, Key_Caret, ___,
   /* none */ Key_Plus, Key_4, Key_5, Key_6, Key_Equals, Key_Pipe,
   Key_PageUp, M(MACRO_ENDASH), Key_1, Key_2, Key_3, Key_Percent, ___,
   ___, ___, Key_0, Key_Home,
   XXX),

  [SHIFT_SYMBOL] =  KEYMAP_STACKED
  (___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___, ___,
   LSHIFT(Key_End), ___, LSHIFT(Key_Backspace), LSHIFT(Key_PageDown),
   ___,

   ___, ___, ___, ___, ___, ___, ___,
   LSHIFT(Key_PrintScreen), ___, LSHIFT(Key_7), LSHIFT(Key_8), LSHIFT(Key_9), ___, ___,
   /* none */ ___, LSHIFT(Key_4), LSHIFT(Key_5), LSHIFT(Key_6), ___, ___,
   LSHIFT(Key_PageUp), ___, LSHIFT(Key_1), LSHIFT(Key_2), LSHIFT(Key_3), ___, ___,
   ___, LSHIFT(Key_Enter), LSHIFT(Key_0), LSHIFT(Key_Home),
   ___),

  [SPECIAL] =  KEYMAP_STACKED
  (Key_mouseWarpNW, Key_mouseWarpNE, ___, ___, ShiftToLayer(SHIFT_SPECIAL), ___, XXX,
   Key_mouseWarpSW, Key_mouseWarpSE, Key_mouseUpL, Key_mouseUp, Key_mouseUpR, Key_mouseWarpEnd, XXX,
   Key_mouseScrollL, Key_mouseScrollUp, Key_mouseL, Key_mouseBtnL, Key_mouseR, Key_mouseBtnR,
   Key_mouseScrollR, Key_mouseScrollDn, Key_mouseDnL, Key_mouseDn, Key_mouseDnR, Key_mouseBtnM, XXX,
   ___, ___, ___, ___,
   ___,

   XXX, ___, ShiftToLayer(SHIFT_SPECIAL), ___, ___, XXX, XXX,
   XXX, XXX, Key_F7, Key_F8, Key_F9, Key_F12, XXX,
   /* none */ XXX, Key_F4, Key_F5, Key_F6, Key_F11, XXX,
   XXX, XXX, Key_F1, Key_F2, Key_F3, Key_F10, XXX,
   ___, ___, ___, ___,
   ___),

  [SHIFT_SPECIAL] =  KEYMAP_STACKED
  (___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___,
   ___,

   ___, ___, ___, ___, ___, ___, ___,
   ___, ___, LSHIFT(Key_F7), LSHIFT(Key_F8), LSHIFT(Key_F9), LSHIFT(Key_F12), ___,
   /* none */ ___, LSHIFT(Key_F4), LSHIFT(Key_F5), LSHIFT(Key_F6), LSHIFT(Key_F11), ___,
   ___, ___, LSHIFT(Key_F1), LSHIFT(Key_F2), LSHIFT(Key_F3), LSHIFT(Key_F10), ___,
   ___, ___, ___, ___,
   ___),

  [QWERTY] = KEYMAP_STACKED
  (UnlockLayer(QWERTY), Key_1, Key_2, Key_3, Key_4, Key_5, Key_LEDEffectNext,
   Key_Backtick, Key_Q, Key_W, Key_E, Key_R, Key_T, Key_Tab,
   Key_PageUp,   Key_A, Key_S, Key_D, Key_F, Key_G,
   Key_PageDown, Key_Z, Key_X, Key_C, Key_V, Key_B, Key_Escape,
   Key_LeftControl, Key_Backspace, Key_LeftGui, Key_LeftShift,
   ShiftToLayer(FUNCTION),

   M(MACRO_ANY),  Key_6, Key_7, Key_8,     Key_9,         Key_0,         LockLayer(NUMPAD),
   Key_Enter,     Key_Y, Key_U, Key_I,     Key_O,         Key_P,         Key_Equals,
                  Key_H, Key_J, Key_K,     Key_L,         Key_Semicolon, Key_Quote,
   Key_RightAlt,  Key_N, Key_M, Key_Comma, Key_Period,    Key_Slash,     Key_Minus,
   Key_RightShift, Key_LeftAlt, Key_Spacebar, Key_RightControl,
   ShiftToLayer(FUNCTION)),


  [NUMPAD] =  KEYMAP_STACKED
  (___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___,
   ___,

   M(MACRO_VERSION_INFO),  ___, Key_Keypad7, Key_Keypad8,   Key_Keypad9,        Key_KeypadSubtract, LockLayer(NUMPAD),
   ___,                    ___, Key_Keypad4, Key_Keypad5,   Key_Keypad6,        Key_KeypadAdd,      ___,
                           ___, Key_Keypad1, Key_Keypad2,   Key_Keypad3,        Key_Equals,         Key_Quote,
   ___,                    ___, Key_Keypad0, Key_KeypadDot, Key_KeypadMultiply, Key_KeypadDivide,   Key_Enter,
   ___, ___, ___, ___,
   ___),

  [FUNCTION] =  KEYMAP_STACKED
  (___,      Key_F1,           Key_F2,      Key_F3,     Key_F4,        Key_F5,           XXX,
   Key_Tab,  ___,              Key_mouseUp, ___,        Key_mouseBtnR, Key_mouseWarpEnd, Key_mouseWarpNE,
   Key_Home, Key_mouseL,       Key_mouseDn, Key_mouseR, Key_mouseBtnL, Key_mouseWarpNW,
   Key_End,  Key_PrintScreen,  Key_Insert,  ___,        Key_mouseBtnM, Key_mouseWarpSW,  Key_mouseWarpSE,
   ___, Key_Delete, ___, ___,
   ___,

   Consumer_ScanPreviousTrack, Key_F6,                 Key_F7,                   Key_F8,                   Key_F9,          Key_F10,          Key_F11,
   Consumer_PlaySlashPause,    Consumer_ScanNextTrack, Key_LeftCurlyBracket,     Key_RightCurlyBracket,    Key_LeftBracket, Key_RightBracket, Key_F12,
                               Key_LeftArrow,          Key_DownArrow,            Key_UpArrow,              Key_RightArrow,  ___,              ___,
   Key_PcApplication,          Consumer_Mute,          Consumer_VolumeDecrement, Consumer_VolumeIncrement, ___,             Key_Backslash,    Key_Pipe,
   ___, ___, Key_Enter, ___,
   ___)

};

/* Re-enable astyle's indent enforcement */
// *INDENT-ON*

/** versionInfoMacro handles the 'firmware version info' macro
 *  When a key bound to the macro is pressed, this macro
 *  prints out the firmware build information as virtual keystrokes
 */

static void versionInfoMacro(uint8_t keyState) {
  if (keyToggledOn(keyState)) {
    Macros.type(PSTR("Keyboardio Model 01 - Kaleidoscope "));
    Macros.type(PSTR(BUILD_INFORMATION));
  }
}

/** anyKeyMacro is used to provide the functionality of the 'Any' key.
 *
 * When the 'any key' macro is toggled on, a random alphanumeric key is
 * selected. While the key is held, the function generates a synthetic
 * keypress event repeating that randomly selected key.
 *
 */

static void anyKeyMacro(uint8_t keyState) {
  static Key lastKey;
  if (keyToggledOn(keyState))
    lastKey.keyCode = Key_A.keyCode + (uint8_t)(millis() % 36);

  if (keyIsPressed(keyState))
    kaleidoscope::hid::pressKey(lastKey);
}

/** Input a unicode character.
 */

static void unicode(uint32_t character, uint8_t keyState) {
  if (keyToggledOn(keyState)) {
    Unicode.type(character);
  }
}


/** macroAction dispatches keymap events that are tied to a macro
    to that macro. It takes two uint8_t parameters.

    The first is the macro being called (the entry in the 'enum' earlier in this file).
    The second is the state of the keyswitch. You can use the keyswitch state to figure out
    if the key has just been toggled on, is currently pressed or if it's just been released.

    The 'switch' statement should have a 'case' for each entry of the macro enum.
    Each 'case' statement should call out to a function to handle the macro in question.

 */

const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  switch (macroIndex) {

  case MACRO_VERSION_INFO:
    versionInfoMacro(keyState);
    break;

  case MACRO_ANY:
    anyKeyMacro(keyState);
    break;

  case MACRO_ENDASH:
    unicode(0x2013, keyState);
    break;

  case MACRO_EMDASH:
    unicode(0x2014, keyState);
    break;
  }
  return MACRO_NONE;
}



/** Indicate that QWERTY is on. */

void QWERTYLEDHook(bool post_clear) {
  if (post_clear) {
    return;
  }

  if (Layer.isOn(QWERTY)) {
    LEDControl.setCrgbAt(0, 0, CRGB(255, 0, 0));
  } else {
    LEDControl.refreshAt(0, 0);
  }
}



// These 'solid' color effect definitions define a rainbow of
// LED color modes calibrated to draw 500mA or less on the
// Keyboardio Model 01.


static kaleidoscope::LEDSolidColor solidRed(160, 0, 0);
static kaleidoscope::LEDSolidColor solidOrange(140, 70, 0);
static kaleidoscope::LEDSolidColor solidYellow(130, 100, 0);
static kaleidoscope::LEDSolidColor solidGreen(0, 160, 0);
static kaleidoscope::LEDSolidColor solidBlue(0, 70, 130);
static kaleidoscope::LEDSolidColor solidIndigo(0, 0, 170);
static kaleidoscope::LEDSolidColor solidViolet(130, 0, 120);

/** toggleLedsOnSuspendResume toggles the LEDs off when the host goes to sleep,
 * and turns them back on when it wakes up.
 */
void toggleLedsOnSuspendResume(kaleidoscope::HostPowerManagement::Event event) {
  switch (event) {
  case kaleidoscope::HostPowerManagement::Suspend:
    LEDControl.paused = true;
    LEDControl.set_all_leds_to({0, 0, 0});
    LEDControl.syncLeds();
    break;
  case kaleidoscope::HostPowerManagement::Resume:
    LEDControl.paused = false;
    LEDControl.refreshAll();
    break;
  case kaleidoscope::HostPowerManagement::Sleep:
    break;
  }
}

/** hostPowerManagementEventHandler dispatches power management events (suspend,
 * resume, and sleep) to other functions that perform action based on these
 * events.
 */
void hostPowerManagementEventHandler(kaleidoscope::HostPowerManagement::Event event) {
  toggleLedsOnSuspendResume(event);
}

/** The 'setup' function is one of the two standard Arduino sketch functions.
  * It's called when your keyboard first powers up. This is where you set up
  * Kaleidoscope and any plugins.
  */

void setup() {
  // First, call Kaleidoscope's internal setup function
  Kaleidoscope.setup();

  // Next, tell Kaleidoscope which plugins you want to use.
  // The order can be important. For example, LED effects are
  // added in the order they're listed here.
  Kaleidoscope.use(
    // The boot greeting effect pulses the LED button for 10 seconds after the keyboard is first connected
    // &BootGreetingEffect,

    // The hardware test mode, which can be invoked by tapping Prog, LED and the left Fn button at the same time.
    &TestMode,

    // LEDControl provides support for other LED modes
    &LEDControl,

    // We start with the LED effect that turns off all the LEDs.
    &LEDOff,

    // The rainbow effect changes the color of all of the keyboard's keys at the same time
    // running through all the colors of the rainbow.
    &LEDRainbowEffect,

    // The rainbow wave effect lights up your keyboard with all the colors of a rainbow
    // and slowly moves the rainbow across your keyboard
    &LEDRainbowWaveEffect,

    // The chase effect follows the adventure of a blue pixel which chases a red pixel across
    // your keyboard. Spoiler: the blue pixel never catches the red pixel
    &LEDChaseEffect,

    // These static effects turn your keyboard's LEDs a variety of colors
    &solidRed, &solidOrange, &solidYellow, &solidGreen, &solidBlue, &solidIndigo, &solidViolet,

    // The breathe effect slowly pulses all of the LEDs on your keyboard
    &LEDBreatheEffect,

    // The AlphaSquare effect prints each character you type, using your
    // keyboard's LEDs as a display
    &AlphaSquareEffect,

    // The stalker effect lights up the keys you've pressed recently
    &StalkerEffect,

    // The numpad plugin is responsible for lighting up the 'numpad' mode
    // with a custom LED effect
    &NumPad,

    // The macros plugin adds support for macros
    &Macros,

    // The MouseKeys plugin lets you add keys to your keymap which move the mouse.
    &MouseKeys,

    // The HostPowerManagement plugin enables waking up the host from suspend,
    // and allows us to turn LEDs off when it goes to sleep.
    &HostPowerManagement,

    // Unicode character input
    &Unicode
  );

  // Register the loop hook defined above.
  Kaleidoscope.useLoopHook(QWERTYLEDHook);

  // While we hope to improve this in the future, the NumPad plugin
  // needs to be explicitly told which keymap layer is your numpad layer
  NumPad.numPadLayer = NUMPAD;

  // We configure the AlphaSquare effect to use RED letters
  AlphaSquare.color = { 255, 0, 0 };

  // We set the brightness of the rainbow effects to 150 (on a scale of 0-255)
  // This draws more than 500mA, but looks much nicer than a dimmer effect
  LEDRainbowEffect.brightness(150);
  LEDRainbowWaveEffect.brightness(150);

  // The LED Stalker mode has a few effects. The one we like is
  // called 'BlazingTrail'. For details on other options,
  // see https://github.com/keyboardio/Kaleidoscope-LED-Stalker
  StalkerEffect.variant = STALKER(BlazingTrail);

  // We want the keyboard to be able to wake the host up from suspend.
  HostPowerManagement.enableWakeup();

  // We want to make sure that the firmware starts with LED effects off
  // This avoids over-taxing devices that don't have a lot of power to share
  // with USB devices
  LEDOff.activate();
}

/** loop is the second of the standard Arduino sketch functions.
  * As you might expect, it runs in a loop, never exiting.
  *
  * For Kaleidoscope-based keyboard firmware, you usually just want to
  * call Kaleidoscope.loop(); and not do anything custom here.
  */

void loop() {
  Kaleidoscope.loop();
}
