/* See LICENSE file for copyright and license details. */

#include <X11/XF86keysym.h> // media keys

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int gappx     = 0;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 1;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int savefloats         = 1;        /* 0 means default behaviour, 1 = savefloats patch */
static const int attachmode         = 2;        /* 0 master (default), 1 = above, 2 = aside, 3 = below, 4 = bottom */
static const int usealtbar          = 1;        /* 1 means use non-dwm status bar */
static const char *altbarclass      = "Polybar"; /* Alternate bar class name */
static const char *alttrayname      = "tray";    /* Polybar tray instance name */
static const char *altbarcmd        = "$HOME/.config/polybar/launch.sh"; /* Alternate bar launch command */
static const char *fonts[]          = {
    "noto:size=14",
	"Font Awesome 5 Free Regular-12",
	"Font Awesome 5 Free Solid-12"
};
static const char dmenufont[]       = "noto:size=14";
static const char col_gray1[]            = "#141414";
static const char col_gray2[]            = "#505050";
static const char col_gray3[]            = "#353535";
static const char col_gray4[]            = "#c6c6c6";
static const char col_gray5[]            = "#fffefe";
static const char col_gray6[]            = "#292929";
static const char col_gray7[]            = "#212121";
static const char col_cyan[]             = "#7e9cb9";
static const char col_blue[]             = "#6699cc";
static const char *colors[][3]      = {
    /*               fg         bg         border   */
    [SchemeNorm] = { col_gray4, col_gray1, col_gray6 },
    [SchemeSel]  = { col_gray5, col_gray6, col_blue },
};

/* tagging */
static const char *tags[] = { "", "", "", "", "", "", "", "", "", "" };

static const Rule rules[] = {
    /* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
   /* class      instance    title       tags mask     switchtotag    isfloating   monitor */
   { "qutebrowser",NULL,      NULL,       1,            1,             0,           -1 },
   { "firefox",    NULL,      NULL,       1,            1,             0,           -1 },
   { "St",         NULL,      NULL,       1 << 1,       1,             0,           -1 },
   { "ncmpcpp",    NULL,      NULL,       1 << 3,       1,             0,           -1 },
   { "Transmission-gtk", NULL, NULL,      1 << 2,       1,             0,           -1 },
   { "SoulsekkQt", NULL,      NULL,       1 << 2,       1,             0,           -1 },
   { "Thunar",     NULL,      NULL,       1 << 4,       1,             0,           -1 },
   { "File-roller", NULL,     NULL,       1 << 4,       1,             1,           -1 },
   { "Subl3",      NULL,      NULL,       1 << 6,       1,             0,           -1 },
   { "Easytag",    NULL,      NULL,       1 << 8,       1,             0,           -1 },
   { "Xfce4-taskmanager", NULL, NULL,     1 << 9,       1,             0,           -1 },
   { "Slack",      NULL,      NULL,       1 << 6,       1,             0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

/*#include "fibonacci.c"*/
static const Layout layouts[] = {
    /* symbol     arrange function */
    { "󰕴",     dwindle },    /* first entry is default */
    { "󰃚",     monocle },
    { "󰡃",     spiral },
    { "󰕰",     tile },
    { "><>",    NULL },    /* no layout function means floating behavior */
    { NULL,     NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2]         = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *munext[]  = { "/usr/bin/mpc", "next", NULL };
static const char *muprev[]  = { "/usr/bin/mpc", "prev", NULL };
static const char *mupause[]  = { "/usr/bin/mpc", "toggle", NULL };
static const char *scrotcmd[] = {"teiler", NULL};
static const char *browsercmd[] = { "firefox", NULL };
static const char *termcmd[]    = { "st", NULL };
static const char *dmenucmd[] = { "dmenu_run_history", NULL };
static const char *roficmd[] = { "rofi", "-show", "drun", "-show-icons", NULL };
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-g", "120x34", NULL };
static const char *exitcmd[] = { "/usr/bin/stop.sh", NULL };
static const char *editcmd[] = { "subl3", NULL };
static const char *filecmd[] = { "thunar", NULL };

#include <X11/XF86keysym.h>
static Key keys[] = {
    /* modifier                     key                    function                   argument */
  { 0, XF86XK_AudioMute,                                  spawn,               SHCMD("amixer sset Master toggle") },
  { 0, XF86XK_AudioRaiseVolume,                           spawn,               SHCMD("/usr/bin/volume up") },
  { 0, XF86XK_AudioLowerVolume,                           spawn,               SHCMD("/usr/bin/volume down") },
  { 0, XF86XK_AudioPrev,                                  spawn,               {.v = muprev } },
  { 0, XF86XK_AudioNext,                                  spawn,               {.v = munext } },
  { 0, XF86XK_AudioPause,                                 spawn,               {.v = mupause } },
  { 0, XF86XK_AudioPlay,                                  spawn,               {.v = mupause } },
  { 0, XF86XK_AudioStop,                                  spawn,               {.v = mupause } },
  { 0, XF86XK_AudioRewind,                                spawn,               SHCMD("mpc seek -10") },
  { 0, XF86XK_AudioForward,                               spawn,               SHCMD("mpc seek +10") },
  { MODKEY,                       XK_l,                   spawn,               SHCMD("slock") },
  { MODKEY,                       XK_w,                   spawn,               {.v = browsercmd } },
  { MODKEY,                       XK_f,                   spawn,               {.v = filecmd } },
  { 0,                            XK_Print,               spawn,               {.v = scrotcmd } },
  { MODKEY,                       XK_space,               spawn,               {.v = roficmd } },
  { MODKEY,                       XK_d,                   spawn,               {.v = dmenucmd } },
  { MODKEY,                       XK_t,                   spawn,               {.v = termcmd } },
  { MODKEY,                       XK_grave,               togglescratch,       {.v = scratchpadcmd } },
  { MODKEY,                       XK_x,                   spawn,               {.v = exitcmd } },
  { MODKEY,                       XK_e,                   spawn,               {.v = editcmd } },
  { MODKEY|ShiftMask,             XK_p,                   spawn,               SHCMD("rofi -modi \"clipboard:greenclip print\" -show clipboard -run-command '{cmd}'") },
  { MODKEY,                       XK_m,                   spawn,               SHCMD("st -c ncmpcpp -e ncmpcpp") },
  { MODKEY,                       XK_Tab,                 focusstack,          {.i = +1 } },
  { MODKEY,                       XK_b,                   togglebar,           {0} },
  { MODKEY,                       XK_j,                   focusstack,          {.i = +1 } },
  { MODKEY,                       XK_k,                   focusstack,          {.i = -1 } },
  { MODKEY,                       XK_i,                   incnmaster,          {.i = +1 } },
  { MODKEY|ShiftMask,             XK_d,                   incnmaster,          {.i = -1 } },
  { MODKEY,                       XK_h,                   setmfact,            {.f = -0.05} },
  { MODKEY,                       XK_l,                   setmfact,            {.f = +0.05} },
  { MODKEY,                       XK_Return,              zoom,                {0} },
  { MODKEY,                       XK_q,                   killclient,          {0} },
  { MODKEY|ShiftMask,             XK_t,                   setlayout,           {.v = &layouts[0]} },
  { MODKEY|ShiftMask,             XK_f,                   setlayout,           {.v = &layouts[1]} },
  { MODKEY|ShiftMask,             XK_m,                   setlayout,           {.v = &layouts[2]} },
  { MODKEY|ControlMask,           XK_r,                   setlayout,           {.v = &layouts[3]} },
  { MODKEY|ShiftMask,             XK_r,                   setlayout,           {.v = &layouts[4]} },
  { MODKEY|ShiftMask,             XK_space,               togglefloating,      {0} },
  { MODKEY|ShiftMask,             XK_j,                   rotatestack,         {.i = +1 } },
  { MODKEY|ShiftMask,             XK_k,                   rotatestack,         {.i = -1 } },
  { MODKEY|ControlMask,           XK_0,                   view,                {.ui = ~0 } },
  { MODKEY|ShiftMask,             XK_0,                   tag,                 {.ui = ~0 } },
  { MODKEY,                       XK_comma,               focusmon,            {.i = -1 } },
  { MODKEY,                       XK_period,              focusmon,            {.i = +1 } },
  { MODKEY|ShiftMask,             XK_comma,               tagmon,              {.i = -1 } },
  { MODKEY|ShiftMask,             XK_period,              tagmon,              {.i = +1 } },
	{ MODKEY|Mod4Mask,              XK_u,                   incrgaps,            {.i = +1 } },
  { MODKEY|Mod4Mask|ShiftMask,    XK_u,                   incrgaps,            {.i = -1 } },
  { MODKEY|Mod4Mask,              XK_i,                   incrigaps,           {.i = +1 } },
  { MODKEY|Mod4Mask|ShiftMask,    XK_i,                   incrigaps,           {.i = -1 } },
  { MODKEY|Mod4Mask,              XK_o,                   incrogaps,           {.i = +1 } },
  { MODKEY|Mod4Mask|ShiftMask,    XK_o,                   incrogaps,           {.i = -1 } },
  { MODKEY|Mod4Mask,              XK_6,                   incrihgaps,          {.i = +1 } },
  { MODKEY|Mod4Mask|ShiftMask,    XK_6,                   incrihgaps,          {.i = -1 } },
  { MODKEY|Mod4Mask,              XK_7,                   incrivgaps,          {.i = +1 } },
  { MODKEY|Mod4Mask|ShiftMask,    XK_7,                   incrivgaps,          {.i = -1 } },
  { MODKEY|Mod4Mask,              XK_8,                   incrohgaps,          {.i = +1 } },
  { MODKEY|Mod4Mask|ShiftMask,    XK_8,                   incrohgaps,          {.i = -1 } },
  { MODKEY|Mod4Mask,              XK_9,                   incrovgaps,          {.i = +1 } },
  { MODKEY|Mod4Mask|ShiftMask,    XK_9,                   incrovgaps,          {.i = -1 } },
  { MODKEY|Mod4Mask,              XK_0,                   togglegaps,          {0} },
  { MODKEY|Mod4Mask|ShiftMask,    XK_0,                   defaultgaps,         {0} },
    TAGKEYS(                      XK_1,                                        0)
    TAGKEYS(                      XK_2,                                        1)
    TAGKEYS(                      XK_3,                                        2)
    TAGKEYS(                      XK_4,                                        3)
    TAGKEYS(                      XK_5,                                        4)
    TAGKEYS(                      XK_6,                                        5)
    TAGKEYS(                      XK_7,                                        6)
    TAGKEYS(                      XK_8,                                        7)
    TAGKEYS(                      XK_9,                                        8)
    TAGKEYS(                      XK_0,                                        9)
    { MODKEY|ShiftMask,           XK_q,                   quit,                {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
    /* click                event mask      button          function        argument */
    { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
    { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
    { ClkWinTitle,          0,              Button2,        zoom,           {0} },
    { ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
    { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
    { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
    { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
    { ClkClientWin,         MODKEY,         Button4,        rotatestack,    {.i = +1 } },
    { ClkClientWin,         MODKEY,         Button5,        rotatestack,    {.i = -1 } },
    { ClkTagBar,            0,              Button1,        view,           {0} },
    { ClkTagBar,            0,              Button3,        toggleview,     {0} },
    { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
    { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

static const char *ipcsockpath = "/tmp/dwm.sock";
static IPCCommand ipccommands[] = {
  IPCCOMMAND(  view,                1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  toggleview,          1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  tag,                 1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  toggletag,           1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  tagmon,              1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  focusmon,            1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  focusstack,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  zoom,                1,      {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  incnmaster,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  killclient,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  togglefloating,      1,      {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  setmfact,            1,      {ARG_TYPE_FLOAT}  ),
  IPCCOMMAND(  setlayoutsafe,       1,      {ARG_TYPE_PTR}    ),
  IPCCOMMAND(  quit,                1,      {ARG_TYPE_NONE}   )
};
