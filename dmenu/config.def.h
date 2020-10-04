/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar = 1;                      /* -b  option; if 0, dmenu appears at bottom     */
/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = {
	"SF Text Pro:size=5"
};
static const char *prompt      = NULL;      /* -p  option; prompt to the left of input field */
static const char *colors[SchemeLast][2] = {
	/*     fg         bg       */
  [SchemeNorm] = { "#c6c6c6", "#212121" },
  [SchemeSel] = { "#4184f3", "#212121" },
	[SchemeOut] = { "#ff0000", "#ff0000" },
  // >>>>>>>>>>>>>>>>>>>> fuzzyhighlight
  // ==================== fuzzyhighlight
  // <<<<<<<<<<<<<<<<<<<< fuzzyhighlight
  // >>>>>>>>>>>>>>>>>>>> more-color
  // ==================== more-color
  // <<<<<<<<<<<<<<<<<<<< more-color
  // >>>>>>>>>>>>>>>>>>>> high-priority
  // ==================== high-priority
  // <<<<<<<<<<<<<<<<<<<< high-priority
  // >>>>>>>>>>>>>>>>>>>> highlight
  [SchemeSelHighlight] = { "#a3be8c", "#212121" },
  [SchemeNormHighlight] = { "#d75f5f", "#222222" },
  // <<<<<<<<<<<<<<<<<<<< highlight
};
/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines      = 0;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";

// >>>>>>>>>>>>>>>>>>>> border
/* Size of the window border */
static unsigned int border_width = 1;
// <<<<<<<<<<<<<<<<<<<< border

// >>>>>>>>>>>>>>>>>>>> center
// ==================== center
// <<<<<<<<<<<<<<<<<<<< center

// >>>>>>>>>>>>>>>>>>>> dynamic-options
// ==================== dynamic-options
// <<<<<<<<<<<<<<<<<<<< dynamic-options

// >>>>>>>>>>>>>>>>>>>> fuzzymatch
// ==================== fuzzymatch
// <<<<<<<<<<<<<<<<<<<< fuzzymatch

// >>>>>>>>>>>>>>>>>>>> grid
// ==================== grid
// <<<<<<<<<<<<<<<<<<<< grid

// >>>>>>>>>>>>>>>>>>>> incremental
// ==================== incremental
// <<<<<<<<<<<<<<<<<<<< incremental

// >>>>>>>>>>>>>>>>>>>> preselect
// ==================== preselect
// <<<<<<<<<<<<<<<<<<<< preselect

// >>>>>>>>>>>>>>>>>>>> pipeout
// ==================== pipeout
// <<<<<<<<<<<<<<<<<<<< pipeout

// >>>>>>>>>>>>>>>>>>>> prefix-completition
// ==================== prefix-completition
// <<<<<<<<<<<<<<<<<<<< prefix-completition

// >>>>>>>>>>>>>>>>>>>> instant
// ==================== instant
// <<<<<<<<<<<<<<<<<<<< instant

// >>>>>>>>>>>>>>>>>>>> symbols
// ==================== symbols
// <<<<<<<<<<<<<<<<<<<< symbols

// >>>>>>>>>>>>>>>>>>>> navhistory
// ==================== navhistory
// <<<<<<<<<<<<<<<<<<<< navhistory

// >>>>>>>>>>>>>>>>>>>> line-height
static unsigned int lineheight = 0;         /* -lh option; minimum height of a menu line     */
// <<<<<<<<<<<<<<<<<<<< line-height
