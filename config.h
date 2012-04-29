/* See LICENSE file for copyright and license details. */

/* appearance */
static const char font[]            = "-*-stlarch-*-*-*-*-12-*-*-*-*-*-*-*" "," "-*-terminus-medium-*-*-*-12-*-*-*-*-*-iso10646-1";
static const char colors[MAXCOLORS][ColLast][8] = {
	{ "#444444", "#BBBBBB", "#1A1A1A" }, /* 1 = normal */
	{ "#005577", "#EEEEEE", "#005577" }, /* 2 = selected */
	{ "#FF2882", "#FFFFFF", "#FF2882" }, /* 3 = urgent */
	{ "#444444", "#93D44F", "#1A1A1A" }, /* 4 = green */
	{ "#444444", "#EAB93D", "#1A1A1A" }, /* 5 = yellow */
	{ "#444444", "#89B6E2", "#1A1A1A" }, /* 6 = cyan */
	{ "#444444", "#EEEEEE", "#1A1A1A" }, /* 7 = magenta */
	{ "#444444", "#899CA1", "#1A1A1A" }, /* 8 = grey unusable */
};
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 24;       /* snap pixel */
static const unsigned int systrayspacing = 1;   /* systray spacing */
static const Bool showsystray       = True;     /* False means no systray */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = True;     /* False means bottom bar */
static const Bool viewontag         = True;     /* Switch view on tag switch */

static const Rule rules[] = {
	/* class                    instance            title               tags mask     isfloating   iscentred    monitor */
	{ "URxvt",                  "alsamixer",        NULL,               0,            True,        True,        -1 },
	{ "Display",                NULL,               NULL,               0,            True,        True,        -1 },
	{ "XFontSel",               NULL,               NULL,               0,            True,        True,        -1 },
	//{ "MPlayer",                NULL,               NULL,               0,            True,        True,        -1 },
	//{ "mplayer2",               NULL,               NULL,               0,            True,        True,        -1 },
	{ "Galculator",             NULL,               NULL,               0,            True,        True,        -1 },
	{ "Gcolor2",                NULL,               NULL,               0,            True,        True,        -1 },
	{ "Pystopwatch",            NULL,               NULL,               0,            True,        True,        -1 },
	{ "URxvt",                  "tmux",             NULL,               1,            False,       False,       -1 }, 
	{ "URxvt",                  "mutt",             NULL,               2,            False,       False,       -1 }, 
	{ "Claws-mail",             NULL,               NULL,               2,            False,       False,       -1 },
	{ "Firefox",                NULL,               NULL,               2,            True,        True,        -1 },
	{ "Firefox",                "Navigator",        NULL,               2,            False,       False,       -1 },
	{ "Opera",                  NULL,               NULL,               2,            False,       False,       -1 },
	{ "Vimprobable2",           NULL,               NULL,               2,            False,       False,       -1 },
	{ "luakit",                 NULL,               NULL,               2,            False,       False,       -1 },
	{ "Sublime_text",           NULL,               NULL,               4,            False,       False,       -1 },
	{ "Geany",                  NULL,               NULL,               4,            False,       False,       -1 },
	{ "java-lang-Thread",       NULL,               "NetBeans IDE 6.1", 4,            False,       False,       -1 },
	{ "Gvim",                   NULL,               NULL,               4,            False,       False,       -1 },
	{ "Qtcreator",              NULL,               NULL,               4,            False,       False,       -1 },
	{ "Viewnior",               NULL,               NULL,               8,            False,       False,       -1 },
	{ "Mirage",                 NULL,               NULL,               8,            False,       False,       -1 },
	{ "Geeqie",                 NULL,               NULL,               8,            False,       False,       -1 },
	{ "Deadbeef",               NULL,               NULL,               8,            False,       False,       -1 },
	{ "Avidemux",               NULL,               NULL,               8,            False,       False,       -1 },
	{ "Puddletag",              NULL,               NULL,               8,            False,       False,       -1 },
	{ "Audacity",               NULL,               NULL,               8,            False,       False,       -1 },
	{ "de-hattrickorganizer-HO",NULL,               NULL,               8,            False,       False,       -1 }, 
	{ "Pidgin",                 NULL,               NULL,               16,           False,       False,       -1 },
	{ "Kadu",                   NULL,               NULL,               16,           False,       False,       -1 },
	{ "Gimp",                   NULL,               NULL,               32,           True,        False,       -1 },
	{ "Mtpaint",                NULL,               NULL,               32,           False,       False,       -1 },
	{ "Xfe",                    NULL,               NULL,               64,           False,       False,       -1 },
	{ "Lyx",                    NULL,               NULL,               64,           False,       False,       -1 },
	{ "libreoffice-writer",     NULL,               NULL,               64,           False,       False,       -1 },
	{ "libreoffice-calc",       NULL,               NULL,               64,           False,       False,       -1 },
	{ "libreoffice-math",       NULL,               NULL,               64,           False,       False,       -1 },
	{ "libreoffice-impress",    NULL,               NULL,               64,           False,       False,       -1 },
	{ NULL,                     NULL,               "LibreOffice",      64,           False,       False,       -1 },
};

/* layout(s) */
static const float mfact      = 0.5;    /* factor of master area size [0.05..0.95] */
static const int nmaster      = 1;      /* number of clients in master area */
static const Bool resizehints = False;  /* True means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
    { "[T]",      tile },               /* first entry is default */
    { "[M]",      monocle },
    { "[F]",      NULL },               /* no layout function means floating behavior */
    { "[B]",      bstack },
    { "[G]",      gaplessgrid },
    { "[P]",      pidgin },
    
	//{ "",        tile },               [> first entry is default <]
	//{ "",        monocle },
	//{ "",        NULL },               [> no layout function means floating behavior <]
	//{ "",        bstack },
	//{ "",        gaplessgrid },
	//{ "",        pidgin },
};

/* tagging */
static const Tag tags[7] = {
	/* name      layout             mfact    nmaster */
	{ "sys",     &layouts[0],       -1,      -1 },
	{ "web",     &layouts[1],       -1,      -1 },
	{ "dev",     &layouts[0],       -1,      -1 },
	{ "ent",     &layouts[0],       -1,      -1 },
	{ "msg",     &layouts[5],       0.80,    -1 },
	{ "img",     &layouts[1],       -1,      -1 },
	{ "etc",     &layouts[1],       -1,      -1 },
};

/* key definitions */
#define ALTKEY Mod1Mask
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char terminal[]        = "urxvtc";
static const char scratchpadname[]  = "scratchpad";
static const char *dmenucmd[]       = { "dmenu_run", "-b", "-fn", font, "-nb", colors[0][ColBG], "-nf", colors[0][ColFG],"-sb", colors[1][ColBG], "-sf", colors[1][ColFG], NULL };
static const char *termcmd[]        = { terminal, NULL };
static const char *tabbedtermcmd[]  = { terminal, "-pe", "tabbed", NULL };
static const char *tmuxcmd[]        = { terminal, "-name", "tmux", "-e", "sh", "-c", "atmux", NULL };
static const char *mocpcmd[]        = { terminal, "-name", "mocp", "-e", "mocp", NULL };
static const char *htopcmd[]        = { terminal, "-name", "htop", "-e", "htop", NULL };
static const char *scratchpadcmd[]  = { terminal, "-name", scratchpadname, "-geometry", "132x22", NULL };
static const char *lockcmd[]        = { "slimlock", NULL };
static const char *nextsongcmd[]    = { "mocp", "-f", NULL };
static const char *prevsongcmd[]    = { "mocp", "-r", NULL };
static const char *screenshotcmd[]  = { "scrot", NULL };

/* multimedia keys */
static const char *xf_calc[]        = { "galculator", NULL };
static const char *xf_player[]      = { terminal, "-name", "mocp", "-e", "mocp", NULL };
static const char *xf_mail[]        = { terminal, "-name", "mutt", "-e", "mutt", NULL };
static const char *xf_homepage[]    = { "luakit", NULL };
static const char *xf_explorer[]    = { "spacefm", NULL };
static const char *xf_favourites[]  = { "youtube-player", NULL };
static const char *xf_mute[]        = { "amixer", "sset", "'Master'", "toggle", NULL };
static const char *xf_play[]        = { "mocp", "-G", NULL };
static const char *xf_volume_up[]   = { "amixer", "set", "'Master'", "playback", "1+", "unmute", NULL };
static const char *xf_volume_down[] = { "amixer", "set", "'Master'", "playback", "1-", "unmute", NULL };

static Key keys[] = {
	/* modifier                     key         function        argument */
	{ MODKEY,                       XK_z,       spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_c,       spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_c,       spawn,          {.v = tabbedtermcmd } },
	{ MODKEY,                       XK_x,       spawn,          {.v = tmuxcmd } },
	{ MODKEY,                       XK_a,       spawn,          {.v = mocpcmd } },
	{ MODKEY,                       XK_F12,     spawn,          {.v = lockcmd } },
	{ 0|ControlMask,                XK_comma,   spawn,          {.v = prevsongcmd } },
	{ 0|ControlMask,                XK_period,  spawn,          {.v = nextsongcmd } },
	{ ALTKEY|ControlMask,           XK_Delete,  spawn,          {.v = htopcmd } },
	{ 0,                            XK_Print,   spawn,          {.v = screenshotcmd } },
	{ MODKEY,                       XK_s,       togglescratch,  {.v = scratchpadcmd } },
	{ MODKEY,                       XK_f,       togglemax,      {0} },
	{ MODKEY,                       XK_b,       togglebar,      {0} },
	{ MODKEY,                       XK_j,       focusstack,     {.i = +1 } },
	{ ALTKEY,                       XK_Tab,     focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,       focusstack,     {.i = -1 } },
	{ ALTKEY|ShiftMask,             XK_Tab,     focusstack,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_j,       pushdown,       {0} },
	{ MODKEY|ShiftMask,             XK_k,       pushup,         {0} },
	{ MODKEY,                       XK_e,       incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,       incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,       setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,       setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return,  zoom,           {0} },
	{ MODKEY,                       XK_Tab,     view,           {0} },
	{ MODKEY,                       XK_grave,   focusurgent,    {0} },
	{ ALTKEY,                       XK_F4,      killclient,     {0} },
	{ MODKEY|ShiftMask,             XK_t,       setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ShiftMask,             XK_m,       setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ShiftMask,             XK_f,       setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ShiftMask,             XK_b,       setlayout,      {.v = &layouts[3]} },
	{ MODKEY|ShiftMask,             XK_g,       setlayout,      {.v = &layouts[4]} },
	{ MODKEY|ShiftMask,             XK_p,       setlayout,      {.v = &layouts[5]} },
	{ MODKEY,                       XK_space,   setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,   togglefloating, {0} },
	{ MODKEY,                       XK_0,       view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,       tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,   focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period,  focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,   tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,  tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_Left,    cycle,          {.i = -1 } },
	{ MODKEY,                       XK_Right,   cycle,          {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_Left,    tagcycle,       {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_Right,   tagcycle,       {.i = +1 } },
	TAGKEYS(                        XK_1,                       0)
	TAGKEYS(                        XK_2,                       1)
	TAGKEYS(                        XK_3,                       2)
	TAGKEYS(                        XK_4,                       3)
	TAGKEYS(                        XK_5,                       4)
	TAGKEYS(                        XK_6,                       5)
	TAGKEYS(                        XK_7,                       6)
	//TAGKEYS(                        XK_8,                       7)
	//TAGKEYS(                        XK_9,                       8)
	{ MODKEY|ShiftMask,             XK_q,       quit,           {0} },
	{ MODKEY,                       XK_u,       moveresize,     {.v = (int []){ 0, 25, 0, 0 } } },
	{ MODKEY,                       XK_i,       moveresize,     {.v = (int []){ 0, -25, 0, 0 } } },
	{ MODKEY,                       XK_o,       moveresize,     {.v = (int []){ 25, 0, 0, 0 } } },
	{ MODKEY,                       XK_y,       moveresize,     {.v = (int []){ -25, 0, 0, 0 } } },
	{ MODKEY|ShiftMask,             XK_u,       moveresize,     {.v = (int []){ 0, 0, 0, 25 } } },
	{ MODKEY|ShiftMask,             XK_i,       moveresize,     {.v = (int []){ 0, 0, 0, -25 } } },
	{ MODKEY|ShiftMask,             XK_o,       moveresize,     {.v = (int []){ 0, 0, 25, 0 } } },
	{ MODKEY|ShiftMask,             XK_y,       moveresize,     {.v = (int []){ 0, 0, -25, 0 } } },
	{ 0,                            0x1008ff11, spawn,          {.v = xf_volume_down } },
	{ 0,                            0x1008ff12, spawn,          {.v = xf_mute } },
 	{ 0,                            0x1008ff13, spawn,          {.v = xf_volume_up } },
	{ 0,                            0x1008ff14, spawn,          {.v = xf_play } },
	{ 0,                            0x1008ff18, spawn,          {.v = xf_homepage } },
	{ 0,                            0x1008ff19, spawn,          {.v = xf_mail } },
	{ 0,                            0x1008ff1d, spawn,          {.v = xf_calc } },
	{ 0,                            0x1008ff30, spawn,          {.v = xf_favourites } },
	{ 0,                            0x1008ff32, spawn,          {.v = xf_player } },
	{ 0,                            0x1008ff33, spawn,          {.v = xf_explorer } },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

