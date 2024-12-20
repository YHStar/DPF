#pragma once

/**
   This file contains C Macros that describe this plugin.
   With these macros we can tell the host what features the plugin requires.
   New functions will be available to call and/or override depending on which macros are enabled.

   All values are either integer or strings.
   For boolean-like values 1 means 'on' and 0 means 'off'.
 */

/**
   The plugin name.
   This is used to identify your plugin before a Plugin instance can be created.
   @note This macro is required.
 */
#define DISTRHO_PLUGIN_NAME "CairoUI"

/**
   Number of audio inputs the plugin has.
   @note This macro is required.
 */
#define DISTRHO_PLUGIN_NUM_INPUTS 1

/**
   Number of audio outputs the plugin has.
   @note This macro is required.
 */
#define DISTRHO_PLUGIN_NUM_OUTPUTS 1

/**
   The plugin URI when exporting in LV2 format.
   TODO describe what a URI is
   @note This macro is required.
 */
#define DISTRHO_PLUGIN_URI "http://distrho.sf.net/examples/CairoUI"

/**
   Whether the plugin has a custom UI.
 */
#define DISTRHO_PLUGIN_HAS_UI 1

/**
   Whether the plugin processing is realtime-safe.
   TODO - list rtsafe requirements
 */
#define DISTRHO_PLUGIN_IS_RT_SAFE 1

/**
   Whether the plugin is a synth.
   @ref DISTRHO_PLUGIN_WANT_MIDI_INPUT is automatically enabled when this is too.
   @see DISTRHO_PLUGIN_WANT_MIDI_INPUT
 */
// #define DISTRHO_PLUGIN_IS_SYNTH 0

/**
   Request the minimum buffer size for the input and output event ports.
   Currently only used in LV2, with a default value of 2048 if unset.
 */
// #define DISTRHO_PLUGIN_MINIMUM_BUFFER_SIZE 2048

/**
   Whether the plugin has an LV2 modgui.

   This will simply add a "rdfs:seeAlso <modgui.ttl>" on the LV2 manifest.
   It is up to you to create this file.
 */
// #define DISTRHO_PLUGIN_USES_MODGUI 0

/**
   Enable direct access between the UI and plugin code.
   @see UI::getPluginInstancePointer()
   @note DO NOT USE THIS UNLESS STRICTLY NECESSARY!!
         Try to avoid it at all costs!
 */
// #define DISTRHO_PLUGIN_WANT_DIRECT_ACCESS 0

/**
   Whether the plugin introduces latency during audio or midi processing.
   @see Plugin::setLatency(uint32_t)
 */
// #define DISTRHO_PLUGIN_WANT_LATENCY 0

/**
   Whether the plugin wants MIDI input.
   This is automatically enabled if @ref DISTRHO_PLUGIN_IS_SYNTH is true.
 */
// #define DISTRHO_PLUGIN_WANT_MIDI_INPUT 0

/**
   Whether the plugin wants MIDI output.
   @see Plugin::writeMidiEvent(const MidiEvent&)
 */
// #define DISTRHO_PLUGIN_WANT_MIDI_OUTPUT 0

/**
   Whether the plugin wants to change its own parameter inputs.
   Not all hosts or plugin formats support this,
   so Plugin::canRequestParameterValueChanges() can be used to query support at runtime.
   @see Plugin::requestParameterValueChange(uint32_t, float)
 */
// #define DISTRHO_PLUGIN_WANT_PARAMETER_VALUE_CHANGE_REQUEST 0

/**
   Whether the plugin provides its own internal programs.
   @see Plugin::initProgramName(uint32_t, String&)
   @see Plugin::loadProgram(uint32_t)
 */
// #define DISTRHO_PLUGIN_WANT_PROGRAMS 0

/**
   Whether the plugin uses internal non-parameter data.
   @see Plugin::initState(uint32_t, String&, String&)
   @see Plugin::setState(const char*, const char*)
 */
// #define DISTRHO_PLUGIN_WANT_STATE 0

/**
   Whether the plugin implements the full state API.
   When this macro is enabled, the plugin must implement a new getState(const char* key) function, which the host calls when saving its session/project.
   This is useful for plugins that have custom internal values not exposed to the host as key-value state pairs or parameters.
   Most simple effects and synths will not need this.
   @note this macro is automatically enabled if a plugin has programs and state, as the key-value state pairs need to be updated when the current program changes.
   @see Plugin::getState(const char*)
 */
// #define DISTRHO_PLUGIN_WANT_FULL_STATE 0

/**
   Whether the plugin wants time position information from the host.
   @see Plugin::getTimePosition()
 */
// #define DISTRHO_PLUGIN_WANT_TIMEPOS 0

/**
   Whether the UI uses Cairo for drawing instead of the default OpenGL mode.
   When enabled your UI instance will subclass CairoTopLevelWidget instead of TopLevelWidget.
 */
#define DISTRHO_UI_USE_CAIRO 1

/**
   Whether the UI uses a custom toolkit implementation based on OpenGL.
   When enabled, the macros DISTRHO_UI_CUSTOM_INCLUDE_PATH and DISTRHO_UI_CUSTOM_WIDGET_TYPE are required.
 */
// #define DISTRHO_UI_USE_CUSTOM 0

/**
   The include path to the header file used by the custom toolkit implementation.
   This path must be relative to dpf/distrho/DistrhoUI.hpp
 */
// #define DISTRHO_UI_CUSTOM_INCLUDE_PATH

/**
   The top-level-widget typedef to use for the custom toolkit.
   This widget class MUST be a subclass of DGL TopLevelWindow class.
   It is recommended that you keep this widget class inside the DGL namespace,
   and define widget type as e.g. DGL_NAMESPACE::MyCustomTopLevelWidget.
 */
// #define DISTRHO_UI_CUSTOM_WIDGET_TYPE

/**
   Whether the %UI uses NanoVG for drawing instead of the default raw OpenGL mode.@n
   When enabled your %UI instance will subclass NanoTopLevelWidget instead of TopLevelWidget.
 */
// #define DISTRHO_UI_USE_NANOVG 0

/**
   Default UI width to use when creating initial and temporary windows.
   Setting this macro allows to skip a temporary UI from being created in certain VST2 and VST3 hosts.
   (which would normally be done for knowing the UI size before host creates a window for it)

   Value must match 1x scale factor.

   When this macro is defined, the companion DISTRHO_UI_DEFAULT_HEIGHT macro must be defined as well.
 */
#define DISTRHO_UI_DEFAULT_WIDTH 200

/**
   Default UI height to use when creating initial and temporary windows.
   Setting this macro allows to skip a temporary UI from being created in certain VST2 and VST3 hosts.
   (which would normally be done for knowing the UI size before host creates a window for it)

   Value must match 1x scale factor.

   When this macro is defined, the companion DISTRHO_UI_DEFAULT_WIDTH macro must be defined as well.
 */
#define DISTRHO_UI_DEFAULT_HEIGHT 200

/**
   Whether the UI is resizable to any size by the user and OS.
   By default this is false, with resizing only allowed when coded from the the plugin UI side.
   Enabling this options makes it possible for the user to resize the plugin UI at anytime.
   @see UI::setGeometryConstraints(uint, uint, bool, bool)
 */
// #define DISTRHO_UI_USER_RESIZABLE 0

/**
   Whether to UI is going to use file browser dialogs.
   By default this is false, with the file browser APIs not available for use.
 */
// #define DISTRHO_UI_FILE_BROWSER 0

/**
   Whether to UI is going to use web browser views.
   By default this is false, with the web browser APIs not available for use.
 */
// #define DISTRHO_UI_WEB_VIEW 0

/**
   The UI URI when exporting in LV2 format.
   By default this is set to @ref DISTRHO_PLUGIN_URI with "#UI" as suffix.
 */
// #define DISTRHO_UI_URI DISTRHO_PLUGIN_URI "#UI"

/**
   The AudioUnit type for a plugin.
   This is a 4-character symbol, automatically set by DPF based on other plugin macros.
   See https://developer.apple.com/documentation/audiotoolbox/1584142-audio_unit_types for more information.
 */
// #define DISTRHO_PLUGIN_AU_TYPE aufx

/**
   A 4-character symbol that identifies a brand or manufacturer, with at least one non-lower case character.
   Plugins from the same brand should use the same symbol.
   @note This macro is required when building AU plugins, and used for VST3 if present
   @note Setting this macro will change the uid of a VST3 plugin.
         If you already released a DPF-based VST3 plugin make sure to also enable DPF_VST3_DONT_USE_BRAND_ID
 */
#define DISTRHO_PLUGIN_BRAND_ID Dstr

/**
   A 4-character symbol which identifies a plugin.
   It must be unique within at least a set of plugins from the brand.
   @note This macro is required when building AU plugins
 */
#define DISTRHO_PLUGIN_UNIQUE_ID dCai

/**
   Custom LV2 category for the plugin.
   This is a single string, and can be one of the following values:

      - lv2:AllpassPlugin
      - lv2:AmplifierPlugin
      - lv2:AnalyserPlugin
      - lv2:BandpassPlugin
      - lv2:ChorusPlugin
      - lv2:CombPlugin
      - lv2:CompressorPlugin
      - lv2:ConstantPlugin
      - lv2:ConverterPlugin
      - lv2:DelayPlugin
      - lv2:DistortionPlugin
      - lv2:DynamicsPlugin
      - lv2:EQPlugin
      - lv2:EnvelopePlugin
      - lv2:ExpanderPlugin
      - lv2:FilterPlugin
      - lv2:FlangerPlugin
      - lv2:FunctionPlugin
      - lv2:GatePlugin
      - lv2:GeneratorPlugin
      - lv2:HighpassPlugin
      - lv2:InstrumentPlugin
      - lv2:LimiterPlugin
      - lv2:LowpassPlugin
      - lv2:MIDIPlugin
      - lv2:MixerPlugin
      - lv2:ModulatorPlugin
      - lv2:MultiEQPlugin
      - lv2:OscillatorPlugin
      - lv2:ParaEQPlugin
      - lv2:PhaserPlugin
      - lv2:PitchPlugin
      - lv2:ReverbPlugin
      - lv2:SimulatorPlugin
      - lv2:SpatialPlugin
      - lv2:SpectralPlugin
      - lv2:UtilityPlugin
      - lv2:WaveshaperPlugin

   See http://lv2plug.in/ns/lv2core for more information.
 */
#define DISTRHO_PLUGIN_LV2_CATEGORY "lv2:UtilityPlugin"

/**
   Custom VST3 categories for the plugin.
   This is a single concatenated string of categories, separated by a @c |.

   Each effect category can be one of the following values:

      - Fx
      - Fx|Ambisonics
      - Fx|Analyzer
      - Fx|Delay
      - Fx|Distortion
      - Fx|Dynamics
      - Fx|EQ
      - Fx|Filter
      - Fx|Instrument
      - Fx|Instrument|External
      - Fx|Spatial
      - Fx|Generator
      - Fx|Mastering
      - Fx|Modulation
      - Fx|Network
      - Fx|Pitch Shift
      - Fx|Restoration
      - Fx|Reverb
      - Fx|Surround
      - Fx|Tools

   Each instrument category can be one of the following values:

      - Instrument
      - Instrument|Drum
      - Instrument|External
      - Instrument|Piano
      - Instrument|Sampler
      - Instrument|Synth
      - Instrument|Synth|Sampler

   And extra categories possible for any plugin type:

      - Mono
      - Stereo
 */
#define DISTRHO_PLUGIN_VST3_CATEGORIES "Fx|Tools|Mono"

/**
   Custom CLAP features for the plugin.
   This is a list of features defined as a string array body, without the terminating @c , or nullptr.

   A top-level category can be set as feature and be one of the following values:

      - instrument
      - audio-effect
      - note-effect
      - analyzer

   The following sub-categories can also be set:

      - synthesizer
      - sampler
      - drum
      - drum-machine

      - filter
      - phaser
      - equalizer
      - de-esser
      - phase-vocoder
      - granular
      - frequency-shifter
      - pitch-shifter

      - distortion
      - transient-shaper
      - compressor
      - limiter

      - flanger
      - chorus
      - delay
      - reverb

      - tremolo
      - glitch

      - utility
      - pitch-correction
      - restoration

      - multi-effects

      - mixing
      - mastering

   And finally the following audio capabilities can be set:

      - mono
      - stereo
      - surround
      - ambisonic
*/
#define DISTRHO_PLUGIN_CLAP_FEATURES "audio-effect", "utility", "mono"

/**
   The plugin id when exporting in CLAP format, in reverse URI form.
   @note This macro is required when building CLAP plugins
*/
#define DISTRHO_PLUGIN_CLAP_ID "studio.kx.distrho.examples.cairo-ui"

enum Parameters {
   kParameterKnob,
   kParameterTriState,
   kParameterButton,
   kParameterCount
};
