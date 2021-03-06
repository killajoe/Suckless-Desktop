/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx       = 1;   /* border pixel of windows */
static const unsigned int snap           = 32;  /* snap pixel */
static const unsigned int gappih         = 10;  /* horiz inner gap between windows */
static const unsigned int gappiv         = 10;  /* vert inner gap between windows */
static const unsigned int gappoh         = 10;   /* horiz outer gap between windows and screen edge */
static const unsigned int gappov         = 10;   /* vert outer gap between windows and screen edge */
static const int smartgaps               = 1;   /* 1 means no outer gap when there is only one window */
static const int showbar                 = 1;   /* 0 means no bar */
static const int topbar                  = 1;   /* 0 means bottom bar */
static const int horizpadbar             = 6;   /* horizontal padding for statusbar */
static const int vertpadbar              = 10;   /* vertical padding for statusbar */
static const int focusonnetactive        = 1;   /* 0 means default behaviour, 1 means auto-focus on urgent window */
static const int attachmode              = 2;   /* 0 = master (default), 1 = above, 2 = aside, 3 = below, 4 = bottom */
static const int pertag                  = 1;   /* 0 means global layout across all tags (default), 1 = layout per tag (pertag) */
static const int pertagbar               = 0;   /* 0 means using pertag, but with the same barpos, 1 = normal pertag */
static const int zoomswap                = 1;   /* 0 means default behaviour, 1 = zoomswap patch */
static const int fancybar                = 1;   /* 0 means default behaviour, 1 = fancybar patch */
static const int savefloats              = 1;   /* 0 means default behaviour, 1 = savefloats patch */
static const int losefullscreen          = 1;   /* 0 means default behaviour, 1 = losefullscreen patch */
static const int nrg_force_vsplit        = 1;   /* nrowgrid layout, 1 means force 2 clients to always split vertically */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 0;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray             = 1;   /* 0 means no systray */
static const char *fonts[]         		 = {"Inter:style=Regular:size=10", "Font Awesome 5 Pro:style=Solid:pixelsize=12:antialias=true", "Font Awesome 5 Brands:style=Solid:pixelsize=12:antialias=true", "Material Design Icons:Regular:pixelsize=22:antialias=true"};
static const char dmenufont[]            = "SF Pro Text:size=5";
static const char col_gray1[]            = "#141414";
static const char col_gray2[]            = "#505050";
static const char col_gray3[]            = "#353535";
static const char col_gray4[]            = "#c6c6c6";
static const char col_gray5[]            = "#fffefe";
static const char col_gray6[]            = "#292929";
static const char col_gray7[]            = "#212121";
static const char col_cyan[]             = "#7e9cb9";
static const char col_blue[]			 = "#6699cc";
/*static const unsigned int baralpha       = 0xd0;*/
/*static const unsigned int baralpha       = 225;*/
static const unsigned int baralpha       = 235;
static const unsigned int borderalpha    = 255;
static const char *colors[][3] = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray4, col_gray1, col_blue },
	[SchemeSel]  = { col_gray5, col_gray6,  col_gray7  },
};
static const unsigned int alphas[][3] = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

/* tagging */
static const char *tags[] = { "", "", "", "", "", "", "", "", "", "" };
/*static const char *tags[] = { "", "", "", "", "", "", "", "", "", "" };*/

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 *  WM_WINDOW_ROLE(STRING) = role
	 */
	/* class            role                          instance     title   tags mask  switchtag  iscentered   isfloating   monitor */
	{ "qutebrowser",    NULL,                         NULL,        NULL,   1,	      1,         0,           0,            1 },
	{ "firefox",        NULL,                         NULL,        NULL,   1,	      1,         0,           0,            1 },
	{ "Nightly",        NULL,                         NULL,        NULL,   1,	      1,         0,           0,            1 },
	{ "Google-chrome",  NULL,                         NULL,        NULL,   1,	      1,         0,           0,            1 },
	{ "Vivaldi-stable", NULL,                         NULL,        NULL,   1,	      1,         0,           0,            1 },
	{ "Surf",           NULL,                         NULL,        NULL,   1,	      1,         0,           0,            1 },
	{ "ncmpcpp",   		NULL,  				  		  NULL,   	   NULL,   1 << 3,    1,         0,			  0,		    1 },
	{ "St",	            NULL,                         NULL,        NULL,   1 << 1,    1,         0,           0,            1 },
	{ "Transmission-gtk",NULL,                        NULL,        NULL,   1 << 2,    1,         0,           0,            1 },
	{ "SoulseekQt",		NULL,                         NULL,        NULL,   1 << 2,    1,         0,           0,            1 },
	{ "Thunar",		    NULL,                         NULL,        NULL,   1 << 4,    1,         0,           0,            1 },
	{ "File-roller",    NULL,                         NULL,        NULL,   1 << 4,    1,         1,           1,            1 },
	{ "mpv",          	NULL,                         NULL,        NULL,   1 << 5,    1,         0,           0,            1 },
	{ "Subl3",		    NULL,                         NULL,        NULL,   1 << 6,    1,         0,           0,            1 },
	{ "Code",		    NULL,                         NULL,        NULL,   1 << 6,    1,         0,           0,            1 },
	{ "Steam",          NULL,                         NULL,        NULL,   1 << 7,    1,         0,           0,            1 },
	{ "Slack",          NULL,                         NULL,        NULL,   1 << 7,    1,         0,           0,            1 },
	{ "Easytag",	    NULL,                         NULL,        NULL,   1 << 8,    1,         1,           0,            1 },
	{ "Xfce4-taskmanager",NULL,                       NULL,        NULL,   1 << 9,    1,         1,           0,            1 },
	{ "Gimp",           NULL,                         NULL,        NULL,   1 << 9,    1,         0,           1,            1 },
	{ "firefox",		"GtkFileChooserDialog",       "Save File", NULL,   0,         0,         1,           1,            1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

#include "vanitygaps.c"

static const int layoutaxis[] = {
	SPLIT_VERTICAL,   /* layout axis: 1 = x, 2 = y; negative values mirror the layout, setting the master area to the right / bottom instead of left / top */
	TOP_TO_BOTTOM,    /* master axis: 1 = x (from left to right), 2 = y (from top to bottom), 3 = z (monocle), 4 = grid */
	TOP_TO_BOTTOM,    /* stack axis:  1 = x (from left to right), 2 = y (from top to bottom), 3 = z (monocle), 4 = grid */
};

static const Layout layouts[] = {
	/* symbol	arrange function */
	{ "󰕴",	dwindle }, /* first entry is default */
	{ "󰙀",	tile },
	{ "󰕰", grid },
	{ "󰕫", centeredmaster },
	{ "󰕬", centeredfloatingmaster },
	{ "󰕯",	NULL },    /* no layout function means floating behavior */
	{ "󰾍",	bstack },
	{ "󱇚",	bstackhoriz },
	{ "󱒈",	gaplessgrid },
	{ "󰕭",	horizgrid },
	{ "󱒇",	nrowgrid },
	{ "󰡃",	spiral },
	{ "󰃚",	monocle },
	{ "󱒉",	deck },
	{ NULL,	NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
	
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run_history", NULL };
static const char *roficmd[] = { "rofi", "-show", "drun", "-show-icons", NULL };
/*static const char *scrotcmd[] = {"/usr/bin/scr", NULL};*/
static const char *scrotcmd[] = {"teiler", NULL};
static const char *termcmd[]  = { "st", NULL };
/*static const char *browsercmd[] = { "firefox", NULL };*/
static const char *browsercmd[] = { "firefox", NULL };
/*static const char *altbrowsercmd[] = { "qutebrowser", NULL };*/
static const char *exitcmd[] = { "/usr/bin/stop.sh", NULL };
static const char *munext[]  = { "/usr/bin/mpc", "next", NULL };
static const char *muprev[]  = { "/usr/bin/mpc", "prev", NULL };
static const char *mupause[]  = { "/usr/bin/mpc", "toggle", NULL };
static const char *filecmd[] = { "thunar", NULL };
static const char *editcmd[] = { "subl3", NULL };
static const char *vimcmd[] = { "gvim", NULL };
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-g", "120x34", NULL };

#include <X11/XF86keysym.h>
static Key keys[] = {
	/* modifier                     key        function           argument */
	{ MODKEY,                       XK_d,      spawn,             {.v = dmenucmd } },
	/*{ MODKEY,						XK_space,  spawn,             {.v = dmenucmd } },*/
	{ MODKEY, 						XK_space,  spawn, 			  {.v = roficmd } },
	{ MODKEY,                       XK_t, 	   spawn,             {.v = termcmd } },
	{ MODKEY,                       XK_grave,  togglescratch,  	  {.v = scratchpadcmd } },
	{ MODKEY|ShiftMask,             XK_b,      togglebar,         {0} },
	{ MODKEY,                       XK_j,      focusstack,        {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,        {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_j,      rotatestack,       {.i = +1 } },
	{ MODKEY|Mod1Mask,              XK_k,      rotatestack,       {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,        {.i = +1 } },
	{ MODKEY,                       XK_u,      incnmaster,        {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,          {.f = -0.05} },
	{ MODKEY|ControlMask,           XK_l,      setmfact,          {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_h,      setcfact,          {.f = +0.25} },
	{ MODKEY|ShiftMask,             XK_l,      setcfact,          {.f = -0.25} },
	{ MODKEY|ShiftMask,             XK_o,      setcfact,          {.f =  0.00} },
	{ MODKEY|Mod1Mask,              XK_m,      zoom,              {0} },
	{ MODKEY|Mod1Mask,              XK_u,      incrgaps,          {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_u,      incrgaps,          {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_i,      incrigaps,         {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_i,      incrigaps,         {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_o,      incrogaps,         {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_o,      incrogaps,         {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_6,      incrihgaps,        {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_6,      incrihgaps,        {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_7,      incrivgaps,        {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_7,      incrivgaps,        {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_8,      incrohgaps,        {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_8,      incrohgaps,        {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_9,      incrovgaps,        {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_9,      incrovgaps,        {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_0,      togglegaps,        {0} },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_0,      defaultgaps,       {0} },
	{ MODKEY,                       XK_Tab,    view,              {0} },
	{ Mod1Mask,                     XK_Tab,    view,              {0} },
	{ Mod1Mask|ControlMask,         XK_Tab,    view,              {0} },
	{ MODKEY,                       XK_q,      killclient,        {0} },
	{ MODKEY|Mod1Mask|ControlMask,  XK_1,      setlayout,         {.v = &layouts[0]} },
	{ MODKEY|Mod1Mask|ControlMask,  XK_2,      setlayout,         {.v = &layouts[1]} },
	{ MODKEY|Mod1Mask|ControlMask,  XK_3,      setlayout,         {.v = &layouts[2]} },
	{ MODKEY|Mod1Mask|ControlMask,  XK_4,      setlayout,         {.v = &layouts[3]} },
	{ MODKEY|Mod1Mask|ControlMask,  XK_5,      setlayout,         {.v = &layouts[4]} },
	{ MODKEY|Mod1Mask|ControlMask,  XK_6,      setlayout,         {.v = &layouts[5]} },
	{ MODKEY|Mod1Mask|ControlMask,  XK_7,      setlayout,         {.v = &layouts[6]} },
	{ MODKEY|Mod1Mask|ControlMask,  XK_8,      setlayout,         {.v = &layouts[7]} },
	{ MODKEY|Mod1Mask|ControlMask,  XK_9,      setlayout,         {.v = &layouts[8]} },
	{ MODKEY|Mod1Mask|ControlMask,  XK_0,      setlayout,         {.v = &layouts[9]} },
	{ MODKEY|Mod1Mask|ControlMask,  XK_w,      setflexlayout,     {.i = 293 } }, // centered master
	{ MODKEY|ControlMask,           XK_e,      setflexlayout,     {.i = 273 } }, // bstackhoriz layout
	{ MODKEY,                       XK_r,      setflexlayout,     {.i = 272 } }, // bstack layout
	{ MODKEY|ControlMask,           XK_t,      setflexlayout,     {.i = 261 } }, // default tile layout
	{ MODKEY|ShiftMask,             XK_g,      setflexlayout,     {.i = 263 } }, // tile + grid layout
	{ MODKEY|ControlMask,           XK_w,      setflexlayout,     {.i =   7 } }, // grid
	{ MODKEY|Mod1Mask|ControlMask,  XK_e,      setflexlayout,     {.i = 262 } }, // deck layout
	{ MODKEY|ControlMask,           XK_r,      setflexlayout,     {.i =   6 } }, // monocle
	{ MODKEY|ControlMask,           XK_g,      setflexlayout,     {.i = 257 } }, // columns (col) layout
	{ MODKEY|ControlMask,           XK_space,  setlayout,         {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating,    {0} },
	{ MODKEY|ShiftMask,             XK_f,      togglefullscreen,  {0} },
	{ MODKEY,                       XK_n,      view,              {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,               {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,          {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,          {.i = +1 } },
	{ MODKEY|ControlMask,           XK_comma,  cyclelayout,       {.i = -1 } },
	{ MODKEY|ControlMask,           XK_period, cyclelayout,       {.i = +1 } },
	{ MODKEY|Mod1Mask,              XK_comma,  tagmon,            {.i = +1 } },
	{ MODKEY|Mod1Mask,              XK_period, tagmon,            {.i = -1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_comma,  tagallmon,         {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_period, tagallmon,         {.i = -1 } },
	{ MODKEY|Mod1Mask|ControlMask,  XK_comma,  tagswapmon,        {.i = +1 } },
	{ MODKEY|Mod1Mask|ControlMask,  XK_period, tagswapmon,        {.i = -1 } },
	TAGKEYS(                        XK_1,                         0)
	TAGKEYS(                        XK_2,                         1)
	TAGKEYS(                        XK_3,                         2)
	TAGKEYS(                        XK_4,                         3)
	TAGKEYS(                        XK_5,                         4)
	TAGKEYS(                        XK_6,                         5)
	TAGKEYS(                        XK_7,                         6)
	TAGKEYS(                        XK_8,                         7)
	TAGKEYS(                        XK_9,                         8)
	TAGKEYS(                        XK_0,                         9)
	TAGKEYS(                        XK_F1,                        0)
	TAGKEYS(                        XK_F2,                        1)
	TAGKEYS(                        XK_F3,                        2)
	TAGKEYS(                        XK_F4,                        3)
	TAGKEYS(                        XK_F5,                        4)
	TAGKEYS(                        XK_F6,                        5)
	TAGKEYS(                        XK_F7,                        6)
	TAGKEYS(                        XK_F8,                        7)
	TAGKEYS(                        XK_F9,                        8)
	TAGKEYS(                        XK_F10,                       9)
	{ MODKEY|ShiftMask,             XK_q,      quit,              {0} },
	{ MODKEY|ControlMask,           XK_t,      rotatelayoutaxis,  {.i = 0} },    /* flextile, 0 = layout axis */
	{ MODKEY|ControlMask,           XK_Tab,    rotatelayoutaxis,  {.i = 1} },    /* flextile, 1 = master axis */
	{ MODKEY|ControlMask|ShiftMask, XK_Tab,    rotatelayoutaxis,  {.i = 2} },    /* flextile, 2 = stack axis */
	{ MODKEY|ControlMask,           XK_Return, mirrorlayout,      {0} },         /* flextile, flip master and stack areas */
	{ 0,							XK_Print,	spawn,			{.v = scrotcmd } },
	{ 0, XF86XK_AudioMute,			spawn,						SHCMD("amixer sset Master toggle") },
	{ 0, XF86XK_AudioRaiseVolume,	spawn,						SHCMD("/usr/bin/volume up") },
	{ 0, XF86XK_AudioLowerVolume,	spawn,						SHCMD("/usr/bin/volume down") },
	{ 0, XF86XK_AudioPrev,			spawn,		 				{.v = muprev } },
	{ 0, XF86XK_AudioNext,			spawn,						{.v = munext } },
	{ 0, XF86XK_AudioPause,			spawn,						{.v = mupause } },
	{ 0, XF86XK_AudioPlay,			spawn,						{.v = mupause } },
	{ 0, XF86XK_AudioStop,			spawn,						{.v = mupause } },
	{ 0, XF86XK_AudioRewind,		spawn,						SHCMD("mpc seek -10") },
	{ 0, XF86XK_AudioForward,		spawn,						SHCMD("mpc seek +10") },
	{ MODKEY,						XK_w,		spawn,			{.v = browsercmd } },
	/*{ MODKEY|ShiftMask,				XK_w,		spawn,			SHCMD("QT_SCALE_FACTOR=0.5 qutebrowser") },*/
	{ MODKEY|ShiftMask,				XK_w,		spawn,			SHCMD("qutebrowser") },
	{ MODKEY|Mod1Mask,				XK_w,		spawn,			SHCMD("google-chrome-stable") },
	{ MODKEY,						XK_x,		spawn,			{.v = exitcmd } },
	{ MODKEY,						XK_e,		spawn,			{.v = editcmd } },
	{ MODKEY|ShiftMask, 			XK_e,		spawn,			{.v = vimcmd } },
	{ MODKEY|ShiftMask,				XK_p,		spawn,			SHCMD("rofi -modi \"clipboard:greenclip print\" -show clipboard -run-command '{cmd}'") },
	/*{ MODKEY|ShiftMask,				XK_p,		spawn,			SHCMD("clipmenu") },*/
	{ MODKEY,						XK_b,		spawn,		    SHCMD("buku-dmenu") },
	/*{ MODKEY,						XK_m,		spawn,			SHCMD("st -c ncmpcpp -e ncmpcpp -S media_library") },*/
	{ MODKEY,						XK_m,		spawn,			SHCMD("st -c ncmpcpp -e ncmpcpp") },
	{ MODKEY|ShiftMask,				XK_m,		spawn,			SHCMD("QT_SCALE_FACTOR=0.5 audacious") },
	{ MODKEY,						XK_f,		spawn,			{.v = filecmd } },
	{ MODKEY,						XK_l,       spawn,		    SHCMD("slock") },
};
 
/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask         button          function        argument */
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