/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int gappx     = 10;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 20;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 30;       /* vert outer gap between windows and screen edge */
static const int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int usealtbar          = 1;        /* 1 means use non-dwm status bar */
static const char *altbarclass      = "Polybar"; /* Alternate bar class name */
static const char *alttrayname      = "tray";    /* Polybar tray instance name */
static const Bool viewontag         = False;     /* Switch view on tag switch */
static const int horizpadbar        = 2;        /* horizontal padding for statusbar */
static const int vertpadbar         = 21;        /* vertical padding for statusbar */
static const char *fonts[]          = { "Liberation Mono:size=9",
                                        "Material Icons:size=14" };
static const char dmenufont[]       = "monospace:size=10";
static char normbgcolor[]           = "#222222";
static char normbordercolor[]       = "#444444";
static char normfgcolor[]           = "#bbbbbb";
static char selfgcolor[]            = "#eeeeee";
static char selbordercolor[]        = "#7e9cb9";
static char selbgcolor[]            = "#7e9cb9";
static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
	   [SchemeTitle]  = { normfgcolor, normbgcolor, normbordercolor  },
};

/* Xresources file location */
static const char *xres = "$HOME/.Xresources";

/* tagging */
static const char *tags[] = { "", "", "", "", "", "", "", "", "", "" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class        instance    title               tags mask   switchtotag  isfloating   isterminal  noswallow   monitor */
    { "firefox",      NULL,       NULL,               1,	       	1,			 0,           0,          0,          -1 },
    { "Surf",		  NULL,       NULL,               1,	       	1,			 0,           0,          0,          -1 },
    { "st",		      NULL,       NULL,               1 << 1,      	1,			 0,           0,          0,          -1 },
    { "ncmpcpp",   	  NULL,       NULL,               1 << 1,     	1,			 0,           0,          0,          -1 },
    { "Transmission-gtk", NULL,   NULL,               1 << 2,       1,			 0,           0,          0,          -1 },
    { "SoulseekQt",   NULL,   	  NULL,               1 << 2,       1,			 0,           0,          0,          -1 },
    { "Thunar", 	  NULL,		  NULL,               1 << 4,       1,			 0,           0,          0,          -1 },
    { "File-roller",  NULL,		  NULL,               1 << 4,       1,			 0,           0,          0,          -1 },
    { "Subl3", 		  NULL,       NULL,               1 << 6,       1,			 0,           0,          0,          -1 },
	{ "Easytag",      NULL,       NULL,               1 << 8,       1,			 0,           1,          0,          -1 },
	{ "Xfce4-taskmanager", NULL,  NULL,               1 << 9,       1,			 0,           1,          0,          -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

 static const Layout layouts[] = {
 	/* symbol     arrange function */
 	{ "[]=",      tile },    /* first entry is default */
 	{ "[M]",      monocle },
	{ "[@]",      spiral },
	{ "[\\]",     dwindle },
	{ "H[]",      deck },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
	{ "HHH",      grid },
	{ "###",      nrowgrid },
	{ "---",      horizgrid },
	{ ":::",      gaplessgrid },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ NULL,       NULL },
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
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run_history", NULL };
static const char *termcmd[]  = { "st", NULL };
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-g", "120x34", NULL };
static const char *browsercmd[] = { "firefox", NULL };
static const char *altbrowsercmd[] = { "surf", NULL };
static const char *exitcmd[] = { "/usr/bin/stop.sh", NULL };
static const char *editcmd[] = { "subl3", NULL };
static const char *filecmd[] = { "thunar", NULL };
static const char *munext[]  = { "/usr/bin/mpc", "next", NULL };
static const char *muprev[]  = { "/usr/bin/mpc", "prev", NULL };
static const char *mupause[]  = { "/usr/bin/mpc", "toggle", NULL };
static const char *scrotcmd[] = {"/usr/bin/scr", NULL};

#include <X11/XF86keysym.h>
#include "movestack.c"
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY,						XK_space,  spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_t, 	   spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_grave,  togglescratch,  {.v = scratchpadcmd } },
	{ MODKEY|ControlMask|ShiftMask, XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY|ControlMask,           XK_r,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_h,      setcfact,       {.f = +0.25} },
	{ MODKEY|ShiftMask,             XK_l,      setcfact,       {.f = -0.25} },
	{ MODKEY|ShiftMask,             XK_o,      setcfact,       {.f =  0.00} },
//	{ MODKEY,                       XK_Return, zoom,           {0} },
//	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,             		    XK_q,      killclient,     {0} },
	{ MODKEY|ShiftMask,             XK_t,      setlayout,      {.v = &layouts[0]} },
//	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ControlMask,           XK_f,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_g,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_r,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY|ShiftMask,             XK_r,      setlayout,      {.v = &layouts[4]} },
//	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_s,      togglesticky,   {0} },
	{ MODKEY,                       XK_Tab,    view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_Tab,    tag,            {.ui = ~0 } },
	{ MODKEY|ControlMask,           XK_j,      focusmon,       {.i = -1 } },
	{ MODKEY|ControlMask,           XK_k,      focusmon,       {.i = +1 } },
	{ MODKEY|ControlMask|ShiftMask, XK_j,      tagmon,         {.i = -1 } },
	{ MODKEY|ControlMask|ShiftMask, XK_k,      tagmon,         {.i = +1 } },
//	{ MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
//	{ MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },
//	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
	{ MODKEY,                       XK_F5,     xrdb,           {.v = NULL } },
	{ MODKEY|Mod4Mask,              XK_u,      incrgaps,       {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_u,      incrgaps,       {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_i,      incrigaps,      {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_i,      incrigaps,      {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_o,      incrogaps,      {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_o,      incrogaps,      {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_6,      incrihgaps,     {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_6,      incrihgaps,     {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_7,      incrivgaps,     {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_7,      incrivgaps,     {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_8,      incrohgaps,     {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_8,      incrohgaps,     {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_9,      incrovgaps,     {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_9,      incrovgaps,     {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_0,      togglegaps,     {0} },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_0,      defaultgaps,    {0} },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
    TAGKEYS(                        XK_0,                      9)
    {MODKEY,						XK_l,       spawn,		   SHCMD("slock") },
    { 0, XF86XK_AudioMute,			spawn,					   SHCMD("amixer sset Master toggle") },
	{ 0, XF86XK_AudioRaiseVolume,	spawn,					   SHCMD("/usr/bin/volume up") },
	{ 0, XF86XK_AudioLowerVolume,	spawn,					   SHCMD("/usr/bin/volume down") },
	{ 0, XF86XK_AudioPrev,			spawn,		 			   {.v = muprev } },
	{ 0, XF86XK_AudioNext,			spawn,					   {.v = munext } },
	{ 0, XF86XK_AudioPause,			spawn,					   {.v = mupause } },
	{ 0, XF86XK_AudioPlay,			spawn,					   {.v = mupause } },
	{ 0, XF86XK_AudioStop,			spawn,					   {.v = mupause } },
	{ 0, XF86XK_AudioRewind,		spawn,					   SHCMD("mpc seek -10") },
	{ 0, XF86XK_AudioForward,		spawn,					   SHCMD("mpc seek +10") },
	{ MODKEY,						XK_w,		spawn,		   {.v = browsercmd } },
	{ MODKEY|ShiftMask,		    	XK_w,		spawn,		   {.v = altbrowsercmd } },
	{ MODKEY,						XK_x,		spawn,		   {.v = exitcmd } },
	{ MODKEY,						XK_e,		spawn,		   {.v = editcmd } },
	{ MODKEY,						XK_b,		spawn,		   SHCMD("buku-dmenu") },
	{ MODKEY|ShiftMask,				XK_p,		spawn,		   SHCMD("clipmenu") },
	{ MODKEY,						XK_m,		spawn,		   SHCMD("st -c ncmpcpp -e ncmpcpp") },
	{ MODKEY,						XK_f,		spawn,		   {.v = filecmd } },
	{ 0,							XK_Print,	spawn,		   {.v = scrotcmd } },
	{ MODKEY|ControlMask|ShiftMask, XK_e,      quit,           {1} }, 
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,                 Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,                 Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkLtSymbol,          0,                 Button4,        cyclelayout,    {.i = +1 } },
	{ ClkLtSymbol,          0,                 Button5,        cyclelayout,    {.i = -1 } },
	{ ClkWinTitle,          0,                 Button2,        zoom,           {0} },
	{ ClkStatusText,        0,                 Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,            Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY|Mod1Mask,   Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,            Button3,        resizemouse,    {0} },
	{ ClkClientWin,         MODKEY,            Button4,        rotatestack,    {.i = +1 } },
	{ ClkClientWin,         MODKEY,            Button5,        rotatestack,    {.i = -1 } },
	{ ClkClientWin,         MODKEY,            Button2,        zoom,           {0} },
	{ ClkClientWin,         MODKEY|Mod1Mask,   Button4,        cyclelayout,    {.i = -1 } },
	{ ClkClientWin,         MODKEY|Mod1Mask,   Button5,        cyclelayout,    {.i = +1 } },
	{ ClkTagBar,            0,                 Button1,        view,           {0} },
	{ ClkTagBar,            0,                 Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,            Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,            Button3,        toggletag,      {0} },
};

static const char *ipcsockpath = "/tmp/dwm.sock";
static IPCCommand ipccommands[] = {
  IPCCOMMAND(  view,                1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  toggleview,          1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  tag,                 1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  toggletag,           1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  tagmon,              1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  focusmon,            1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  focusmonnum,         1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  focusstack,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  zoom,                1,      {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  spawn,               1,      {ARG_TYPE_PTR}    ),
  IPCCOMMAND(  incnmaster,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  killclient,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  togglefloating,      1,      {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  setmfact,            1,      {ARG_TYPE_FLOAT}  ),
  IPCCOMMAND(  setlayoutsafe,       1,      {ARG_TYPE_PTR}    ),
  IPCCOMMAND(  quit,                1,      {ARG_TYPE_NONE}   )
};

