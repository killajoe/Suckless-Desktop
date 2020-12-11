/* user and group to drop privileges to */
static const char *user  = "nobody";
static const char *group = "nobody"; // use "nobody" for arch

static const char *colorname[NUMCOLS] = {
	[INIT] =   "#141414",     /* after initialization */
	[INPUT] =  "#7e9cb9",   /* during input */
	[FAILED] = "#f76767",   /* wrong password */
	#if CAPSCOLOR_PATCH
	[CAPS] =   "#ee5555",       /* CapsLock on */
	#endif // CAPSCOLOR_PATCH
	#if PAMAUTH_PATCH
	[PAM] =    "#967ab2",   /* waiting for PAM */
	#endif // PAMAUTH_PATCH
	#if KEYPRESS_FEEDBACK_PATCH
	[BLOCKS] = "#c6c6c6",   /* key feedback block */
	#endif // KEYPRESS_FEEDBACK_PATCH
};

#if XRESOURCES_PATCH
/*
 * Xresources preferences to load at startup
 */
ResourcePref resources[] = {
		{ "color0",       STRING,  &colorname[INIT] },
		{ "color4",       STRING,  &colorname[INPUT] },
		{ "color1",       STRING,  &colorname[FAILED] },
		#if CAPSCOLOR_PATCH
		{ "color3",       STRING,  &colorname[CAPS] },
		#endif // CAPSCOLOR_PATCH
		#if PAMAUTH_PATCH
		{ "color5",       STRING,  &colorname[PAM] },
		#endif // PAMAUTH_PATCH
};
#endif // XRESOURCES_PATCH

#if ALPHA_PATCH
/* lock screen opacity */
static const float alpha = 0.9;
#endif // ALPHA_PATCH

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 1;

#if BLUR_PIXELATED_SCREEN_PATCH
/* Enable blur */
#define BLUR
/* Set blur radius */
static const int blurRadius=5;
/* Enable Pixelation */
//#define PIXELATION
/* Set pixelation radius */
static const int pixelSize=10;
#endif // BLUR_PIXELATED_SCREEN_PATCH

#if CONTROLCLEAR_PATCH
/* allow control key to trigger fail on clear */
static const int controlkeyclear = 0;
#endif // CONTROLCLEAR_PATCH

#if DPMS_PATCH
/* time in seconds before the monitor shuts down */
static const int monitortime = 5;
#endif // DPMS_PATCH

#if KEYPRESS_FEEDBACK_PATCH
static short int blocks_enabled = 1; // 0 = don't show blocks
static const int blocks_width = 0; // 0 = full width
static const int blocks_height = 16;

// position
static const int blocks_x = 0;
static const int blocks_y = 0;

// Number of blocks
static const int blocks_count = 10;
#endif // KEYPRESS_FEEDBACK_PATCH

#if MESSAGE_PATCH
/* default message */
static const char * message = "Welcome.";

/* text color */
static const char * text_color = "#ffffff";

/* text size (must be a valid size) */
static const char * font_name = "6x10";
#endif // MESSAGE_PATCH

#if PAMAUTH_PATCH
/* PAM service that's used for authentication */
static const char* pam_service = "login";
#endif // PAMAUTH_PATCH

#if QUICKCANCEL_PATCH
/* time in seconds to cancel lock with mouse movement */
static const int timetocancel = 4;
#endif // QUICKCANCEL_PATCH