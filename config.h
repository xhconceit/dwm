/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows 窗口边框大小*/
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar 是否显示状态栏*/
static const int topbar             = 0;        /* 0 means bottom bar 状态栏显示在顶部还是底部*/
static const char *fonts[]          = { "Source Code Pro:size=12" };
static const char dmenufont[]       = "Source Code Pro:size=12";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging 标签名字 */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions Mod1Mask: Alt Mod4Mask: Window */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
// 极简应用程序选择器
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };

// 临时的浮动居中终端
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-g", "120x34", NULL };

// 终端
static const char *termcmd[]  = { "st", NULL };

// chromium 浏览器
static const char *browsercmd[]  = { "chromium", NULL };

// poweroff 关机
static const char *poweroffcmd[]  = { "poweroff", NULL };

// reboot 重启
static const char *rebootcmd[]  = { "reboot", NULL };

// ranger 终端文件管理
static const char ranger[] = "ranger";
static const char *rangercmd[] = { "st", "-e", ranger, NULL };

static Key keys[] = {
	// 临时的浮动居中终端
	{ MODKEY,                       XK_grave,  togglescratch,  {.v = scratchpadcmd } },
        // ranger
        { MODKEY,                       XK_F3,     spawn,          {.v = rangercmd} },
        // 重启
        { MODKEY|ShiftMask,             XK_r,      spawn,          {.v = rebootcmd} },
        // 关机
        { MODKEY|ShiftMask,             XK_e,      spawn,          {.v = poweroffcmd} },
        // chromium
        { MODKEY,                       XK_F2,     spawn,          {.v = browsercmd } },
        /* modifier                     key        function        argument */
        // 极简应用程序选择器
        { MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
        // 终端
        { MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
        // 显示 隐藏 状态栏
        { MODKEY,                       XK_b,      togglebar,      {0} },
        // 下一个窗口
        { MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
        // 上一个窗口
        { MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
        // 水平窗口
        { MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
        // 垂直窗口
        { MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
        // 缩小窗口
        { MODKEY,                       XK_h,      setmfact,       {.f = -0.02} },
        // 扩大窗口
        { MODKEY,                       XK_l,      setmfact,       {.f = +0.02} },
        // 将当前选中窗口或者下一个窗口提为主窗口
        { ShiftMask,                    XK_Return, zoom,           {0} },
        // 切换上一次选择的标签
        { MODKEY,                       XK_Tab,    view,           {0} },
        // 关闭当前窗口
        { MODKEY,                       XK_q,      killclient,     {0} },
        // 多窗口模式
        { MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
        /*
        // 浮动窗口模式
        { MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
        // 单窗口模式
        { MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
        // 切换上一次选择的窗口模式
        { MODKEY,                       XK_space,  setlayout,      {0} },
        */
        //
        { MODKEY,                       XK_space,  togglefloating, {0} },
        // 选择全部标签
        { MODKEY,                       XK_0,      view,           {.ui = ~0 } },
        // 当前窗口同步到全部标签
        { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
        { MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
        { MODKEY,                       XK_period, focusmon,       {.i = +1 } },
        { MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
        { MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
        TAGKEYS(                        XK_1,                      0)
        TAGKEYS(                        XK_2,                      1)
        TAGKEYS(                        XK_3,                      2)
        TAGKEYS(                        XK_4,                      3)
        TAGKEYS(                        XK_5,                      4)
        TAGKEYS(                        XK_6,                      5)
        TAGKEYS(                        XK_7,                      6)
        TAGKEYS(                        XK_8,                      7)
        TAGKEYS(                        XK_9,                      8)
        // 退出 dwm
        { MODKEY|ShiftMask,             XK_q,      quit,           {0} },
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
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

