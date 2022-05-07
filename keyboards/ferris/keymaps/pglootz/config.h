// Copyright 2021-2022 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#define USE_SERIAL
#define SPLIT_USB_DETECT
#define MASTER_RIGHT

#define BILATERAL_COMBINATIONS

#define TAPPING_TERM 150 
#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD
#define TAPPING_FORCE_HOLD_PER_KEY

#define ONESHOT_TAP_TOGGLE 2

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

// Use Left Ctrl + Right Ctrl to activate the Command feature.
#define IS_COMMAND() (get_mods() == MOD_MASK_CTRL)

// When idle, turn off Caps Word after 5 seconds.
#define CAPSWORD_USE_SHIFT

#define COMBO_COUNT 4
