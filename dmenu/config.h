/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar = 0;                      /* -b  option; if 0, dmenu appears at bottom     */
static int fuzzy = 1;
static int centered = 1;                    /* -c option; centers dmenu on screen */
static int min_width = 400;                    /* minimum width when centered */
static unsigned int border_width = 1; /* size of the window border */
/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = {
	"SF Text Pro:size=10"
};
static const char *prompt      = NULL;      /* -p  option; prompt to the left of input field */
	static const char *colors[SchemeLast][2] = {
	/*     				fg         bg       */
	[SchemeNorm] = { "#c6c6c6", "#282828" },
	[SchemeSel] = { "#282828", "#6699cc" },
	[SchemeSelHighlight] = { "#c6c6c6", "#6699cc" },
	[SchemeNormHighlight] = { "#d75f5f", "#222222" },
	[SchemeOut] = { "#ff0000", "#ff0000" },
};
/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines      = 10;
/* -h option; minimum height of a menu line */
static unsigned int lineheight = 18;
static unsigned int min_lineheight = 8;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";
