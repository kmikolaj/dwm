/* See LICENSE file for copyright and license details. */

/* appearance */
static const char font[]            = "-*-stlarch-*-*-*-*-12-*-*-*-*-*-*-*" "," "-*-terminus-medium-*-*-*-12-*-*-*-*-*-iso10646-1";
//static const char font[]            = "xft:Envy Code R:pixelsize=11";
//static const char font[]            = "xft:Dejavu Sans Mono:medium:size=10";
static const char colors[MAXCOLORS][ColLast][8] = {
	{ "#444444", "#839496", "#073642" }, /* 1 = normal */
	{ "#B58900", "#FDF6E3", "#073642" }, /* 2 = selected */
	{ "#D33682", "#FDF6E3", "#D33682" }, /* 3 = urgent */
	{ "#444444", "#657b83", "#073642" }, /* 4 = gray */
	{ "#444444", "#859900", "#073642" }, /* 5 = green */
	{ "#444444", "#2AA198", "#073642" }, /* 6 = cyan */
	{ "#444444", "#D33682", "#073642" }, /* 7 = magenta */
	{ "#444444", "#CB4B16", "#073642" }, /* 8 = unusable */
	{ "#444444", "#B58900", "#073642" }, /* 9 = yellow */
};
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 24;       /* snap pixel */
static const unsigned int systrayspacing = 1;   /* systray spacing */
static const Bool showsystray       = True;     /* False means no systray */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = True;     /* False means bottom bar */
static const Bool viewontag         = True;     /* Switch view on tag switch */
static const Bool clicktofocus      = False;    /* Change focus only on click */

static const Rule rules[] = {
	/* class                    instance            title               tags mask         isfloating   iscentred    monitor */
	{ "URxvt",                  "alsamixer",        NULL,                    0,           True,        True,        -1 },
	{ "Display",                NULL,               NULL,                    0,           True,        True,        -1 },
	{ "XFontSel",               NULL,               NULL,                    0,           True,        True,        -1 },
	//{ "MPlayer",                NULL,               NULL,                  0,           True,        True,        -1 },
	//{ "mplayer2",               NULL,               NULL,                  0,           True,        True,        -1 },
	{ "Galculator",             NULL,               NULL,                    0,           True,        True,        -1 },
	{ "Gcolor2",                NULL,               NULL,                    0,           True,        True,        -1 },
	{ "Pystopwatch",            NULL,               NULL,                    0,           True,        True,        -1 },
	{ "URxvt",                  "tmux",             NULL,               1 << 0,           False,       False,       -1 }, 
	{ "URxvt",                  "mutt",             NULL,               1 << 1,           False,       False,       -1 }, 
	{ "Claws-mail",             NULL,               NULL,               1 << 1,           False,       False,       -1 },
	{ "Firefox",                NULL,               NULL,               1 << 1,           True,        True,        -1 },
	{ "Firefox",                "Navigator",        NULL,               1 << 1,           False,       False,       -1 },
	{ "Opera",                  NULL,               NULL,               1 << 1,           False,       False,       -1 },
	{ "Chromium",               NULL,               NULL,               1 << 1,           False,       False,       -1 },
	{ "Dwb",                    NULL,               NULL,               1 << 1,           False,       False,       -1 },
	{ "luakit",                 NULL,               NULL,               1 << 1,           False,       False,       -1 },
	{ "sublime-text",           NULL,               NULL,               1 << 2,           False,       False,       -1 },
	{ "Geany",                  NULL,               NULL,               1 << 2,           False,       False,       -1 },
	{ "Eclipse",                NULL,               NULL,               1 << 2,           False,       False,       -1 },
	{ "Gvim",                   NULL,               NULL,               1 << 2,           False,       False,       -1 },
	{ "QtCreator",              NULL,               NULL,               1 << 2,           False,       False,       -1 },
	{ "Viewnior",               NULL,               NULL,               1 << 3,           False,       False,       -1 },
	{ "Mirage",                 NULL,               NULL,               1 << 3,           False,       False,       -1 },
	{ "Geeqie",                 NULL,               NULL,               1 << 3,           False,       False,       -1 },
	{ "Deadbeef",               NULL,               NULL,               1 << 3,           False,       False,       -1 },
	{ "Avidemux",               NULL,               NULL,               1 << 3,           False,       False,       -1 },
	{ "Puddletag",              NULL,               NULL,               1 << 3,           False,       False,       -1 },
	{ "Audacity",               NULL,               NULL,               1 << 3,           False,       False,       -1 },
	{ "de-hattrickorganizer-HO",NULL,               NULL,               1 << 3,           False,       False,       -1 }, 
	{ "crawl-tiles"            ,NULL,               NULL,               1 << 3,           True,        True,        -1 }, 
	{ "Pidgin",                 NULL,               NULL,               1 << 4,           False,       False,       -1 },
	{ "Kadu",                   NULL,               NULL,               1 << 4,           False,       False,       -1 },
	{ "Gimp",                   NULL,               NULL,               1 << 5,           False,       False,       -1 },
	{ "Mtpaint",                NULL,               NULL,               1 << 5,           False,       False,       -1 },
	{ "Xfe",                    NULL,               NULL,               1 << 5,           False,       False,       -1 },
	{ "Lyx",                    NULL,               NULL,               1 << 5,           False,       False,       -1 },
	{ "libreoffice-writer",     NULL,               NULL,               1 << 5,           False,       False,       -1 },
	{ "libreoffice-calc",       NULL,               NULL,               1 << 5,           False,       False,       -1 },
	{ "libreoffice-math",       NULL,               NULL,               1 << 5,           False,       False,       -1 },
	{ "libreoffice-impress",    NULL,               NULL,               1 << 5,           False,       False,       -1 },
	{ NULL,                     NULL,               "LibreOffice",      1 << 5,           False,       False,       -1 },
	{ "Calibre-gui",            NULL,               NULL,               1 << 5,           False,       False,       -1 },
	{ "sigil",                  NULL,               NULL,               1 << 5,           False,       False,       -1 }
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
	//{ "",        monocle },
	//{ "",        NULL },               [> no layout function means floating behavior <]
	//{ "",        bstack },
	//{ "",        gaplessgrid },
	//{ "",        pidgin },
};

/* tagging */
static const Tag tags[6] = {
	/* name      layout             mfact    nmaster */
	{ "sys",     &layouts[0],       -1,      -1 },
	{ "web",     &layouts[1],       -1,      -1 },
	{ "dev",     &layouts[3],       0.90,    -1 },
	{ "ent",     &layouts[0],       -1,      -1 },
	{ "msg",     &layouts[5],       0.80,    -1 },
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
static const char *dmenucmd[]       = { "dmenu_run", "-b", "-fn", font, "-nb", colors[0][ColBG], "-nf", colors[0][ColFG],"-sb", colors[8][ColFG], "-sf", colors[8][ColBG], NULL };
static const char *dlocatecmd[]     = { "dlocate", "-l", "10", "-b", "-fn", font, "-nb", colors[0][ColBG], "-nf", colors[0][ColFG],"-sb", colors[8][ColFG], "-sf", colors[8][ColBG], NULL };
static const char *quitcmd[]        = { "dmenu_quit", "-b", "-fn", font, "-nb", colors[0][ColBG], "-nf", colors[0][ColFG],"-sb", colors[8][ColFG], "-sf", colors[8][ColBG], NULL };
static const char *umountcmd[]      = { "dmenu_umount", "-b", "-fn", font, "-nb", colors[0][ColBG], "-nf", colors[0][ColFG],"-sb", colors[8][ColFG], "-sf", colors[8][ColBG], NULL };
static const char *termcmd[]        = { terminal, NULL };
static const char *tabbedtermcmd[]  = { terminal, "-pe", "tabbed", NULL };
static const char *tmuxcmd[]        = { terminal, "-name", "tmux", "-e", "sh", "-c", "atmux", NULL };
static const char *musiccmd[]       = { terminal, "-name", "ncmpcpp", "-e", "ncmpcpp", NULL };
static const char *rangercmd[]      = { terminal, "-name", "ranger", "-e", "ranger", NULL };
static const char *torrentcmd[]     = { terminal, "-name", "torrent", "-e", "rtorrent", NULL };
static const char *htopcmd[]        = { terminal, "-name", "htop", "-e", "htop", NULL };
static const char *scratchpadcmd[]  = { terminal, "-name", scratchpadname, "-geometry", "132x22", NULL };
static const char *lockcmd[]        = { "slimlock", NULL };
static const char *nextsongcmd[]    = { "mpc", "next", NULL };
static const char *prevsongcmd[]    = { "mpc", "prev", NULL };
static const char *brightnessup[]   = { "brightness", "up", NULL };
static const char *brightnessdown[] = { "brightness", "down", NULL };
static const char *screenshotcmd[]  = { "sh", "-c", "screenshot -d ~/pictures", NULL };
static const char *screenshotwcmd[] = { "sh", "-c", "screenshot -w -d ~/pictures", NULL };

/* multimedia keys */
static const char *xf_calc[]        = { "galculator", NULL };
static const char *xf_player[]      = { terminal, "-name", "ncmpcpp", "-e", "ncmpcpp", NULL };
static const char *xf_mail[]        = { terminal, "-name", "mutt", "-e", "mutt", NULL };
static const char *xf_homepage[]    = { "sh", "-c", "$BROWSER", NULL };
static const char *xf_explorer[]    = { "spacefm", NULL };
static const char *xf_favourites[]  = { "youtube-player", NULL };
static const char *xf_mute[]        = { "amixer", "sset", "'Master'", "toggle", NULL };
static const char *xf_play[]        = { "mpc", "toggle", NULL };
static const char *xf_stop[]        = { "mpc", "stop", NULL };
static const char *xf_volume_up[]   = { "amixer", "set", "'Master'", "playback", "3%+", "unmute", NULL };
static const char *xf_volume_down[] = { "amixer", "set", "'Master'", "playback", "3%-", "unmute", NULL };
static const char *xf_touchpad[] 	= { "touchpadtoggle", NULL };

static Key keys[] = {
	/* modifier                     key         function        argument */
	{ MODKEY,                       XK_z,       dmenuspawn,     {.v = dmenucmd } },
	{ MODKEY,                       XK_q,       dmenuspawn,     {.v = dlocatecmd } },
	{ MODKEY|ShiftMask,             XK_l,       dmenuspawn,     {.v = quitcmd } },
	{ MODKEY,                       XK_m,       dmenuspawn,     {.v = umountcmd } },
	{ MODKEY|ShiftMask,             XK_c,       spawn,          {.v = tabbedtermcmd } },
	{ MODKEY,                       XK_c,       spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_x,       spawn,          {.v = tmuxcmd } },
	{ MODKEY,                       XK_a,       runorraise,     {.v = musiccmd } },
	{ MODKEY,                       XK_r,       spawn,          {.v = rangercmd } },
	{ MODKEY,                       XK_w,       spawn,          {.v = torrentcmd } },
	{ MODKEY,                       XK_F12,     spawn,          {.v = lockcmd } },
	{ ControlMask,                  XK_comma,   spawn,          {.v = brightnessdown } },
	{ ControlMask,                  XK_period,  spawn,          {.v = brightnessup } },
	{ ALTKEY|ControlMask,           XK_Delete,  spawn,          {.v = htopcmd } },
	{ 0,                            XK_Print,   spawn,          {.v = screenshotcmd } },
	{ ALTKEY,                       XK_Print,   spawn,          {.v = screenshotwcmd } },
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
	{ MODKEY|ShiftMask,             XK_e,       centerwindow,   {0} },
	{ MODKEY|ShiftMask,             XK_t,       setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ShiftMask,             XK_m,       setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ShiftMask,             XK_f,       setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ShiftMask,             XK_b,       setlayout,      {.v = &layouts[3]} },
	{ MODKEY|ShiftMask,             XK_g,       setlayout,      {.v = &layouts[4]} },
	{ MODKEY|ShiftMask,             XK_p,       setlayout,      {.v = &layouts[5]} },
	{ MODKEY,                       XK_space,   setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,   togglefloating, {0} },
	//{ MODKEY,                       XK_0,       view,           {.ui = ~0 } },
	//{ MODKEY|ShiftMask,             XK_0,       tag,            {.ui = ~0 } },
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
	{ 0,                            0x1008ff02, spawn,          {.v = brightnessup } },
	{ 0,                            0x1008ff03, spawn,          {.v = brightnessdown } },
	{ 0,                            0x1008ff11, spawn,          {.v = xf_volume_down } },
	{ 0,                            0x1008ff12, spawn,          {.v = xf_mute } },
	{ 0,                            0x1008ff13, spawn,          {.v = xf_volume_up } },
	{ 0,                            0x1008ff14, spawn,          {.v = xf_play } },
	{ 0,                            0x1008ff15, spawn,          {.v = xf_stop } },
	{ 0,                            0x1008ff16, spawn,          {.v = prevsongcmd } },
	{ 0,                            0x1008ff17, spawn,          {.v = nextsongcmd } },
	{ 0,                            0x1008ff18, spawn,          {.v = xf_homepage } },
	{ 0,                            0x1008ff19, runorraise,     {.v = xf_mail } },
	{ 0,                            0x1008ff1d, spawn,          {.v = xf_calc } },
	{ 0,                            0x1008ff2e, spawn,          {.v = xf_homepage } },
	{ 0,                            0x1008ff30, spawn,          {.v = xf_favourites } },
	{ 0,                            0x1008ff32, spawn,          {.v = xf_player } },
	{ 0,                            0x1008ff33, spawn,          {.v = xf_explorer } },
	{ 0,                            0x1008ffa9, spawn,          {.v = xf_touchpad } },
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

